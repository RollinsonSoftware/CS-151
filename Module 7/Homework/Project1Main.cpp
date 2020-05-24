/*
File name: Project1Main.cpp

Purpose/Problem:
A palindrome is a string that reads the same backward and forward.  For example, 
the words mom, dad, madam, and radar are all palindromes. 

Palindromes ignore blanks and all punctuation, looking only at letters and numbers.  
For example the phrase "madam i'm adam" is a palindrome.

Write a class PString that is derived from the STL string class.  The PString class
should add a member function:

  bool isPalindrome()  
which determines whether the string is a palindrome.  Include a constructor that 
takes an STL string object as a parameter and passes it to the string base constructor.  
Test your class by having a main program that asks the user to enter a string.  
The program uses the string to initialize a PString object and then calls isPalindrome() 
to determine whether the string entered is a palindrome.

Author: John Rollinson, CS151

Module #: 7
Homework #: 1

Algorithm:
Loop through the string and pick out all numbers and letters.
Convert each letter to its lower case counter part.
Add each lower case char or number to a new string with no spaces or punctuation.
Loop through the array again and check if the first index is the same as the last
index, then the second with the second to last and so on.
If if the char comparison matches then continue, if you hit any case where they don't
match then return false.
Test using the provided test cases on canvas by making several PString objects.
*/
#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class PString: public string 
{
	 public:
	 	//Full constructor
		PString(string str) : string(str)
		{
			if(this -> isPalindrome())
			{
				cout << "\"" << str << "\"  : is a Palindrome!" << endl;
			}
			else
			{
				cout << "\"" << str << "\"  : is NOT a Palindrome!" << endl;
			}
		}
		
		//Destructor
		~PString() {}
		
		bool isPalindrome()
		{
			int left, right; //keeps track of the left and right index
			char checkLeft, checkRight; //keeps track of current char on left and right index

			string str(this -> c_str()); //the original string from the user.
			string word = ""; 	//new string with no spaces or puncutation
			
			for(int i = 0; i < str.length(); i++)
			{
				if((str[i] > 64 && str[i] < 91 ) || //lower case
				   (str[i] > 96 && str[i] < 123) || //upper case
				   (str[i] > 47 && str[i] < 57))    //number
				{
					word += tolower(str[i]);		
				}
			}
			for(left = 0 , right = word.length() - 1; left < right; left++, right--)
			{
				checkLeft = word[left];
				checkRight = word[right];
				
				if(checkLeft == checkRight) //the left and right are the same
				{
					continue;	
				}
				if(checkLeft != checkRight) 
				{
					return false;
				}	
			}
			return true;
		}
};

int main(int argc, char** argv) 
{	
	//Test Cases

	PString chic("Chic");
	PString book("Book");
	PString kayak("Kayak");
	PString nums("25 ABC 9cba52");
	PString dont("Don't nod");
	PString notEven("Not even close!");
	PString panama("A man, a plan, a canal -- Panama");
	
	//manually input more words if you want.
	while(true)
	{
		string user; //string from the user.
		
		cout << "Enter a word or phrase (0 to exit): ";
		cin >> user;
		
		if(user == "0")
		{
			break;
		}
		else
		{
			PString check(user);
			continue;
		}
	}

	return 0;
}
