/*
File name: Project1and2Main.cpp

Purpose/Problem:
Assuming that a year has 365 days, write a class named DayOfYear that takes 
an integer representing a day of the year and translates it to a string for 
output consisting of the month followed by day of the month.  For example:

day 2 would be "January 2".
day 32 would be "February 1".
day 365 would be "December 31".
The class should have:

a constructor for the class which takes as a parameter an integer representing 
the day number of the year
an private integer member variable to store the parameter
a "getter" to return the value of the member variable
member function which overloads the stream extraction operator to print the day in 
month-day format.
static constants which will assist in the conversion from an integer to a month-day 
format, for example, a collection of month names and days in each month.

The DayOfYear class described above should have a second constructor that takes two parameters: 
a string representing a month name and an integer in the range 1 through 31 representing the day 
of the month.  The constructor should then initialize the integer member of the class to represent 
the day specified by the month and day of month parameters.  The constructor should terminate the 
program with an appropriate error message if the month name entered is invalid or if the number 
entered for a day is outside the range of days for the month given.

Add the following overloaded operators:

prefix and postfix ++ (increment) operators.  These operators should modify the DayOfYear object 
so that it represents the next day.  If the day is already the end of the year, then the new value 
of the object will represent the first day of the year.

prefix and posfix –– (decrement) operators.  These operators should modify the DayOfYear object so 
that it represent the previous day.  If the day is already the first day of the year, then the new 
value of the object will represent the last day of the year.

Demonstrate the class by writing a main program which shows the appropriate month-day dates for 
days numbered 15, 31, 59, 180, and 360.

Also in main, demonstrate the second constructor by displaying the appropriate day number for 
"January 1", "March 4", "July 27", and "December 31".

Demonstrate how the prefix –– operator works on the first date (January 1) and the prefix ++ 
operator works on the second date (March 4) above.  To do this, using separate cout statements, 
show the original value of the object (in month-day format), the object using the prefix++ or –– 
operator, and the final value of the object on three separate lines.  For example, to demonstrate 
the prefix –– on day 1, the output might look like:

  Using day 1:
  The original value: January 1  
  Using prefix––    : December 31  
  After prefix––    : December 31
Also demonstrate how the postfix version of the –– and ++ operators work by doing the same thing 
on the third (July 27) and fourth (December 31) dates above, respectively.

Finally demonstrate what happens when an invalid month/day combination (such as February 30) is 
entered using the second constructor.

Author: John Rollinson, CS151

Module #: 7
Homework #: 1 and 2

Algorithm:
Test the single argument constructor for the first project in the main function.
Test the full argument constructor for the second project in the main function.
Test all of the overloaded operators.
*/
#include <iostream>
#include "DayOfYear.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	cout << " - Project 1 Testing -\nUsing the single argument constructor:\n";
	
	DayOfYear day1 = DayOfYear(15);
	cout << day1 << endl;
	
	DayOfYear day2 = DayOfYear(31);
	cout << day2 << endl;
	
	DayOfYear day3 = DayOfYear(59);
	cout << day3 << endl;
	
	DayOfYear day4 = DayOfYear(180);
	cout << day4 << endl;
	
	DayOfYear day5 = DayOfYear(360);
	cout << day5 << endl;
	
	cout << "\n=============================\n";
	
	cout << "\n - Project 2 Testing -\nUsing the full constructor:\n";
	
	DayOfYear day6 = DayOfYear("January", 1);
	cout << day6 << endl;
	
	DayOfYear day7 = DayOfYear("march", 4);
	cout << day7 << endl;
	
	DayOfYear day8 = DayOfYear("JULY", 27);
	cout << day8 << endl;
	
	DayOfYear day9 = DayOfYear("DeCeMbEr", 31);
	cout << day9 << endl;
	
	//pre and post output:
	cout << "\nUsing Jan. 1st: " << "\nThe original value: " << day6 << "\nUsing prefix--: " << --day6 << "\nAfter prefix--: " << day6 << endl;
	
	cout << "\nUsing Mar. 4th:\n" << "The original value: " << day7 << "\nUsing prefix++: " << ++day7 << "\nAfter prefix++: " << day7 << endl;

	cout << "\nUsing Jul. 27th: " << "\nThe original value: " << day8 << "\nUsing postfix--: " << day8-- << "\nAfter postfix--: " << day8 << endl;
	
	cout << "\nUsing Dec. 31st:\n" << "The original value: " << day9 << "\nUsing postfix++: " << day9++ << "\nAfter postfix++: " << day9 << endl;	

	cout << "\nEntering an invalid date into constructor:\n";
	
	DayOfYear day10 = DayOfYear("February", 30);
	cout << day10;
	
	return 0;
}
