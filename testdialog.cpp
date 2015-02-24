#include "testdialog.h"
#include "ui_testdialog.h"
#include "dialog.h"

int i;
static int tostartstop=0;
double array_max(QVector<double> a, long size)
{
       long i;
       double max=-32000;
       for (i=0; i<size; i++)
       {
           if (a[i]>max)
           {
                max=a[i];
           }
       }
       return(max);
}
double array_min(QVector<double> a, long size)
{
    long i;
    double min=100000;
       for (i=0; i<size; i++)
       {
         if (a[i]<min)
         {
            min=a[i];
         }
       }
       return(min);
}
Dialog2::Dialog2(QWidget *parent) :QDialog(parent),ui2(new Ui::Dialog2)
{

    ui2->setupUi(this);
    Dialog get;
    _sokMany1 = new QTcpSocket*[SERVER_COUNT];
    for (i=0;i<SERVER_COUNT;++i)
        if(i==0||i==2||i==SERVER_COUNT-2)
            _sokMany1[i] = new QTcpSocket(this);
    for (i=0;i<SERVER_COUNT;++i)
        if(i==0||i==2||i==SERVER_COUNT-2)
            _nameMany[i]="";
    for (i=0;i<SERVER_COUNT;++i)
        if(i==0||i==2||i==SERVER_COUNT-2)
            _blockSizeMany[i]=0;
    for (i=0;i<SERVER_COUNT;++i)
        if(i==0||i==2||i==SERVER_COUNT-2)
            connect(_sokMany1[i], SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(onSokDisplayError(QAbstractSocket::SocketError)));
    signalMapper = new QSignalMapper(this);
    for (i=0;i<SERVER_COUNT;++i)
        if(i==0||i==2||i==SERVER_COUNT-2)
            signalMapper->setMapping(_sokMany1[i],int (i));
    for (i=0;i<SERVER_COUNT;++i)
        if(i==0||i==2||i==SERVER_COUNT-2)
            connect(_sokMany1[i],SIGNAL(readyRead()),signalMapper,SLOT(map()));
    connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(onSokReadyRead(int)));
    signalMapper2 = new QSignalMapper(this);
    for (i=0;i<SERVER_COUNT;++i)
        if(i==0||i==2||i==SERVER_COUNT-2)
            signalMapper2->setMapping(_sokMany1[i],int (i));
    for (i=0;i<SERVER_COUNT;++i)
        if(i==0||i==2||i==SERVER_COUNT-2)
            connect(_sokMany1[i],SIGNAL(connected()),signalMapper2,SLOT(map()));
    connect(signalMapper2,SIGNAL(mapped(int)),this,SLOT(onSokConnected(int)));
    connect(this,SIGNAL(rejected()),this,SLOT(onSockDisconnect()));
    ui2->lTemp->setText(get.Temp);
    for (i=0;i<SERVER_COUNT;++i)
        if(i==0||i==2||i==SERVER_COUNT-2)
        {
            _sokMany1[i]->connectToHost(get.HostName, get.PortName+i);
        }
    ui2->labelPause->hide();
    ui2->cpGraph_2->hide();
}
Dialog2::~Dialog2()
{
    delete ui2;
}
void Dialog2::onSokDisplayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, "пїЅпїЅпїЅпїЅпїЅпїЅ 1", "пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, "пїЅпїЅпїЅпїЅпїЅпїЅ 2", "пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ");
        break;
    default:
        QMessageBox::information(this, "пїЅпїЅпїЅпїЅпїЅпїЅ 3", "пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ "+_sokMany1[0]->errorString());
    }
}
void Dialog2::onSokReadyRead(int i)
{

    QDataStream in(_sokMany1[i]);
    if (_blockSizeMany[i] == 0)
    {
        if (_sokMany1[i]->bytesAvailable() < (int)sizeof(qint64))
            return;
        in >>_blockSizeMany[i];
        qDebug()<<"bytesavailable"<<_sokMany1[i]->bytesAvailable()<<_sokMany1[i]->localPort();
        qDebug() << "_blockSize now " <<i<< _blockSizeMany[i];

    }
    if (_sokMany1[i]->bytesAvailable() <_blockSizeMany[i])
    {
        return;
    }
    else
        _blockSizeMany[i] = 0;
    quint8 command;
    in >> command;
    qDebug() << "Received command " << command<<"on port"<<static_cast<int>(_sokMany1[i]->localPort());
    switch (command)
    {
        case MyClient::comMessageToAll:
        {
            QString message;
            in >> message;
            QStringList points=message.split("*");
            ui2->lXRange->setText(QString::number(points.size()));
            qDebug()<<points.last()<<endl;
            if (!ui2->pushButtonPause->isChecked())
            {
                x.clear();
                y.clear();
                for (long i=0;i<points.size()-1;++i)
                {
                    x.push_back(i);
                    y.push_back(points.at(i).toLong());
                }
                x1=x;
                y1=y;
                //AddToLog2(x,y);
               // qDebug()<<points.at(4000);
                ui2->cpGraph->addGraph();
                ui2->cpGraph->graph(0)->setPen(QPen(Qt::red));
                ui2->cpGraph->graph(0)->setData(x,y);
                ui2->cpGraph->xAxis->setRange(0,points.size());
                ui2->lYRange->setText(QString::number(array_max(y,(points.size()-1))-array_min(y,(points.size()-1))));
                ui2->cpGraph->xAxis2->setVisible(true);
                ui2->cpGraph->xAxis2->setTickLabels(false);
                ui2->cpGraph->yAxis2->setVisible(true);
                ui2->cpGraph->yAxis2->setTickLabels(false);
                connect(ui2->cpGraph->xAxis, SIGNAL(rangeChanged(QCPRange)), ui2->cpGraph->xAxis2, SLOT(setRange(QCPRange)));
                connect(ui2->cpGraph->yAxis, SIGNAL(rangeChanged(QCPRange)), ui2->cpGraph->yAxis2, SLOT(setRange(QCPRange)));
                ui2->cpGraph->graph(0)->rescaleAxes();
                ui2->cpGraph->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
                if (tostartstop==0)
                    ui2->cpGraph->replot();
                }
            else
            {
                x1=x;
                y1=y;
            }


        }
        break;
        case MyClient::comTempStat:
        {
            QString message;
            in >> message;
            if (!ui2->pushButtonPause->isChecked())
                ui2->lTemp->setText(message);
        }
        break;
        default:
        {
            QString message;
            if (!ui2->pushButtonPause->isChecked())
                in>>message;
        }
    }

}
void Dialog2::onSokConnected(int i)
{
    _blockSizeMany[i] = 0;
     QString dev1="Interf1";
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (qint64)0;
    out << (uint8_t)MyClient::comAutchReq;
    out << dev1;
    _nameMany[i] =dev1;
    out.device()->seek(0);
    out << (qint64)(block.size() - sizeof(qint64));
    _sokMany1[i]->write(block);
}
void Dialog2::onSockDisconnect()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (qint64)0;
    out << (uint8_t)MyClient::comStopSendInterf;
    out.device()->seek(0);
    out << (qint64)(block.size() - sizeof(qint64));
    _sokMany1[0]->write(block);
    for (i=0;i<SERVER_COUNT;++i)
        if(i==0||i==2||i==SERVER_COUNT-2)
            _sokMany1[i]->disconnectFromHost();
    for (i=0;i<SERVER_COUNT;++i)
        if(i==0||i==2||i==SERVER_COUNT-2)
            _blockSizeMany[i]=0;
}
void Dialog2::AddToLog2(QVector<double> x, QVector<double> y)
{
    qDebug()<<"save"<<endl;
    QFile file("interf.txt");
    if (file.open(QIODevice::Append))
    {
        QTextStream stream(&file);
        for (long i=0;i<x.size();++i)
            stream << x.at(i)<<" "<<y.at(i)<<endl;
        stream << endl;
        file.close();
    }

}


