#include"Stack.h"
#include"Stack.cpp"
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main()
{
	Stack<int> myStack = Stack<int>(15);
	myStack.Push(5);
	myStack.Push(6);
	myStack.Push(7);
	myStack.Push(8);
	myStack.Push(9);
	cout << "Peek: " << myStack.Peek() << endl;
	myStack.Pop();
	cout << "GetAllocated: " << myStack.GetAllocated() << endl;
	system("pause");
	return 0;
}