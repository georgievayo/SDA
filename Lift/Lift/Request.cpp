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


#include "Request.h"

Request::Request()
{
}

Request::Request(string dir, int floor, double time)
{
	this->dir = dir;
	this->floor = floor;
	this->time = time;
}

void Request::operator=(Request const & other)
{
	this->dir = other.dir;
	this->floor = other.floor;
	this->time = other.time;
}

string Request::GetDir()
{
	return this->dir;
}

int Request::GetFloor()
{
	return this->floor;
}

double Request::GetTime()
{
	return this->time;
}
