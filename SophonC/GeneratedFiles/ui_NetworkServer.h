/********************************************************************************
** Form generated from reading UI file 'NetworkServer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKSERVER_H
#define UI_NETWORKSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkServer
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *QTW;
    QWidget *Q1;
    QWidget *Q2;
    QWidget *Q3;

    void setupUi(QWidget *NetworkServer)
    {
        if (NetworkServer->objectName().isEmpty())
            NetworkServer->setObjectName(QString::fromUtf8("NetworkServer"));
        NetworkServer->resize(758, 538);
        verticalLayout = new QVBoxLayout(NetworkServer);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 7, -1, -1);
        QTW = new QTabWidget(NetworkServer);
        QTW->setObjectName(QString::fromUtf8("QTW"));
        QTW->setMovable(true);
        Q1 = new QWidget();
        Q1->setObjectName(QString::fromUtf8("Q1"));
        QTW->addTab(Q1, QString());
        Q2 = new QWidget();
        Q2->setObjectName(QString::fromUtf8("Q2"));
        QTW->addTab(Q2, QString());
        Q3 = new QWidget();
        Q3->setObjectName(QString::fromUtf8("Q3"));
        QTW->addTab(Q3, QString());

        verticalLayout_2->addWidget(QTW);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(NetworkServer);

        QTW->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(NetworkServer);
    } // setupUi

    void retranslateUi(QWidget *NetworkServer)
    {
        NetworkServer->setWindowTitle(QApplication::translate("NetworkServer", "NetworkServer", nullptr));
        QTW->setTabText(QTW->indexOf(Q1), QApplication::translate("NetworkServer", "\345\215\217\350\256\256\345\210\206\345\270\203", nullptr));
        QTW->setTabText(QTW->indexOf(Q2), QApplication::translate("NetworkServer", "IP\350\256\277\351\227\256\350\257\246\346\203\205", nullptr));
        QTW->setTabText(QTW->indexOf(Q3), QApplication::translate("NetworkServer", "IO\347\273\237\350\256\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetworkServer: public Ui_NetworkServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKSERVER_H
