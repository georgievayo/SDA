/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Yoana Georgieva
* @idnumber 61920
* @task 1
* @compiler VC
*
*/

//#include"stdafx.h"
#include "Operator.h"

Operator::Operator()
{}

Operator::Operator(char s, char o)
{
	this->symbol = s;
	this->op = o;
}

char Operator::GetOperator()
{
	return this->op;
}

char Operator::GetSymbol()
{
	return this->symbol;
}
