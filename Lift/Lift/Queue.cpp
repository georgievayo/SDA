/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Yoana Georgieva
* @idnumber 61920
* @task 2
* @compiler VC
*
*/


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
	this->headIndex = 0;
	this->currentIndex = 0;
}

template<class DataType>
Queue<DataType>::~Queue()
{
	delete[] this->Data;
}

template<class DataType>
void Queue<DataType>::Enqueue(DataType element)
{
	this->Data[this->currentIndex] = element;
	this->currentIndex++;
}

template<class DataType>
void Queue<DataType>::Dequeue()
{
	if (this->headIndex < 0)
	{
		cout << "Error" << endl;
	}
	else if (this->headIndex < this->capacity)
	{
		this->headIndex++;
	}
}

template<class DataType>
DataType Queue<DataType>::GetHead()
{
	return this->Data[this->headIndex];
}

template<class DataType>
bool Queue<DataType>::isEmpty()
{
	return this->headIndex == this->currentIndex;
}

template<class DataType>
bool Queue<DataType>::isFull()
{
	return this->currentIndex == this->capacity;
}

