#include"Stack.h"
#include<iostream>
#include<string>
using namespace std;


int main()
{
	Stack myStack = Stack(3);
	cout << "GetAllocated:" << myStack.GetAllocated();
	myStack.Push(3);
	myStack.Push(4);
	myStack.Push(5);
	myStack.Push(6);
	cout << "GetAllocated:" << myStack.GetAllocated()<<endl;
	cout << myStack.Peek() << endl;
	cout << myStack.Pop() << endl;
	cout << myStack.Peek() << endl;
	cout << myStack.Pop() << endl;
	cout << myStack.Peek() << endl;
	cout << myStack.isEmpty() << endl;
	system("pause");
	return 0;
}