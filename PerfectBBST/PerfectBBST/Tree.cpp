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

#include "Tree.h"

template<class T>
Tree<T>::Tree()
{
	this->root = NULL;
	this->i = 0;
}

template<class T>
Tree<T>::~Tree()
{
}

template<class T>
void Tree<T>::sortedListToBST(DynamicArray<T>& sortedList)
{
	int len = sortedList.GetUsedElements();
	this->root = BuildTree(sortedList, 0, len - 1);

}

template<class T>
bool Tree<T>::Add(T value)
{
	if (this->root == NULL)
	{
		this->root = new Node<T>(value);
		return true;
	}
	Node<T>* node = this->root;

	while (node != NULL)
	{
		if (value < node->value)
		{
			Node<T>* left = node->GetLeft();
			if (left != NULL)
			{
				node = left;
			}
			else
			{
				node->SetLeft(new Node<T>(value));
				return true;
			}
		}
		else if (!(value == node->value))
		{
			Node<T>* right = node->GetRight();
			if (right != NULL)
			{
				node = right;
			}
			else
			{
				node->SetRight(new Node<T>(value));
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}

template<class T>
T* Tree<T>::Search(T value)
{
	Node<T>* node = this->root;
	while (node != NULL)
	{
		T nodeValue = node->value;
		if (value < nodeValue)
		{
			node = node->GetLeft();
		}
		else if (!(value == nodeValue))
		{
			node = node->GetRight();
		}
		else
		{
			return &(node->value);
		}
	}
	return NULL;
}

template<class T>
T* Tree<T>::Remove(Node<T>*& node, T value)
{
	T* result;
	if (node == NULL)
	{
		return NULL;
	}
	T nodeValue = node->value;
	if (value < nodeValue)
	{
		Remove(node->GetLeft(), value);
	}
	else if (!(value == nodeValue))
	{
		Remove(node->GetRight(), value);
	}
	else
	{
		result = &node->value;
		if (node->GetRight() != NULL)
		{
			node = FindLeftMostNode(node->GetRight());
		}
		else if (node->GetLeft() != NULL)
		{
			node = node->GetLeft();
		}
		else
		{
			node = NULL;
		}
		return result;

	}
}

template<class T>
T* Tree<T>::RemoveIt(T value)
{
	return Remove(this->root, value);
}


template<class T>
Node<T>* Tree<T>::BuildTree(DynamicArray<T>& sortedList, int start, int end)
{
	if (start > end)
		return NULL;

	int mid = (start + end) / 2;

	Node<T>* left = BuildTree(sortedList, start, mid - 1);
	Node<T>* root = new Node<T>(sortedList.GetElement(i));
	i++;
	Node<T>* right = BuildTree(sortedList, mid + 1, end);

	root->SetLeft(left);
	root->SetRight(right);

	return root;
}

template <class T>
Node<T>* Tree<T>::FindLeftMostNode(Node<T>*& root)
{

	if (root->GetLeft() == NULL)
	{
		return root;
	}
	FindLeftMostNode(root->GetLeft());

}
