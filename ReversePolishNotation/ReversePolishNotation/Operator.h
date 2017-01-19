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


// Class Operator that represents operators with their symbol and sign

#pragma once
#ifndef OPERATOR_H
#define OPERATOR_H

class Operator
{
private:
	char symbol;
	char op;

public:

	//Default constructor
	Operator();

	// Overloaded constructor
	Operator(char s, char o);

	//Function that gets the symbol of the operator
	char GetSymbol();

	//Function that gets the sign of the operator
	char GetOperator();
};
#endif // OPERATOR_H
