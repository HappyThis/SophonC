#ifndef QRINGBUFFER_P_H
#define QRINGBUFFER_P_H

#include <QByteArray>

#include <QList>

#include<QtGlobal>

#include<winsock2.h>

#include<windows.h>

#include<QDebug>


#ifndef QRINGBUFFER_CHUNKSIZE

#define QRINGBUFFER_CHUNKSIZE 4096

#endif

enum
{

	MaxAllocSize = (1 << (std::numeric_limits<int>::digits - 1)) - 1
};

enum
{

	MaxByteArraySize = MaxAllocSize - sizeof(std::remove_pointer<QByteArray::DataPtr>::type)
};

class QRingBuffer
{
public:

	QRingBuffer(int growth = QRINGBUFFER_CHUNKSIZE) :
		head(0), tail(0), tailBuffer(0), basicBlockSize(growth), bufferSize(0) { }
	~QRingBuffer() {}

	char *readPointerAtPosition(qint64 pos, qint64 &length);

	char *reserve(qint64 bytes);

	char *reserveFront(qint64 bytes);

	void truncate(qint64 pos)
	{
		if (pos < bufferSize)
			chop(bufferSize - pos);
	}

	bool isEmpty()
	{
		return bufferSize == 0;
	}

	int getChar()
	{
		if (isEmpty())
			return -1;
		char c = *readPointer();
		free(1);
		return int(uchar(c));
	}

	void putChar(char c)
	{
		char *ptr = reserve(1);
		*ptr = c;
	}

	void ungetChar(char c)
	{
		if (head > 0) {
			--head;
			buffers.first()[head] = c;
			++bufferSize;
		}
		else {
			char *ptr = reserveFront(1);
			*ptr = c;
		}
	}

	void clear();

	qint64 read(QByteArray *data, qint64 maxLength);
	qint64 read(char *data, qint64 maxLength);

	qint64 peek(char *data, qint64 maxLength, qint64 pos = 0);

	void append(const char *data, qint64 size);

	void append(const QByteArray &qba);

	qint64 skip(qint64 length)
	{
		qint64 bytesToSkip = qMin(length, bufferSize);

		free(bytesToSkip);
		return bytesToSkip;
	}

	void chop(qint64 length);

	qint64 readLine(char *data, qint64 maxLength);

	bool canReadLine()
	{
		return indexOf('\n', bufferSize) >= 0;
	}

	qint64 getBufferSize()
	{
		return bufferSize;
	}
private:

	qint64 nextDataBlockSize()
	{
		return (tailBuffer == 0 ? tail : buffers.first().size()) - head;
	}

	char *readPointer()
	{
		return bufferSize == 0 ? Q_NULLPTR : (buffers.first().data() + head);
	}
	qint64 indexOf(char c, qint64 maxLength, qint64 pos = 0);

	void free(qint64 bytes);
private:
	QList<QByteArray> buffers;

	int head, tail;

	int tailBuffer;

	int basicBlockSize;

	qint64 bufferSize;
};

#endif // QRINGBUFFER_P_H
