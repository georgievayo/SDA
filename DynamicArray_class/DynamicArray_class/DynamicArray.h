#pragma once
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <class DataType>
class DynamicArray
{
private:
	int size;
	DataType* data;
	int currentIndex;

public:
	DynamicArray();
	~DynamicArray();
	DynamicArray(DynamicArray const & other);
	DynamicArray& operator=(DynamicArray const & other);
	void Add(DataType newElement);
	void Remove();
	int GetUsedElements();
	DataType GetElement(int position);
	int GetSize();
	void Resize();
	bool isFull();
};
#endif
