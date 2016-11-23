#include "DynamicArray.h"
#include<iostream>

using namespace std;

template<class DataType>
DynamicArray<DataType>::DynamicArray()
{
	this->size = 2;
	this->currentIndex = -1;
	this->data = new DataType[this->size];
}

template<class DataType>
DynamicArray<DataType>::~DynamicArray()
{
	delete[] this->data;
}

template<class DataType>
DynamicArray<DataType>::DynamicArray(DynamicArray const & other)
{
	this->data = new DataType[other.size];

	for (int i = 0; i <= other.currentIndex; i++)
	{
		this->data[i] = other.data[i];
	}

	this->currentIndex = other.currentIndex;
	this->size = other.size;
}

template<class DataType>
DynamicArray<DataType>& DynamicArray<DataType>::operator=(DynamicArray<DataType> const & other)
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

template<class DataType>
void DynamicArray<DataType>::Add(DataType newElement)
{
	if (isFull())
	{
		Resize();
	}
	this->currentIndex++;
	this->data[this->currentIndex] = newElement;
}

template<class DataType>
void DynamicArray<DataType>::Resize()
{
	DataType* newData = new DataType[this->size * 2];
	for (int i = 0; i < this->size; i++)
	{
		newData[i] = this->data[i];
	}
	delete[] this->data;
	this->size *= 2;
	this->data = newData;
}

template<class DataType>
void DynamicArray<DataType>::Remove()
{
	DataType* newData = new DataType[this->currentIndex];
	for (int i = 0; i < this->currentIndex; i++)
	{
		newData[i] = this->data[i];
	}
	delete[] this->data;
	this->currentIndex--;
	this->size = this->currentIndex;
	this->data = newData;
}

template<class DataType>
DataType DynamicArray<DataType>::GetElement(int position)
{
	return this->data[position];
}


template<class DataType>
int DynamicArray<DataType>::GetSize()
{
	return this->size;
}


template<class DataType>
int DynamicArray<DataType>::GetUsedElements()
{
	return this->currentIndex + 1;
}

template<class DataType>
bool DynamicArray<DataType>::isFull()
{
	return this->currentIndex + 1 >= this->size;
}
