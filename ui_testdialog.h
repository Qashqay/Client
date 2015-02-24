/********************************************************************************
** Form generated from reading UI file 'testdialog.ui'
**
** Created: Fri 13. Feb 13:36:38 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDIALOG_H
#define UI_TESTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QLabel *label;
    QLabel *lYRange;
    QLabel *label_3;
    QLabel *lXRange;
    QLabel *lTemp;
    QLabel *label_4;
    QLabel *lPoints;
    QCustomPlot *cpGraph;
    QLabel *labelPause;
    QCustomPlot *cpGraph_2;
    QLabel *labelName;
    QDialogButtonBox *buttonBox1;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonPause;
    QPushButton *pushButtonSave;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName(QString::fromUtf8("Dialog2"));
        Dialog2->resize(744, 428);
        Dialog2->setMinimumSize(QSize(744, 428));
        Dialog2->setMaximumSize(QSize(744, 428));
        label = new QLabel(Dialog2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 9, 201, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        lYRange = new QLabel(Dialog2);
        lYRange->setObjectName(QString::fromUtf8("lYRange"));
        lYRange->setGeometry(QRect(50, 40, 91, 21));
        lYRange->setFrameShape(QFrame::WinPanel);
        lYRange->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(Dialog2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 10, 201, 31));
        label_3->setFont(font);
        lXRange = new QLabel(Dialog2);
        lXRange->setObjectName(QString::fromUtf8("lXRange"));
        lXRange->setGeometry(QRect(310, 40, 101, 20));
        lXRange->setFrameShape(QFrame::WinPanel);
        lXRange->setFrameShadow(QFrame::Sunken);
        lTemp = new QLabel(Dialog2);
        lTemp->setObjectName(QString::fromUtf8("lTemp"));
        lTemp->setGeometry(QRect(620, 40, 81, 21));
        lTemp->setFrameShape(QFrame::WinPanel);
        lTemp->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(Dialog2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(610, 9, 101, 31));
        label_4->setFont(font);
        lPoints = new QLabel(Dialog2);
        lPoints->setObjectName(QString::fromUtf8("lPoints"));
        lPoints->setGeometry(QRect(10, 270, 531, 16));
        cpGraph = new QCustomPlot(Dialog2);
        cpGraph->setObjectName(QString::fromUtf8("cpGraph"));
        cpGraph->setGeometry(QRect(10, 79, 721, 311));
        labelPause = new QLabel(cpGraph);
        labelPause->setObjectName(QString::fromUtf8("labelPause"));
        labelPause->setGeometry(QRect(430, 0, 271, 131));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(72);
        font1.setBold(true);
        font1.setWeight(75);
        labelPause->setFont(font1);
        labelPause->setTextFormat(Qt::RichText);
        cpGraph_2 = new QCustomPlot(cpGraph);
        cpGraph_2->setObjectName(QString::fromUtf8("cpGraph_2"));
        cpGraph_2->setGeometry(QRect(380, 150, 331, 141));
        cpGraph_2->setAcceptDrops(false);
        labelName = new QLabel(cpGraph);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setGeometry(QRect(70, 20, 361, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        labelName->setFont(font2);
        buttonBox1 = new QDialogButtonBox(Dialog2);
        buttonBox1->setObjectName(QString::fromUtf8("buttonBox1"));
        buttonBox1->setGeometry(QRect(640, 390, 81, 32));
        buttonBox1->setOrientation(Qt::Horizontal);
        buttonBox1->setStandardButtons(QDialogButtonBox::Cancel);
        buttonBox1->setCenterButtons(false);
        horizontalLayoutWidget = new QWidget(Dialog2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 390, 401, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonPause = new QPushButton(horizontalLayoutWidget);
        pushButtonPause->setObjectName(QString::fromUtf8("pushButtonPause"));
        pushButtonPause->setCheckable(true);

        horizontalLayout->addWidget(pushButtonPause);

        pushButtonSave = new QPushButton(horizontalLayoutWidget);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        horizontalLayout->addWidget(pushButtonSave);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        lYRange->raise();
        label_3->raise();
        lXRange->raise();
        lTemp->raise();
        label_4->raise();
        lPoints->raise();
        cpGraph->raise();
        buttonBox1->raise();
        label->raise();
        horizontalLayoutWidget->raise();

        retranslateUi(Dialog2);
        QObject::connect(buttonBox1, SIGNAL(rejected()), Dialog2, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QDialog *Dialog2)
    {
        Dialog2->setWindowTitle(QApplication::translate("Dialog2", "\320\224\320\232\320\222\320\241", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog2", "\320\240\320\260\320\267\320\274\320\260\321\205 \320\270\320\275\321\202\320\265\321\200\321\204\320\265\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", 0, QApplication::UnicodeUTF8));
        lYRange->setText(QString());
        label_3->setText(QApplication::translate("Dialog2", "\320\224\320\273\320\270\320\275\320\260 \320\270\320\275\321\202\320\265\321\200\321\204\320\265\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", 0, QApplication::UnicodeUTF8));
        lXRange->setText(QString());
        lTemp->setText(QString());
        label_4->setText(QApplication::translate("Dialog2", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260", 0, QApplication::UnicodeUTF8));
        lPoints->setText(QString());
        labelPause->setText(QApplication::translate("Dialog2", "\320\237\320\260\321\203\320\267\320\260", 0, QApplication::UnicodeUTF8));
        labelName->setText(QString());
        pushButtonPause->setText(QApplication::translate("Dialog2", "\320\237\320\260\321\203\320\267\320\260", 0, QApplication::UnicodeUTF8));
        pushButtonSave->setText(QApplication::translate("Dialog2", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog2", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDIALOG_H
