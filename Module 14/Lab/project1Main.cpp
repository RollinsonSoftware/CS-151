/*
File name: project1Main.cpp

Purpose/Problem:
Using the LinkedList.h file below, add the following functions to increase the 
usability of the class it contains:

display the contents of the list on the console
print "(null)" if the list is empty
remove a node with a specific data element (e.g., 25.0)
return false if the element is not found, true if removed
remove a node at a specific location
return the element removed if successful, throw run-time exception if invalid location
find the last index of a specific data element
return -1 if element is not found
determine if the list contains a specific data element
return true if found, false if not found
modify or set the data value of a node at a specific index
return true if index is occupied and update was successful, false otherwise
Demonstrate how each of your functions work in a tester program.  When completed, 
turn a final version of LinkedList.h and the file containing your tester program, 
along with either print screens or screen snips showing the output of your programs.

Author: John Rollinson, Shachar Habusha; CS151

Module #: 14
Lab #: 1
*/
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char** argv) 
{
	LinkedList<int> myInt;
	for(int i = 0; i < 2; i++)
	{	
		for(int j = 0 ; j < 10 ; j++)
		{	
			myInt.addFirst(j);
		}
	}
	
	cout << "Displaying Integer Linked List:" <<endl;
	myInt.display();
	
	cout << "Removing 3" << endl;
	myInt.remove(3);
	
	cout << "Displaying updated Integer Linked List:" <<endl;
	myInt.display();
	
	cout << "Removing 15" <<endl;
	cout << myInt.remove(15) << endl;
	
	cout << "Displaying updated Integer Linked List:" <<endl;
	myInt.display();
	
	cout << "Finding last index of 9" << endl;
	cout << myInt.indexOf(9) << endl;
	
	cout << "Does the list contains a specific data element of 8: " << endl;
	cout << ((myInt.contains(8))? "True": "False") << endl;
	
	cout << "Modifying location 4 and turning it to 100" << endl;
	myInt.set(4 , 100);
	
	cout << "Displaying updated Integer Linked List:" <<endl;
	myInt.display();
	
	cout <<"Removing at location 3:" << endl;
	myInt.removeAt(3);
	
	cout << "Displaying updated Integer Linked List:" <<endl;
	myInt.display();
	
	system("pause");
	return 0;
}
