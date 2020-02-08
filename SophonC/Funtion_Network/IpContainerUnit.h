#pragma once

#define MaxProtocol 35


struct IpContainerUnit {

	unsigned int protocol[MaxProtocol];

	unsigned int conter;

	unsigned int totLength;

	char startTime[20];

	char endTime[20];

	char ip[4 * 8 + 7 + 1];
};

