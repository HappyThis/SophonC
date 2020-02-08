#pragma once

#include<QString>

struct RemoteCaptureUint {

	char source[4*8+7+1];
	char dest[4*8+7+1];
	char time[20];
	QString protocol;
	unsigned int lenth;
};