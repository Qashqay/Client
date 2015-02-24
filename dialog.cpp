#include "dialog.h"
#include "testdialog.h"
#include "ui_dialog.h"

#include <QtGui>
#include <QDebug>
#include <QFile>
static int check[2]={0,0};
static QString deviceStat1, deviceStat2, deviceStat3, deviceStat4;
static int i;

Dialog::Dialog(QWidget *parent) :QDialog(parent),ui(new Ui::Dialog)
{
   фыва ui->setupUi(this);
    this->setWindowFlags(Qt::WindowMinimizeButtonHint);
    ui->pteMessage->installEventFilter(this);
    _sokMany = new QTcpSocket*[SERVER_COUNT];
    sound = new QSound("./CUCKOO.wav");
    for (i=0;i<SERVER_COUNT;++i)
        _sokMany[i] = new QTcpSocket(this);
    for (i=0;i<SERVER_COUNT;++i)
        _nameMany[i]="";
    HostName=ReadIPFromFile();
    PortName=FIRST_PORT;
    Temp = ui->lTemp->text();
    //connect(ui->pbInterfer, SIGNAL(clicked()), this, SLOT(openNewWindow()));
    connect(_sokMany[0], SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(onSokDisplayError(QAbstractSocket::SocketError)));
    signalMapper = new QSignalMapper(this);
    for (i=0;i<SERVER_COUNT;++i)
        signalMapper->setMapping(_sokMany[i],int (i));
    for (i=0;i<SERVER_COUNT;++i)
        connect(_sokMany[i],SIGNAL(readyRead()),signalMapper,SLOT(map()));
    connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(onSokReadyRead(int)));
    signalMapper2 = new QSignalMapper(this);
    for (i=0;i<SERVER_COUNT;++i)
        signalMapper2->setMapping(_sokMany[i],int (i));
    for (i=0;i<SERVER_COUNT;++i)
        connect(_sokMany[i],SIGNAL(connected()),signalMapper2,SLOT(map()));
    connect(signalMapper2,SIGNAL(mapped(int)),this,SLOT(onSokConnected(int)));
    connect(_sokMany[0], SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));
    ui->lProp->setStyleSheet("QLabel { color: black;}");
    ui->lProp->setText("Не подключен");
    ChangePalette(ui->frame);
    ChangePalette(ui->fNorm,0,0,0);
    ChangePalette(ui->fDrop,0,0,0);
    ChangePalette(ui->fStop,255,0,0);
    ui->sbPort->hide();
    ui->leHost->hide();
    ui->leName->hide();
    ui->pbInterfer->setEnabled(false);
    //ui->pbInterfer->setEnabled(true);
    mpTimeoutTimer = new QTimer();
    mpTimeoutTimer2 = new QTimer();
    mpTimeoutTimer3 = new QTimer();
    mpTimeoutTimer4 = new QTimer();
    connect(this,SIGNAL(normalModeBegun()),this,SLOT(startTimeOut()));
    connect(mpTimeoutTimer,SIGNAL(timeout()),this,SLOT(onCheckMach()));
    connect(this,SIGNAL(stopModeBegun()),this,SLOT(startTimeOut2()));
    connect(mpTimeoutTimer2,SIGNAL(timeout()),this,SLOT(onCheckMachStop()));
    connect(this,SIGNAL(dropModeBegun()),this,SLOT(startTimeOut3()));
    connect(mpTimeoutTimer3,SIGNAL(timeout()),this,SLOT(onCheckMachDrop()));    
    this->setWindowTitle("ДКВС ("+ReadIPFromFile()+")");
    connect(this,SIGNAL(detectedDelay()),this,SLOT(startTimeOut4()));
    minimumContrast();
}

Dialog::~Dialog()
{
    delete sound;
    delete signalMapper;
    delete signalMapper2;
    delete _sokMany;
    delete ui;
}

