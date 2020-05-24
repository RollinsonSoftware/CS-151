/*
File name: project2Main.cpp

Purpose/Problem:
In this lab, you will use many of the C-string and C++ string functions to 
follow a number through several conversions from/to numbers, strings, binary strings, 
and hex strings.

Author: John Rollinson, CS151

Module #: 8
Lab #: 2

Algorithm:
Create an int variable named "original", prompt for and read in the value from the user,
  cout >> "Please enter...
  int original = 0 ;  
  cin >> original ;
 
Convert the number to a string using the "to_string" function. Add the word " rah!" onto 
the end of the new string. Print the string on the console.
  string original_as_string = 
                 to_string(original) + " rah!" ; 
  cout ... 
 
Convert back to a number using an istringstream class. Print the new number on the console.
  istringstream inpstr(original_as_string) ;  
  int original_copy ;
  inpstr >> original_copy ;
  cout ...
 
Convert your number to a binary string of 0's and 1's and print the results:
  char *binary = new char[33] ;
  *(binary + 32) = '\0' ;
  int index = 32 ;
  do {
      *(binary + (--index)) = 
                (char) (original_copy % 2 + '0') ;  
      original_copy /= 2 ;
  } while (original_copy > 0) ;
  cout << "That number in binary is: " 
       << (binary + index) << endl ;
 
Use the stoi function to convert the string of binary 0's and 1's back the original 
number in decimal and print.
  int original_copy = stoi((binary + index), nullptr, 2) ;
  cout ...  
 
Convert your number to hexadecimal (base 16). Print the number in hex.
  stringstream iostr ;
  iostr << hex << original ;
  cout ...  
 
Back to decimal and print.
  iostr >> hex >> original_copy ;
  cout ...  
An example of the output from your program is given below using 424970 for the number 
entered by the user:

Sample output from your program

Provide examples of output from your program for the following decimal numbers: 0, 1000, 
65536, and 2147483647.
*/

//Header Files
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or 
input loop */

int main(int argc, char** argv) 
{	
	//Looping for input, exit case is any negative number.
	while(true)
	{
		//Given on canvas, accepts all postive whole numbers and zero.
		int original;  
		cout << "Enter a non-negative whole number(Any negative to exit): ";
		cin >> original;
		
		if(original < 0)
		{
			break;
		}
		else
		{
			//Variables:
			stringstream iostr;
			int original_copy;
			
			//Given code.
			string original_as_string = to_string(original) + " rah!";
			cout << left << setw(57) << "That number converted to a string: " << original_as_string << endl;
			
			istringstream inpstr(original_as_string);  
			inpstr >> original_copy;
			cout << left << setw(57) << "Converted back to a number: " << original_copy << endl;
			
			char *binary = new char[33];
			*(binary + 32) = '\0';
			int index = 32;
			
			do
			{
				*(binary + (--index)) = (char)(original_copy % 2 + '0');  
			    original_copy /= 2;
			}while(original_copy > 0);
			
			cout << left << setw(57) << "That number in binary is: " << (binary + index) << endl;
			
			original_copy = stoi((binary + index), nullptr, 2);
			cout << setw(57) << "Back to decimal: " << original_copy << endl;
			//End of given code.
			
			//Output:
			cout  << left << setw(57) << "Here's your number in hex: ";
			iostr << std::hex << original_copy;
			cout << hex << original_copy << endl; 
			
			iostr >> hex >> original_copy;
			cout << left << setw(57) << dec << "And back once more: " << original_copy << endl << endl;
		}
	}
	system("pause");
	return 0;
}
