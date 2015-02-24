#include <QtGui/QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("cp1251"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("cp1251"));
    QApplication a(argc, argv);
    Dialog *w=new Dialog();
    w->show();
    return a.exec();
}
