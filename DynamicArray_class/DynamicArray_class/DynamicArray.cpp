#include "DynamicArray.h"
#include<iostream>

using namespace std;

DynamicArray::DynamicArray()
{
	this->size = 2;
	this->currentIndex = -1;
	this->data = new int[this->size];
}

DynamicArray::~DynamicArray()
{
	delete[] this->data;
}

DynamicArray::DynamicArray(DynamicArray const & other)
{
	this->data = new int[other.size];

	for (int i = 0; i <= other.currentIndex; i++)
	{
		this->data[i] = other.data[i];
	}

	this->currentIndex = other.currentIndex;
	this->size = other.size;
}

DynamicArray& DynamicArray::operator=(DynamicArray const & other)
{
	if (this != &other)
	{
		delete[] this->data;
		this->data = NULL;
		this->currentIndex = 0;
		this->size = 0;

		DynamicArray(other);
	}

	return *this;
}

void DynamicArray::Add(int newElement)
{
	if (isFull())
	{
		Resize();
	}
	this->currentIndex++;
	this->data[this->currentIndex] = newElement;
}

void DynamicArray::Resize()
{
	int* newData = new int[this->size * 2];
	for (int i = 0; i < this->size; i++)
	{
		newData[i] = this->data[i];
	}
	delete[] this->data;
	this->size *= 2;
	this->data = newData;
}

void DynamicArray::Remove()
{
	int* newData = new int[this->currentIndex];
	for (int i = 0; i < this->currentIndex; i++)
	{
		newData[i] = this->data[i];
	}
	delete[] this->data;
	this->currentIndex--;
	this->size = this->currentIndex;
	this->data = newData;
}

int DynamicArray::GetElement(int position)
{
	return this->data[position];
}

int DynamicArray::GetSize()
{
	return this->size;
}

int DynamicArray::GetUsedElements()
{
	return this->currentIndex + 1;
}

bool DynamicArray::isFull()
{
	return this->currentIndex + 1 >= this->size;
}
