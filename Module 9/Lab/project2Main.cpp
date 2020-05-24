/*
File name: project2Main.cpp

Purpose/Problem:
Multiply every number in the file by a fixed amount.

Author: John Rollinson, CS151

Module #: 9
Lab #: 2

Algorithm:
Step 1:  Perform steps 1, 2, and 3 from Project #1 above.

Step 2:  Perform step 4 from Project #1 above, except open the binary file for both 
input ant output:

  fstream data_file(file_name, ios::binary | ios::in | ios::out) ; 
  if (! data_file) ... 
Step 3:  Prompt the user to enter a "multiplier" and store in a double variable named, 
say, multiplier.

Step 4:  Read the 10 integers from the file, display on the screen, multiply by the 
multiplier, and write back out onto the file.

  // Read ints from data file, multiply, and store back in the file
  cout << "Reading and updating ints..." << endl ;
  for (int i = 1 ; i <= 10 ; i++) {
      int data ; 
      long position = data_file.tellg() ; 
      data_file.read(reinterpret_cast <char *>(&data), sizeof(int)) ;
      cout << data << " -> " ; 
      data = round(data * multiplier) ;
      cout << data << endl ;
      data_file.seekp(position, ios::beg) ; // write updated number
      data_file.write(reinterpret_cast <char *>(&data), sizeof(int)) ;
  } 
 
Notice the way this code works:
store the current "read" position in a long
read the next int in the file
multiply the int by the multiplier
set the "write" position to the original "read" position
write the new number over the old number
Step 5:  Do the same for the 10 double values in the file.

Step 6:  Close the file and exit.

Step 7:  Copy the binary data file created from Project #1 into this Project and run 
your program.

Notice that the integers and the square roots were multiplied by 2, but the values of 
the squares were multiplied by 4.

Run the program again using 2 as the multiplier.  Make sure that the new values are now 
four times the original values and the squares are 16 times their original values.

Run once more time using 0.25 as the multiplier.  The new values should be restored back 
to their original numbers (1 - 10 and their square roots).
*/
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(int argc, char** argv) 
{
	
	const string fileName = "array.dat";
	
	fstream data_file(fileName, ios::binary | ios::in | ios::out);
	
	if (!data_file) 
	{
		data_file.close();
		cout << "ERROR: FILE COULD NOT BE OPENED! Terminating..." << endl;
		system("pause");
		exit(1) ;
	}
	
	double multiplier;
	cout << "Enter the multiplier: ";
	cin >> multiplier;
	
	cout << "\n=====MULTIPLIER AND ORIGINAL VALUES=====" << endl;
	//Given Code:
	// Read ints from data file, multiply, and store back in the file
  	cout << "Reading and updating ints..." << endl ;
  	for (int i = 1 ; i <= 10 ; i++) 
	{
	    int data ; 
	    long position = data_file.tellg() ; 
	    data_file.read(reinterpret_cast <char *>(&data), sizeof(int)) ;
	    cout << data << " -> " ; 
	    data = round(data * multiplier) ;
	    cout << data << endl ;
	    data_file.seekp(position, ios::beg) ; // write updated number
	    data_file.write(reinterpret_cast <char *>(&data), sizeof(int)) ;
    }
    
    cout << "\n=====MULTIPLIER AND SQRT VALUES=====" << endl;
	
	for (int i = 1 ; i <= 10 ; i++) {
      double data2 ; 
      long position2 = data_file.tellg() ; 
      data_file.read(reinterpret_cast <char *>(&data2), sizeof(double)) ;
      cout << data2 << " -> " ; 
      data2 = data2 * multiplier ; // do not need to round a double
      cout << data2 << endl ;
      data_file.seekp(position2, ios::beg) ; // write updated number
      data_file.write(reinterpret_cast <char *>(&data2), sizeof(double)) ;
  } 
	data_file.close();
	system("pause");
	return 0;
}
