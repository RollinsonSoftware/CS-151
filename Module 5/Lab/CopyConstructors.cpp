/**
* Program Name: CopyConstructors.cpp

* Program Discription: Lab 5 part 2
	Develop a copy constructor which fixes a issues with shallow copies.
	
* Algorithm: 
	This part of the lab will create a class that mimics strings.  
	Initially it will have the following functions:
	a constructor
	a destructor
	a print function
	a change function
	We'll use an array of chars to store the string, and find 
	out what happens when a copy constructor is missing and when one is added.

Define the String class
Inside the String class, define two private variables
  char *string ; 
  int size ;
 
Also inside the class define prototypes for the five functions:
  public: 
     String(const char *s = "") ;    // constructor 
     ~String() ;                     // destructor 
     void print() ;                  // print the string 
     void change(const char *) ;     // reassign the string  
 
Outside the String class, the constructor for this class should take a string, 
store in in the heap, and assign it to the string instance member:
  //Constructor
  String::String(const char *original) {  
     size = strlen(original) ; 
     string = new char[size + 1] ; 
     strcpy(string, original) ; 
 }
 
The change function should replace the current string stored in this object with a new string.
  // Replace with another String object
  void String::change(const char *original) {  
     delete [] string ; 
     size = strlen(original) ; 
     string = new char[size + 1] ; 
     strcpy(string, original) ; 
  }
 
The destructor should just return the character array in the string instance 
member back to the heap.
The print function should simply print the string on the console.
Make sure that your program compiles.  Study the class and make sure that 
you understand how each function works.
Create main
In main, create two String objects, one using a constructor and one using an 
assignment statement.  Notice that the assignment statement will use the default 
copy constructor, since we haven't created one yet...
  // Create String using a constructor and assignment statement
  cout << "Create two strings, one using constructor, "
       << another an assignment statement" << endl ;
  String str1("MiraCosta College") ;       // constructor
  String str2 = str1 ;                     // assignment
 
Print the value of both string on the console using the print function.
Change the string stored in the second String object using the change function, 
then print both again.
 // Use the change method and print
  cout << "\nAfter changing string 2 using change()" << endl ;
  str2.change("Cal State San Marcos") ; 
  ...
 
Change the value of the first String object using the change function and print both again.
  // Use the change method on string 1 and print
  cout << "\nAfter changing string 1 using change()" << endl ;
  str1.change("UCSD") ;
  ...
Clearly we have a problem:

Without a copy constructor, the pointer in the second string object was simply 
pointing to the same string as the first object.  However, when the change function 
was used on the second, a new string was created in the heap, freeing the memory 
used by the second string.  That meant that the first object now had a dangling pointer, 
since the object it was pointing to had just been deleted!

Create a copy constructor for the String class
Inside the String class, define a fifth prototype function, this one for a copy constructor.
  String(const String &) ;   // copy constructor  
 
Outside the String class, implement the copy constructor.
  // Copy constructor that creates a new String
  String::String(const String &original) { 
     size = original.size ; 
     string = new char[size + 1] ; 
     strcpy(string, original.string) ; 
  } 
 
Run your program again and verify that it works properly.  This should fix the problem 
caused by the assignment statement creating the second String object.
* Date:2/27/2020
* Programers: Shachar Habusha, Chandler Ott, Samsuan Nejahad, John Rollinson
**/
#include <iostream>
#include <cstring>

using namespace std;

class String{
	private:
		char *string ; 
 	    int size ;	
 	    
 	public:
 	 String(const char *s = "") ;    // constructor 
 	 String(const String &) ;   	 // copy constructor
     ~String() ;                     // destructor 
     void print() ;                  // print the string 
     void change(const char *) ;     // reassign the string 
 		
};

int main(){
		// Create String using a constructor and assignment statement
	  cout << "Create two strings, one using constructor, " << "another an assignment statement" << endl ;
	  String str1("MiraCosta College") ;       // constructor
	  String str2 = str1 ;                     // assignment
	  
	  str1.print();
	  str2.print();
	  
	   // Use the change method and print
	  cout << "\nAfter changing string 2 using change()" << endl ;
	  str2.change("Cal State San Marcos") ; 
	  str2.print();
	  // Use the change method on string 1 and print
	  cout << "\nAfter changing string 1 using change()" << endl ;
	  str1.change("UCSD") ;
	  str1.print();
	
	return 0;
}

 //Constructor
  String::String(const char *original) {  
     size = strlen(original) ; 
     string = new char[size + 1] ; 
     strcpy(string, original) ; 
 }
 
   void String::change(const char *original) {  
     delete [] string ; 
     size = strlen(original) ; 
     string = new char[size + 1] ; 
     strcpy(string, original) ; 
  }
  
  String::~String(){
  	delete []string;
  	size = 0;
  } 
  
  void String::print(){
  	cout <<"The String is: " <<  endl;
  	for(int i = 0; i < size; i++){
  		cout << *(string+i);
	  }
	  cout<<endl;
}

 // Copy constructor that creates a new String
  String::String(const String &original) { 
     size = original.size ; 
     string = new char[size + 1] ; 
     strcpy(string, original.string) ; 
  } 
