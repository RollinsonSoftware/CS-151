/*
File name: project1Main.cpp

Purpose/Problem:
Write a class BCheckString that is derived from the STL string class. 
This new class will have two member functions:

A BCheckString (string s) constructor that receives a string object passed 
by value and passes it on to the base class constructor.
A char operator [ ] (int k) function that throws a BoundsException object 
if k is negative or is greater than or equal to the length of the string. 
If k is within the bounds of the string, this function will return the character 
at position k in the string.
Write the definition of the BoundsException class. Test your class with a main 
function that attempts to access characters that are within and outside the bounds 
of a suitably initialized BCheckString object.

Author: John Rollinson, CS151

Module #: 13
Homework #: 1

Algorithm:
Create a BCheckString object and intialize it.
Access an index with-in bounds.
Attempt to access an index out of bounds.
Throw a BoundsException.
*/

//Header Files
#include <iostream>
#include <string>
#include "BoundsException.h"

using namespace std;

class BCheckString : string
{
	public:
		BCheckString(string s) : string(s)
		{
			
		}
		char operator[](int k)
		{
			if(k < 0 || k >= this->length())
			{
				throw BoundsException(1);
			}
			return this->at(k);
		}
};

int main(int argc, char** argv) 
{
	BCheckString object("JOHNROLLINSON");
	
	try
	{
		cout << "Testing inside the bounds with object[4]: ";
		cout << object[4] << endl;
		
		cout << "\nTesting outside the bounds with object[22]: " << endl;
		cout << object[22] << endl;
	}
	catch(BoundsException())
	{
		
	}
	system("pause");
	return 0;
}
