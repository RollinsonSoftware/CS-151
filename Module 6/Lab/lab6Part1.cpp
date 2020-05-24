/* lab6Part1.cpp 
 * Author:     John Rollinson
 * Module:     6
 * Project:    Lab, Part 1
 * 
Problem statement: override the assignment and stream extraction operators 
 to do the same thing as those two functions.  You also will override several 
 other operators to make your String class more versatile.
 
Last week you created a basic String class which introduced a copy constructor.  
That class had two functions, print and change, one which printed the member string 
on the console and the other which changed the value of the member string.

In this project you will override the assignment and stream extraction operators to 
do the same thing as those two functions.  You also will override several other operators 
to make your String class more versatile.

Load and initialize the EString class
Create a new project in Dev-C++ (or whatever IDE you are using).
Download the EString.cpp file found at the bottom of this lab and load into your project.
Inside the EString class, add the following prototype for the assignment operator:
  EString &operator=(const EString &) ;  
 
Outside of the EString class, add the following definition for the assignment operator:
  // Assignment operator
   EString & EString::operator=(const EString &original) { 
       delete [] string ; 
       size = original.size ; 
       string = new char[size + 1] ; 
       strcpy(string, original.string) ; 
       return *this ; 
   }
Notice the similarity between the copy constructor and the overridden assignment function.  
(Only the first and last lines are different!)

Again inside the EString class, declare the prototype for the stream extraction (<<) operator:
  friend ostream &operator<<(ostream &, const EString &) ; 
 
And outside the EString class, define the stream extraction operator:
  // Stream extraction operator
  ostream & operator<<(ostream &out, 
                       const EString &output_EString) {  
      out << output_EString.string ;
      return out ;
  } 
Notice that this function is not a member of the EString class, so it is defined as a friend, 
allowing it direct access to the private members of the EString class.

Also notice that the address of the output stream is returned, as the output stream object has 
been changed and needs to be updated.  This also allows for cascading.

Test the assignment and stream extraction operators
In main:
Declare an EString object, say estring1, and assign its string member to "Hello MiraCosta!".  
Declare another EString object, say estring2, but don't assign it to anything.
  EString estring1 = "Hello MiraCosta!", estring2 ;  
 
In a third line, assign e2 to e1 to test the assignment operator:
  estring2 = estring1 ;  
 
Use a single cout to display both objects on different lines. This will test the ability to 
cascade EString objects in a cout statement.
  cout << "First string:  " << estring1 << endl
       << "Second string: " << estring2 << endl << endl ;  
 
Verify that both objects printed the same string.
Create four more overloaded operators for the EString class
Add prototypes for the new operators inside the EString class:
  EString operator++() ; 
  EString operator++(int) ;
  char & operator[](int) ;
  friend EString operator+(const EString &, const EString &) ;  
 
The first function above should define the prefix version of the ( ++ ) operator.
Convert all of the lower-case letters in the calling object's string to upper-case.  
(You can use a loop or any other means to do this.)
Return the calling object (*this).
The second function above should define the postfix version of the ( ++ ) operator.  
In this case, the function should change all letters in the calling object's string to uppercase, 
but return the original version of the calling object.
Create a new EString object which is a copy of the calling object.
Convert all of the lower-case letters in the calling object's string to uppercase.
Return the copy.
The third function above should return the address of the character in the EString's string.
If the index of the parameter is less than 0 or greater than the size of the string, then print 
an error message and stop the program (use the exit function).
Otherwise return the address of the character at the position specified in the parameter.
The fourth function should define the addition operator ( + ) which takes two EString objects 
and returns a third EString in which the strings of both parameter objects have been concatenated 
together.
Create a new array of chars with a size one more than the sum of the sizes of the two EString 
objects.
Use strcpy to copy the contents of the first string into the new array.
Use strcat to copy the contents of the second string into the new array.
Using the new array as a parameter, return a new EString object.
Test your new EString class operators
Adding to main, create two EString objects each containing a short sentences with upper and 
lower-case letters, a number, and some punctuation.
Demonstrate the use of the prefix and postfix ++ operators using one of the EStrings created above.  For each operator, print:
the original EString
the EString with the prefix (or postfix) operator being applied.
the EString after the operator finished
Because of the way cout works, use individual cout statements, do NOT use a single cout statement.  
For example, to demonstrate the use of the prefix operator on the string "New Year's Party at 8:30." 
, your output might look like:

  Original string:        New Year's Party at 8:30.  
  Using prefix operator:  NEW YEAR'S PARTY AT 8:30.
  After using prefix:     NEW YEAR'S PARTY AT 8:30.  
Do the same thing using the postfix operator. (Note that the second string should still have 
lower-case letters when using postfix.)

Use the + operator to create a fifth EString consisting of all both test EString objects 
concatenated together.  Print that EString on the console.
Using a loop, use the overloaded [  ] operator to extract each character in one of the 
EString objects and print each on a single line separated by a space character.
Again using the overloaded [  ]  operator, make another loop to increment each character's 
value in one of the EString objects using the ++ operator, then print that character.  
(Separate characters with a space):

  N E W   Y E A R ' S   P A R T Y   A T   8 : 3 0 .  
  O F X ! Z F B S ( T ! Q B S U Z ! B U ! 9 ; 4 1 /
  
Algorithm:
Create two Estring objects.
Test the prefix and postfix increment overloaded functions.
Test the addition overloaded operator.
Loop through the array to show that the [] overloaded operands are working.
Loop again to also test and show the sample output above using the 
prefix increment, assignment, and brackets([]) overloaded operands.
*/

