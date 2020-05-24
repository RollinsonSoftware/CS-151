/*
File name: project1Main.cpp

Purpose/Problem:
Write a function that accepts a C-string as an argument and returns 
the number of words contains in the string.  For instance, if the string 
argument is "Four score and seven years ago", the function should return the 
number 6.  

Demonstrate the function in a program that asks the user to input a string and 
then passes it to the function.  The number of words in the string should be 
displayed on the screen.

Author: John Rollinson, CS151

Module #: 8
Homework #: 1

Algorithm:
Loop for strings from the user, strings can not be larger than 50 chars.
Using the numWordsIn() function, the program checks for the number of the words
in the given string.
The function checks the first char in the c-string for letters.
	This is to make sure it is not counting numbers, special chars, or just a blank
	space as whole words in the string.
This also ensures it still works for words like I, and a.
If the first char is valid then loop for number of spaces in the string.
Adding 1 to this will give the number of words in a sentence.
Finally display to the consol how many words were found in the given c-string
from the user.
*/

//Header Files
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

/* run this program using the console pauser or add your own getch, 
system("pause") or input loop */

//Prototypes
void numWordsIn(char []);

//Constants
const int INITIAL_LENGTH = 50;

int main(int argc, char** argv) 
{
	char userInput[INITIAL_LENGTH];
	
	while(true)
	{
		//Reading user input
		cout << "Enter a string (0 to exit): ";
		cin.getline(userInput, INITIAL_LENGTH);
			
		if(userInput[0] == '0')
		{
			break;
		}
		else
		{
			numWordsIn(userInput);
		}
	}
	system("pause"); 
	return 0;
}

/*
Reads a c-string (char array) and returns as output 
the number of words contained in the c-string.
*/
void numWordsIn(char *charArray)
{
	//length of the string from the user.
	int size = strlen(charArray);
	//Keeps track of the number of words.
	int words = 1;
	
	//Checking first char for any special chars or spaces
	if(((int)charArray[0] > 64 && (int)charArray[0] < 91 ) || //lower case
	   ((int)charArray[0] > 96 && (int)charArray[0] < 123))   //upper case
	{
		for(int i = 0; i <= size; i++)
		{
			//Checking for the space char using the ASCII value 32.
			if((int)charArray[i] == 32)
			{
				words++;
			}
		}	
	}
	else
	{
		words = 0;
	}
	//Displaying the output to the user
	cout << "Total # of words in the sentence: " << words << endl << endl;
}
