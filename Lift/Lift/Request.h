/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Yoana Georgieva
* @idnumber 61920
* @task 2
* @compiler VC
*
*/

#pragma once
#ifndef REQUEST_H
#define REQUEST_H

#include<iostream>

using namespace std;


class Request
{
public:

	//Default constructor
	Request();

	//Overloaded construcor with three parameters to set all values of request
	Request(string dir, int floor, double time);

	//Overloaded operator =
	void operator=(Request const & other);

	//Function that gets directory of request
	string GetDir();

	//Function that gets floor of request
	int GetFloor();

	//Function that gets time of request
	double GetTime();

private:
	string dir;
	int floor;
	double time;
};

#endif