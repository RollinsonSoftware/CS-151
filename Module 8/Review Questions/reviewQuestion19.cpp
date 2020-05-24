/*
Author: John Rollinson

Review Question #19 Module 8:

This function takes a nonempty string as a parameter and returns the last char
in the string.
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

char lastChar(const char *str);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Initial size of the cstring, make larger for sentences.
//set to 20 for testing short phrases and single words.
const int SIZE = 20;

int main(int argc, char** argv) 
{
	char cString[SIZE], finalChar;
	
	//Prompt the user for input.
	cout << "Please enter a string: ";
	cin.getline(cString, SIZE);
	
	//Testing the function that takes a cstring as the only arguement
	//Returns the last char in the cstring.
	finalChar = lastChar(cString);
	cout << "The last character of the string is: " << finalChar << endl;
	
	system("pause");
	return 0;
}

char lastChar(const char *str)
{
	//Find the length of the string first.
	int length = strlen(str);
	
	//Final char is stored in the n-1 index.
	return str[length - 1];
}
