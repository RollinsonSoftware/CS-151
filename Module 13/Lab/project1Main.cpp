/*
File name: project1Main.cpp

Purpose/Problem:
Write a function that accepts an integer parameter and returns its integer 
square root (if it exists).  The function should throw an exception if it is passed an 
integer that is not a perfect square. 

Do not handle the exception in the function, but instead create the exception 
handler in main. 

Make the exception a new exception class which your program creates.

Demonstrate the function with a driver program that passes the function the numbers 
0 through 25, then prints whether or not the number is a perfect square.  (A "perfect 
square" is a whole number whose square root is also a whole number.)

Author: John Rollinson, CS151

Module #: 13
Lab #: 1
*/

//Header Files
#include <iostream>
#include <math.h>

using namespace std;

void root(int x);

struct ArithmeticException : public std::exception
{
	const char *errorMessage() const throw ()
    {
    	return " DOES NOT have a perfect square";
    }
};
int main(int argc, char** argv) 
{
	for(int i = 0 ; i < 26; i++)
	{
		root(i);
	}
	
	system("pause");
	return 0;
}
void root(int x)
{
 	cout << x;
	try
	{	
		if(sqrt(x) != (int)sqrt(x))
		{
			throw ArithmeticException();
		}
		cout<< " DOES have a perfect square " <<endl;
	}
	catch(ArithmeticException& e)
	{
		cout << e.errorMessage() << endl;
	}
}
