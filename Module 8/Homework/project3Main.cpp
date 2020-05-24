/*
File name: project3Main.cpp

Purpose/Problem:
Write a program that has an array of at least 10 string objects that hold people's names and phone numbers.  Use the following:

"Hoshikawa Tanaka, 678-1223"
"Joe Looney, 586-0097"
"Geri Palmer, 223-8787"
"Lynn Lopez, 887-1212"
"Holly Gaddis, 223-8878"
"Julio Reyes, 486-0998"
"Bob Kain 586-8712"
"Jacques Franc, 586-7676"
"Warren Glover, 223-9037"
"Jeane Rodriquez, 678-4939"
"Ron Palmer, 486-2783"

The program should ask the user to enter a name or partial name to search for in the array.  Any entries in the array that match the string entered should be displayed.  For example if the user enters "Palmer", the program should display the following names:

Geri Palmer, 223-8787
Ron Palmer, 486-2783

Demonstrate the function in a program that asks the user to input a string and 
then passes it to the function.  The number of words in the string should be 
displayed on the screen.

Author: John Rollinson, CS151

Module #: 8
Homework #: 3

Algorithm:
Initialize the contact list as an array of cstrings.
Initialize another cstring array to keep track of the search phrase or word,
A pointer that points to a match found in the contact list,
An int to keep track of the index being accessed in the contact list,
and finally a bool variable to keep track of whether or not another match
was previously found.
Loop for user input, if they enter 0 exit the program
else loop through the contacts list
for each index redeclare the pointer, if the pointer reference is not NULL
then a match has been found, if it is NULL the whole contact list was searched
and no match was found.
Allows for multiple test cases, reset the tracker variables after each iteration.
*/

//Header Files
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <array>

using namespace std;

/* run this program using the console pauser or add your own getch, 
system("pause") or input loop */

//Constants
const int NUM_CONTACTS = 11, //Number of contacts in the address book
		  STRING_LENGTH = 100; //String length for each contact entry in the address book.

int main(int argc, char** argv) 
{
	//Data set:
	char phoneList[NUM_CONTACTS][STRING_LENGTH] = {
									"Becky Warren, 678-1223",
									"Joe Looney, 586-0097",
									"Geri Palmer, 223-8787",
									"Lynn Presnell, 887-1212",
									"Holly Gaddis 223-8878",
									"Sam Wiggins, 486-0998",
									"Bob Kain, 586-7676",
									"Tim Haynes, 586-7676",
									"Warren Gaddies, 223-9037",
									"Jean James, 678-4939",
									"Ron Palmer, 486-2783"};	
	while(true)
	{
		//Variables:			
		//Array to contain search term, and a point that points to a matching 
		//string in the contact list.					
		char lookUp[STRING_LENGTH], *strPtr = NULL; 
		//Keeps track of the index of the contact list.
		int index = 0;
		//Keeps track of if a match has already been found in another iteration.
		bool found = false; 
		
		//Get input:
		cout << "Enter name to search (0 to exit): ";
		cin.getline(lookUp, STRING_LENGTH); //string to search for.
		
		if(lookUp[0] == '0')
		{
			break; //End program
		}
		else
		{
			//Search for the given string
			for(index; index < NUM_CONTACTS; index++)
			{
				strPtr = strstr(phoneList[index], lookUp);
				if(strPtr != NULL)
				{
					cout << phoneList[index] << endl; //Match found!
					found = true; //one or more matches have already been found.
				}		
			}
			if(!found) //No match found.
			{
				cout << "No one in your contacts matched the search criteria." << endl;
			}	
		}	
	}
	system("pause");
	return 0;
}
