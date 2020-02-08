/********************************************************************************
** Form generated from reading UI file 'ChoosePath.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEPATH_H
#define UI_CHOOSEPATH_H

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

class Ui_ChoosePath
{
public:
    QVBoxLayout *verticalLayout_2;
    QTreeView *treeView;
    QHBoxLayout *horizontalLayout;
    QLabel *showPath;
    QPushButton *confirmPath;

    void setupUi(QWidget *ChoosePath)
    {
        if (ChoosePath->objectName().isEmpty())
            ChoosePath->setObjectName(QString::fromUtf8("ChoosePath"));
        ChoosePath->resize(554, 529);
        verticalLayout_2 = new QVBoxLayout(ChoosePath);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(ChoosePath);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(treeView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        showPath = new QLabel(ChoosePath);
        showPath->setObjectName(QString::fromUtf8("showPath"));
        showPath->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(showPath);

        confirmPath = new QPushButton(ChoosePath);
        confirmPath->setObjectName(QString::fromUtf8("confirmPath"));

        horizontalLayout->addWidget(confirmPath);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ChoosePath);

        QMetaObject::connectSlotsByName(ChoosePath);
    } // setupUi

    void retranslateUi(QWidget *ChoosePath)
    {
        ChoosePath->setWindowTitle(QApplication::translate("ChoosePath", "ChoosePath", nullptr));
        showPath->setText(QString());
        confirmPath->setText(QApplication::translate("ChoosePath", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChoosePath: public Ui_ChoosePath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEPATH_H
