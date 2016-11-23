#include "Queue.h"

template<class DataType>
Queue<DataType>::Queue()
{
}

template<class DataType>
Queue<DataType>::Queue(int size)
{
	this->capacity = size;
	Data = new DataType[this->capacity];
	this->headIndex = -1;
	this->currentIndex = -1;
}

template<class DataType>
Queue<DataType>::~Queue()
{
	delete[] Data;
}

template<class DataType>
void Queue<DataType>::Enqueue(DataType element)
{
	if (this->headIndex == -1)
	{
		this->headIndex = 0;
	}
	++this->currentIndex;
	this->Data[this->currentIndex] = element;
}

template<class DataType>
void Queue<DataType>::Dequeue()
{
	if (this->headIndex == -1)
	{
		cout << "Error" << endl;
	}
	else
	{
		this->headIndex++;
	}

}

template<class DataType>
DataType Queue<DataType>::GetHead()
{
	return this->Data[this->headIndex];
}
