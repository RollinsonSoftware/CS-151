/*
Names: Chandler Ott, John Rollinson, Shachar Habusha, Sam Nejad
File Name: GymMembership.cpp
Purpose: create a class that tracks the following for a new gym:
			number of active members
			id's for new members
			total visits for all members
			member names, number of visits, and membership type
Algorithm:
In this first part of the lab, you will create a class that tracks the following for a new gym:

number of active members
id's for new members
total visits for all members
member names, number of visits, and membership type
Define the Member class
Create a new project in Dev-C++ (or whatever IDE you are using).
Create two constants at the top of your program:
  const double BASIC_RATE = 28.50,  
               PREMIUM_RATE = 60.00 ;  
 
Create a struct named Member.  It should have:
static member declarations for an int named last_id, another int named active_members, 
and a third int named total_visits. 
static int total_visits,      // count all visits from members  
           active_members,    // total members active in my gym 
           last_id ;          // id assigned to newest member
 
instance members for the member's id (an int), member's name (string), membership type 
(a char), and visits (another int).
  int id ;         // id of this member
  string name ;    // name of this member
  char type ;      // type of member (B = basic, P = premium)  
  int visits ;     // visits by this member
 
a constructor which:
assigns the last_id to the member's id, then increments the last_id by 1
increments the active_members count by 1
assigns the member's name to a string passed as a parameter
assigns the member's membership type to another parameter passed as a char
  Member(string name, char type) {
      this->name = name ;
      this->type = type ;
      active_members++ ;
      id = last_id++ ;
  }
 
a destructor which decrements the active_members by 1
Outside Member the structure, define the static variables in the structure
Set the last_id to 10000.
Set the active_members and total_visits to 0.
  // Define static variables
  int Member::total_visits = 0 ;
  int Member::active_members = 0 ;  
  int Member::last_id = 100000 ;
 
Create members and start counting visits
Create a function named visit which increments the number of visits for a member 
and for the gym.
It should take a reference or pointer to Member struct as its lone parameter.
It should increment the number of visits for the member and the total visits for the gym
In main:
Create a vector of pointers to Member structures.
Create a Member object using the new operator and add pointers to the following Member 
objects to the vector:
      Member       Type  
  --------------   ----
  Oprah Winfrey     P
  Fluffy Iglesias   P
  Charlie Sheen     B
  Bill Gates        B
 
Drop the membership for Charlie Sheen.
delete the pointer to Charlie's Member object from the vector
delete Charlie's Member object from the heap.
For each of the three remaining members:
Generate a random number between 5 and 20.
Call the visit function for that member that many times
When done, print a report which prints for each member:
the member's id
the member's name
the number of visits
the monthly rate for the member (type = 'B' use the basic rate, 'P' use the premium rate).
At the bottom of the report, use the static variables to show the total visit for the 
gym and the number of active members (should be 3).
*/
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const double BASIC_RATE = 28.50,  
             PREMIUM_RATE = 60.00;
               
struct Member
{
		string name;
		int visits, id;
		char type;
		static int total_visits, active_members, last_id;
		
	Member(string name, char type) 
		{
	      this->name = name ;
	      this->type = type ;
	      visits = 0;
	      active_members++ ;
	      id = last_id++ ;
	  	}
	  	
	~Member() 
	{
		active_members--; 
	}
	
};

	// Defining static variables  
	  int Member::total_visits = 0 ;
	  int Member::active_members = 0 ;  
	  int Member::last_id = 100000 ;
	  
	  void visit(Member &m);
	  
int main() {
	
	srand(time(NULL));
	
	vector<Member*> mem_ptrs;
	
	Member *oprah = new Member("Oprah Winfrey",'P');
	Member *fluffy = new Member("Fluffy Iglesias",'P');
	Member *charlie = new Member("Charlie Sheen",'B');
	Member *bill = new Member("Bill Gates",'B');
	
	mem_ptrs.push_back(oprah);
	mem_ptrs.push_back(fluffy);
	mem_ptrs.push_back(bill);
	mem_ptrs.push_back(charlie);
	
	//delete the pointer to Charlie's Member object from the vector
	mem_ptrs.pop_back();
	
	//delete Charlie's Member object from the heap.
	delete charlie;
	
	
	for(int j =0; j <mem_ptrs.size(); j ++) {
		int rand_num = rand() % 16 + 5;
		
		for (int i = 0; i < rand_num; i++)
		{
			visit(*mem_ptrs.at(j));
		}
	}
	
	//Printing
	
	cout << setw(-3) << right << "ID" <<setw(13) << right << "Member" << setw(17) << right << "Type" << setw(12) << right << "Visits" << endl;
	cout << "------   ---------------    ----      ------" << endl; 
	
	for(int i = 0; i < mem_ptrs.size(); i++)
	{
		cout << setw(0) << right << mem_ptrs.at(i)->id << setw(18) << right << mem_ptrs.at(i)->name << setw(8) << right << mem_ptrs.at(i)->type << setw(12) << right << mem_ptrs.at(i)->visits << endl; 	
	}
	
	cout << "\nTotal visits for the entire Gym: " << Member::total_visits << endl;
	cout << "Total active members for the entire Gym: " << Member::active_members << endl;
	return 0;
}

void visit(Member &m)
{
	m.visits++;
	Member::total_visits++;
}