//void Dialog::openNewWindow()
//{
//        if ((check[0]!=3) && (check[1]!=2))
//            AddToLog("Выключите режим");
//        else
//        {
//            QByteArray block;
//            QDataStream out(&block, QIODevice::WriteOnly);
//            out << (qint64)0;
//            out << (uint8_t)MyClient::comSendInterf;
//            out.device()->seek(0);
//            out << (qint64)(block.size() - sizeof(qint64));
//            _sokMany[0]->write(block);
//            for (i=0;i<SERVER_COUNT-1;++i)
//                 _sokMany[i]->disconnectFromHost();
//            ui->pbConnect->setEnabled(false);
//            ui->pbInterfer->setEnabled(false);
//            newWin = new Dialog2(this);
//            newWin->show();
//            connect(newWin,SIGNAL(rejected()),this,SLOT(StopInterf()));
//            connect(newWin,SIGNAL(rejected()),this,SLOT(on_pbConnect_clicked()));
//        }
////    }
////    else
////    {
////        QByteArray block;
////        QDataStream out(&block, QIODevice::WriteOnly);
////        out << (qint64)0;
////        out << (uint8_t)MyClient::comSendInterf;
////        out.device()->seek(0);
////        out << (qint64)(block.size() - sizeof(qint64));
////        _sokMany[0]->write(block);
////        for (i=0;i<SERVER_COUNT-1;++i)
////            _sokMany[i]->disconnectFromHost();
////        ui->pbConnect->setEnabled(false);
////        ui->pbInterfer->setEnabled(false);
////        newWin = new Dialog2(this);
////        newWin->show();
////        connect(newWin,SIGNAL(rejected()),this,SLOT(StopInterf()));
////        connect(newWin,SIGNAL(rejected()),this,SLOT(on_pbConnect_clicked()));
////    }
//}

void Dialog::onSokDisplayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, "Ошибка 1", "Не удается подключиться к прибору");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, "Ошибка 2", "Не удается подключиться к прибору");
        break;
    default:
        QMessageBox::information(this, "Ошибка", "Перезапустите программу");
    }
}

