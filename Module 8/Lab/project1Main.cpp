/*
File name: project1Main.cpp

Purpose/Problem:
A palindrome is a word, number, or phrase that reads the same both forward 
and backward. For example, "noon" and "madam" are palindrome words. Palindromes 
can also be sentences, where adjustments are made for capital letters, spaces, 
and punctuation are ignored. Examples of palindrome phrases include "Madam, I'm 
Adam." and "Was it a cat I saw?"

Write a function named "isPalindrome" which takes a string as input and returns 
true if the string is a palindrome.

Author: John Rollinson, CS151

Module #: 8
Lab #: 1

Algorithm:
Step 1: Create a method with heading: bool isPalindrome(string test_string)

Step 2: Convert the string to lowercase by looking at each character in the string and 
converting any letter between 'A' and 'Z' to lowercase. If you can, use a lambda expression 
similar to the following, where str contains the string to be converted to lowercase:

  for_each(str.begin(), str.end(), 
        [](char &c) { c = tolower(c) ; } ) ;  
        
Step 3: Create a new string by copying all of the digits '0' - '9' and letters 'a' - 'z' 
in the string from Step 2.

Step 4: Copy the string from Step 3 into another new string, then reverse the characters 
in the this string as shown below:

  int n = str.length() ;
  for (int i = 0 ; i < n / 2 ; i++) {  
      swap(str[i], str[n - i - 1]) ;
  }  
  
Step 5: Compare the two strings from Steps 3 and 4 above using the string's compare 
function. If the two are equal, then the original word is a palindrome.

Step 6: In main, call your isPalindrome function using the following test strings 
and print the results:

Chic
Book
Kayak
Don’t nod.
12345
25 ABC 9cba52
Not even close.
Campus motto: Bottoms up, Mac!
A man, a plan, a canal -- Panama
*/

//Header Files
#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <bits/stdc++.h> 

using namespace std;

/* run this program using the console pauser or add your own getch,
 system("pause") or input loop */

//Prototypes:
bool isPalindrome(string test_string);

int main(int argc, char** argv) 
{	
	//Test cases
	string test[] = {"Chic", "Book", "Kayak", "Don't nod", "12345", "25 ABC 9cba52", 
			"Not even close.", "Campus motto: Bottoms up, Mac!", 
			"A man, a plan, a canal -- Panama"};
			
	for(int i = 0; i < sizeof(test)/sizeof(test[0]); i++)
	{
		isPalindrome(test[i]);
	}
	system("pause");
	return 0;
}

//Takes given string returns true if the string is a palindrome, false otherwise.
bool isPalindrome(string test_string)
{
	bool result;
	string temp = "";
	
	// converts string to lowercase (given on canvas)
	for_each(test_string.begin(), test_string.end(), [](char &c) 
	{ 
		c = tolower(c) ; 
	}); 
    
    for (int i = 0; i < test_string.length(); i++)
    {
    	if (test_string[i] < '0' || 
		   (test_string[i] > '9' && test_string[i] < 'a') || 
		    test_string[i] > 'z')
    	{
    		continue;	
		}
    	else
    	{
    		temp += test_string[i]; 
    	}
	}
    
    string reverse_test = temp;
    
    //Reversing the string (given on canvas)
    int n = temp.length();
	for (int i = 0 ; i < n / 2 ; i++) 
	{  
	    swap(reverse_test[i], reverse_test[n - i - 1]);
  	}
	
	result = temp.compare(reverse_test);
	
	//Output:
	if (result == 0)
	{
		cout << "Testing: \"" << test_string << "\"" << " =======> is a palindrome!" << endl;
	}
	else
	{
		cout << "Testing: \"" << test_string << "\"" << " =======> is NOT a palindrome!" << endl;
	}	
    return result;
}

