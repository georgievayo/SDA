/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Yoana Georgieva
* @idnumber 61920
* @task 4
* @compiler VC
*
*/

#pragma once
#include"Node.cpp"
#include"DynamicArray.h"

#include<iostream>

#ifndef TREE_H
#define TREE_H

template<class T>
class Tree
{
private:
	Node<T>* root;
	int i;
	T* Remove(Node<T>*& node, T value);

public:
	Tree();
	~Tree();
	Node<T>* BuildTree(DynamicArray<T>& sortedList, int start, int end);
	void sortedListToBST(DynamicArray<T>& sortedList);
	bool Add(T value);
	T* Search(T value);
	T* RemoveIt(T value);
	Node<T>* FindLeftMostNode(Node<T>*& root);

};
#endif