void Dialog::onSokReadyRead(int i)
{
    QDataStream in(_sokMany[i]);
    if (_blockSizeMany[i] == 0)
    {
        if (_sokMany[i]->bytesAvailable() < (int)sizeof(qint64))
            return;
        in >>_blockSizeMany[i];
        qDebug()<<"bytes available"<<_sokMany[i]->bytesAvailable();
        qDebug() << "_blockSize now " <<_blockSizeMany[i];
    }
    if (_sokMany[i]->bytesAvailable() <_blockSizeMany[i])
        return;
    else
        _blockSizeMany[i] = 0;
    quint8 command;
    in >> command;
    qDebug() << "Received command " << command<<"on port"<<_sokMany[i]->localPort();
    switch (command)
    {
        case MyClient::comMessageToAll:
        {
            QString user;
            in >> user;
            QString message;
            in >> message;
            qDebug()<<message;
            if (message=="")
            {AddToLog("Обработка интерферограммы",1); return;}
            QStringList pieces = message.split( " " );
            pieces.insert(pieces.size()-1,"dT = "+ui->lContrast->text()+" ");
            message=pieces.join(" ");
            if (message.count("возможно:"))
            {
                QString neededWord = pieces.value( 8 );
                    ui->lProp->setStyleSheet("QLabel { color : red; }");
                ui->lProp->setText(neededWord);
                if((neededWord.count("Лавсан"))||(neededWord.count("Этанол"))||(neededWord.count("Изопропанол"))||(neededWord.count("Фторопласт"))||(neededWord.count("Полистерол")))
                    ChangePalette(ui->frame,0,0,255);
                else
                    ChangePalette(ui->frame,255,255,0);
                ChangePalette(ui->fNorm,0,0,0);
                ChangePalette(ui->fStop,255,0,0);
                ChangePalette(ui->fDrop,255,255,0);
                AddToLog(QDate::currentDate().toString(Qt::SystemLocaleDate)+" "+message, Qt::yellow,0);
                play1();
                this->showNormal();
                emit(detectedDelay());
            }
            else
            {
                QString neededWord = pieces.value( 6 )+"\n"+pieces.value(15);
                ui->lProp->setStyleSheet("QLabel { color : yellow; }");
                ui->lProp->setText(neededWord);
                if((neededWord.count("Лавсан"))||(neededWord.count("Этанол"))||(neededWord.count("Изопропанол"))||(neededWord.count("Фторопласт"))||(neededWord.count("Полистерол")))
                    ChangePalette(ui->frame,0,0,255);
                else
                    ChangePalette(ui->frame,255,0,0);
                ChangePalette(ui->fNorm,0,0,0);
                ChangePalette(ui->fStop,255,0,0);
                ChangePalette(ui->fDrop,255,255,0);
                AddToLog(QDate::currentDate().toString(Qt::SystemLocaleDate)+" "+message, Qt::red,0);
                play1();
                this->showNormal();
                emit(detectedDelay());
            }
        }
        break;
        case MyClient::comSendAllLog:
        {
            QString message;
            in >> message;
            QStringList messages=message.split(",");
            AddToLog("------------------------------------------------------------------------",Qt::black,2);
            for (int j=0;j<messages.size()-1;++j)
                AddToLog(messages.at(j),Qt::black,2);
            AddToLog(QDate::currentDate().toString(Qt::SystemLocaleDate)+"------------------------------------------------------------",Qt::black,2);
        }
        break;
        case MyClient::comSendLastLog:
        {
            QString message;
            in >> message;
            AddToLog("------------------------------------------------------------------------",Qt::magenta,1);
            AddToLog(message,Qt::magenta,1);
            AddToLog("------------------------------------------------------------------------",Qt::magenta,1);
        }
        break;
        case MyClient::comErrNameInvalid:
        {
            QMessageBox::information(this, "Ошибка", "Неподходящее имя");
            _sokMany[i]->disconnectFromHost();
        }
        break;
        case MyClient::comErrNameUsed:
        {
            QMessageBox::information(this, "Ошибка", "Имя уже используется");
           _sokMany[i]->disconnectFromHost();
        }
        break;
        case MyClient::comNormalMode:
        {
            QString message;
            in>>message;
            AddToLog("Выключите режим",Qt::black,1);
        }
        break;
        case MyClient::comStatusInt:
        {
            QString message;
            in >> message;
            QStringList Mes_Count=message.split("/");
            if(Mes_Count.size()==2)
            {
                deviceStat1=Mes_Count.at(0);
                deviceStat3=Mes_Count.at(1);
            }
            ui->lIntObr->setText(message);
        }
        break;
        case MyClient::comTempStat:
        {
            QString message;
            in >> message;
            ui->lTemp->setText(message);
        }
        break;
        case MyClient::comContrast:
        {
            QString message;
            in >> message;
            qDebug()<<message;
            int contr = message.toDouble();
            if (contr < minContrast)
            {
                AddToLog(QDate::currentDate().toString(Qt::SystemLocaleDate)+" "+QTime::currentTime().toString()+" "+"Контраст меньше критического значения",Qt::red,0);
                ChangePalette(ui->frame,255,255,0);
                ui->lProp->setStyleSheet("QLabel { color: black;}");
                ui->lProp->setText("Низкая мощность излучателя");
                //qDebug()<<contr<<minContrast;
                this->showNormal();
                emit(detectedDelay());
            }
            ui->lContrast->setText(message);
        }
        break;
        case MyClient::comMilReady:
        {
            QString message;
            in>>message;
            switch (message.toInt())
            {
            case MyClient::comNormalMode:
            {
                ChangePalette(ui->fNorm,0,255,0);
                ChangePalette(ui->fDrop,0,0,0);
                ChangePalette(ui->fStop,0,0,0);
                connect(mpTimeoutTimer4,SIGNAL(timeout()),this,SLOT(onCheckMachDelay()));
                emit(normalModeBegun());
                check[0]=4; check[1]=4;
            }
            break;
            case MyClient::comDrop:
            {
                ChangePalette(ui->fNorm,0,0,0);
                ChangePalette(ui->fDrop,0,0,0);
                ChangePalette(ui->fStop,255,0,0);
                if((check[0]==3))
                    check[1]=2;
                else
                    check[0]=2;
                 emit(dropModeBegun());
            }
            break;
            case MyClient::comStop:
            {
                ChangePalette(ui->fNorm,0,0,0);
                ChangePalette(ui->fDrop,255,255,0);
                ChangePalette(ui->fStop,255,0,0);
                if(check[0]!=3)
                    check[0]=3;
                else
                    check[1]=0;
                emit(stopModeBegun());
            }
            break;
            case MyClient::comDropToNorm:
            {
                ChangePalette(ui->fNorm,0,255,0);
                ChangePalette(ui->fDrop,0,0,0);
                ChangePalette(ui->fStop,0,0,0);
                connect(mpTimeoutTimer4,SIGNAL(timeout()),this,SLOT(onCheckMachDelay()));
                emit(normalModeBegun());
                check[0]=4; check[1]=4;
            }
                break;
            }
            ui->pbSend->setEnabled(true);
            ui->pbNormal->setEnabled(true);
            ui->pbDrop->setEnabled(true);
            ui->pbStop->setEnabled(true);
            ui->pbPowerOff->setEnabled(true);
            ui->pbInterfer->setEnabled(true);
            ChangePalette(ui->frame,0,255,0);
            ui->lProp->setStyleSheet("QLabel { color: white;}");
            ui->lProp->setText("НОРМА");
        }
        break;
        case MyClient::comMilOut:
        {
            QString message;
            in>>message;
            ui->pbSend->setEnabled(false);
            ui->pbNormal->setEnabled(false);
            ui->pbDrop->setEnabled(false);
            ui->pbStop->setEnabled(false);
            ui->pbPowerOff->setEnabled(false);
            ui->pbInterfer->setEnabled(false);
            //ui->pbInterfer->setEnabled(true);
            ChangePalette(ui->frame);
            ui->lProp->setStyleSheet("QLabel { color: black;}");
            ui->lProp->setText("Не подключен");
            ui->lIntObr->clear();
            ui->lTemp->clear();
            ui->lContrast->clear();
        }
        break;
    }
}

