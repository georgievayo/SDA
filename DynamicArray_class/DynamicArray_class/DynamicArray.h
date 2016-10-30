#pragma once
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray
{
private:
	int size;
	int* data;
	int currentIndex;

public:
	DynamicArray();
	~DynamicArray();
	DynamicArray(DynamicArray const & other);
	DynamicArray& operator=(DynamicArray const & other);
	void Add(int newElement);
	void Remove();
	int GetUsedElements();
	int GetElement(int position);
	int GetSize();
	void Resize();
	bool isFull();
};
#endif
