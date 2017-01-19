#include "Node.h"
#include<iostream>

using namespace std;

Node::Node()
{
}

Node::Node(string word, double mark)
{
	this->data = word;
	this->mark = mark;
}

Node::~Node()
{
	this->children.clear();
}

string Node::GetData()
{
	return this->data;
}

void Node::SetMark(double m)
{
	this->mark = m;
}

double Node::GetMark()
{
	return this->mark;
}

vector<Node*> Node::GetChildren()
{
	return this->children;
}


void Node::AddChild(Node* c)
{
	this->children.push_back(c);
}

Node* Node::SearchChild(string child)
{
	for (int i = 0; i < children.size(); i++)
	{
		if (children.at(i)->GetData() == child)
		{
			return children.at(i);
		}
	}

	return NULL;
}

void Node::PrintChildren()
{
	/*for (size_t i = 0; i < children.size(); i++)
	{
		cout << children[i]->GetData() << " ";
	}*/
}
