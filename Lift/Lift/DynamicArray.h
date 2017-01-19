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


// Class representing dynamic array of Requests

#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include "Request.h"

class DynamicArray
{

private:
	int size;
	Request* data;
	int currentIndex;

public:

	// Default constructor that sets initial size, current index
	DynamicArray();

	DynamicArray(int size);

	// Destructor
	~DynamicArray();

	// Copy-constructor
	DynamicArray(DynamicArray const & other);

	// Overloading operator=
	DynamicArray& operator=(DynamicArray const & other);

	// Function that inserts element at the end of array
	void Add(Request const &newElement);

	// Function that sorts array by floor
	void Sort();

	// Function that gets the current number of elements in array
	int GetUsedElements();

	// Function that gets the element at certain position
	Request& GetElement(int position);

	// Function that gets the allocated size of array
	int GetSize();

	// Function that checks if the array is full
	bool isFull();

private:

	//Help function that doubles size of current array
	void Resize();
};
#endif
