/*
File name: project1main.cpp

Purpose/Problem:
Start with a pillbox having 10 empty slots. Your job is to put 10 pills 
(lettered A, B, C... J) by selecting a slot randomly for each pill until finding 
an empty slot. For each pill, record the number of attempts it took to find an 
empty slot for that pill.

Author: John Rollinson, CS151

Module #: 4
Homework #: 1

Algorithm:
Create the structure for Pill, which defines the letter of the pill and keeps track of the attempts.
Set the seed of the C++ random number generator to create a different set of numbers each time the program runs.
Create an array of 10 unique pointers to Pill structures.
By using unique pointers, we guarantee that each Pill can be referenced by one and only one slot in the pillbox.
Create a loop for which processes a single pill (lettered A, B, C... through J).
For that pill, generate another loop that creates a random number between 0 and 9. Make sure that you track the 
number of attempts it takes to find an open slot in the pillbox.
If the slot at that index is not available, go back and try another random number, increasing the number of 
attempts by 1.
If the slot is available, then create a new Pill structure for this pill letter and the number of attempts it 
took to find an available slot for this pill.
Exit the loop generating random numbers, and start looking for a slot for the next pill.
When all 10 pills have been placed into a slot in the pillbox, print a report showing:

The slot number (0 - 9)
The pill letter assigned to that slot (slots[i]->pill_number)
The number of attempts it took to find an available slot for that pill letter (slots[i]->attempts)
A grand total of the number of attempts

Notice that pill A (the first pill) should take only one attempt, since all ten slots are available when placing that pill. For pill B, 
the number of attempts should also be a very low number, since 9 of the 10 slots are still available.

However, as the pill numbers climb, so should the number of attempts. For example when trying to place pill J, 9 of the 10 slots are already filled.

Sort all the pills in the array by pill letter and then output a second report.
*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Pill
{
	char letter;
	int attempts;
	
	Pill(char newLetter, int newAttempts)
	{
		letter = newLetter;
		attempts = newAttempts;
	}
	~Pill()
	{
		
	}
};

const int SIZE = 10;

int main(int argc, char** argv) 
{
	srand(time(NULL));
	unique_ptr<Pill> slots[SIZE]; 
	
	for(int i = 0; i < SIZE; i++)
	{
		char pill_letter = (char)(i + 65);
		int attempts = 1;
		
		while(true)
		{
			//Generate random number in range 0 - 9
			int index = rand() % 10;
			if(!slots[index])
			{
				//Empty
				unique_ptr<Pill> new_pill(new Pill(pill_letter, attempts));
				slots[index] = move(new_pill);
				break;
			}
			else
			{
				attempts++;
			}
		}
	}
	
	int totalAttempts = 0;
	
	//Output:
	cout << setw(5) << left << "Slot" << setw(5) << left << "Pill" << setw(8) << "Attempts" << endl;
	cout << setw(5) << "---- " << setw(5) << "---- " << setw(8) << "--------" << endl;
	
	for(int i = 0; i < SIZE; i++)
	{
		totalAttempts += slots[i] -> attempts;
		cout << setw(5) << i << setw(5) << slots[i] -> letter << setw(8) << slots[i] -> attempts << endl;
	}
	
	cout << "\nTotal Attempts :" << totalAttempts << "\n" << endl;
	
	//Shorting by letter Extra Credit:
  	for(int i = 0; i < SIZE - 1; i++)
	{
   	// int tmp = 0; //temporary variable
    	for(int j = i + 1; j < SIZE; j++)
		{
       		if(slots[i] -> letter > slots[j] -> letter)
			{
        		//tmp++;
        		unique_ptr <Pill> tmp(new Pill(slots[i] ->	letter , slots[i] -> attempts));
         		slots[i] = move(slots[j]);
         		slots[j] = move(tmp);
       		}
    
    	}
  	}
  	
	//Output:
	cout << setw(5) << left << "Slot" << setw(5) << left << "Pill" << setw(8) << "Attempts" << endl;
	cout << setw(5) << "---- " << setw(5) << "---- " << setw(8) << "--------" << endl;
	
	for(int i = 0; i < SIZE; i++)
	{
		totalAttempts += slots[i] -> attempts;
		cout << setw(5) << i << setw(5) << slots[i] -> letter << setw(8) << slots[i] -> attempts << endl;
	}
	
	cout << "\nTotal Attempts :" << totalAttempts << "\n" << endl;
	return 0;
}
