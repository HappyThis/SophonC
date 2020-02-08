/********************************************************************************
** Form generated from reading UI file 'RemoteCmd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTECMD_H
#define UI_REMOTECMD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemoteCmd
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *RemoteCmd)
    {
        if (RemoteCmd->objectName().isEmpty())
            RemoteCmd->setObjectName(QString::fromUtf8("RemoteCmd"));
        RemoteCmd->resize(707, 559);
        verticalLayout = new QVBoxLayout(RemoteCmd);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(RemoteCmd);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(RemoteCmd);

        QMetaObject::connectSlotsByName(RemoteCmd);
    } // setupUi

    void retranslateUi(QWidget *RemoteCmd)
    {
        RemoteCmd->setWindowTitle(QApplication::translate("RemoteCmd", "RemoteCmd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemoteCmd: public Ui_RemoteCmd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTECMD_H
