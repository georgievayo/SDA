// DynamicArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
struct DA
{
	int size;
	int used;
	int *data;
};

void Init(DA *arr)
{
	arr->data = NULL;
	arr->used = 0;
	arr->size = 0;
}

void Reallocate(DA *arr, int newSize)
{
	int* temp = new int[newSize];
	for (int i = 0; i < arr->used; i++)
	{
		temp[i] = arr->data[i];
	}
	delete[] arr->data;
	arr->data = temp;
	arr->size = newSize;
}

void Add(DA *arr, int newElement)
{
	if (arr->size <= arr->used)
	{
		int newSize = (arr->size == 0 ? 2 : arr->size*2);
		Reallocate(arr, newSize);
	}
	arr->data[arr->used++] = newElement;
}

void Free(DA *arr)
{
	arr->size = 0;
	arr->used = 0;
	delete[] arr->data;
	arr->data = NULL;
}

int GetData(DA *arr, int index)
{
	return arr->data[index];
}

int _tmain(int argc, _TCHAR* argv[])
{
	DA da;
	Init(&da);
	Add(&da, 5);
	Free(&da);
	return 0;
}

