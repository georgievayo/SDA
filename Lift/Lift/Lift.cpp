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

#include"Queue.h"
#include"Queue.cpp"
#include"Request.h"
#include"DynamicArray.h"
#include<iostream>
#include<math.h>
#include<string>
#include<fstream>
#include <cmath>

using namespace std;

//Function that gets the direction of request read from file as string
string GetDirection(string &input)
{
	if (input[0] == 'c')
	{
		if (input[5] == 'u' && input[6] == 'p')
		{
			return "up";
		}
		else
		{
			return "down";
		}
	}
	else
	{
		return "";
	}
}

//Function that gets the floor of request read from file as string
int GetFloor(string &input)
{
	string floor;
	int counter = 0;
	int numberOfFloor = 0;
	if (input[0] == 'g')
	{
		int index = 3;
		while (input[index] != ' ')
		{
			floor += input[index];
			index++;
		}
		return stoi(floor);
	}

	else
	{
		for (size_t i = 0; i < input.length(); i++)
		{
			if (counter == 2)
			{
				int index = i;
				while (input[index] != ' ')
				{
					floor += input[index];
					index++;
				}
			}

			if (input[i] == ' ')
			{
				counter++;
			}
		}
	}
	return stoi(floor);
}

//Function that gets the time of request read from file as string
double GetTime(string &input)
{
	int counter = 0;
	string time;
	if (input[0] == 'c')
	{
		for (size_t i = 0; i < input.length(); i++)
		{
			if (counter == 3)
			{
				time += input[i];
			}

			if (input[i] == ' ')
			{
				counter++;
			}
		}
	}
	else
	{
		for (size_t i = 0; i < input.length(); i++)
		{
			if (counter == 2)
			{
				time += input[i];
			}

			if (input[i] == ' ')
			{
				counter++;
			}
		}
	}
	return stod(time);
}

//Function that gets request read from file as string
Request GetRequest(string &input)
{
	Request request;
	//if the request is call
	if (input[0] == 'c')
	{
		request = Request(GetDirection(input), GetFloor(input), GetTime(input));
	}
	//if the request is go
	else if (input[0] == 'g')
	{
		request = Request("", GetFloor(input), GetTime(input));
	}

	return request;
}

//Function that gets current direction
string GetCurrentDirection(int &currentFloor, Request r)
{
	if (r.GetFloor() > currentFloor)
	{
		return "up";
	}
	else
	{
		return "down";
	}
}

int main(int argc, char** argv)
{
	int n;
	int k;
	const int secondsPerFloor = 5;
	string input;
	double time = 0;
	int currentFloor = 1;
	string currentDir = "up";

	ifstream file(argv[1]);
	getline(file,input,' ');
	n = stoi(input);
	getline(file, input);
	k = stoi(input);

	DynamicArray inputRequests = DynamicArray(k);
	Queue<Request> orderedRequests = Queue<Request>(k);

	while (getline(file, input))
	{
		inputRequests.Add(GetRequest(input));
	}

	time = inputRequests.GetElement(0).GetTime();
	bool* elementsUsed = new bool[k];
	for (int i = 0; i < k; i++)
	{
		elementsUsed[i] = false;
	}

	for (int i = 0; i < k; i++)
	{
		if (!elementsUsed[i])
		{
			Request currentElement = inputRequests.GetElement(i);
			DynamicArray toBeExecuted = DynamicArray();

			elementsUsed[i] = true;
			toBeExecuted.Add(currentElement);

			if (currentElement.GetFloor() > currentFloor)
			{
				currentDir = "up";
			}
			else
			{
				currentDir = "down";
			}

			if (i < k - 1)
			{
				for (int j = i + 1; j < k; j++)
				{
					if (elementsUsed[j])
					{
						continue;
					}

					Request candidateElement = inputRequests.GetElement(j);
					if (currentDir == "up")
					{
						if (candidateElement.GetFloor() <= currentElement.GetFloor() &&
							candidateElement.GetFloor() >= currentFloor &&
							(candidateElement.GetTime() - time) / 5 + currentFloor <= candidateElement.GetFloor())
						{
							elementsUsed[j] = true;
							toBeExecuted.Add(candidateElement);
						}
					}
					else
					{
						if (candidateElement.GetFloor() >= currentElement.GetFloor() &&
							candidateElement.GetFloor() <= currentFloor &&
							(abs(candidateElement.GetTime() - time) / 5 + candidateElement.GetFloor() >= currentFloor || candidateElement.GetTime() < time))
						{
							elementsUsed[j] = true;
							toBeExecuted.Add(candidateElement);
						}

					}
				}
			}
			time += (currentElement.GetFloor() - 1) * 5;
			currentFloor = currentElement.GetFloor();
			toBeExecuted.Sort();

			for (int w = 0; w < toBeExecuted.GetUsedElements(); w++)
			{
				if (w == 0)
				{
					orderedRequests.Enqueue(toBeExecuted.GetElement(w));
				}

				if (w > 0 && toBeExecuted.GetElement(w - 1).GetFloor() != toBeExecuted.GetElement(w).GetFloor())
				{
					orderedRequests.Enqueue(toBeExecuted.GetElement(w));
				}
			}
		}
	}

	time = inputRequests.GetElement(0).GetTime();
	currentFloor = 1;
	
	while (!orderedRequests.isEmpty())
	{
		cout << time + abs((orderedRequests.GetHead().GetFloor() - currentFloor)) * 5 << " " << orderedRequests.GetHead().GetFloor() << " " << GetCurrentDirection(currentFloor, orderedRequests.GetHead()) << endl;
		time = time + abs((orderedRequests.GetHead().GetFloor() - currentFloor)) * 5;
		currentFloor = orderedRequests.GetHead().GetFloor();
		orderedRequests.Dequeue();
	}

	return 0;
}

