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
#ifndef NODE_H
#define NODE_H
template<class T>
class Node
{
private:
	Node<T>* left;
	Node<T>* right;

public:
	T value;
	Node();
	Node(const T& value);
	~Node();
	Node<T>*& GetLeft();
	void SetLeft(Node<T>* node);
	Node<T>*& GetRight();
	T GetValue();
	void SetRight(Node<T>* node);
	void SetValue(T value);
};
#endif
