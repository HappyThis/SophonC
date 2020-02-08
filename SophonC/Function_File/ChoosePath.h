#pragma once

#include <QWidget>

#include "ui_ChoosePath.h"

#include "../BasisFunction/BasisFunction.h"

#include<QStandardItemModel>

#include<QStack>

#pragma execution_character_set("utf-8")

class ChoosePath : public QWidget
{
	Q_OBJECT

public:
	ChoosePath(QWidget *parent = Q_NULLPTR);

	~ChoosePath();

	void SetLinker(Linker* link);

private:

	Ui::ChoosePath ui;

	Linker* linker;

	QStandardItem* currentItem;

	QStandardItemModel *model;

	QString Result;

private slots:

	void Proc(Linker*, QByteArray data, Token token);

	void GetNextDir(const QModelIndex &index);

	void GetResult(const QModelIndex &index);

	void Confirm();

};
