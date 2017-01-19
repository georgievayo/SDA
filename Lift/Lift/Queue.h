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

// Template class representing queque
#pragma once

#ifndef QUEUE_H
#define QUEUE_H

template<class DataType>
class Queue
{
public:

	//Default constructor
	Queue();

	//Constructor with one parameter
	Queue(int size);

	//Destructor
	~Queue();

	//Function that adds element at the end of the queue
	void Enqueue(DataType element);

	//Function that removes the head of the queue
	void Dequeue();

	//Function that gets the head of the queue
	DataType GetHead();

	//Function that checks if the queue is empty
	bool isEmpty();

	//Function that checks if the queue is full
	bool isFull();

private:
	DataType* Data;
	int headIndex;
	int currentIndex;
	int capacity;

};

#endif
