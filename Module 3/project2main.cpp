/*
File name: project2main.cpp

Purpose/Problem:
Modify the program above to allow the user to enter name-score pairs.  
For each student taking the test, the user should enter a string representing 
name of the student, followed by an integer representing the student's score.  
Modify both the sorting and average-calculating functions so they take arrays 
of objects, with each object containing the name and score of a single student.  
In traversing the arrays, use pointers than array indices.

Author: John Rollinson, CS151

Module #: 3
Homework #: 2

Algorithm:
Declare the structure details.
Prompt the user to enter the number of students.
Declare the pointer type variables.
Dynamically allocate the memory for the structure.
Prompt the user to enter the names and scores of the students.
Sort the array using pointers in the sort function.
Define a function called average, this will find the average test score.
Sort the array and display the sorted data to the screen.
Display results for the user.
*/
#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct details
{
	string name;
	int score;
};

void sort(details p[], int number);
void average(details p[], int number);

int main(int argc, char** argv) 
{
	int number;
	cout << "Enter the number of students: ";
	cin >> number;
	
	struct details *d, *t;
	t = new details[number];
	d = t;
	
	for(int i = 0; i < number; i++)
	{
		cout << "Enter the name and score: ";
		cin >> (d + i) -> name;
		cin >> (d + i) -> score;
	}
	
	sort(d, number);
	
	cout << "Sorted test scores are:" << endl;
	for(int i = 0; i < number; i++)
	{
		cout << (d + i) -> name << "\t" << (d + i) -> score << endl;
	}
	
	average(d, number);
	delete t, d;
	
	system("pause");
	return 0;
}

void sort(details p[], int number)
{
	details *d = p;
	details temp;
	
	for(int i = 0; i < number; i++)
	{
		for(int j = i + 1; j < number; j++)
		{
			if(((d + i) -> score) > ((d + j) -> score))
			{
				temp = *(d + i);
				*(d + i) = *(d + j);
				*(d + j) = temp;
			}
		}
	}
}
void average(details p[], int number)
{
	double total = 0;
	double average;
	
	details *d = p;
	
	for(int i = 0; i < number; i++)
	{
		total = total + (d + i) -> score;
	}
	
	average = (total / static_cast<double>(number));
	
	cout << "The average of the scores is: " << average << endl;
}