void Dialog2::on_pushButtonPause_toggled(bool checked)
{
    if (checked)
    {
        ui2->labelPause->show();
    }
    else
    {
        ui2->labelPause->hide();
        ui2->labelName->setText(" ");
    }

}

void Dialog2::on_pushButton_clicked()
{
    ui2->pushButtonPause->setChecked(true);
    ui2->labelPause->hide();
    fileName = QFileDialog::getOpenFileName(this, "Open Interf", "", "Text (*.interf)");
    ui2->labelName->setText(fileName);
    QFile file(fileName);
    QVector<double> x1,y1;
    QString firststr;
    QStringList notuseany;
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        while (!stream.atEnd())
        {
            qDebug()<<"wow"<<endl;
            firststr = stream.readLine();
            notuseany=firststr.split("\t");
            if (notuseany.size()!=2)
                break;
            x1.push_back(notuseany.at(0).toInt());
            y1.push_back(notuseany.at(1).toInt());
        }
        qDebug()<<"Ok"<<endl;
        file.close();
    }
    ui2->cpGraph->addGraph();
    ui2->cpGraph->graph(0)->setPen(QPen(Qt::red));
    ui2->cpGraph->graph(0)->setData(x1,y1);
    ui2->cpGraph->xAxis->setRange(0,x1.size());
    ui2->lYRange->setText(QString::number(array_max(y1,(y1.size()))-array_min(y1,(y1.size()))));
    //if(((array_max(y1,(y1.size()))-array_min(y1,(y1.size())))>27000&&((array_max(y1,(y1.size()))-array_min(y1,(y1.size())))<35000)))
    ui2->cpGraph->xAxis2->setVisible(true);
    ui2->cpGraph->xAxis2->setTickLabels(false);
    ui2->cpGraph->yAxis2->setVisible(true);
    ui2->cpGraph->yAxis2->setTickLabels(false);
    connect(ui2->cpGraph->xAxis, SIGNAL(rangeChanged(QCPRange)), ui2->cpGraph->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui2->cpGraph->yAxis, SIGNAL(rangeChanged(QCPRange)), ui2->cpGraph->yAxis2, SLOT(setRange(QCPRange)));
    ui2->cpGraph->graph(0)->rescaleAxes();
    ui2->cpGraph->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    if (tostartstop==0)
        ui2->cpGraph->replot();
}

void Dialog2::on_pushButtonSave_clicked()
{
    bool k=ui2->pushButtonPause->isChecked();
    ui2->pushButtonPause->setChecked(true);
    QString fileName = QFileDialog::getSaveFileName(this, "Save interferogram", "", "Interferogram (*.interf)");
    QFile file(fileName);

    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        if (k)
        {
            qDebug()<<"Checked"<<endl;
        for (int i=0;i<x.size();++i)
            stream << x.at(i)<<"\t"<<y.at(i)<<"\r\n";
        }
        else
        {
            qDebug()<<"Not checked"<<endl;
            for (int i=0;i<x1.size();++i)
                stream << x1.at(i)<<"\t"<<y1.at(i)<<"\r\n";
        }
        file.close();
        ui2->labelName->setText("Сохранено");
    }
    if (!k)
        ui2->pushButtonPause->setChecked(false);

}
