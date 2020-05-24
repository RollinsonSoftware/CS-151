/*
File name: project1Main.cpp

Purpose/Problem:
Design a class named AbstractSort that can be used to analyze the number 
of comparisons performed by a sorting algorithm. The class should have a 
member function compare that is capable of comparing two array elements, 
and a means of keeping track of the number of comparisons performed . The 
class should be an abstract class with a pure virtual member function:

  virtual void sort(int arr [ ], int size ) = 0 ;  
  
which, when overridden, will sort the array by calling the compare 
function to determine the relative order of pairs of numbers.

Create a subclass of AbstractSort that uses a simple sorting algorithm to 
implement the sort function. The class should have a member function that can 
be called after the sorting is done to retrieve the number of comparisons performed.

Your output should show the array before and after sorting, as well as the 
number of comparisons required to sort the array

Author: John Rollinson, CS151

Module #: 12
Homework #: 1

Algorithm:
Create a new SimpleSort pointer.
Print the original unsorted array to the console.
Sort the array.
Print the new sorted array to the console.
Print the total number of comparisons made to the console.
*/

//Header Files
#include <iostream>
#include <array>

using namespace std;

class AbstractSort
{
	protected:
		int numOfComparisons;
		
	public:
		/*
		No argument defualt constructor.
		intializes the number of comparisons to 0.
		*/
		AbstractSort()
		{
			numOfComparisons = 0;
		}
		/*
		Function to check if the first argument passes is 
		greater than the second arugment passed.
		Takes to integers as parameters which are going to be compared.
		Returns true if num1 is larger than num2, false otherwise.
		*/
		bool compare(int num1, int num2)
		{
			numOfComparisons++;
			
			if(num1 > num2)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		/*
		Declaration of the pure virtual function sort.
		Defined in the child class.
		*/
		void virtual sort(int array[], int size) = 0;
};
class SimpleSort : public AbstractSort
{
	public:
		SimpleSort() : AbstractSort()
		{
			//Calls the parent constructor.
		}
		/*
		Implementation of the pure virtual function sort.
		Uses the quick sort algorithm to sort the passes array.
		*/
		void sort(int array[], int size)
		{
			quickSort(array, 0, size - 1);
		}
		/*
		Implementation of the quick sort algorithm.
		Takes the integer array, starting index, and ending index.
		*/
		void quickSort(int array[], int start, int end)
		{
			if(start < end)
			{
				int pivot = array[end];
				int i = start;
				int j = end;
				
				while(i != j)
				{
					if(compare(pivot, array[i]))
					{
						i = i + 1;
					}
					else
					{
						array[j] = array[i];
						array[i] = array[j-1];
						j = j - 1;
					}
				}
	
				array[j] = pivot;
				quickSort(array, start, j - 1);
				quickSort(array, j + 1, end);	
			}
		}
		/*
		Returns the total number of comparisons made during sorting.
		*/
		int getNumOfComparisons()
		{
			return numOfComparisons;
		}
		/*
		Function to print the given array.
		Takes the given integer array, and its size as arguements.
		No return type, only console output.
		*/
		void print(int array[], int size)
		{
			for(int i = 0; i < size; i++)
			{
				cout << array[i] << ", ";
			}
			cout << endl;
		}
};
/*
Main function for testing above classes and functions.
*/
int main(int argc, char** argv) 
{
	int test[] = {2, 26, 324, 1, 69, 420, 666, 3, 13, 256};
	int size = sizeof(test)/sizeof(test[0]);
	
	SimpleSort *arraySorter = new SimpleSort();
	
	cout << "Original array: " << endl;
	arraySorter->print(test, size);
	
	arraySorter->sort(test, size);
	
	cout << "Sorted array using quick sort algorithm:" << endl;
	arraySorter->print(test, size);
	
	cout << "Total number of comparisons: " << arraySorter->getNumOfComparisons() << endl;
	
	system("pause");
	return 0;
}
