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


#include<iostream>
#include"DynamicArray.cpp"
//#include"Tree.h"
#include"Tree.cpp"
#include"Pair.h"
#include<string>
#include<fstream>

using namespace std;

Tree<Pair> tree = Tree<Pair>();

void AddElement(string input)
{
	//parsing values from string
	int key = 0;
	string keyAsString = "";
	string data;

	int index = 4;
	while (input[index] != ' ')
	{
		keyAsString += input[index];
		index++;
	}

	key = stoi(keyAsString);

	index++;
	while (index < input.length())
	{
		data += input[index];
		index++;
	}

	//add values
	Pair pair = Pair(key, data);
	bool isAdded = tree.Add(pair);
	if (!isAdded)
	{
		Pair* existingPair = tree.Search(pair);
		existingPair->AddData(data);
	}
}

void SearchElement(string input)
{
	//parsing values from string
	int key = 0;
	string keyAsString = "";
	string data;

	int index = 7;
	while (input[index] != ' ')
	{
		keyAsString += input[index];
		index++;
	}

	key = stoi(keyAsString);

	index++;
	while (index < input.length())
	{
		data += input[index];
		index++;
	}

	//search pair and print the result
	Pair pair = Pair(key, data);
	Pair* existingPair = tree.Search(pair);

	if (existingPair != NULL)
	{
		if (existingPair->Contains(data))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	else
	{
		cout << "false" << endl;
	}
}

void RemoveElement(string input)
{
	//parsing values from string
	int key = 0;
	string keyAsString = "";
	string data;

	int index = 7;
	while (input[index] != ' ')
	{
		keyAsString += input[index];
		index++;
	}

	key = stoi(keyAsString);

	index++;
	while (index < input.length())
	{
		data += input[index];
		index++;
	}

	//remove pair and print result
	Pair pair = Pair(key, data);
	Pair* existingPair = tree.Search(pair);
	if (existingPair == NULL)
	{
		cout << "false" << endl;
		return;
	}
	else
	{
		if (existingPair->GetData().size() > 1)
		{
			existingPair->RemoveData(data);
		}
		else
		{
			tree.RemoveIt(pair);
		}
		cout << "true" << endl;
	}
}

void RemoveAll(string input)
{
	//parsing values from string
	int key = 0;
	string keyAsString = "";

	int index = 10;
	while (isdigit(input[index]))
	{
		keyAsString += input[index];
		index++;
	}

	key = stoi(keyAsString);

	//remove pair and print result
	Pair pair = Pair(key, "");
	Pair* removedPair = tree.RemoveIt(pair);
	if (removedPair != NULL)
	{
		cout << removedPair->GetData().size() << endl;
	}
	else
	{
		cout << "0" << endl;
	}

}

int main(int argc, char* argv[])
{
	DynamicArray<Pair> list = DynamicArray<Pair>();

	//Read data from binary file and add it to Dynamic Array
	ifstream reader(argv[1]);
	while (!reader.eof())
	{
		int key;
		reader.read((char*)&key, sizeof(key));

		int size = 0;
		reader.read((char*)&size, sizeof(size));

		char *buffer = new char[size + 1];
		reader.read(buffer, size);

		buffer[size] = '\0';
		if (buffer[0] != '\0')
		{
			Pair pairToAdd = Pair(key, buffer);
			Pair* existingPair = list.Contains(pairToAdd);
			if (existingPair == NULL)
			{
				list.Add(pairToAdd);
			}
			else
			{
				existingPair->AddData(buffer);
			}
		}	
	}

	//Sort dynamic array and build the tree
	list.Sort();
	tree.sortedListToBST(list);

	//Get queries from the console and execute them
	string input;
	while (getline(cin, input))
	{
		if (input[0] == 'a')
		{
			AddElement(input);
		}
		else if (input[0] == 's')
		{
			SearchElement(input);
		}
		else if (input[0] == 'r' && input[6] == ' ')
		{
			RemoveElement(input);
		}
		else if (input[0] == 'r' && input[6] == 'a')
		{
			RemoveAll(input);
		}
	}

	system("pause");
	return 0;
}

