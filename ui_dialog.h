/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Fri 13. Feb 13:36:38 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QTextEdit *pteMessage;
    QListWidget *lwLog;
    QFrame *frame;
    QLabel *lProp;
    QPushButton *pbSend;
    QPushButton *pbPowerOff;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *leHost;
    QSpinBox *sbPort;
    QLineEdit *leName;
    QPushButton *pbConnect;
    QPushButton *pbDisconnect;
    QGroupBox *groupBox;
    QFrame *fNorm;
    QFrame *fDrop;
    QFrame *fStop;
    QPushButton *pbNormal;
    QPushButton *pbDrop;
    QPushButton *pbStop;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbInterfer;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *lIntObr;
    QLabel *label_4;
    QLabel *lTemp;
    QLabel *lAddres;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *lContrast;
    QCheckBox *checkBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setEnabled(true);
        Dialog->resize(622, 523);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(591, 523));
        Dialog->setMaximumSize(QSize(701, 523));
        QIcon icon;
        icon.addFile(QString::fromUtf8("sm_icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setSizeGripEnabled(true);
        Dialog->setModal(false);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 450, 161, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        pteMessage = new QTextEdit(Dialog);
        pteMessage->setObjectName(QString::fromUtf8("pteMessage"));
        pteMessage->setGeometry(QRect(10, 470, 251, 21));
        pteMessage->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pteMessage->setTabChangesFocus(false);
        lwLog = new QListWidget(Dialog);
        lwLog->setObjectName(QString::fromUtf8("lwLog"));
        lwLog->setGeometry(QRect(130, 210, 481, 221));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lwLog->sizePolicy().hasHeightForWidth());
        lwLog->setSizePolicy(sizePolicy1);
        lwLog->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        lwLog->setAutoScroll(false);
        lwLog->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        frame = new QFrame(Dialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(150, 10, 461, 141));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        lProp = new QLabel(frame);
        lProp->setObjectName(QString::fromUtf8("lProp"));
        lProp->setGeometry(QRect(0, 0, 461, 141));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lProp->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Black"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lProp->setFont(font1);
        lProp->setFrameShape(QFrame::NoFrame);
        lProp->setFrameShadow(QFrame::Sunken);
        lProp->setAlignment(Qt::AlignCenter);
        lProp->setMargin(0);
        pbSend = new QPushButton(Dialog);
        pbSend->setObjectName(QString::fromUtf8("pbSend"));
        pbSend->setEnabled(false);
        pbSend->setGeometry(QRect(270, 470, 91, 21));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pbSend->sizePolicy().hasHeightForWidth());
        pbSend->setSizePolicy(sizePolicy2);
        pbPowerOff = new QPushButton(Dialog);
        pbPowerOff->setObjectName(QString::fromUtf8("pbPowerOff"));
        pbPowerOff->setEnabled(false);
        pbPowerOff->setGeometry(QRect(460, 490, 121, 23));
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 280, 111, 132));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        leHost = new QLineEdit(verticalLayoutWidget);
        leHost->setObjectName(QString::fromUtf8("leHost"));
        leHost->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(leHost->sizePolicy().hasHeightForWidth());
        leHost->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(leHost);

        sbPort = new QSpinBox(verticalLayoutWidget);
        sbPort->setObjectName(QString::fromUtf8("sbPort"));
        sbPort->setEnabled(true);
        sizePolicy3.setHeightForWidth(sbPort->sizePolicy().hasHeightForWidth());
        sbPort->setSizePolicy(sizePolicy3);
        sbPort->setMaximum(65536);
        sbPort->setValue(1232);

        verticalLayout->addWidget(sbPort);

        leName = new QLineEdit(verticalLayoutWidget);
        leName->setObjectName(QString::fromUtf8("leName"));
        leName->setEnabled(true);
        sizePolicy3.setHeightForWidth(leName->sizePolicy().hasHeightForWidth());
        leName->setSizePolicy(sizePolicy3);
        leName->setMouseTracking(true);

        verticalLayout->addWidget(leName);

        pbConnect = new QPushButton(verticalLayoutWidget);
        pbConnect->setObjectName(QString::fromUtf8("pbConnect"));
        sizePolicy2.setHeightForWidth(pbConnect->sizePolicy().hasHeightForWidth());
        pbConnect->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(pbConnect);

        pbDisconnect = new QPushButton(verticalLayoutWidget);
        pbDisconnect->setObjectName(QString::fromUtf8("pbDisconnect"));
        pbDisconnect->setEnabled(false);

        verticalLayout->addWidget(pbDisconnect);

        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(10, 10, 131, 161));
        groupBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        groupBox->setAcceptDrops(false);
        groupBox->setAutoFillBackground(false);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        groupBox->setChecked(false);
        fNorm = new QFrame(groupBox);
        fNorm->setObjectName(QString::fromUtf8("fNorm"));
        fNorm->setGeometry(QRect(90, 30, 30, 30));
        fNorm->setMaximumSize(QSize(30, 30));
        fNorm->setFrameShape(QFrame::WinPanel);
        fNorm->setFrameShadow(QFrame::Raised);
        fDrop = new QFrame(groupBox);
        fDrop->setObjectName(QString::fromUtf8("fDrop"));
        fDrop->setGeometry(QRect(90, 110, 30, 30));
        fDrop->setMaximumSize(QSize(30, 30));
        fDrop->setFrameShape(QFrame::WinPanel);
        fDrop->setFrameShadow(QFrame::Raised);
        fStop = new QFrame(groupBox);
        fStop->setObjectName(QString::fromUtf8("fStop"));
        fStop->setGeometry(QRect(90, 70, 30, 30));
        fStop->setMaximumSize(QSize(30, 30));
        fStop->setFrameShape(QFrame::WinPanel);
        fStop->setFrameShadow(QFrame::Raised);
        pbNormal = new QPushButton(groupBox);
        pbNormal->setObjectName(QString::fromUtf8("pbNormal"));
        pbNormal->setEnabled(false);
        pbNormal->setGeometry(QRect(10, 30, 71, 30));
        pbNormal->setMaximumSize(QSize(16777215, 30));
        pbDrop = new QPushButton(groupBox);
        pbDrop->setObjectName(QString::fromUtf8("pbDrop"));
        pbDrop->setEnabled(false);
        pbDrop->setGeometry(QRect(10, 110, 71, 30));
        pbDrop->setMaximumSize(QSize(16777215, 30));
        pbStop = new QPushButton(groupBox);
        pbStop->setObjectName(QString::fromUtf8("pbStop"));
        pbStop->setEnabled(false);
        pbStop->setGeometry(QRect(10, 70, 71, 30));
        pbStop->setMaximumSize(QSize(16777215, 30));
        splitter = new QSplitter(Dialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(0, 0, 0, 0));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pbInterfer = new QPushButton(Dialog);
        pbInterfer->setObjectName(QString::fromUtf8("pbInterfer"));
        pbInterfer->setGeometry(QRect(10, 210, 111, 31));
        layoutWidget1 = new QWidget(Dialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(150, 170, 461, 21));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setPointSize(10);
        label_2->setFont(font2);

        horizontalLayout_2->addWidget(label_2);

        lIntObr = new QLabel(layoutWidget1);
        lIntObr->setObjectName(QString::fromUtf8("lIntObr"));
        lIntObr->setFont(font2);

        horizontalLayout_2->addWidget(lIntObr);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_4->setFont(font2);

        horizontalLayout_2->addWidget(label_4);

        lTemp = new QLabel(layoutWidget1);
        lTemp->setObjectName(QString::fromUtf8("lTemp"));
        lTemp->setFont(font2);

        horizontalLayout_2->addWidget(lTemp);

        lAddres = new QLabel(Dialog);
        lAddres->setObjectName(QString::fromUtf8("lAddres"));
        lAddres->setGeometry(QRect(30, 0, 81, 21));
        layoutWidget2 = new QWidget(Dialog);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(390, 450, 191, 18));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        horizontalLayout_3->addWidget(label_3);

        lContrast = new QLabel(layoutWidget2);
        lContrast->setObjectName(QString::fromUtf8("lContrast"));
        lContrast->setFont(font2);

        horizontalLayout_3->addWidget(lContrast);

        checkBox = new QCheckBox(Dialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(13, 183, 161, 31));
        layoutWidget->raise();
        layoutWidget->raise();
        splitter->raise();
        layoutWidget->raise();
        label->raise();
        pteMessage->raise();
        lwLog->raise();
        frame->raise();
        pbSend->raise();
        pbPowerOff->raise();
        verticalLayoutWidget->raise();
        groupBox->raise();
        pbInterfer->raise();
        lAddres->raise();
        checkBox->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\320\224\320\232\320\222\320\241", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "\320\232\320\276\320\274\320\260\320\275\320\264\320\275\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pteMessage->setToolTip(QApplication::translate("Dialog", "\320\222\320\262\320\276\320\264 \320\272\320\276\320\274\320\260\320\275\320\264", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pteMessage->setWhatsThis(QApplication::translate("Dialog", "\320\222\320\262\320\276\320\264 \320\272\320\276\320\274\320\260\320\275\320\264", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lwLog->setToolTip(QApplication::translate("Dialog", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lwLog->setWhatsThis(QApplication::translate("Dialog", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", "\320\262\321\213\320\260\320\277", QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        lProp->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbSend->setToolTip(QApplication::translate("Dialog", "\320\236\321\202\320\277\321\200\320\260\320\262\320\272\320\260 \320\272\320\276\320\274\320\274\320\260\320\275\320\264\321\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pbSend->setWhatsThis(QApplication::translate("Dialog", "\320\236\321\202\320\277\321\200\320\260\320\262\320\272\320\260 \320\272\320\276\320\274\320\260\320\275\320\264\321\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pbSend->setText(QApplication::translate("Dialog", "\320\241\320\262\321\217\320\267\321\214", 0, QApplication::UnicodeUTF8));
        pbPowerOff->setText(QApplication::translate("Dialog", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\277\321\200\320\270\320\261\320\276\321\200", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        leHost->setToolTip(QApplication::translate("Dialog", "IP", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        leHost->setWhatsThis(QApplication::translate("Dialog", "IP \320\260\320\264\321\200\320\265\321\201 \321\201\320\265\321\200\320\262\320\265\321\200\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        leHost->setText(QApplication::translate("Dialog", "192.168.0.2", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sbPort->setToolTip(QApplication::translate("Dialog", "Host", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        sbPort->setWhatsThis(QApplication::translate("Dialog", "\320\245\320\276\321\201\321\202 (\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\262 \321\201\320\273\321\203\321\207\320\260\320\265 \320\276\321\202\320\272\320\260\320\267\320\260 \321\201\320\265\321\200\320\262\320\265\321\200\320\260)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        leName->setToolTip(QApplication::translate("Dialog", "\320\230\320\274\321\217 \320\272\320\273\320\270\320\265\320\275\321\202\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        leName->setWhatsThis(QApplication::translate("Dialog", "\320\240\320\260\320\261\320\276\321\207\320\265\320\265 \320\270\320\274\321\217 \320\272\320\273\320\270\320\265\320\275\321\202\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        leName->setText(QApplication::translate("Dialog", "SensorM1", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        pbConnect->setWhatsThis(QApplication::translate("Dialog", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\272 \321\201\320\265\321\200\320\262\320\265\321\200\321\203", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pbConnect->setText(QApplication::translate("Dialog", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        pbDisconnect->setWhatsThis(QApplication::translate("Dialog", "\320\236\321\202\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\276\321\202 \321\201\320\265\321\200\320\262\320\265\321\200\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pbDisconnect->setText(QApplication::translate("Dialog", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog", "\320\240\320\265\320\266\320\270\320\274\321\213", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbNormal->setToolTip(QApplication::translate("Dialog", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\321\213\320\271  \321\200\320\265\320\266\320\270\320\274", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pbNormal->setWhatsThis(QApplication::translate("Dialog", "\320\222\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\275\320\276\321\200\320\274\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \321\200\320\265\320\266\320\270\320\274\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pbNormal->setText(QApplication::translate("Dialog", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\321\213\320\271", 0, QApplication::UnicodeUTF8));
        pbDrop->setText(QApplication::translate("Dialog", "\320\241\320\261\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        pbStop->setText(QApplication::translate("Dialog", "\320\222\321\213\320\272\320\273.", 0, QApplication::UnicodeUTF8));
        pbInterfer->setText(QApplication::translate("Dialog", "\320\230\320\275\321\202\320\265\321\200\321\204\320\265\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "\320\230\320\267\320\274\320\265\321\200\320\265\320\275\320\276/\320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\276", 0, QApplication::UnicodeUTF8));
        lIntObr->setText(QString());
        label_4->setText(QApplication::translate("Dialog", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260", 0, QApplication::UnicodeUTF8));
        lTemp->setText(QString());
        lAddres->setText(QString());
        label_3->setText(QApplication::translate("Dialog", "\320\232\320\276\320\275\321\202\321\200\320\260\321\201\321\202", 0, QApplication::UnicodeUTF8));
        lContrast->setText(QString());
        checkBox->setText(QApplication::translate("Dialog", "\320\237\320\276\320\273\320\275\320\260\321\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
