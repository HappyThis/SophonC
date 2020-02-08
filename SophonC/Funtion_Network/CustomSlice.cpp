#include "CustomSlice.h"


CustomSlice::CustomSlice(QString label, qreal value)
	: QPieSlice(label, value)
{
	connect(this, &CustomSlice::hovered, this, &CustomSlice::showHighlight);
}

QBrush CustomSlice::originalBrush()
{
	return m_originalBrush;
}

void CustomSlice::showHighlight(bool show)
{
	if (show) {
		QBrush brush = this->brush();
		m_originalBrush = brush;
		brush.setColor(brush.color().lighter());
		setBrush(brush);
		setExploded(true);

	}
	else {
		setBrush(m_originalBrush);
		setExploded(false);
	}
}
