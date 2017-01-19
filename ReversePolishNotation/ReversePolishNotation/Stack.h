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


// Template class representing stack

#pragma once
#ifndef STACK_H
#define STACK_H
template <class DataType>
class Stack
{
public:
	// Default constructor that sets initial size of stack, current index and creates an array
	Stack();

	// Destructor
	~Stack();

	// Function that inserts new element on the top of stack
	void Push(const DataType element);

	// Function that remove the top of stack and returns it
	DataType Pop();

	// Function that gets the top of stack
	DataType Peek() const;

	// Function that gets the allocated size of array
	int GetAllocated() const;

	// Function that checks if the stack is empty
	bool isEmpty() const;

private:
	// Help function that doubles size of current stack
	void Resize();

private:
	int maxSize; 
	DataType* Data;
	int allocated;
};

#endif // STACK_H