#pragma once
#ifndef STACK_H
#define STACK_H
class Stack
{
public:
	Stack(int capacity);
	~Stack();
	void Push(const int element);
	int Pop();
	int Peek() const;
	int GetAllocated() const;
	bool isEmpty() const;
	void Resize();

private:
	int maxSize;
	int *Data;
	int allocated;
};

#endif // STACK_H