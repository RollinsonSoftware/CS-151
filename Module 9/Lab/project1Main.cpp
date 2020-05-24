/*
File name: project1Main.cpp

Purpose/Problem:
Create a binary file consisting of 10 ints (1 - 10) and 10 doubles (square roots)

Author: John Rollinson, CS151

Module #: 9
Lab #: 1

Algorithm:
The file will be a binary file containing the 10 numbers (from 1 to 10) each as an int, 
followed by the square roots of those numbers each as a double.

Step 1: Create a program in your favorite C++ IDE.

Step 2: Include the following libraries in your program:

iostream
fstream
math.h
Step 3:  Create a constant for the file name "array.dat"

Step 4:  Open an ofstream variable for binary output.  If the statement fails, print an 
error message and exit.

  ofstream data_file( <file name>, ios::binary | ios::out) ;  
  if (! data_file) {
     cout ...
     exit(1) ;
  }
 
Step 5:  Write the numbers from 1 to 10 as integers stored as binary numbers (the way they 
are stored in main memory).

  for (int i = 1 ; i <= 10 ; i++) {
      data_file.write(reinterpret_cast <char *>(&i), sizeof(int)) ;  
  }
 
Step 6:  Write the square roots of the numbers from 1 - 10 onto the same file.  Store as 
doubles.

Step 7:  Close the file and exit.

Run the program to create the data file containing the original set of numbers.

*/
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
	
	const string fileName = "array.dat";
	
	ofstream data_file(fileName, ios::binary | ios::out);
	
	if(!data_file) 
	{
		data_file.close();
		cout << "ERROR: FILE COULD NOT BE OPENED! Terminating..." << endl;
		system("pause");
		exit(1) ;
	}
	
	for(int i = 1; i <= 10; i++) 
	{
		data_file.write(reinterpret_cast <char *>(&i), sizeof(int));  
    }
	
	double sqrtNum;
	
	for(double i = 1; i <= 10; i++) 
	{
		sqrtNum = sqrt(i);
		data_file.write(reinterpret_cast <char *>(&sqrtNum), sizeof(double));  
    }
	
	cout << "Data has been written to the file..." << endl;
	
	data_file.close();
	system("pause");
	return 0;
}
