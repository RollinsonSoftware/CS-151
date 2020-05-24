/*
File name: project2Main.cpp

Purpose/Problem:
A sequence of integers such as 1, 3, 5, 7, ...  can be represented 
by a function that takes a non-negative integer as parameter and 
returns the corresponding term of the sequence.  For example, the 
sequence of odd numbers just cited can be represented by the function

  int odd (int k) { return 2 * k + 1 ; }
    
Write an abstract class AbstractSeq that has a pure virtual member function

  virtual int fun(int k) = 0 ;  
  
as a stand-in for an actual sequence, and two member functions

  void printSeq(int k, int m} ;  
  int sumSeq(int k, int m) ;
  
that are passed two integer parameters k and m, where k < m.  
The function printSeq will print all the terms fun(k} through fun(m) 
of the sequence, and likewise, the function sumSeq will return the sum 
of those terms.

Demonstrate your AbstractSeq class by creating two subclasses that you 
use to sum the terms of at least two different sequences. 

Your output should show the full sequences (using printseq) and the sum
of the numbers in each sequence (using sumSeq).  For the sum, please start 
and end somewhere inside the entire sequence printed

Author: John Rollinson, CS151

Module #: 12
Homework #: 2

Algorithm:
Create a new pointer for each sequence.
For each sequence:
Print the sequence to the console.
Print the sum of all numbers in the sequence to the console.
*/

//Header Files
#include <iostream>

using namespace std;

class AbstractSeq
{
	public:
		/*
		Pure virtual function defined in the child classes.
		*/
		virtual int fun(int k) = 0;
		
		/*
		Function to print all the terms in the sequence.
		Takes two integers as arguements.
		Where k is the starting value of k, m is the number of terms
		being printed.
		*/
		void printSeq(int k, int m)
		{
			while(k <= m)
			{
				cout << fun(k) << ", ";
				k++;	
			}
		}
		/*
		Function to sum all the terms in the sequence.
		Takes two integers as arguments.
		Where k is the starting value of k, m is the number of terms
		being printed.
		*/
		int sumSeq(int k, int m)
		{
			int sum = 0;
			
			while(k <= m)
			{
				sum += fun(k);
				k++;
			}
			return sum;
		}
};
/*
Defines a sequence of odd integers.
*/
class OddSeq : public AbstractSeq
{
	public:
		/*
		Implementation of the pure virtual function fun()
		Generates terms of an odd number sequence.
		*/
		int fun(int k)
		{
			return (2 * k + 1);
		}
};
/*
Defines a sequence of even integers.
*/
class EvenSeq : public AbstractSeq
{
	public:
		/*
		Implementation of the pure virtual function fun()
		Generates terms of an even number sequence.
		*/
		int fun(int k)
		{
			return (2 * k);
		}
};
/*
Main function to test above classes and functions.
*/
int main(int argc, char** argv) 
{
	AbstractSeq *OddNumSeq, *EvenNumSeq;
	OddNumSeq = new OddSeq();
	EvenNumSeq = new EvenSeq();
	
	cout << "Odd number sequence (from 1-20): " << endl << endl;
	OddNumSeq->printSeq(0, 9);
	cout << "\nSum of the sequence: " << OddNumSeq->sumSeq(0, 9) << endl << endl;
	
	cout << "Even number sequence (from 1-20): " << endl << endl;
	EvenNumSeq->printSeq(1, 10);
	cout << "\nSum of the sequence: " << EvenNumSeq->sumSeq(1, 10) << endl << endl;
	
	system("pause");
	return 0;
}
