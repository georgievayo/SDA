#pragma once
#ifndef STACK_H
#define STACK_H
template <class DataType>
class Stack
{
public:
	Stack(int capacity);
	~Stack();
	void Push(const DataType element);
	DataType Pop();
	DataType Peek() const;
	int GetAllocated() const;
	bool isEmpty() const;
	void Resize();

private:
	int maxSize;
	DataType* Data;
	int allocated;
};

#endif // STACK_H