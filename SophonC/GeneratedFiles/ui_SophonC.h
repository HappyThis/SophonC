/********************************************************************************
** Form generated from reading UI file 'SophonC.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOPHONC_H
#define UI_SOPHONC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SophonCClass
{
public:
    QAction *actionOfStart;
    QAction *actions;
    QAction *action1;
    QAction *actionOfRedirect;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QTableWidget *tableWidgetOfAdd;
    QTabWidget *QTW;
    QWidget *Q3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLabel *labelOfShowTime;
    QLabel *labelOfShowName;
    QLabel *labelOfShowNumber;
    QLabel *labelOfShowOs;
    QLabel *labelOfShowIp;
    QLabel *labelOfNumber;
    QLabel *labelOfIp;
    QLabel *labelOfName;
    QLabel *labelOfTime;
    QLabel *labelOfOs;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelOfHardware;
    QPushButton *buttonOfRemotePath;
    QWidget *Q1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addFileSendingQueue;
    QPushButton *fileSend;
    QPushButton *clearFileSendingQueue;
    QPushButton *chooleFile;
    QTableWidget *tableOfFileSend;
    QWidget *Q2;
    QWidget *Q4;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SophonCClass)
    {
        if (SophonCClass->objectName().isEmpty())
            SophonCClass->setObjectName(QString::fromUtf8("SophonCClass"));
        SophonCClass->resize(1249, 735);
        SophonCClass->setToolButtonStyle(Qt::ToolButtonIconOnly);
        actionOfStart = new QAction(SophonCClass);
        actionOfStart->setObjectName(QString::fromUtf8("actionOfStart"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SophonC/start.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOfStart->setIcon(icon);
        actions = new QAction(SophonCClass);
        actions->setObjectName(QString::fromUtf8("actions"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/SophonC/settings.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actions->setIcon(icon1);
        action1 = new QAction(SophonCClass);
        action1->setObjectName(QString::fromUtf8("action1"));
        actionOfRedirect = new QAction(SophonCClass);
        actionOfRedirect->setObjectName(QString::fromUtf8("actionOfRedirect"));
        centralWidget = new QWidget(SophonCClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, -1, 0, -1);
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(5);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(100, 100));
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setDefaultDropAction(Qt::IgnoreAction);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setShowGrid(false);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        tableWidgetOfAdd = new QTableWidget(centralWidget);
        if (tableWidgetOfAdd->columnCount() < 4)
            tableWidgetOfAdd->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetOfAdd->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetOfAdd->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetOfAdd->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetOfAdd->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        tableWidgetOfAdd->setObjectName(QString::fromUtf8("tableWidgetOfAdd"));
        tableWidgetOfAdd->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidgetOfAdd->sizePolicy().hasHeightForWidth());
        tableWidgetOfAdd->setSizePolicy(sizePolicy1);
        tableWidgetOfAdd->setFocusPolicy(Qt::NoFocus);
        tableWidgetOfAdd->setFrameShape(QFrame::NoFrame);
        tableWidgetOfAdd->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetOfAdd->setShowGrid(false);
        tableWidgetOfAdd->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableWidgetOfAdd, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        QTW = new QTabWidget(centralWidget);
        QTW->setObjectName(QString::fromUtf8("QTW"));
        Q3 = new QWidget();
        Q3->setObjectName(QString::fromUtf8("Q3"));
        horizontalLayout_2 = new QHBoxLayout(Q3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelOfShowTime = new QLabel(Q3);
        labelOfShowTime->setObjectName(QString::fromUtf8("labelOfShowTime"));

        gridLayout_2->addWidget(labelOfShowTime, 4, 0, 1, 1);

        labelOfShowName = new QLabel(Q3);
        labelOfShowName->setObjectName(QString::fromUtf8("labelOfShowName"));

        gridLayout_2->addWidget(labelOfShowName, 3, 0, 1, 1);

        labelOfShowNumber = new QLabel(Q3);
        labelOfShowNumber->setObjectName(QString::fromUtf8("labelOfShowNumber"));

        gridLayout_2->addWidget(labelOfShowNumber, 0, 0, 1, 1);

        labelOfShowOs = new QLabel(Q3);
        labelOfShowOs->setObjectName(QString::fromUtf8("labelOfShowOs"));

        gridLayout_2->addWidget(labelOfShowOs, 1, 0, 1, 1);

        labelOfShowIp = new QLabel(Q3);
        labelOfShowIp->setObjectName(QString::fromUtf8("labelOfShowIp"));

        gridLayout_2->addWidget(labelOfShowIp, 2, 0, 1, 1);

        labelOfNumber = new QLabel(Q3);
        labelOfNumber->setObjectName(QString::fromUtf8("labelOfNumber"));

        gridLayout_2->addWidget(labelOfNumber, 0, 1, 1, 1);

        labelOfIp = new QLabel(Q3);
        labelOfIp->setObjectName(QString::fromUtf8("labelOfIp"));

        gridLayout_2->addWidget(labelOfIp, 2, 1, 1, 1);

        labelOfName = new QLabel(Q3);
        labelOfName->setObjectName(QString::fromUtf8("labelOfName"));

        gridLayout_2->addWidget(labelOfName, 3, 1, 1, 1);

        labelOfTime = new QLabel(Q3);
        labelOfTime->setObjectName(QString::fromUtf8("labelOfTime"));

        gridLayout_2->addWidget(labelOfTime, 4, 1, 1, 1);

        labelOfOs = new QLabel(Q3);
        labelOfOs->setObjectName(QString::fromUtf8("labelOfOs"));

        gridLayout_2->addWidget(labelOfOs, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        line = new QFrame(Q3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelOfHardware = new QLabel(Q3);
        labelOfHardware->setObjectName(QString::fromUtf8("labelOfHardware"));
        labelOfHardware->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_4->addWidget(labelOfHardware);

        buttonOfRemotePath = new QPushButton(Q3);
        buttonOfRemotePath->setObjectName(QString::fromUtf8("buttonOfRemotePath"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/SophonC/recv.ico"), QSize(), QIcon::Normal, QIcon::Off);
        buttonOfRemotePath->setIcon(icon2);

        verticalLayout_4->addWidget(buttonOfRemotePath);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 3);

        horizontalLayout_2->addLayout(horizontalLayout);

        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/SophonC/info.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QTW->addTab(Q3, icon3, QString());
        Q1 = new QWidget();
        Q1->setObjectName(QString::fromUtf8("Q1"));
        verticalLayout_3 = new QVBoxLayout(Q1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        addFileSendingQueue = new QPushButton(Q1);
        addFileSendingQueue->setObjectName(QString::fromUtf8("addFileSendingQueue"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/SophonC/queue.ico"), QSize(), QIcon::Normal, QIcon::Off);
        addFileSendingQueue->setIcon(icon4);

        horizontalLayout_3->addWidget(addFileSendingQueue);

        fileSend = new QPushButton(Q1);
        fileSend->setObjectName(QString::fromUtf8("fileSend"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/SophonC/send.ico"), QSize(), QIcon::Normal, QIcon::Off);
        fileSend->setIcon(icon5);

        horizontalLayout_3->addWidget(fileSend);

        clearFileSendingQueue = new QPushButton(Q1);
        clearFileSendingQueue->setObjectName(QString::fromUtf8("clearFileSendingQueue"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/SophonC/clear.ico"), QSize(), QIcon::Normal, QIcon::Off);
        clearFileSendingQueue->setIcon(icon6);

        horizontalLayout_3->addWidget(clearFileSendingQueue);

        chooleFile = new QPushButton(Q1);
        chooleFile->setObjectName(QString::fromUtf8("chooleFile"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/SophonC/chooseLocalFile.ico"), QSize(), QIcon::Normal, QIcon::Off);
        chooleFile->setIcon(icon7);

        horizontalLayout_3->addWidget(chooleFile);

        horizontalLayout_3->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        tableOfFileSend = new QTableWidget(Q1);
        if (tableOfFileSend->columnCount() < 3)
            tableOfFileSend->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableOfFileSend->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableOfFileSend->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableOfFileSend->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        tableOfFileSend->setObjectName(QString::fromUtf8("tableOfFileSend"));
        tableOfFileSend->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableOfFileSend->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableOfFileSend->horizontalHeader()->setStretchLastSection(true);
        tableOfFileSend->verticalHeader()->setVisible(false);
        tableOfFileSend->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableOfFileSend);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 15);

        verticalLayout_3->addLayout(verticalLayout);

        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/SophonC/file.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QTW->addTab(Q1, icon8, QString());
        Q2 = new QWidget();
        Q2->setObjectName(QString::fromUtf8("Q2"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/SophonC/spy.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QTW->addTab(Q2, icon9, QString());
        Q4 = new QWidget();
        Q4->setObjectName(QString::fromUtf8("Q4"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/SophonC/limit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QTW->addTab(Q4, icon10, QString());

        verticalLayout_2->addWidget(QTW);

        SophonCClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SophonCClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1249, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(262, 153, 170, 104));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_2->setGeometry(QRect(346, 153, 149, 80));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_3->setGeometry(QRect(387, 153, 137, 78));
        SophonCClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(SophonCClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SophonCClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(actionOfStart);
        menu->addAction(actionOfRedirect);
        menu_2->addAction(actions);
        menu_3->addAction(action1);

        retranslateUi(SophonCClass);

        QTW->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SophonCClass);
    } // setupUi

    void retranslateUi(QMainWindow *SophonCClass)
    {
        SophonCClass->setWindowTitle(QApplication::translate("SophonCClass", "SophonC", nullptr));
        actionOfStart->setText(QApplication::translate("SophonCClass", "\345\220\257\345\212\250\347\275\221\347\273\234\346\234\215\345\212\241", nullptr));
        actions->setText(QApplication::translate("SophonCClass", "\350\256\276\347\275\256", nullptr));
        action1->setText(QApplication::translate("SophonCClass", "\350\257\264\346\230\216", nullptr));
        actionOfRedirect->setText(QApplication::translate("SophonCClass", "\351\207\215\345\256\232\345\220\221IP\345\234\260\345\235\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SophonCClass", "\344\270\212\347\272\277\345\272\217\345\217\267(\351\232\220\350\227\217)", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SophonCClass", "IP\345\234\260\345\235\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SophonCClass", "\347\263\273\347\273\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SophonCClass", "\350\256\241\347\256\227\346\234\272\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("SophonCClass", "\344\270\212\347\272\277\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("SophonCClass", "\350\207\252\345\256\232\344\271\211\344\270\212\347\272\277\344\277\241\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetOfAdd->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("SophonCClass", "\344\270\212\347\272\277\345\272\217\345\217\267(\351\232\220\350\227\217)", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetOfAdd->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("SophonCClass", "IP\345\234\260\345\235\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetOfAdd->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("SophonCClass", "\347\263\273\347\273\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetOfAdd->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("SophonCClass", "\350\256\241\347\256\227\346\234\272\345\220\215\347\247\260", nullptr));
        labelOfShowTime->setText(QApplication::translate("SophonCClass", "\344\270\212\347\272\277\346\227\266\351\227\264:", nullptr));
        labelOfShowName->setText(QApplication::translate("SophonCClass", "\350\256\241\347\256\227\346\234\272\345\220\215\347\247\260:", nullptr));
        labelOfShowNumber->setText(QApplication::translate("SophonCClass", "\344\270\212\347\272\277\345\272\217\345\217\267:", nullptr));
        labelOfShowOs->setText(QApplication::translate("SophonCClass", "\346\223\215\344\275\234\347\263\273\347\273\237:", nullptr));
        labelOfShowIp->setText(QApplication::translate("SophonCClass", "IP\345\234\260\345\235\200:", nullptr));
        labelOfNumber->setText(QString());
        labelOfIp->setText(QString());
        labelOfName->setText(QString());
        labelOfTime->setText(QString());
        labelOfOs->setText(QString());
        labelOfHardware->setText(QString());
        buttonOfRemotePath->setText(QApplication::translate("SophonCClass", "\346\226\207\344\273\266\346\216\245\346\224\266\345\234\260\345\235\200\357\274\232default", nullptr));
        QTW->setTabText(QTW->indexOf(Q3), QApplication::translate("SophonCClass", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        addFileSendingQueue->setText(QApplication::translate("SophonCClass", "\345\212\240\345\205\245\346\226\207\344\273\266\345\217\221\351\200\201\351\230\237\345\210\227", nullptr));
        fileSend->setText(QApplication::translate("SophonCClass", "\345\217\221\351\200\201", nullptr));
        clearFileSendingQueue->setText(QApplication::translate("SophonCClass", "\346\270\205\347\251\272\346\226\207\344\273\266\345\217\221\351\200\201\351\230\237\345\210\227", nullptr));
        chooleFile->setText(QApplication::translate("SophonCClass", "NULL", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableOfFileSend->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("SophonCClass", "\344\270\212\347\272\277\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableOfFileSend->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("SophonCClass", "\345\217\221\351\200\201\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableOfFileSend->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("SophonCClass", "\350\277\234\347\250\213\346\226\207\344\273\266\345\255\230\346\224\276\344\275\215\347\275\256", nullptr));
        QTW->setTabText(QTW->indexOf(Q1), QApplication::translate("SophonCClass", "\346\226\207\344\273\266\345\210\206\345\217\221", nullptr));
        QTW->setTabText(QTW->indexOf(Q2), QApplication::translate("SophonCClass", "\345\244\232\345\261\217\347\233\221\346\216\247", nullptr));
        QTW->setTabText(QTW->indexOf(Q4), QApplication::translate("SophonCClass", "\345\212\237\350\203\275\351\231\220\345\210\266", nullptr));
        menu->setTitle(QApplication::translate("SophonCClass", "\345\220\257\345\212\250\351\200\211\351\241\271", nullptr));
        menu_2->setTitle(QApplication::translate("SophonCClass", "\347\233\270\345\205\263\350\256\276\347\275\256", nullptr));
        menu_3->setTitle(QApplication::translate("SophonCClass", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SophonCClass: public Ui_SophonCClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOPHONC_H
