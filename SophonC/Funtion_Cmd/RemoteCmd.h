#pragma once
#include"../BasisFunction/BasisFunction.h"
#include "ui_RemoteCmd.h"
#pragma execution_character_set("utf-8")
#include<QKeyevent>
class RemoteCmd : public BasisFunction
{
	Q_OBJECT
public:
	RemoteCmd(Linker* linker);

	~RemoteCmd();

protected slots:

	virtual void ProcInfo(Token token, QByteArray data, Linker* linker);

private:

	Ui::RemoteCmd ui;

	QString Text;

	QTextCursor Cur;
protected:
	bool eventFilter(QObject *target, QEvent *event);
private slots:

	void TextChange();

	void CurChange();
};

