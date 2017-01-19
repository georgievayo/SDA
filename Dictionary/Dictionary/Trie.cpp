#include "Trie.h"
#include<iostream>
using namespace std;

Trie::Trie()
{
	root = new Node();
}


Trie::~Trie()
{
}

Node* Trie::GetRoot()
{
	return this->root;
}

Node* Trie::AddAsRootChild(string word, double mark)
{
	bool containsWord = false;
	for (size_t i = 0; i < root->GetChildren().size(); i++)
	{
		if (root->GetChildren()[i]->GetData() == word)
		{
			containsWord = true;
			if (mark != 0)
			{
				root->GetChildren()[i]->SetMark(mark);
			}
			return root->GetChildren()[i];
		}
	}
	if (!containsWord)
	{
		Node* newNode = new Node(word, mark);
		root->AddChild(newNode);
		return newNode;
	}
}

Node* Trie::AddWord(string word, double mark, Node* parent)
{
	bool containsWord = false;
	for (size_t i = 0; i < parent->GetChildren().size(); i++)
	{
		if (parent->GetChildren()[i]->GetData() == word)
		{
			containsWord = true;
			if (mark != 0)
			{
				parent->GetChildren()[i]->SetMark(mark);
			}
			return parent->GetChildren()[i];
		}
	}
	if (!containsWord)
	{
		Node* newNode = new Node(word, mark);
		parent->AddChild(newNode);
		return newNode;
	}
}

Node* Trie::FindWord(string word, Node* parent)
{
	if (parent->GetChildren().size() == 0)
	{
		return NULL;
	}
	for (size_t i = 0; i < parent->GetChildren().size(); i++)
	{
		if (parent->GetChildren()[i]->GetData() == word)
		{
			return parent->GetChildren()[i];
		}
	}
	return NULL;
}
