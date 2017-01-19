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
#include<vector>
using namespace std;

class Pair
{
private:
	int key;
	vector<string> data;

public:
	Pair();
	Pair(const int& key, const string& data);
	void AddData(const string& data);
	bool RemoveData(const string& data);
	bool Contains(const string& data);

	int GetKey();
	vector<string> GetData();
	bool operator< (const Pair& other);
	bool operator== (const Pair& other);
};