void Dialog::play1()
{
    sound->setLoops(-1);
    sound->play();
}
void Dialog::onSokConnected(int i)
{
    ui->pbConnect->setEnabled(false);
    ui->pbDisconnect->setEnabled(true);
    ui->lProp->setStyleSheet("QLabel { color: black;}");
    ui->lProp->clear();
    _blockSizeMany[i] = 0;
    if (i==0)
        AddToLog(QDate::currentDate().toString(Qt::SystemLocaleDate)+" "+QTime::currentTime().toString()+" "+"Подключен к "+" "+_sokMany[i]->peerAddress().toString(),Qt::green,0);
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (qint64)0;
    out << (uint8_t)MyClient::comAutchReq;
    out << ui->leName->text();
    _nameMany[i] = ui->leName->text()+(char)(((int)'0')+i);
    out.device()->seek(0);
    out << (qint64)(block.size() - sizeof(qint64));
    _sokMany[i]->write(block);
}

void Dialog::onSokDisconnected()
{
    ui->pbConnect->setEnabled(true);
    ui->pbDisconnect->setEnabled(false);
    ui->pbSend->setEnabled(false);
    ui->pbNormal->setEnabled(false);
    ui->pbDrop->setEnabled(false);
    ui->pbStop->setEnabled(false);
    ui->pbPowerOff->setEnabled(false);
    AddToLog(QDate::currentDate().toString(Qt::SystemLocaleDate)+QTime::currentTime().toString()+" "+"Отключен от датчика ", Qt::green,0);
    ui->lProp->setStyleSheet("QLabel { color: black;}");
    ui->lProp->setText("Не подключен");
    ChangePalette(ui->frame);
    ui->lIntObr->clear();
    ui->lTemp->clear();
    ui->lContrast->clear();
    ui->pbInterfer->setEnabled(false);
    disconnect(mpTimeoutTimer4,SIGNAL(timeout()),this,SLOT(onCheckMachDelay()));
}

void Dialog::on_pbConnect_clicked()
{
    for (i=0;i<SERVER_COUNT;++i)
    {
        _sokMany[i]->connectToHost(ReadIPFromFile(), FIRST_PORT+i);
        qDebug()<<"connected to"<<_sokMany[i]->peerAddress().toString();
    }
}

void Dialog::on_pbDisconnect_clicked()
{
    for (i=0;i<SERVER_COUNT;++i)
    {
        _sokMany[i]->disconnectFromHost(); _blockSizeMany[i]=0;
    }
}

