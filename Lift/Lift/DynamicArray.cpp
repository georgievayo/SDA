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

#include "DynamicArray.h"
#include<iostream>

using namespace std;

DynamicArray::DynamicArray()
{
	this->size = 2;
	this->currentIndex = -1;
	this->data = new Request[this->size];
}

DynamicArray::DynamicArray(int size)
{
	this->size = size;
	this->currentIndex = -1;
	this->data = new Request[this->size];
}


DynamicArray::~DynamicArray()
{
	delete[] this->data;
}


DynamicArray::DynamicArray(DynamicArray const & other)
{
	this->data = new Request[other.size];

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


void DynamicArray::Add(Request const &newElement)
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
	Request* newData = new Request[this->size * 2];
	for (int i = 0; i < this->size; i++)
	{
		newData[i] = this->data[i];
	}
	delete[] this->data;
	this->size *= 2;
	this->data = newData;
}


void DynamicArray::Sort()
{
	for (int i = 1; i <= this->currentIndex; i++)
	{
		for (int j = this->currentIndex; j >= i; --j)
		{
			if (this->data[j - 1].GetFloor() > this->data[j].GetFloor())
			{
				Request element = this->data[j - 1];
				this->data[j - 1] = this->data[j];
				this->data[j] = element;
			}
		}
	}
}


Request& DynamicArray::GetElement(int position)
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
