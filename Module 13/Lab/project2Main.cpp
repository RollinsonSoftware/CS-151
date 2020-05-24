/*
File name: project2Main.cpp

Purpose/Problem:

Write a function

  T accum(vector <T> v)  
that forms and returns the "sum" of all items in the vector v passed to it.  
For example, if T is a numeric type such as int or double, the numeric sum will 
be returned, and if T represents the STL string type, then the result of 
concatenation is returned.

Note: For any type T, the expression T( ) yields the value or object created by 
the default constructor.  For example , T( ) yields the empty string object if T 
is the string class.  If T represents a numeric type such as int, then T( ) yields 0.  
Use this fact to initialize the value to be returned.

In main, use your function to "sum" vectors of ints, of doubles, and of strings.  
In your output, please show the contents of each vector and the "sum" of the elements 
in that vector.

When completed, turn in all program files and either print screens or screen snips 
showing the output of your programs.


Author: John Rollinson, CS151

Module #: 13
Lab #: 2
*/

//Header Files
#include <iostream>
#include <vector>
using namespace std;

template<class T>
T accum(vector <T> vec) 
{
	T sum = vec[0];

	for(int i = 1; i < vec.size(); i++)
	{	
		sum += vec[i];
	}
	return sum;
}

int main(int argc, char** argv) 
{
	vector<int> numVec; 
	vector<string> wordVec;
	
	cout << "Integer example:" << endl;
	for (int i = 0; i < 50; i++)
	{
		numVec.push_back(i);
	}
	cout << "The sum of the vector is: " << accum(numVec) << endl;
	
	cout << "\nString example:" << endl;
	wordVec.push_back("John");
	wordVec.push_back("Joe");
	wordVec.push_back("Jeff");
	wordVec.push_back("Jim");
	wordVec.push_back("Jacob");
	wordVec.push_back("Jesus");
	cout << "The sum of the vector is: " << accum(wordVec) << endl;
	
	system("pause");
	return 0;
}