void Dialog::on_pbSend_clicked()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (qint64)0;
    if (ui->pteMessage->toPlainText()=="sendlast")
    {
        out << (uint8_t)MyClient::comSendLastLog;
        out.device()->seek(0);
        out << (qint64)(block.size() - sizeof(qint64));
        _sokMany[0]->write(block);
        ui->pteMessage->clear();
        return;
    }
    else if (ui->pteMessage->toPlainText()=="sendall")
    {
        out << (uint8_t)MyClient::comSendAllLog;
        out.device()->seek(0);
        out << (qint64)(block.size() - sizeof(qint64));
        _sokMany[0]->write(block);
        ui->pteMessage->clear();
        return;
    }
    else if (ui->pteMessage->toPlainText()=="help")
    {
        AddToLog("------------------------------------------------------------------------",Qt::black,1);
        AddToLog("sendall - отправить весь лог событий",Qt::black,1);
        AddToLog("sendlast - отправить последнее событие",Qt::black,1);
        AddToLog("normal - нажатие на Нормальный",Qt::black,1);
        AddToLog("stop - нажатие на ВЫКЛ.",Qt::black,1);
        AddToLog("drop - нажатие на Сброс",Qt::black,1);
        AddToLog("poweroff - отключение (необходимо указать пароль)",Qt::black,1);
        AddToLog("activatebuttons - активировать все заблокированные кнопки",Qt::black,1);
        AddToLog("clearall - очистить весь лог",Qt::black,1);
        AddToLog("restart - повторное подключение к серверу",Qt::black,1);
        AddToLog("------------------------------------------------------------------------",Qt::black,1);
        ui->pteMessage->clear();
        return;
    }
    else if (ui->pteMessage->toPlainText()=="normal")
    {
        on_pbNormal_clicked();
        ui->pteMessage->clear();
        return;
    }
    else if (ui->pteMessage->toPlainText()=="stop")
    {
        on_pbStop_clicked();
        ui->pteMessage->clear();
        return;
    }
    else if (ui->pteMessage->toPlainText()=="drop")
    {
        on_pbDrop_clicked();
        ui->pteMessage->clear();
        return;
    }
    else if (ui->pteMessage->toPlainText()=="poweroff -0932")
    {
        QByteArray block1;
        QDataStream out1(&block1, QIODevice::WriteOnly);
        out1 << (qint64)0;
        out1 << (uint8_t)MyClient::comPowerOff;
        out1.device()->seek(0);
        out1 << (qint64)(block1.size() - sizeof(qint64));
        _sokMany[0]->write(block1);
        check[0]=6; check[1]=6;
        ui->pteMessage->clear();
        return;
    }
    else if (ui->pteMessage->toPlainText()=="activatebuttons")
    {
        ui->pbNormal->setEnabled(true);
        ui->pbDrop->setEnabled(true);
        ui->pbStop->setEnabled(true);
        ui->pbInterfer->setEnabled(true);
        ui->pteMessage->clear();
        return;
    }
    else if (ui->pteMessage->toPlainText()=="clearall")
    {
        ui->lwLog->clear();
        ui->pteMessage->clear();
        return;
    }
    else if (ui->pteMessage->toPlainText()=="restart")
    {
        on_pbDisconnect_clicked();
        on_pbConnect_clicked();
        ui->pteMessage->clear();
        return;
    }
    else
        AddToLog("Неизвестная команда",Qt::black,1);
    ui->pteMessage->clear();
}

void Dialog::AddToLog(QString text, QColor color, int a)
{
    switch (a)
    {
        case 0:
        {
            ui->lwLog->insertItem(0, text);
            ui->lwLog->item(0)->setTextColor(color);
            QFile file("permanent.log");
            if (file.open(QIODevice::Append))
            {
                QTextStream stream(&file);
                stream << ui->lwLog->item(0)->text()<<"\r\n";
                stream << endl;
                file.close();
            }
        }
        break;
        case 1:
        {
            ui->lwLog->insertItem(0, text);
            ui->lwLog->item(0)->setTextColor(color);
        }
        break;
        case 2:
        {
            ui->lwLog->insertItem(0, text);
            ui->lwLog->item(0)->setTextColor(color);
            QFile file("allLog.log");
            if (file.open(QIODevice::Append))
            {
                QTextStream stream(&file);
                stream << ui->lwLog->item(0)->text()<<"\r\n";
                stream << endl;
                file.close();
            }
        }
        break;
    }

}

