#include"Queue.h"
#include"Queue.cpp"
#include<iostream>

using namespace std;

int main()
{
	Queue<int> myQueue = Queue<int>(5);
	myQueue.Enqueue(13);
	myQueue.Enqueue(14);
	myQueue.Enqueue(15);
	cout << "Head: " << myQueue.GetHead() << endl;
	myQueue.Dequeue();
	cout << "Head: " << myQueue.GetHead() << endl;
	system("pause");
	return 0;
}