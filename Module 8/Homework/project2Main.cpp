/*
File name: project2Main.cpp

Purpose/Problem:
Imagine you are developing a software package that requires users to enter 
their own passwords.  Your software requires that user's passwords meet the 
following criteria:

the passwords should be at least six characters long
the passwords should contains at least one uppercase and at least one lowercase 
letter
the password should have at least one digit

Write a program that asks for a password and then verifies that it meets the 
stated criteria.  if it doesn't, then the program should display a message 
telling the user why.  If it does, then the program should tell the user that 
the password has been accepted.

Author: John Rollinson, CS151

Module #: 8
Homework #: 2

Algorithm:
Loop for input from the user to test multiple passwords, set 0 as the exit value.
Verify the given password with the isValid() function call.

When checking the password in the isValid() function, first check the length of the
given password string is greater than or equal to 6.
Then loop through the char array and check for any detections of a lower case, upper
case, or numerical value.
Update boolean tracker variables accordingly. 
For each missing requirement display a message saying what they are missing.
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
bool isValid(char []);

//Constants
const int INITIAL_LENGTH = 30;

int main(int argc, char** argv) 
{
	char password[INITIAL_LENGTH];
	
	cout << "Your password must meet the following conditions:\n" <<
			"- The password should be at least six characters long.\n" <<
			"- The passwords should contain at least one uppercase and at least one lowercase letter.\n" <<
			"- The password should have at least one digit." << endl;
	
	while(true)
	{
		//Reading user input
		cout << "\nEnter a password (0 to exit): ";
		cin.getline(password, INITIAL_LENGTH);
			
		if(password[0] == '0')
		{
			break;
		}
		else
		{
			isValid(password);
		}
	}
	system("pause"); 
	return 0;
}

//Checks for a valid password string, returns true if valid, false otherwise.
bool isValid(char *password)
{
	bool lower = false;
	bool upper = false;
	bool digit = false;
	int size = strlen(password);
	
	for(int i = 0; i < size; i++)
	{
		if((int)password[i] > 64 && (int)password[i] < 91) //upper case has been found.
		{
			upper = true;
		}
		else if((int)password[i] > 96 && (int)password[i] < 123) //lower case has been found.
		{
			lower = true;
		}
		else if((int)password[i] > 47 && (int)password[i] < 57) //number has been found.
		{
			digit = true;
		}
		else
		{
			//special char found, can define later if this should be allowed, not specified in assignment.
		}
	}
	//Output:
	if(size < 6)
	{
		cout << "Your password must be at least 6 characters long." << endl;
	}
	if(!upper)
	{
		cout << "Your password must contain at least 1 upper case letter." << endl;
	}
	if(!lower)
	{
		cout << "Your password must contain at least 1 lower case letter." << endl;
	}
	if(!digit)
	{
		cout << "Your password must contain at least 1 numerical digit." << endl;
	}
	if(lower && upper && digit)
	{
		cout << "Congratulations your password has been accepted: " << password << endl;
		return true;
	}
	return false;
}
