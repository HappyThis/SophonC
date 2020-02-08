#include "ChoosePath.h"

ChoosePath::ChoosePath(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setAttribute(Qt::WA_DeleteOnClose);

	setAttribute(Qt::WA_QuitOnClose, false);

	QObject::connect(ui.treeView, SIGNAL(doubleClicked(const QModelIndex &)), this,SLOT(GetNextDir(const QModelIndex &)));

	QObject::connect(ui.treeView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(GetResult(const QModelIndex &)));

	QObject::connect(ui.confirmPath, SIGNAL(clicked()), this, SLOT(Confirm()));

	model = new QStandardItemModel(0, 1);

	model->setHeaderData(0, Qt::Horizontal, tr("        目录"));

	ui.treeView->setModel(model);

}

ChoosePath::~ChoosePath() {

}

void ChoosePath::SetLinker(Linker * link) {

	linker = link;

	setWindowTitle(QString(linker->ip) + "----" + "目录选择");

	linker->instance->Send(new SendInfo(CommandGetDir));

}
void ChoosePath::GetNextDir(const QModelIndex & index){


    currentItem= model->itemFromIndex(index);

	QStandardItem* Fitem = currentItem;

	while (currentItem->hasChildren()) {

		currentItem->removeRow(0);
	}

	SendInfo *SI=new SendInfo(CommandGetFiles);

	QStack<QString>Dir;

	do {
		Dir.push(Fitem->text());
	} while (Fitem = Fitem->parent());
	QString Path;
	while (!Dir.isEmpty()) {
		Path = Path + Dir.top();
		Dir.pop();
	}
	SI->GetInfo()->append(Path);

	linker->instance->Send(SI);
}
void ChoosePath::GetResult(const QModelIndex & index){

	QStandardItem* resultItem = model->itemFromIndex(index);


	QStack<QString>Dir;

	do {
		Dir.push(resultItem->text());
	} while (resultItem = resultItem->parent());
	Result.clear();
	while (!Dir.isEmpty()) {
		Result = Result + Dir.top();
		Dir.pop();
	}

	ui.showPath->setText(Result);
	

}
void ChoosePath::Confirm(){
	linker->remotePath.clear();
	linker->remotePath.append(Result);
}
void ChoosePath::Proc(Linker* link, QByteArray data, Token token) {

	if (link != linker) {
		return;
	}
	switch (token)
	{
	case CommandGetDir: {

		QByteArrayList byteList = data.split('|');

		int sz = byteList.size();

		model->setRowCount(sz);

		for (int i = 0; i < sz; i++) {
			QStandardItem *item = new QStandardItem(QString(byteList.at(i)));
			model->setItem(i, 0, item);
			item->setIcon(QIcon(":/SophonC/disk.ico"));
		}

		break;
	}

	case CommandGetFiles: {

		QByteArrayList byteList = data.split('|');

		for (int i = 0; i < byteList.size(); i++) {

			if (byteList.at(i).trimmed().isEmpty()) {
				continue;
			}

			QStandardItem *sonItem = new QStandardItem(QString(byteList.at(i)) +"/");
		//	sonItem->setIcon();
			currentItem->appendRow(sonItem);
			//currentItem->setChild(currentItem->row(),i,sonItem);
		}

		break;
	}

	default:
		break;
	}
}
