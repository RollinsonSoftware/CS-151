/*
File name: project2Main.cpp

Purpose/Problem:
Perform the reverse of project 1, that is, create two functions (one recursive, 
the other iterative) which take a string of 0’s and 1’s, and return an int with 
its decimal equivalent.

For example, your program should take the string "1100100" as input and return an 
int with a decimal value of 100.

Please use only arithmetic operators such as addition, multiplication, integer divide 
/, and the modulo % operator in this lab.  Do NOT use the pow function or a stringstream 
object to perform conversions or to raise numbers to a power.

Author: John Rollinson, CS151

Module #: 11
Lab #: 2

Algorithm:
An example: To convert the string "1100100" to a decimal number, 
look at the following sequence:

Set the variable sum to 0.
Convert the first character in the string "1" to a number (i.e., 1) and add to sum
Multiply sum by 2 and add the second character converted a number (2 * 1 + 1 = 3)
Multiply sum by 2 and add the third character converted to a number (2 * 3 + 0 = 6)
Multiply sum by 2 and add the fourth character (2 * 6 + 0 = 12)
Multiply sum by 2 and add the fifth character (2 * 12 + 1 = 25)
Multiply sum by 2 and add the sixth character (2 * 25 + 0 = 50)
Multiply sum by 2 and add the seventh character (2 * 50 + 0 = 100)
Voila! The number in sum (100) is "1100100" converted to a decimal number.  
Notice that this is the reverse of the conversion example used in problem 1 above.

Do you see a pattern? Can you create an iterative function which converts this 
pattern into a loop? That will be your iterative solution.

For your recursive solution, use the same questions you answered above:

what is the stopping (or "base") case?
what is the recursive case?
what will your function take as its parameter(s)
what will your recursive function return?
Use the strings which you created in Project 1 as test data sets. The results 
should be the original numbers used as test data in Project 1.
*/

//Header Files
#include <iostream>
#include <string>

using namespace std;
  
int binaryToDecimalIter(string num)
{
	int decimalValue = 0;
	int base = 1; //Initializing base value to 1, i.e 2^0
	  
	int temp = stoi(num);
	while(temp) 
	{
		int last_digit = temp % 10;
		temp = temp / 10;
		  
		decimalValue += last_digit * base;
		  
		base = base * 2;
	}
	return decimalValue;
}
int binaryToDecimalRecur(int num)
{	
	if(num == 0)
	{
		return 0;
	}
	else
	{
		return num % 10 + 2 * binaryToDecimalRecur(num / 10);
	}
}
int main()
{
	int num;
	string str[] = {"0", "101", "100000", "11110000", "1010101010"};
	
	for(int i = 0; i < sizeof(str)/sizeof(str[0]); i++)
	{	  
		cout << str[i] << " in decimal is: " << binaryToDecimalIter(str[i]) << endl;
		num = stoi(str[i]);
		cout << str[i] << " in decimal is: " << binaryToDecimalRecur(num) << endl;	
	}
	system("pause");
	return 0;
}
