/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Yoana Georgieva
* @idnumber 61920
* @task 1
* @compiler VC
*
*/

//#include"stdafx.h"
#include "Stack.h"
#include<iostream>
#include<assert.h>
using namespace std;

template<class DataType>
Stack<DataType>::Stack()
{
	this->allocated = 0;
	this->maxSize = 4;
	Data = new DataType[this->maxSize];
}

template<class DataType>
Stack<DataType>::~Stack()
{
	delete[] Data;
}

template<class DataType>
void Stack<DataType>::Push(const DataType element)
{
	if (this->allocated >= this->maxSize)
	{
		Resize();
	}
	Data[this->allocated] = element;
	this->allocated += 1;
}

template<class DataType>
DataType Stack<DataType>::Pop()
{
	assert(this->allocated > 0);
	this->allocated--;
	return Data[this->allocated];
	
}

template<class DataType>
DataType Stack<DataType>::Peek() const
{
	assert(this->allocated > 0);
	return Data[this->allocated - 1];
}

template<class DataType>
bool Stack<DataType>::isEmpty() const
{
	return this->allocated == 0;
}

template<class DataType>
void Stack<DataType>::Resize()
{
	DataType *newData = new DataType[this->maxSize * 2];
	for (int i = 0; i < this->maxSize; i++)
	{
		newData[i] = Data[i];
	}
	delete[] Data;
	this->maxSize *= 2;
	Data = newData;
}

template<class DataType>
int Stack<DataType>::GetAllocated() const
{
	return this->allocated;
}