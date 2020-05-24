/*
File name: project1main.cpp

Purpose/Problem:
Write a program that dynamically allocates an array large enough to hold a 
user-defined number of test scores.  Once all of the scores are entered the 
array should be passed to a function that sorts them in ascending order.  
Another function should be called that calculates the average score.  
The program should then display the sorted list of scores and the average 
with appropriate headings.  Use pointer notation rather than array notation 
whenever possible.

Author: John Rollinson, CS151

Module #: 3
Homework #: 1

Algorithm:
Implement the sortTestScores function that accepts a dynamic array of test scores and
the size of the array and then sorts the test scores in asecending order.
Implement the averageTestScore function that accepts a dynamic array of the test scores and
the size of the array and then calculates and returns the average of the test scores.
Implement the printTestScores function that accepts a dynamic array of test scores and the
size of the array and then prints all the test scores stored in the array.
Implement the main function that dynamically allocates an array with the user specified size
and reads the test scores from the user into the array. It sorts the test scores in ascending
order, finds the average of test scores, and prints the test scores by using the function.
Do not allow the negative numbers for test scores and use the pointer notation instead of the
array notation.
*/
#include <iostream>
#include <iomanip>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* The following program dynamically allocates an array
   with the user specified size and reads the test scores
   from the user into the array. It sorts the test scores
   in ascending order, finds the average of the test scores,
   and prints the test scores by using the functions. It
   does not allow a negative number for a test score and
   uses pointer notation instead of array notation.*/


using namespace std;

//function prototypes:
void sortTestScores(int *testScores, int size);
void printTestScore(int *testScores, int size);
double averageTestScore(int *testScores, int size);

/*
The following sortTestScores function accepts a dynamic array of the test scores
and the size of the array and then sorts the test scores in ascending order.
*/
void sortTestScores(int *testScores, int size)
{
	//get the last location of the array.
	int *last = testScores + size;
	
	for(int *start = testScores; start < last - 1; start++)
	{
		for(int *next = start + 1; next < last; next++)
		{
			//swap the values if next is less than start
			if(*next < *start)
			{
				int temp = *start;
				*start = *next;
				*next = temp;
			}
		}
	}
}
/*
The following averageTestScore function accepts a dynamic array of the test scores
and the size of the array and then calculates and returns the average of the test
scores.
*/
double averageTestScore(int *testScores, int size)
{
	int sum = 0;
	int *current = testScores;
	
	//compute the sum of all the test scores
	for(int i = 0; i < size; i++)
	{
		sum += *current;
		current++;
	}
	
	return ((double)sum / size);
}
/*
The following printTestScores function accepts a dynmaic array of the test scores
and the size of the array and then prints all the test scores stored in the array.
*/
void printTestScores(int *testScores, int size)
{
	//print all the test scores stored in the array.
	int *current = testScores;
	
	for(int i = 0; i < size; i++)
	{
		cout << *current << " ";
		current++;
	}
	cout << endl;
}

int main(int argc, char** argv) {
	//variables:
	int *testScores; // to dynamically allocate an array
	int size;
	int score;
	double average;
	
	//prompt the user to enter the size of the array.
	cout << "Enter the size of the array: ";
	cin >> size;
	
	//allocate the array dynamically large enough to hold the test scores.
	testScores = new int[size];
	
	//prompt the user to enter the scores into the array.
	cout << "\nEnter " << size << " positive values for the test scores." << endl;
	
	for(int i = 0; i < size; i++)
	{
		//prompt the user to enter a test score.
		cout << "Score " << (i + 1) << ": ";
		cin >> score;
		
		//checking for negative numbers
		while(score < 0)
		{
			cout << "Again: " << (i + 1) << ": ";
			cin >> score;
		}
		
		//Store the test score into the array
		testScores[i] = score;
	}
	
	cout << "\nTest scores before sorting: ";
	printTestScores(testScores, size);
	
	sortTestScores(testScores, size);
	cout << "Test scores after sorting: ";
	printTestScores(testScores, size);
	
	average = averageTestScore(testScores, size);
	cout << "Average test score: " << setprecision(2) << fixed << average << endl;
	cout << endl;
	system("pause");
	
	
	return 0;
}
