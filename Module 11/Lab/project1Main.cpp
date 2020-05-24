/*
File name: project1Main.cpp

Purpose/Problem:
Create two functions (one recursive, one iterative) which take a non-negative 
whole number (in decimal as specified in your C++ source code) and convert it 
to a string of 0’s and 1’s representing the same number in binary (base 2).

For example, define an int variable and initialize it to (decimal) 100. Your 
recursive and iterative functions, when passed this variable, should both return 
the string "1100100".

Please use only arithmetic operators such as multiplication, integer divide /, 
and the modulo % operators in this lab.  Do NOT use the pow function or a 
stringstream object to perform conversions or raise numbers to a power.

Author: John Rollinson, CS151

Module #: 11
Lab #: 1

Algorithm:
An example: To convert the decimal number 100 to a string of 0's and 1's, 
continuously take the modulo (remainder) of the number when divided by 2, 
and put those 0's and 1's together to form a string:

100 / 2 is 50, and 100 % 2 is 0
50 / 2 is 25 and 50 % 2 is 0
25 / 2 is 12 and 25 % 2 is 1
12 / 2 is 6 and 12 % 2 is 0
6 / 2 is 3 and 6 % 2 is 0
3 / 2 is 1 and 3 % 2 is 1
0 and 1 % 2 is 1

The base case is reached when the division by 2 results in a 0

The result is the modulos put together to form a string (reading up from the bottom) 1100100.

To test your program(s), print the binary string equivalents of 0’s and 1’s for the 
following decimal numbers: 0, 5, 32, 240, and 682.
*/

//Header Files
#include <iostream>
#include <string>

using namespace std;

string decimalToBinaryIter(int num)
{
	// array to store binary number
	int binaryValue[32];
  	string outValue = "";
	int count = 0;
	
	if(num == 0)
	{
		outValue = "0";
	}
	while(num > 0) 
	{
		//storing remainder in binary array
		binaryValue[count] = num % 2;
		num = num / 2;
		count++;
	}
	for (int j = count - 1; j >= 0; j--)
	{
		outValue = outValue + to_string(binaryValue[j]);
	}
	return outValue;
}
int decimalToBinaryRecur(int num)
{
	if(num == 0) 
	{
		return num;
	}
	else
	{
		return num % 2 + 10 * decimalToBinaryRecur(num / 2);
	}
}
int main()
{
	int numbers[] = {0, 5, 32, 240, 682};
	
	for(int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
	{	  
		cout << numbers[i] << " in binary is: " << decimalToBinaryIter(numbers[i]) << endl;
		cout << numbers[i] << " in binary is: " << decimalToBinaryRecur(numbers[i]) << endl;	
	}
	system("pause");
	return 0;
}
