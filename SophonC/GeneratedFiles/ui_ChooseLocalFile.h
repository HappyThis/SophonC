/********************************************************************************
** Form generated from reading UI file 'ChooseLocalFile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELOCALFILE_H
#define UI_CHOOSELOCALFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseLocalFile
{
public:
    QVBoxLayout *verticalLayout_2;
    QTreeView *treeView;
    QHBoxLayout *horizontalLayout;
    QLabel *showLocalFile;
    QPushButton *confirmLocalFile;

    void setupUi(QWidget *ChooseLocalFile)
    {
        if (ChooseLocalFile->objectName().isEmpty())
            ChooseLocalFile->setObjectName(QString::fromUtf8("ChooseLocalFile"));
        ChooseLocalFile->resize(550, 420);
        ChooseLocalFile->setMinimumSize(QSize(550, 420));
        ChooseLocalFile->setMaximumSize(QSize(550, 420));
        verticalLayout_2 = new QVBoxLayout(ChooseLocalFile);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        treeView = new QTreeView(ChooseLocalFile);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout_2->addWidget(treeView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        showLocalFile = new QLabel(ChooseLocalFile);
        showLocalFile->setObjectName(QString::fromUtf8("showLocalFile"));

        horizontalLayout->addWidget(showLocalFile);

        confirmLocalFile = new QPushButton(ChooseLocalFile);
        confirmLocalFile->setObjectName(QString::fromUtf8("confirmLocalFile"));

        horizontalLayout->addWidget(confirmLocalFile);

        horizontalLayout->setStretch(0, 1);

        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ChooseLocalFile);

        QMetaObject::connectSlotsByName(ChooseLocalFile);
    } // setupUi

    void retranslateUi(QWidget *ChooseLocalFile)
    {
        ChooseLocalFile->setWindowTitle(QApplication::translate("ChooseLocalFile", "ChooseLocalFile", nullptr));
        showLocalFile->setText(QApplication::translate("ChooseLocalFile", "\345\217\221\351\200\201\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        confirmLocalFile->setText(QApplication::translate("ChooseLocalFile", "\347\241\256\350\256\244\351\200\211\346\213\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseLocalFile: public Ui_ChooseLocalFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELOCALFILE_H
