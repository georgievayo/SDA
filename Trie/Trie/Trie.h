#pragma once
#include"Node.h"
class Trie
{
public:
	Trie();
	~Trie();
	Node* GetRoot();
	Node* AddAsRootChild(string word, double mark);
	Node* AddWord(string word, double mark, Node* parent);
	Node* FindWord(string word, Node* parent);
	//bool ContainsWord(string word);

private:
	Node* root;
};

