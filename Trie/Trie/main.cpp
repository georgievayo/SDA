#include<iostream>
#include"Trie.h"
using namespace std;

int main()
{
	Trie dict;
	Node* parent = dict.AddAsRootChild("typo", 15);
	dict.AddWord("mnogo", 14, parent);
	cout << dict.FindWord("typo", dict.GetRoot())->GetMark();
	system("pause");
	return 0;
}