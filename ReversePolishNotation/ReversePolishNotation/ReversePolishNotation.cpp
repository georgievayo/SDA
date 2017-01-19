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


//#include "stdafx.h"
#include"Stack.h"
#include"Stack.cpp"
#include"Operator.h"
#include"DynamicArray.h"
#include"DynamicArray.cpp"
#include<iostream>
#include<string>
#include<math.h>
#include<fstream>

using namespace std;


// Function that checks if a character is a digit
bool isDigit(char item)
{
	return (int)item >= 48 && (int)item <= 57;
}

// Function that checks if a character is an operator
bool isOperator(char item, DynamicArray<Operator> &operationsFromFile)
{
	for (unsigned int i = 0; i <= operationsFromFile.GetUsedElements(); i++)
	{
		if (operationsFromFile.GetElement(i).GetSymbol() == item)
		{
			return true;
		}
	}
	return false;
}

// Function that finds a number in string with start position
double FindNumber(string str, int start)
{
	string num = "\0";
	double number = 0;
	int index = start;
	while (isDigit(str[index]))
	{
		num += str[index];
		index++;
	}
	for (unsigned int i = 0; i < num.length(); i++)
	{
		number += pow(10, (num.length() - i - 1)) * ((int)num[i] - 48);
	}
	return number;
}

// Function that finds a number in string with start position which holds the last digit of number
double FindNumberToCalculate(string str, int start)
{
	double number = 0;
	int index = start;
	int power = 0;
	while (isDigit(str[index]))
	{
		number += pow(10, power) * ((int)str[index] - 48);
		power++;
		index--;
	}
	if (str[index] == '-')
	{
		return -number;
	}
	else
	{
		return number;
	}
}

// Function that receives a symbol and return the sign of an operator
char FindOperation(char symbol, DynamicArray<Operator> &operationsFromFile)
{
	for (unsigned int i = 0; i < operationsFromFile.GetUsedElements(); i++)
	{
		if (operationsFromFile.GetElement(i).GetSymbol() == symbol)
		{
			return operationsFromFile.GetElement(i).GetOperator();
		}
	}
}


//Function that counts digits of a number
int FindNumberOfDigits(int num)
{
	int digits = 0;
	while (num)
	{
		num /= 10;
		digits++;
	}
	return digits;
}


// Function that receives two operands and operation and calculates an expression
double Calculate(double operand1, double operand2, char operation, DynamicArray<Operator>&operationsFromFile)
{

	switch (FindOperation(operation, operationsFromFile))
	{
	case'+': return operand1 + operand2;
	case'-': return operand1 - operand2;
	case'*': return operand1 * operand2;
	case'/': return operand1 / operand2;
	}

}


// Function that reverses the prefix to postfix
void FromPrefixToPostfix(Stack<double>&operands, Stack<char>&operators, string &input, DynamicArray<Operator>&operationsFromFile)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '-' && isDigit(input[i + 1])) // checks for a negative number
		{
			operands.Push(-FindNumber(input, i + 1));
			cout << operands.Peek() << " ";
			if (operands.GetAllocated() >= 2 && operators.GetAllocated() > 0)
			{
				cout << operators.Pop() << " ";
				operands.Pop();
				operands.Pop();
			}
			else
			{
				cout << "Error" << endl; // incorrect prefix
				return;
			}
			i += FindNumberOfDigits(FindNumber(input, i + 1));
		}

		else if (isDigit(input[i])) // checks for a positive number
		{
			operands.Push(FindNumber(input, i));
			cout << operands.Peek() << " ";
			if (operands.GetAllocated() >= 2 && operators.GetAllocated() > 0)
			{
				cout << operators.Pop() << " ";
				operands.Pop();
				operands.Pop();
			}
			else
			{
				cout << "Error" << endl; // incorrect prefix
				return;
			}
			i += (FindNumberOfDigits(FindNumber(input, i)) - 1);
		}
		else if (isOperator(input[i], operationsFromFile)) // checks for an operator
		{
			operators.Push(input[i]);
		}
	}

	while (!operators.isEmpty()) // prints all operators in the stack
	{
		cout << operators.Pop() << " ";
	}

}

double CalculatePrefix(Stack<double>&operands, Stack<char>&operators, string &input, DynamicArray<Operator>&operationsFromFile)
{
	for (int i = input.length() - 1; i >= 0; i--)
	{
		if (isOperator(input[i], operationsFromFile))
		{
			operators.Push(input[i]);
			if (operands.GetAllocated() > 1)
			{
				int op1 = operands.Pop();
				int op2 = operands.Pop();
				int newOperand = Calculate(op1, op2, operators.Pop(), operationsFromFile);
				operands.Push(newOperand);
			}
		}
		else if (isDigit(input[i]))
		{
			operands.Push(FindNumberToCalculate(input, i));
			if (operands.Peek() < 0)
			{
				i -= FindNumberOfDigits(FindNumberToCalculate(input, i)) + 1;
			}
			else
			{
				i -= FindNumberOfDigits(FindNumberToCalculate(input, i));
			}

		}
	}
	return (operands.Peek() * 100000 + 0.5) / 100000; // returns calculated prefix with 5 decimal places 
}

// Function that validate the prefix
bool ValidatePrefix(string &prefix, DynamicArray<Operator> &operationsFromFile)
{
	bool flag = false;
	for (unsigned int i = 0; i < prefix.length(); i++)
	{
		bool flag = false;
		if (!isDigit(prefix[i]) && prefix[i] != ' ' && prefix[i] != '-')
		{
			for (unsigned int j = 0; j < operationsFromFile.GetUsedElements(); j++)
			{
				if (prefix[i] == operationsFromFile.GetElement(j).GetSymbol())
				{
					flag = true;
				}
			}
			if (flag == false)
			{
				return flag;
			}
		}

	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Stack<double> stackOperands = Stack<double>();
	Stack<char> stackOperators = Stack<char>();

	string prefix;
	DynamicArray<Operator> operationsFromFile = DynamicArray<Operator>();

	if (argc > 0)
	{
		ifstream firstFile;
		firstFile.open(argv[1]);
		if (firstFile.is_open())
		{
			getline(firstFile, prefix);
		}
		else
		{
			cout << "The file is not opened." << endl;
		}
		firstFile.close();

		ifstream secondFile;
		secondFile.open(argv[2]);
		string line;
		if (secondFile.is_open())
		{
			while (!secondFile.eof())
			{
				getline(secondFile, line);
				operationsFromFile.Add(Operator(line[0], line[2]));
			}
		}
		else
		{
			cout << "The file is not opened." << endl;
		}
		secondFile.close();
	}


	if (ValidatePrefix(prefix, operationsFromFile))
	{
		FromPrefixToPostfix(stackOperands, stackOperators, prefix, operationsFromFile);
		cout << endl;
		cout << CalculatePrefix(stackOperands, stackOperators, prefix, operationsFromFile) << endl;
	}
	else
	{
		cout << "Error" << endl;
	}


	system("pause");
	return 0;
}

