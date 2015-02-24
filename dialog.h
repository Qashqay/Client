#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QEvent>
#include <QHostAddress>
#include <stdint.h>
#include "testdialog.h"
#include "..\Server\myclient.h"
#ifndef SERVER_COUNT
#define SERVER_COUNT 7
#endif
#ifndef FIRST_PORT
#define FIRST_PORT 1232
#endif
using namespace std;
class MyClient;

namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString HostName;
    int PortName;
    QString Temp;
     bool eventFilter(QObject *object, QEvent *event);

//public slots:
//    void openNewWindow();

private slots:
    void onSokReadyRead(int i);
    void onSokConnected(int i);
    void onSokDisconnected();
    void onSokDisplayError(QAbstractSocket::SocketError socketError);
    void on_pbConnect_clicked();
    void on_pbDisconnect_clicked();
    void on_pbSend_clicked();
    void onCheckMach();
    void onCheckMachStop();
    void onCheckMachDrop();
    void onCheckMachDelay();
    void play1();
    void on_pbNormal_clicked();
    void on_pbDrop_clicked();
    void pbDropToNorm();
    void on_pbStop_clicked();
    void on_pbPowerOff_clicked();
    void startTimeOut();
    void startTimeOut2();
    void startTimeOut3();
    void startTimeOut4();
    void onSockStopSend();
    void StopInterf();

    void on_pbInterfer_clicked();

signals:
    void normalModeBegun();
    void stopModeBegun();
    void dropModeBegun();
    void detectedDelay();

private:
    Ui::Dialog *ui;
    Dialog2 *newWin;
    QSignalMapper *signalMapper;
    QSignalMapper *signalMapper2;
    QTcpSocket **_sokMany;
    qint64 _blockSizeMany[SERVER_COUNT];
    QString _nameMany[SERVER_COUNT];
    QTimer *mpTimeoutTimer;
    QTimer *mpTimeoutTimer2;
    QTimer *mpTimeoutTimer3;
    QTimer *mpTimeoutTimer4;
    QSound *sound;
    double minContrast;
    void AddToLog(QString text, QColor color = Qt::black, int a = 0);
    void ChangePalette(QFrame *frame,int red = 255,int green = 255,int blue = 255);
    QString ReadIPFromFile();
    int getTime();
    void minimumContrast();
};


#endif // DIALOG_H