#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

class EString //enchanced String class
{ 

    private:
        char *string;                              // pointer to an array of chars
        int size;                                  // size of the array

    public:
        EString(const char *s = "");               // constructor
        ~EString();                                // destructor
        
        int getSize();							   // returns size
        EString(const EString &);                  // copy constructor
        
        EString &operator=(const EString &);	  
        friend ostream &operator<<(ostream &, const EString &); 
        EString operator++(); 
		EString operator++(int);
		char & operator[](int);
		friend EString operator+(const EString &, const EString &); 
};

// Constructor
EString::EString(const char *original) 
{
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

// Destructor
EString::~EString() 
{
    delete []string;
}

int EString::getSize()
{
	return size;
}

// Copy constructor 
EString::EString(const EString &original) 
{
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
}

// Assignment operator
EString & EString::operator=(const EString &original) 
{ 
      delete [] string; 
      size = original.size; 
      string = new char[size + 1]; 
      strcpy(string, original.string); 
      return *this; 
}

// Stream extraction operator
ostream & operator<<(ostream &out,  const EString &output_EString) 
{  
  out << output_EString.string;
  return out;
} 
  
//++ operator postfix
EString EString::operator++() 
{	
    for(int i = 0; i < size; i++)
	{
    	string[i] = toupper(string[i]); 	
	}  
	return *this;
}

//++ operator prefix
EString EString::operator++(int) 
{ 
	EString post = *this;
	
    for(int i = 0; i < size; i++)
	{
    	string[i] = toupper(string[i]); 	
	}
	return post;
}

char & EString::operator[](int letter) 
{
	if(letter < 0 || letter > size)
	{
		cout << "There is an error with what you have entered: " << endl;
	}
	else
	{
		return string[letter];
	}
}
	
EString operator+(const EString &one , const EString &two) 
{
	int s = strlen(one.string) + strlen(two.string) + 1; // size for new Estring
	
	char * nstring = new char[s + 1] ; // new String
	
	strcpy(nstring, one.string);
	
	strcat(nstring, two.string);
	
	EString newEString = nstring; // new estring
	
	return newEString;
 }


int main()
{
	EString estring1 = "Hello MiraCosta!";
	EString estring2  = estring1; 
	cout << "First string:  " << estring1 << endl << "Second string: " << estring2 << endl << endl ; 
 
	//Testing Estring class operators
	//sentence1 will test prefix, sentence 2 will test postfix
	EString sentence1 = "New Year's Party at 8:30.";
	EString sentence2 = "John A Rollinson";
	
	//PREFIX
	cout << "Original String 1:  " << sentence1 << endl;
	cout << "Using prefix operator:  " <<  ++sentence1 << endl;
	cout << "After using prefix: " << ++sentence1 << endl; 

	//POSTFIX
	cout << "\nOriginal String 2: " << sentence2 << endl;
	cout << "Using postfix operator:  " <<  sentence2++ << endl;
	cout << "After using postfix: " << sentence2 << endl; 

	//ADDITION
	EString combinedString = sentence1 + " " + sentence2; 
	cout <<"\nString 1 and String 2 concatenated together: " << combinedString << endl << endl;
	
	cout <<"Testing Overloaded operator [] with = and ++: " << endl;
	
	//BRACKETS
	for(int i = 0; i < sentence1.getSize(); i++)
	{
		cout << sentence1[i] << " " ;	 	
	}
	
	cout << endl;
	
	//ASSIGNMENT
	for(int i = 0; i < sentence1.getSize(); i++)
	{
		sentence1[i] = ++sentence1[i];
		cout << sentence1[i] << " " ;	 	
	}
   return 0;
}
