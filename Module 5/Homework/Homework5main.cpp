/*
File name: Homework5main.cpp

Purpose/Problem:
Design a class Numbers that can be used to translate whole dollar amounts in the range 
of 0 through 9999 into an English description of the number. For example, the number 
713 would be translated into the string "seven hundred thirteen", and 8203 would be 
translated into "eight thousand two hundred three".
The class should have a single integer member variable:

  int number ;  
and a collection of static string members that specify how to translate dollar amounts 
amounts into the desired string format. (Should they also be constants?)

For example, you might use static strings such as:

  string lessThan20[ ] = "
            zero", "one", ..., " eighteen", "nineteen" } ;
  string hundred = "hundred" ;
  string thousand = "thousand" ;
The class should have a constructor that accepts a non-negative integer and uses it to 
initialize the Numbers object.

It also should have a member function print() that prints the English description of 
the Numbers object.

Demonstrate the class by writing a main program the asks the user to enter a number 
in the proper range and then prints out its English description on the console.

Author: John Rollinson, CS151

Module #: 5
Homework #: 1

Algorithm:
define 2 string arrays
1 for numbers less than 20
1 for each of the "10s" less than 100
define 2 string variables for 100 and 1000
With in the Numbers class deffinition, and print() definition:
while the number given by the user is greater than 0
first check for the 1000s place, set number = number mod 1000
then check for the 100s place, set number = number mod 100
finally check if the number is greater than 20 or less than 20
after each check concadinate the string accordingly, print it.
if a number is negative stop the program.
in the main function, read in a number from the user between 0-9999
pass it to the print function, and display the number in word format to the user.
*/
#include <iostream>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//class declaration:
class Numbers
{
	private:
		int number;
		static string lessThan20[20];
		static string hundred;
		static string thousand;
		static string tens[8];
		
	public:
		//constructor
		Numbers(int n)
		{
			//check for negative values
			if(n < 0)
			{
				cout << "Error, negative numbers are not accepted!\nNow Terminating!" << endl;
				exit(0);
			}
			else
			{
				number = n;
			}
		}
		void print()
		{
			//continue until remainder is greater than 0
			while(number > 0)
			{
				//check for thousands and print accordingly
				if((number / 1000) > 0)
				{
					cout << lessThan20[number / 1000] << " " << thousand << " ";
					
					//update number to have the remainder of the division.
					number = number % 1000;
				}
				//check for hundreds
				else if((number / 100) > 0)
				{
					cout << lessThan20[number / 100] << " " << hundred << " ";
					//update number to have the remainder of the division.
					number = number % 100;
				}
				//check if remainder until now is greater or equal to 20.
				else if(number >= 20)
				{
					//e.g, twenty is index 0
					cout << tens[(number / 10) - 2] << " ";
					//update number to have the remainder of the division.
					number = number % 10;
				}
				//print number is less than 20.
				else
				{
					cout << lessThan20[number];
					//break from loop beacuse we have printed everything now.
					break;
				}
			}
		}
};

//define static variables:
string Numbers::lessThan20[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
									"nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
									"sixteen", "seventeen", "eighteen", "nineteen"};
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";
string Numbers::tens[8] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main(int argc, char** argv) 
{
	//variable to store user input, prompt then read
	int userInput;
	
	cout << "Please enter a number between 0 - 9999: ";
	cin >> userInput;
	
	//create a Numbers object with the input from the user
	Numbers num(userInput);
	
	//print the string version of the number
	num.print();
	
	return 0;
}
