#pragma once

#include <QWidget>

#include "ui_ChooseLocalFile.h"

#include<QPushbutton>

#include<QDirModel>

#include<QSplitter>

#include<QStandardItem>

#include<QStack>

#include<QDebug>

class ChooseLocalFile : public QWidget
{
	Q_OBJECT

public:
	ChooseLocalFile(QString *FilePath,QString *FileName, QPushButton * Button, QWidget * parent = Q_NULLPTR);

	~ChooseLocalFile();

private:

	Ui::ChooseLocalFile ui;

	QPushButton *button;

	QString *path,*name;

	QString tempPath, tempName;

	QSplitter *splitter;

	QDirModel *model;



private slots:

	void GetResult(const QModelIndex &index);

	void Confirm();
};
