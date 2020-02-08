#include "ChooseLocalFile.h"

ChooseLocalFile::ChooseLocalFile(QString *FilePath, QString *FileName, QPushButton *Button, QWidget *parent)
	: QWidget(parent), button(Button), path(FilePath), name(FileName)
{
	ui.setupUi(this);

	splitter = new QSplitter;

	model = new QDirModel;

	ui.treeView->setModel(model);

	splitter->setWindowTitle("文件管理");

	QObject::connect(ui.treeView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(GetResult(const QModelIndex &)));

	QObject::connect(ui.confirmLocalFile, SIGNAL(clicked()), this, SLOT(Confirm()));
}

ChooseLocalFile::~ChooseLocalFile() {

}

void ChooseLocalFile::GetResult(const QModelIndex & index) {



	QString Result = model->filePath(index);

	QFileInfo fileInfo(Result);

	if (fileInfo.isFile()) {

		ui.showLocalFile->setText(Result);

		tempPath.clear();

		tempPath.append(Result);

		tempName = model->fileName(index);

	}





}

void ChooseLocalFile::Confirm() {

	button->setText(ui.showLocalFile->text());
	path->clear();
	path->append(tempPath);
	name->clear();
	name->append(tempName);
}