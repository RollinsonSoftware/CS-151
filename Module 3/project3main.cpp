/*
File name: project3main.cpp

Purpose/Problem:
In statistics, the mode of a set of values is the value that occurs most often.  
Write a program that determines how many pieces of pie most people eat in a year.  
Set up a dynamically-allocated integer array that can hold responses from 30 people.  
For each person enter the number of pieces they say they eat in a year.  
Then write a function that finds the mode of those 30 values (this will be the 
number of pie slices eaten by the most people).  The function that finds and returns 
the mode should accept two arguments, an array of integers, and a value indicating 
how many elements are in the array.

Author: John Rollinson, CS151

Module #: 3
Homework #: 3

Algorithm:
Read in the number of slices of pie each person ate into an array.
Sort the array from smallest values to largest values.
Find the mode by looping through the array and checking 2 indicies at
a time, keeping track of the how many time each value has come up.
compare the count to the current mode to see if a new mode has been
found on each loop iteration.
Output the results to the user. 
*/
#include <iostream>

using namespace std;

int findMode(int *, int);

int main(int argc, char** argv) 
{
	int numPeople, temp;
	
	cout << "Enter the number of people: ";
	cin >> numPeople;
	
	int slices[30];
	cout << "Enter the number of slices " << numPeople << " people ate: " << endl;
	
	for(int i = 0; i < numPeople; i++)
	{
		cin >> slices[i];
	}
	
	for(int i = 0; i < numPeople; i++)
	{
		for(int j = i + 1; j < numPeople - 1; j++)
		{
			if(slices[i] > slices[j])
			{
				//sorting the array.
				temp = slices[i];
				slices[i] = slices[j];
				slices[j] = temp;
			}
		}
	}
	
	int mode = findMode(slices, numPeople);
	cout << "Most people eat " << mode << " slices of pie." << endl;
	
	system("pause");
	return 0;
}
int findMode(int slices[], int size)
{
	//variables to keep track of the count and the mode.
	int counter, mode = 0;
	
	//loop to find the mode of an array.
	for(int i = 0; i < size; i++)
	{
		counter = 1;
		
		//if two adjacent elements equal each other.
		while(slices[i] == slices[i + 1])
		{
			counter++;
			i++;
		}
		if(counter > mode)
		{
			mode = slices[i]; //replacing mode
		}
		if(counter > 1)
		{
			i--;
		}
	}
	return mode; //returning mode
} //end of function.
