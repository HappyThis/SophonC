/********************************************************************************
** Form generated from reading UI file 'RemoteCapture.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTECAPTURE_H
#define UI_REMOTECAPTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemoteCapture
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *RemoteCapture)
    {
        if (RemoteCapture->objectName().isEmpty())
            RemoteCapture->setObjectName(QString::fromUtf8("RemoteCapture"));
        RemoteCapture->resize(630, 761);
        RemoteCapture->setMinimumSize(QSize(630, 761));
        RemoteCapture->setMaximumSize(QSize(630, 761));
        verticalLayout = new QVBoxLayout(RemoteCapture);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(RemoteCapture);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 0));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(RemoteCapture);

        QMetaObject::connectSlotsByName(RemoteCapture);
    } // setupUi

    void retranslateUi(QWidget *RemoteCapture)
    {
        RemoteCapture->setWindowTitle(QApplication::translate("RemoteCapture", "RemoteCapture", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RemoteCapture", "\346\212\223\346\215\225\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RemoteCapture", "\346\272\220\345\234\260\345\235\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RemoteCapture", "\347\233\256\346\240\207\345\234\260\345\235\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("RemoteCapture", "\345\215\217\350\256\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("RemoteCapture", "\351\225\277\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemoteCapture: public Ui_RemoteCapture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTECAPTURE_H
