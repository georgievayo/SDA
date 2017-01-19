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

#include "Pair.h"

Pair::Pair()
{

}

Pair::Pair(const int& key,const string& data)
{
	this->key = key;
	this->data.push_back(data);
}


void Pair::AddData(const string& data)
{
	this->data.push_back(data);
}

bool Pair::RemoveData(const string& data)
{
	for (size_t i = 0; i < this->data.size(); i++)
	{
		if (this->data[i] == data)
		{
			this->data.erase(this->data.begin() + i);
			return true;
		}
	}
	return false;
}

bool Pair::Contains(const string & data)
{
	for (size_t i = 0; i < this->data.size(); i++)
	{
		if (this->data[i] == data)
		{
			return true;
		}
	}
	return false;
}

int Pair::GetKey()
{
	return this->key;
}

vector<string> Pair::GetData()
{
	return this->data;
}

bool Pair::operator<(const Pair& other)
{
	return this->key < other.key;
}

bool Pair::operator== (const Pair& other)
{
	return this->key == other.key;
}