void Dialog::on_pbNormal_clicked()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (qint64)0;
    out << (uint8_t)MyClient::comNormalMode;
    out.device()->seek(0);
    out << static_cast<qint64>(block.size() - sizeof(qint64));
    qDebug()<<static_cast<qint64>(block.size() - sizeof(qint64));
    _sokMany[0]->write(block);
    ChangePalette(ui->fNorm,0,255,0);
    ChangePalette(ui->fDrop,0,0,0);
    ChangePalette(ui->fStop,0,0,0);
    check[0]=4; check[1]=4;
    connect(mpTimeoutTimer4,SIGNAL(timeout()),this,SLOT(onCheckMachDelay()));
    emit(normalModeBegun());
}


void Dialog::on_pbDrop_clicked()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (qint64)0;
    out << (uint8_t)MyClient::comDrop;
    out.device()->seek(0);
    out << static_cast<qint64>(block.size() - sizeof(qint64));
    _sokMany[0]->write(block);
    sound->stop();
    ChangePalette(ui->frame,0,255,0);
    ui->lProp->setStyleSheet("QLabel { color: white;}");
    ui->lProp->setText("НОРМА");
    ChangePalette(ui->fNorm,0,0,0);
    ChangePalette(ui->fDrop,0,0,0);
    ChangePalette(ui->fStop,255,0,0);
    if((check[0]==3))
        check[1]=2;
    else
        check[0]=2;
    mpTimeoutTimer4->stop();
    emit(dropModeBegun());
}
void Dialog::pbDropToNorm()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (qint64)0;
    out << (uint8_t)MyClient::comDropToNorm;
    out.device()->seek(0);
    out << static_cast<qint64>(block.size() - sizeof(qint64));
    _sokMany[0]->write(block);
    sound->stop();
    ChangePalette(ui->frame,0,255,0);
    ui->lProp->setStyleSheet("QLabel { color: white;}");
    ui->lProp->setText("НОРМА");
    ChangePalette(ui->fNorm,0,0,0);
    ChangePalette(ui->fDrop,0,0,0);
    ChangePalette(ui->fStop,255,0,0);
    if((check[0]==3))
        check[1]=2;
    else
        check[0]=2;
    mpTimeoutTimer4->stop();
    emit(dropModeBegun());
}
void Dialog::on_pbStop_clicked()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (qint64)0;
    out << (uint8_t)MyClient::comStop;
    out.device()->seek(0);
    out << static_cast<qint64>(block.size() - sizeof(qint64));
    _sokMany[0]->write(block);
    ChangePalette(ui->fNorm,0,0,0);
    ChangePalette(ui->fDrop,255,255,0);
    ChangePalette(ui->fStop,255,0,0);
    if(check[0]!=3)
        check[0]=3;
    else
        check[1]=0;
    ui->pbNormal->setEnabled(false);
    ui->pbDrop->setEnabled(false);
    disconnect(mpTimeoutTimer4,SIGNAL(timeout()),this,SLOT(onCheckMachDelay()));
    emit(stopModeBegun());
}

