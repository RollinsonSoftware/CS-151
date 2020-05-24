/*
File name: project2Main.cpp

Purpose/Problem:
Modify the SimpleVector class template presented in this chapter, 
to include the member functions push_back and pop_back. These functions 
should emulate the STL vector class member functions of the same name. 
(See Table 16-4.) The push_back function should throw an exception if 
the array is full. The push_back function should accept an argument 
and insert its value at the end of the array. The pop_back function 
should accept no argument and remove the last element from the array. 
The pop_back function should throw an exception is the array is empty.

Test the class with a driver program using a SimpleVector of numbers, 
then pushing and popping several numbers. Do the same thing with a 
SimpleVector of strings.

Don't forget to demonstrate both exception conditions.

Author: John Rollinson, CS151

Module #: 13
Homework #: 2

Algorithm:
Declare and intialize 2 simple vectors, one of type int and one of type string.
Print the vector before doing anything to show that it is empty.
Attempt to pop_back() on the empty vector.
catch the BoundsException.
Print the contents of the vector to show it is still empty.
Begin pushing objects onto the vector until another BoundsExcpetion is thrown.
catch the BoundsException.
Print the contents of the vecotr to show that it is full and after catching the
error, it reallocated and added a new index.
Repeat these steps twice, once for a vector of ints and once for a vector of
strings.
*/

//Header Files
#include <iostream>
#include <string>
#include <iomanip>
#include "SimpleVector.h"
#include "BoundsException.h"

using namespace std;

int main(int argc, char** argv) 
{
	
	//Simple Vector of numbers:
  	SimpleVector<int> vec(5);
  	
  	//Simple Vector of strings:
  	SimpleVector<string> names(5, 1);
	
  	cout << "Testing with a vector of integers.\nVector after intialization:\n" << endl;
	vec.print();

  	try
  	{
    	cout << "\nPopping on an empty array..." << endl;
    	vec.pop_back();
  	}
  	catch(BoundsException)
  	{
    	vec.print();
  	}
	try
  	{
    	cout << "\nPushing on more values than the size of the array allows..." << endl;
    	vec.push_back(6);
    	vec.push_back(32);
    	vec.push_back(44);
    	vec.push_back(10);
    	vec.push_back(23);
    	vec.push_back(-80);
	}
  	catch(BoundsException)
  	{
    	vec.print();
  	}
  	
  	//=====STRING TESTING=====
  	
  	cout << "==========" << endl;
  	cout << "\nTesting with a vector of strings.\nVector after intialization:\n" << endl;
  	cout << "==========" << endl;
	names.print();
	
	try
  	{
    	cout << "\nPopping on an empty array..." << endl;
    	names.pop_back();
  	}
  	catch(BoundsException)
  	{
    	names.print();
  	}
	try
  	{
    	cout << "\nPushing on more values than the size of the array allows..." << endl;
    	names.push_back("Jack");
    	names.push_back("Jim");
    	names.push_back("John");
    	names.push_back("Joe");
    	names.push_back("Jerome");
    	names.push_back("Jorge");
	}
  	catch(BoundsException)
  	{
    	names.print();
  	}

	system("pause");
  	return 0;
}
