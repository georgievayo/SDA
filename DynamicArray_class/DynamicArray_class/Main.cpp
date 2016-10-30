#include "DynamicArray.h"
#include<iostream>

using namespace std;

int main()
{
	DynamicArray myArray = DynamicArray();
	myArray.Add(5);
	myArray.Add(15);
	myArray.Add(20);
	myArray.Add(25);
	myArray.Add(30);
	cout << "elements: " << myArray.GetSize()<<endl;
	cout << "Used elements: " << myArray.GetUsedElements() << endl;
	cout << "Element in position 0 is: " << myArray.GetElement(0)<<endl;
	cout << "Element in position 1 is: " << myArray.GetElement(1) << endl;
	myArray.Remove();
	cout << "Size after removing is: " << myArray.GetUsedElements()<<endl;

	system("pause");
	return 0;
}
