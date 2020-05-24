/*
File name: Lab1Main.cpp

Purpose/Problem:
In this lab you will manipulate a time variable and corresponding structure, print today's date and 
time in various formats, and determine how to adjust the internal form of other dates.

Author: John Rollinson, CS151

Module #: 4
Lab #: 1

Algorithm:
Open a new Dev-C++ project
At the top of the program, include the ctime library.
In main, create string arrays for:
weeks of the day (Sunday=0, Monday=1, Tuesday=2...)
months of the year (January=0, February=1, March=2...)
Create a time_t variable and set to the current time (don't forget to include ctime at the top of your program).
time_t now = time(NULL) ;
Establish a tm structure and reference with a pointer. Assign to the current time:
 tm *local = localtime(&now) ;
Using the values in the structure, print today's date using the following formats:
  1/1/20 (m/d/yy)
  January 1, 2020  
    1-Jan-2020
Print the current time in the following formats:
  17:30
  5:30pm / 12:00am  
Create a tm structure for your birthday and time, assigning all variables appropriately:
  tm birthday ;
 
  birthday.tm_year = ??? - 1900 ;
  birthday.tm_mon = ?? ;
  birthday.tm_mday = ?? ;
  birthday.tm_hour = ?? ;
  birthday.tm_min = ?? ;
  birthday.tm_sec = ?? ;
  birthday.tm_isdst = ?? ;  
Determine how many seconds after epoch you were born, then use the ctime function to print the date and time, and finally 
determine how old you are in seconds. (You can use any other big moment in your life, such as receiving your high school diploma, 
proposing to your significant other, driving your first car, opening your first paycheck, or a significant moment in history.)
  time_t time_of_birthday = mktime(&birthday) ;  
  cout << ctime(&time_of_birthday) << endl 
       << "I was born " << time_of_birthday
       << " seconds after epoch!" << endl ;  
Determine the number of seconds that occur in one week. (Multiply the number of days in a week by the number of hours 
in a day, by the number of minutes in an hour, by the number of seconds in a minute).  Use the computer to calculate this number.
Subtract the number of seconds in a week from the time_t variable created just above.
Print the date and time occurring exactly one week before the big moment in your life using the ctime function.
*/
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	string months[] = {"January", "February", "March", "April", "May", "June", "July", "August",
						 "September", "November", "Decemeber"};
	
	time_t now = time(NULL);
	
	tm *local = localtime(&now);
	
	cout << (local -> tm_mon) + 1 << "/" << local -> tm_mday << "/" << (local -> tm_year) - 100 << endl;
	cout << months[local -> tm_mon] << " " << local -> tm_mday << ", " << (local -> tm_year) + 1900 << endl;
	
	std::string monthAbrv = months[local -> tm_mon].substr(0, 3);
	cout << local -> tm_mday << "-" << monthAbrv << "-" << (local -> tm_year) + 1900 << endl << endl;
	
	if((local -> tm_min) > 10)
	{
		cout << local -> tm_hour << ":" << local -> tm_min << endl;
	}
	else
	{
		cout << local -> tm_hour << ":" << local -> tm_min << "0" << endl;
	}
	
	
	if((local -> tm_hour) > 12)
	{
		if((local -> tm_min) > 10)
		{
			cout << (local -> tm_hour) - 12 << ":" << local -> tm_min << " pm" << endl;
		}
		else
		{
			cout << (local -> tm_hour) - 12 << ":" << "0" << local -> tm_min << " pm" << endl;
		}
	}
	else if((local -> tm_hour) == 12)
	{
		if((local -> tm_min) > 10)
		{
			cout << local -> tm_hour << ":" << local -> tm_min << " pm" << endl;
		}
		else
		{
			cout << local -> tm_hour << ":" << "0" << local -> tm_min << " pm" << endl;
		}
	}
	else
	{
		if((local -> tm_min) > 10)
		{
			cout << local -> tm_hour << ":" << local -> tm_min << " am" << endl;
		}
		else
		{
			cout << local -> tm_hour << ":" << "0" << local -> tm_min << " am" << endl;
		}
	}
	
	//Creating a tm structure for birthday and time:
	tm birthday;
	birthday.tm_year = (1999) - 1900;
	birthday.tm_mon = (12) - 1;
	birthday.tm_mday = 18;
	birthday.tm_hour = 7;
	birthday.tm_min = 28;
	birthday.tm_sec = 58;
	birthday.tm_isdst = 0;
	
	//Determining the number of seconds after epoch you were born.
	time_t time_of_birthday = mktime(&birthday);
	
	//printing birthday date and time, and no. of seconds after each epoch you were born.
	cout << ctime(&time_of_birthday) << endl << "I was born " << time_of_birthday << " seconds after epoch" << endl;
	
	long long int seconds_in_a_week = 60 * 60 * 24 * 7; // calculating no. of seconds in a week.
	
	time_of_birthday -= seconds_in_a_week; // subtract no.of seconds in a week from time_of_birthday.
	
	cout << "One week earlier to birthday: " << ctime(&time_of_birthday) << endl; //printing date and time exactly 1 week prior to birthday. 
				 
	return 0;
}

//Example code:
/*
int main() 
{    
	// Get the current time in seconds from epoch    
	time_t now_in_seconds ;    
	time(&now_in_seconds) ;                     // Method #1    
	// now_in_seconds = time(NULL) ;            // Method #2    
	cout << "It has been " << now_in_seconds         
	<< " seconds since January 1, 1700" << endl << endl ;    
	// Create an array of days of the week    
	string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",                     
					 "Friday", "Saturday"} ;    
	
	// Convert to a structor of days representing the month, day, seconds, day-ot-the-week,    
	// year, etc.    
	tm *local_time = localtime(&now_in_seconds) ;    
	cout << "Today is:       " << days[local_time->tm_wday] << endl ;    
	cout << "Current hour:   " << local_time->tm_hour << endl ;    
	cout << "Minute is:      " << local_time->tm_min << endl ;    
	cout << "Daylight Savings Time? " << (local_time->tm_isdst ? "Yes" : "No") << endl << endl ;    
	system("pause") ;    
	return 0;
}
*/
