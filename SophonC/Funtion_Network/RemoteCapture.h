#pragma once

#pragma execution_character_set("utf-8")

#include <QWidget>

#include "ui_RemoteCapture.h"

#include"ThreadOfRemoteCapture.h"

#include<QThread>

#include<QFileDialog>

class RemoteCapture : public QWidget
{
	Q_OBJECT

public:
	RemoteCapture(QWidget *parent = Q_NULLPTR);

	~RemoteCapture();

	void Start(QString ip);
	
	void Stop();

private:

	Ui::RemoteCapture ui;

	ThreadOfRemoteCapture* threadOfRemoteCapture;

	QThread * instanceOfRemoteCapture;

	QString ip;

signals:
	void StartCap(QString ip);

private slots:

	void NewPacket(RemoteCaptureUint RCU);

};
