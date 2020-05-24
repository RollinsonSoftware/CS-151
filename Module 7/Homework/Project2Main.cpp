/*
File name: Project2Main.cpp

Purpose/Problem:
Write a class named EncryptableString that is derived from the STL string class. 
The EncryptableString class adds a member function:
void encrypt()

which encrypts the string contained in the object by replacing each letter with 
its successor in the ASCII ordering.  (For example the string baa encrypted would 
become cbb.  Encrypt it again and the string would become dcc.)  Assume that the only 
characters to be encrypted in an EncryptableString object are letters (a ? z and A ? Z), 
and numbers (0 ? 9), and that the successor of 'z' is 'a', the successor of 'Z' is 'A', 
and the successor of '9' is '0'.  Other characters do not need to be encrypted, such as 
spaces and punctuation.

Author: John Rollinson, CS151

Module #: 7
Homework #: 2

Algorithm:
Loop through the string and check for any chars that are not uppercase letters, lowercase
letters, or numbers.
When you know that they are one of the 3 groups, check for "Z", "z", or "9"s. As these chars
are special cases.
Append the propper char "A", "a", and "0" for "Z", "z", and "9".
All other letters and numbers just add 1 to their ascii value and then type cast.
Output the results to the user.
For the main method:
Loop for user input and encrypt each string given.
Each EncryptableString objects constructor will automatically show the encrypted form when 
initialized.
0 will be the exit case, if it is passed alone then the program will exit with the loop.
*/
#include <iostream>
#include <string.h>

using namespace std;

class EncryptableString : public string 
{
	 public:	 	
	 	//Constructor:
		EncryptableString (string word) : string(word)
		{
			cout << "\"" << word << "\" encrypted is: " ;
		}
		//Destructor:
		~EncryptableString() {}
		//Functions:
		void encrypt()
		{
			string word(this->c_str()), encrypted; // from string class
			
			for(int i = 0; i < word.length(); i++)
			{
				if((word[i] < 64 || word[i] > 91 ) && //checking puncuation and spaces.
					(word[i] < 96 || word[i] > 123 ) &&
					(word[i] < 48 || word[i] > 58))
				{	
					encrypted += (char)word[i];
				}
				else if(word[i]== 122) //checks if char is z. 
				{
					encrypted +='a';
				}
				else if(word[i] == 90) //checks if char is Z.
				{
					encrypted += 'A'; 
				}
				else if(word[i] == 57) //checks if char is 9.
				{
					encrypted += '0';
				}
				else //adds one to ascii value of char.
				{
					encrypted += (char)(word[i] + 1);	
				}
			}
			this->swap(encrypted);
			this->toString();
		}
		void toString()
		{
			cout << "\"" << this -> c_str() << "\"" << endl;
		}
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	string input; 
	
	while(true)
	{
		cout << "Enter a phrase (0 to exit): ";
		getline(cin, input);
		
		if(input == "0")
		{
			break;
		}
		else
		{
			EncryptableString user(input);
			user.encrypt(); 
			cout << endl;
		}
	}	
	return 0;
}
