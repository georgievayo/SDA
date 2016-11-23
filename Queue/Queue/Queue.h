#pragma once
template<class DataType>
class Queue
{
public:
	Queue();
	Queue(int size);
	~Queue();
	void Enqueue(DataType element);
	void Dequeue();
	DataType GetHead();

private:
	DataType* Data;
	int headIndex;
	int currentIndex;
	int capacity;

};

