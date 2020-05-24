/*
File name: project3Main.cpp

Purpose/Problem:
A palindrome is a string such as "madam", "radar", "dad", and "I ", that reads the 
same forwards and backwards. The empty string is regarded as a palindrome. Write a 
recursive function with the heading:

  bool isPalindrome(string str, int lower, int upper) 
   
that returns true if and only if the part of the string str in positions lower 
through upper (inclusive at both ends) is a palindrome . Test your function by 
writing a main function that repeatedly asks the user to enter strings. These 
strings are then tested for palindromicity. The program terminates when the user 
presses the ENTER key without typing any characters before it.

Demonstrate your program with at least three strings that are palindromes and 
three strings that are not palindromes.

Author: John Rollinson, CS151

Module #: 11
Homework #: 3

Algorithm:
loop for user input to get a single word or phrase using the getline() function.
check to see if the string from the user is an empty string.
if it is this is our exit case so close the program.
else convert the string to lower case and remove all the spaces.
using the isPalindrome function, check if the string is a palindrome.
output to the console if the original string it is or is not a palindrome.
*/

//Header Files
#include <iostream>
#include <string>
#include <algorithm> 
#include<bits/stdc++.h> 

using namespace std;

/* run this program using the console pauser or add your own getch, 
system("pause") or input loop */

//Prototypes:
bool isPalindrome(string str, int lower, int upper);

int main(int argc, char** argv) 
{
	string word, original;
	
	while(true)
	{
		cout << "Enter a word or phrase (enter to exit): ";
		getline(cin, word);
		original = word;
		
		if(word.length() < 1)
		{
			break;
		}
		else
		{
			word.erase(remove(word.begin(), word.end(), ' '), word.end()); 
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			
			if(isPalindrome(word, 0, word.length() - 1))
			{
				cout << "\"" << original << "\"" << " IS a palindrome." << endl << endl;
			}
			else
			{
				cout << "\"" << original << "\"" << " IS NOT a palindrome." << endl << endl;
			}
		}
	}
	system("pause");
	return 0;
}
/*
Reads in a string, the starting index and the ending index of the string to be scanned.
Returns true if the sequence of chars scanned are a palindrome, and false otherwise.
*/
bool isPalindrome(string str, int lower, int upper)
{	
	if(lower >= upper)
	{
		return true;
	}
	else
	{
		if(str[lower] == str[upper])
		{
			return isPalindrome(str, lower + 1, upper - 1);
		}
		else
		{
			return false;
		}
	}
}
