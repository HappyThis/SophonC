#pragma once


#include <QtCharts>


#include <QPieSlice>

using namespace QtCharts;

class CustomSlice : public QPieSlice
{

	Q_OBJECT

public:
	CustomSlice(QString label, qreal value);

public:

	QBrush originalBrush();

public Q_SLOTS:

	void showHighlight(bool show);

private:
	QBrush m_originalBrush;
};

