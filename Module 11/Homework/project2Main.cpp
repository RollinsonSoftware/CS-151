/*
File name: project2Main.cpp

Purpose/Problem:
Write a recursive Boolean function named isMember. The function should 
accept three parameters: an array of integers, an integer indicating the 
number of elements in the array, and an integer value to be searched for. 
The function should return true if the value is found in the array or false 
if the value is not found. Demonstrate the use of the function in a program 
that asks the user to enter an array of numbers and a value to be searched for.

Author: John Rollinson, CS151

Module #: 11
Homework #: 2

Algorithm:
Prompt user for the size of the array.
loop for input from the user to fill the array.
loop for input from the user for search values to check for in the array.
read input as string and parse to integer, if they type the stop code then exit
	the program.
if given a search value then check if its in the array with isMember function
output accordingly if the number was found in the array or not to the console.
*/

//Header Files
#include <iostream>
#include <array>
#include <string>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") 
or input loop */

//Prototypes
bool isMember(int array[], int size, int search);

int main(int argc, char** argv) 
{
	string input;
	int size, search;
	
	cout << "Enter how many values you would like to use: ";
	cin >> size;
	
	int user[size];
	
	for(int i = 0; i < size; i++)
	{
		cout << "Enter an integer: ";
		cin >> user[i];
	}
	
	while(true)
	{
		cout << "Enter a number to search for, type \"exit\" to quit: ";
		cin >> input;
		
		if(input == "exit")
		{
			break;
		}
		else
		{
			search = stoi(input);
			
			if(isMember(user, sizeof(user)/sizeof(user[0]), search))
			{
				cout << "The number " << search << " IS in the array." << endl << endl;
			}
			else
			{
				cout << "The number " << search << " IS NOT in the array." << endl << endl;
			}	
		}
	}
	system("pause");
	return 0;
}
/*
Reads in an array of integers, the size of the array, and a value to search for in the array
as parameters.
Returns true if the value passed as an argument was found, and false otherwise.
*/
bool isMember(int array[], int size, int search)
{
	if(array[size - 1] == search)
	{
		return true;
	}
	else if((size - 1) == 0)
	{
		return false;
	}
	else
	{
		//cout << "Index: " << array[size - 1] << " |Search: " << search << " |Size: " << size - 1 << endl;
		return isMember(array, size - 1, search);
	}
}
