#include "RingBuffer.h"

#include <string.h>

char *QRingBuffer::readPointerAtPosition(qint64 pos, qint64 &length)
{
	if (pos >= 0)
	{
		pos += head;
		for (int i = 0; i < buffers.size(); ++i)
		{
			length = (i == tailBuffer ? tail : buffers[i].size());
			if (length > pos)
			{
				length -= pos;
				return buffers[i].data() + pos;
			}
			pos -= length;
		}
	}

	length = 0;
	return 0;
}
void QRingBuffer::free(qint64 bytes)
{
	Q_ASSERT(bytes <= bufferSize);

	while (bytes > 0)
	{
		const qint64 blockSize = buffers.first().size() - head;
		if (tailBuffer == 0 || blockSize > bytes)
		{
			if (bufferSize <= bytes)
			{
				if (buffers.first().size() <= basicBlockSize)
				{
					bufferSize = 0;
					head = tail = 0;
				}
				else
				{
					clear();
				}
			}
			else
			{
				Q_ASSERT(bytes < MaxByteArraySize);
				head += int(bytes);
				bufferSize -= bytes;
			}
			return;
		}
		bufferSize -= blockSize;
		bytes -= blockSize;
		buffers.removeFirst();
		--tailBuffer;
		head = 0;
	}
}

char *QRingBuffer::reserve(qint64 bytes)
{
	if (bytes <= 0 || bytes >= MaxByteArraySize)
		return 0;

	if (buffers.isEmpty())
	{
		buffers.append(QByteArray());
		buffers.first().resize(qMax(basicBlockSize, int(bytes)));
	}
	else
	{
		const qint64 newSize = bytes + tail;

		if (newSize > buffers.last().size())
		{

			if (newSize > buffers.last().capacity() && (tail >= basicBlockSize
				|| newSize >= MaxByteArraySize))
			{
				buffers.last().resize(tail);
				buffers.append(QByteArray());
				++tailBuffer;
				tail = 0;
			}

			buffers.last().resize(qMax(basicBlockSize, tail + int(bytes)));
		}
	}
	char *writePtr = buffers.last().data() + tail;
	bufferSize += bytes;
	Q_ASSERT(bytes < MaxByteArraySize);
	tail += int(bytes);
	return writePtr;
}

char *QRingBuffer::reserveFront(qint64 bytes)
{
	if (bytes <= 0 || bytes >= MaxByteArraySize)
		return 0;

	if (head < bytes)
	{
		if (buffers.isEmpty())
		{
			buffers.append(QByteArray());
		}
		else
		{
			buffers.first().remove(0, head);
			if (tailBuffer == 0)
				tail -= head;
		}

		head = qMax(basicBlockSize, int(bytes));
		if (bufferSize == 0)
		{
			tail = head;
		}
		else
		{
			buffers.prepend(QByteArray());
			++tailBuffer;
		}
		buffers.first().resize(head);
	}

	head -= int(bytes);
	bufferSize += bytes;
	return buffers.first().data() + head;
}

void QRingBuffer::chop(qint64 length)
{
	Q_ASSERT(length <= bufferSize);

	while (length > 0)
	{
		if (tailBuffer == 0 || tail > length)
		{
			if (bufferSize <= length)
			{
				if (buffers.first().size() <= basicBlockSize)
				{
					bufferSize = 0;
					head = tail = 0;
				}
				else
				{
					clear();
				}
			}
			else
			{
				Q_ASSERT(length < MaxByteArraySize);
				tail -= int(length);
				bufferSize -= length;
			}
			return;
		}

		bufferSize -= tail;
		length -= tail;
		buffers.removeLast();
		--tailBuffer;
		tail = buffers.last().size();
	}
}

void QRingBuffer::clear()
{
	if (buffers.isEmpty())
		return;

	buffers.erase(buffers.begin() + 1, buffers.end());
	buffers.first().clear();

	head = tail = 0;
	tailBuffer = 0;
	bufferSize = 0;
}

qint64 QRingBuffer::indexOf(char c, qint64 maxLength, qint64 pos)
{
	if (maxLength <= 0 || pos < 0)
		return -1;

	qint64 index = -(pos + head);
	for (int i = 0; i < buffers.size(); ++i)
	{
		qint64 nextBlockIndex = qMin(index + (i == tailBuffer ? tail : buffers[i].size()),
			maxLength);

		if (nextBlockIndex > 0)
		{
			const char *ptr = buffers[i].data();
			if (index < 0)
			{
				ptr -= index;
				index = 0;
			}

			const char *findPtr = reinterpret_cast<const char *>(memchr(ptr, c,
				nextBlockIndex - index));
			if (findPtr)
				return qint64(findPtr - ptr) + index + pos;

			if (nextBlockIndex == maxLength)
				return -1;
		}
		index = nextBlockIndex;
	}
	return -1;
}

qint64 QRingBuffer::read(QByteArray *data, qint64 maxLength)
{
	data->clear();

	const qint64 bytesToRead = qMin(bufferSize, maxLength);
	qint64 readSoFar = 0;
	while (readSoFar < bytesToRead)
	{
		const qint64 bytesToReadFromThisBlock = qMin(bytesToRead - readSoFar,
			nextDataBlockSize());
		if (data)
			data->append(readPointer(), bytesToReadFromThisBlock);
		readSoFar += bytesToReadFromThisBlock;
		free(bytesToReadFromThisBlock);
	}
	return readSoFar;
}


qint64 QRingBuffer::read(char *data, qint64 maxLength)
{
	const qint64 bytesToRead = qMin(bufferSize, maxLength);
	qint64 readSoFar = 0;
	while (readSoFar < bytesToRead)
	{
		const qint64 bytesToReadFromThisBlock = qMin(bytesToRead - readSoFar,
			nextDataBlockSize());
		if (data)
			memcpy(data + readSoFar, readPointer(), bytesToReadFromThisBlock);
		readSoFar += bytesToReadFromThisBlock;
		free(bytesToReadFromThisBlock);
	}
	return readSoFar;
}


qint64 QRingBuffer::peek(char *data, qint64 maxLength, qint64 pos)
{
	qint64 readSoFar = 0;

	if (pos >= 0)
	{
		pos += head;
		for (int i = 0; readSoFar < maxLength && i < buffers.size(); ++i)
		{
			qint64 blockLength = (i == tailBuffer ? tail : buffers[i].size());

			if (pos < blockLength)
			{
				blockLength = qMin(blockLength - pos, maxLength - readSoFar);
				memcpy(data + readSoFar, buffers[i].data() + pos, blockLength);
				readSoFar += blockLength;
				pos = 0;
			}
			else
			{
				pos -= blockLength;
			}
		}
	}

	return readSoFar;
}

void QRingBuffer::append(const char *data, qint64 size)
{
	char *writePointer = reserve(size);
	if (size == 1)
		*writePointer = *data;
	else if (size)
		::memcpy(writePointer, data, size);
}

void QRingBuffer::append(const QByteArray &qba)
{
	if (tail == 0)
	{
		if (buffers.isEmpty())
			buffers.append(qba);
		else
			buffers.last() = qba;
	}
	else
	{
		buffers.last().resize(tail);
		buffers.append(qba);
		++tailBuffer;
	}
	tail = qba.size();
	bufferSize += tail;
}

qint64 QRingBuffer::readLine(char *data, qint64 maxLength)
{
	if (!data || --maxLength <= 0)
		return -1;

	qint64 i = indexOf('\n', maxLength);
	i = read(data, i >= 0 ? (i + 1) : maxLength);

	data[i] = '\0';
	return i;
}
