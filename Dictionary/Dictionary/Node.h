#pragma once
#include <vector>

using namespace std;

class Node
{
public:
	Node();
	Node(string word, double mark);
	~Node();
	void SetMark(double m);
	double GetMark();
	string GetData();
	vector<Node*> GetChildren();
	void AddChild(Node* c);
	Node* SearchChild(string child);
	void PrintChildren();

private:
	string data;
	double mark;
	vector<Node*> children;
};

