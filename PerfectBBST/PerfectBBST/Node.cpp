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

#include "Node.h"


template<class T>
Node<T>::Node()
{
}

template<class T>
Node<T>::~Node()
{
}

template<class T>
Node<T>::Node(const T& value)
{
	this->value = value;
}

template<class T>
Node<T>*& Node<T>::GetLeft()
{
	return this->left;
}

template<class T>
void Node<T>::SetLeft(Node<T>* node)
{
	this->left = node;
}

template<class T>
Node<T>*& Node<T>::GetRight()
{
	return this->right;
}

template<class T>
T Node<T>::GetValue()
{
	return this->GetValue();
}

template<class T>
void Node<T>::SetRight(Node<T>* node)
{
	this->right = node;
}

template<class T>
void Node<T>::SetValue(T value)
{
	this->value = value;
}



