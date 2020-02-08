/********************************************************************************
** Form generated from reading UI file 'FileSend.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESEND_H
#define UI_FILESEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileSend
{
public:

    void setupUi(QWidget *FileSend)
    {
        if (FileSend->objectName().isEmpty())
            FileSend->setObjectName(QString::fromUtf8("FileSend"));
        FileSend->resize(400, 300);

        retranslateUi(FileSend);

        QMetaObject::connectSlotsByName(FileSend);
    } // setupUi

    void retranslateUi(QWidget *FileSend)
    {
        FileSend->setWindowTitle(QApplication::translate("FileSend", "FileSend", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileSend: public Ui_FileSend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESEND_H
