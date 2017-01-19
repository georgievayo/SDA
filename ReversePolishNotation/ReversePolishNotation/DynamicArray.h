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


#pragma once

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
template <class DataType>
class DynamicArray
{

private:
	int size;
	DataType* data;
	int currentIndex;

public:

	// Default constructor that sets initial size, current index
	DynamicArray();

	// Destructor
	~DynamicArray();

	// Copy-constructor
	DynamicArray(DynamicArray const & other);

	// Overloading operator=
	DynamicArray& operator=(DynamicArray const & other);

	// Function that inserts element at the end of array
	void Add(DataType const &newElement);

	// Function that gets the current number of elements in array
	int GetUsedElements();

	// Function that gets the element at certain position
	DataType GetElement(int position);

	// Function that gets the allocated size of array
	int GetSize();

	// Function that checks if the array is full
	bool isFull();

private:

	//Help function that doubles size of current array
	void Resize();
};
#endif