void Dialog::on_pbPowerOff_clicked()
{
    if ((check[0]==0)&&(check[1]==0))
    {
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this, "Выключение", "Вы уверены?\n Это приведет к полному выключению датчика ДКВС",QMessageBox::Yes|QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out << (qint64)0;
            out << (uint8_t)MyClient::comPowerOff;
            out.device()->seek(0);
            out << static_cast<qint64>(block.size() - sizeof(qint64));
            _sokMany[0]->write(block);
            check[0]=0;
            check[1]=0;
        }
    }
    else if ((check[0]==3) && (check[1]==2))
    {
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this, "Выключение", "Вы уверены?\n Это приведет к полному выключению датчика ДКВС",QMessageBox::Yes|QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out << (qint64)0;
            out << (uint8_t)MyClient::comPowerOff;
            out.device()->seek(0);
            out << static_cast<qint64>(block.size() - sizeof(qint64));
            _sokMany[0]->write(block);
            check[0]=0;
            check[1]=0;
        }
    }
    else
        AddToLog("Выключите режим");

}
void Dialog::ChangePalette(QFrame *frame,int red,int green,int blue)
{
    QPalette palette = frame->palette();
    palette.setColor( backgroundRole(), QColor( red, green, blue ) );
    frame->setPalette( palette );
    frame->setAutoFillBackground( true );
}
void Dialog::onCheckMach()
{
    if ((check[0]==4)&&(check[1]==4)&&(deviceStat1==deviceStat2))
        {
//            ui->pbNormal->setEnabled(false);
//            ui->pbDrop->setEnabled(false);
//            ui->pbStop->setEnabled(false);
//            ui->pbInterfer->setEnabled(false);
            ChangePalette(ui->frame);
            ui->lProp->setStyleSheet("QLabel { color: red;}");
            ui->lProp->setText("Аварийное отключение");
            mpTimeoutTimer->stop();
            ChangePalette(ui->fNorm,0,0,0);
            ChangePalette(ui->fDrop,0,0,0);
            ChangePalette(ui->fStop,0,0,0);
            AddToLog(QDate::currentDate().toString(Qt::SystemLocaleDate)+QTime::currentTime().toString()+"Отключен аварийно",Qt::red,0);
            //QMessageBox::information(this, "Обрыв связи", "Возможно датчик был отключен в нештатном режиме");
            this->showNormal();
        }
    if ((check[0]==4)&&(check[1]==4)&&(deviceStat3==deviceStat4))
    {
        ChangePalette(ui->frame);
        ui->lProp->setStyleSheet("QLabel { color: red;}");
        ui->lProp->setText("Ошибка обработки");
        mpTimeoutTimer->stop();
        ChangePalette(ui->fNorm,0,0,0);
        ChangePalette(ui->fDrop,0,0,0);
        ChangePalette(ui->fStop,0,0,0);
        AddToLog(QDate::currentDate().toString(Qt::SystemLocaleDate)+QTime::currentTime().toString()+"Ошибка обработки",Qt::red,0);
        //QMessageBox::information(this, "Обрыв связи", "Возможно датчик был отключен в нештатном режиме");
        this->showNormal();
    }
    deviceStat2=deviceStat1;
    deviceStat3=deviceStat4;

}
void Dialog::onCheckMachStop()
{
    //ui->pbNormal->setEnabled(true);
    ui->pbDrop->setEnabled(true);
    mpTimeoutTimer2->stop();
}
void Dialog::onCheckMachDrop()
{
    ui->pbNormal->setEnabled(true);
    mpTimeoutTimer3->stop();
    //ui->pbDrop->setEnabled(true);
}
void Dialog::onCheckMachDelay()
{

    qDebug()<<"delay";
    pbDropToNorm();
    ChangePalette(ui->fNorm,0,255,0);
    ChangePalette(ui->fDrop,0,0,0);
    ChangePalette(ui->fStop,0,0,0);
    check[0]=4;
    check[1]=4;
    //ui->pbDrop->setEnabled(true);
}
void Dialog::startTimeOut()
{
    mpTimeoutTimer->start(60000);
}
void Dialog::startTimeOut2()
{
    mpTimeoutTimer2->start(1100);
}
void Dialog::startTimeOut3()
{
    mpTimeoutTimer3->start(1100);
}
void Dialog::startTimeOut4()
{

    int time = getTime();
    qDebug()<<time;
    if (time==0)
        return;
    else
        mpTimeoutTimer4->start(time*1000);
}
bool Dialog::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui->pteMessage && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return&&ui->pbSend->isEnabled())
        {
            qDebug("Enter Key Pressed...");
            on_pbSend_clicked();
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}
void Dialog::onSockStopSend()
{
    on_pbStop_clicked();
    on_pbDrop_clicked();
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (qint64)0;
    out << (uint8_t)MyClient::comStopSendInterf;
    out.device()->seek(0);
    out << (qint64)(block.size() - sizeof(qint64));
    _sokMany[0]->write(block);
}
QString Dialog::ReadIPFromFile()
{
    QFile file("ClientSettings.ini");
    QString IPaddr;
    QString firststring;
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        firststring=stream.readLine();
        QStringList notuseany = firststring.split(" ");
        IPaddr = notuseany.at(2);
        file.close();
    }
    else
        IPaddr="127.0.0.1";
    return IPaddr;
}
int Dialog::getTime()
{
    QFile file("ClientSettings.ini");
    QString firststr;
    QString secondstr;
    int time;
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        firststr = stream.readLine();
        secondstr = stream.readLine();
        QStringList notuseany = secondstr.split(" ");
        time = notuseany.at(2).toInt();
        file.close();
    }
    else
        time = 0;
    return time;
}
void Dialog::minimumContrast()
{
    QFile file("ClientSettings.ini");
    QString firststr;
    QString secondstr;
    QString thirdstr;
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        firststr = stream.readLine();
        secondstr = stream.readLine();
        thirdstr = stream.readLine();
        QStringList notuseany = thirdstr.split(" ");
        minContrast = notuseany.at(2).toDouble();
        file.close();
        qDebug()<<minContrast<<endl;
    }
    else
        minContrast = 0;
}
void Dialog::StopInterf()
{
    qDebug()<<"yes";
    ChangePalette(ui->fNorm,0,0,0);
    ChangePalette(ui->fDrop,255,255,0);
    ChangePalette(ui->fStop,0,0,0);
}

