#ifndef TESTDIALOG_H
#define TESTDIALOG_H
#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <stdint.h>
#include <QtGui>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
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
    class Dialog2;
}
class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();

private slots:
    void onSokReadyRead(int i);
    void onSokConnected(int i);
    void onSokDisplayError(QAbstractSocket::SocketError socketError);
    void onSockDisconnect();

    //void on_pushButtonPause_clicked();

    void on_pushButtonPause_toggled(bool checked);

    void on_pushButton_clicked();

    void on_pushButtonSave_clicked();



private:
    Ui::Dialog2 *ui2;
    QTcpSocket **_sokMany1;
    qint64 _blockSizeMany[SERVER_COUNT];
    QString _nameMany[SERVER_COUNT];
    QSignalMapper *signalMapper;
    QSignalMapper *signalMapper2;
    void AddToLog2(QVector<double> x, QVector<double> y);
    QString fileName;
    QVector<double> x,y;
    QVector<double> x1,y1;
};

#endif // TESTDIALOG_H
