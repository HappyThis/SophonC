#include "RemoteCmd.h"



RemoteCmd::RemoteCmd(Linker* linker):BasisFunction(linker){

	ui.setupUi(this);

	setWindowTitle(QString(linker->ip)+"----"+"远程命令行");

	QObject::connect(ui.textEdit, SIGNAL(textChanged()), this, SLOT(TextChange()));

	QObject::connect(ui.textEdit, SIGNAL(cursorPositionChanged()), this, SLOT(CurChange()));

	Text = ui.textEdit->toPlainText();

	Cur = ui.textEdit->textCursor();

	ui.textEdit->installEventFilter(this);
}


RemoteCmd::~RemoteCmd(){
	Send(new SendInfo(CommandCloseCmd));
}
void RemoteCmd::TextChange(){

	QString ChangedText = ui.textEdit->toPlainText();

	if (ChangedText.size() < Text.size()) {

		ui.textEdit->setText(Text);

		return;
	}
}
bool RemoteCmd::eventFilter(QObject * target, QEvent * event)
{
	if (target == ui.textEdit)
	{
		if (event->type() == QEvent::KeyPress)
		{
			QKeyEvent *k = static_cast<QKeyEvent *>(event);

			if (k->key() == Qt::Key_Return)
			{
				ui.textEdit->append("");

				QString EnterText = ui.textEdit->toPlainText();

				QString SendText = EnterText.mid(Text.size(), EnterText.size() - Text.size());


				Text = ui.textEdit->toPlainText();

				Cur = ui.textEdit->textCursor();
				
				SendInfo *SI = new SendInfo(CommandNewStdInput);

				SI->GetInfo()->append(SendText);

				Send(SI);

				return true;
			}
		}
	}
	return QWidget::eventFilter(target, event);
}
void RemoteCmd::CurChange(){

	QTextCursor ChangeCur= ui.textEdit->textCursor();

	if (ChangeCur < Cur) {
		ui.textEdit->setTextCursor(Cur);
	}
}
void RemoteCmd::ProcInfo(Token token, QByteArray data, Linker* linker) {

	switch (token)
	{
	case TokenNewStdOutput: {

		ui.textEdit->append(QString::fromLocal8Bit(data));

		Text = ui.textEdit->toPlainText();

		Cur = ui.textEdit->textCursor();

		break;
	}
	default:

		break;
	}
}
