/* lab6Part2.cpp
 * Author:     John Rollinson
 * Module:     6
 * Project:    Lab, Part 2
 * Problem statement: Create a TimeDate class that is "owned" by an Event class, 
 demonstrating composition.
 
 * Algorithm:
Create a class named TimeDate with the following four private instance members, 
consisting of three ints and one string:
  class TimeDate {
      private:
          int hour, minute, day ;  
          string month ;
  } ;
 
Inside the TimeDate class, create a constructor which uses member lists to initialize 
each of the five instance members of the class:
  public:
      TimeDate(int hour, int minute, int day, string month) :
          hour(hour), 
          minute(minute),
          day(day), 
          month(month) { } ;
 
Also in the Timedate class, create a function which returns the TimeDate as a string:
  string getTimeDate() {
      string print_hour = to_string(hour) ;
      string am_pm = (hour < 12 ? "am" : "pm") ;
      if (hour == 0)
          print_hour = "12" ;
      if (hour > 12)
          print_hour = to_string(hour - 12) ;
      return month + " " + to_string(day) + 
             " at " + print_hour + ":" +  
             (minute < 10 ? "0" : "") + to_string(minute) + am_pm ;  
  }
 
Create a new class named Event which consists of three variables: a start time, an end 
time, and a description:
  class Event {
      private:
          TimeDate start_time, end_time ;  
          string description ;
  } ;
 
Create a constructor for the Event class which initializes all variables using member 
initialization lists and a method to return information about the event:
  public:
     Event(int start_hour, int start_minute, int start_day, 
           string start_month, 
           int end_hour, int end_minute, int end_day,
           string end_month, string description) : 
              <can you determine what goes here?> { } ;
     string getEvent() {
         return description + " starts at " + 
                start_time.getTimeDate() +
                ", ends at " +
                end_time.getTimeDate() ;
     }
 
In main, create two events and print, for example:
  Event party(17, 30, 14, "Oct.", 20, 30, 14, "Oct.", 
              "My Birthday Party") ;
  cout << party.getEvent() << endl ;
  . . .
 
 */
#include <iostream>

using namespace std;

//create TimeDate class
class TimeDate 
{
	private:
    	int hour, minute, day;  
    	string month;
	
	public:
		TimeDate(int hour, int minute, int day, string month) : hour(hour), minute(minute), day(day), month(month) 
		{ 
			
		};
      
    	string getTimeDate()
		{
    		string print_hour = to_string(hour);
    		string am_pm = (hour < 12 ? "am" : "pm");
    		
    		if (hour == 0)
    		{
				print_hour = "12";
          	}
      		if (hour > 12)
      		{
				print_hour = to_string(hour - 12);
          	}
          
    		return month + " " + to_string(day) +   " at " + print_hour + ":" +  (minute < 10 ? "0" : "") + to_string(minute) + am_pm;  
		}		
};
  
class Event 
{
	private:
		TimeDate start_time, end_time;  
		string description;
		
	public:
		Event(int start_hour, int start_minute, int start_day, 
		string start_month, int end_hour, int end_minute, int end_day,
    	string end_month, string description) : start_time(start_hour, start_minute, start_day, start_month), 
		end_time(end_hour,end_minute,end_day,end_month), description(description){ };
		
		string getEvent() 
		{
			return description + " starts at " + start_time.getTimeDate() + ", ends at " + end_time.getTimeDate() ;
		}
};
  
int main()
{
	Event party(15, 30, 3, "Nov.", 20, 30, 3, "Nov.", "My Birthday Party");
	cout << "\nEvent Birthday: " << party.getEvent() << "."<< endl << endl;

	Event graduation(17, 30, 14, "Oct.", 20, 30, 14, "Oct.", "My Graduation Party");
	cout << "New Event: " << graduation.getEvent() << "."<< endl;

	return 0;
}
  
  
