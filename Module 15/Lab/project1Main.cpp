/*
File name: project1Main.cpp

Purpose/Problem:
In the lectures on linked lists and sets, we saw code which performed the intersection 
of two sets A and B (written A n B) and the union of two sets (written A U B).  
Both of these operations return a new set (i.e., they do not change the original 
sets A or B).

Another common relationship is the difference between two sets A and B (written as A – B) 
also called A minus B.  In this operation, a new set is created which contains each 
element in set A unless that element is also in set B.

Showing Sets A, B, and A - B (the difference)

Looking at the picture above, two interesting relationships exist:

(A – B) U (A n B) = A

(A – B) U (A n B) U (B – A) = A U B

In this project, enhance the Set class on Canvas (located at the bottom of this lab 
and also in the "Demonstration Programs" section of this Module) in two ways:

Create a new function named  minus  with the following heading:
  Set<T> minus(Set<T> other_set)  
It should perform the difference operation described above, where the new set returned 
from the function contains all of the elements in calling set minus any element also in 
other_set.

Create an  equals  function which returns true if all of the elements in the calling set 
are in the set passed as a parameter, and vice versa.  The function should have a heading
  bool equals(Set<T> other_set)  
In a different class containing main, test your new minus and equals functions with the 
following four test cases:

Case 1: calling set = {“C”, “G”, “E”, “A”} and other(parameter)  set = {“E”, “C”, “F”}

Case 2: calling set = {“Carlos”, “John”, “Alice”} and other set = {“John”, “Henry”, “Maria”}

Case 3: calling set = {5, 1, 3} and other set = {1, 3, 5, 7, 9}

Case 4: calling set = {5} and other set = { }

For each test case, print the contents of 5 sets:  A (the calling set),  B (other set),  
A – B,  A n B, and  (A – B) U (A n B).

Notice that the last set listed above, (A – B) U (A n B),  should have the same contents 
as set A.  Use the equals function to prove this point.

Author: John Rollinson, CS151

Module #: 15
Lab #: 1
*/

//Header Files
#include <iostream>
#include "SetLinkedList.h"

using namespace std;

int main(int argc, char** argv) 
{	
	cout << "=====Test Case 1=====" << endl;
	Set<char> charCallingSet;
	charCallingSet.insert('C');
	charCallingSet.insert('G');
	charCallingSet.insert('E');
	charCallingSet.insert('A');
	
	Set<char> charParameterSet;
	charParameterSet.insert('E');
	charParameterSet.insert('C');
	charParameterSet.insert('F');
	
	charCallingSet.print(charParameterSet);
	
	cout << "\n=====Test Case 2=====" << endl;
	Set<string> stringCallingSet;
	stringCallingSet.insert("Carlos");
	stringCallingSet.insert("John");
	stringCallingSet.insert("Alice");
	
	Set<string> stringParameterSet;
	stringParameterSet.insert("John");
	stringParameterSet.insert("Henry");
	stringParameterSet.insert("Maria");
	
	stringCallingSet.print(stringParameterSet);
	
	cout << "\n=====Test Case 3=====" << endl;
	Set<int> intCallingSet;
	intCallingSet.insert(5);
	intCallingSet.insert(1);
	intCallingSet.insert(3);
	
	Set<int> intParameterSet;
	intParameterSet.insert(1);
	intParameterSet.insert(3);
	intParameterSet.insert(5);
	intParameterSet.insert(7);
	intParameterSet.insert(9);
	
	intCallingSet.print(intParameterSet);
	
	cout << "\n=====Test Case 4=====" << endl;
	Set<int> specialCallingSet;
	specialCallingSet.insert(5);
	
	Set<int> specialParameterSet; //empty set.

	specialCallingSet.print(specialParameterSet);
	
	system("pause");
	return 0;
}
