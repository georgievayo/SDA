#include "Stack.h"
#include<iostream>
#include<assert.h>
using namespace std;

Stack::Stack(int capacity)
{
	this->allocated = 0;
	this->maxSize = capacity;
	Data = new int[this->maxSize];
}


Stack::~Stack()
{
	delete[] Data;
}

void Stack::Push(const int element)
{
	if (this->allocated >= this->maxSize)
	{
		Resize();
	}
	Data[this->allocated] = element;
	this->allocated += 1;
}

int Stack::Pop()
{
	assert(this->allocated > 0);
	this->allocated--;
	return Data[this->allocated];
	
}

int Stack::Peek() const
{
	assert(this->allocated > 0);
	return Data[this->allocated - 1];
}

bool Stack::isEmpty() const
{
	return this->allocated == 0;
}

void Stack::Resize()
{
	int *newData = new int[this->maxSize * 2];
	for (int i = 0; i < this->maxSize; i++)
	{
		newData[i] = Data[i];
	}
	delete[] Data;
	this->maxSize *= 2;
	Data = newData;
}

int Stack::GetAllocated() const
{
	return this->allocated;
}