void Dialog::on_pbInterfer_clicked()
{
    qDebug()<<check[0]<<check[1];
    if ((check[0]==0)&&(check[1]==0))
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out << (qint64)0;
        if (ui->checkBox->isChecked())
            out << (uint8_t)MyClient::comFullSendInterf;
        else
             out << (uint8_t)MyClient::comSendInterf;
        out.device()->seek(0);
        out << (qint64)(block.size() - sizeof(qint64));
        _sokMany[0]->write(block);
        for (i=0;i<SERVER_COUNT;++i)
             _sokMany[i]->disconnectFromHost();
        ui->pbConnect->setEnabled(false);
        ui->pbInterfer->setEnabled(false);
        newWin = new Dialog2(this);
        newWin->show();
        connect(newWin,SIGNAL(rejected()),this,SLOT(on_pbConnect_clicked()));
        //connect(newWin,SIGNAL(rejected()),this,SLOT(StopInterf()));
    }
    else if ((check[0]==3) && (check[1]==2))
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out << (qint64)0;
        if (ui->checkBox->isChecked())
            out << (uint8_t)MyClient::comFullSendInterf;
        else
             out << (uint8_t)MyClient::comSendInterf;
        out.device()->seek(0);
        out << (qint64)(block.size() - sizeof(qint64));
        _sokMany[0]->write(block);
        for (i=0;i<SERVER_COUNT;++i)
             _sokMany[i]->disconnectFromHost();
        ui->pbConnect->setEnabled(false);
        ui->pbInterfer->setEnabled(false);
        newWin = new Dialog2(this);
        newWin->show();
        connect(newWin,SIGNAL(rejected()),this,SLOT(on_pbConnect_clicked()));
        //connect(newWin,SIGNAL(rejected()),this,SLOT(StopInterf()));
    }
    else
    {
       AddToLog("Выключите режим");
    }
//    }
//    else
//    {
//        QByteArray block;
//        QDataStream out(&block, QIODevice::WriteOnly);
//        out << (qint64)0;
//        out << (uint8_t)MyClient::comSendInterf;
//        out.device()->seek(0);
//        out << (qint64)(block.size() - sizeof(qint64));
//        _sokMany[0]->write(block);
//        for (i=0;i<SERVER_COUNT-1;++i)
//            _sokMany[i]->disconnectFromHost();
//        ui->pbConnect->setEnabled(false);
//        ui->pbInterfer->setEnabled(false);
//        newWin = new Dialog2(this);
//        newWin->show();
//        connect(newWin,SIGNAL(rejected()),this,SLOT(StopInterf()));
//        connect(newWin,SIGNAL(rejected()),this,SLOT(on_pbConnect_clicked()));
}
