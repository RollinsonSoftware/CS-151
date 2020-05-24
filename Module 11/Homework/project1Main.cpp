/*
File name: project1Main.cpp

Purpose/Problem:
Write an iterative version (using a loop instead of recursion ) of the factorial 
function shown in this chapter. Demonstrate the use of the function in a program 
that prints the factorial of a number entered by the user. Use these numbers: 0, 1, 
2, 5, 10, and 15.

Author: John Rollinson, CS151

Module #: 11
Homework #: 1

Algorithm:
Loop for strings of numbers from the user.
if it is a number then parse it to an integer value and call the factorial function.
else if they type in the stop code "exit" then the program quits.
*/

//Header Files
#include <iostream>
#include <string>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or 
input loop */

//Prototypes
int factorial(int num);

int main(int argc, char** argv)
{
	string input;
	
	while(true)
	{
		cout << "Enter a number to see its factorial, type \"exit\" to quit: ";
		cin >> input;
		
		if(input == "exit")
		{
			break;
		}
		else
		{
			factorial(stoi(input));	
		}
	}
	system("pause");
	return 0;
}
/*
Takes in a single int as an argument
Returns the factorial of that number
*/
int factorial(int num)
{
	int fact = 1;
	for(int i = 1; i <= num; i++)
	{
		fact *= i;
	}
	cout << "Factorial of " << num << " is " << fact << endl << endl;
	return fact;
}
