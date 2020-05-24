/* Student.cpp - Function definitions for Student class, child of PersonAtMCC
 * Author:     John Rollinson
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Student.h"
#include <iostream>
using namespace std ;

/**** WRITE THE MISSING CONSTRUCTOR, USE MEMBER INITIALIZATION ****/
//Full Constructor:
Student::Student(long id, string name, string address, string phone, string major, int credits, bool applied, bool vet)
{
	setId(id);
	setName(name);
	setAddress(address);
	setPhone(phone);
	
	this -> major = major;
	this -> credits_received = credits;
	this -> applied_to_4_year = applied;
	this -> is_veteran = vet;	
} 
// Getters for this class only
string Student::getMajor() {
    return major ;
}

int Student::getCreditsReceived() {
    return credits_received ;
}

bool Student::getAppliedTo4Year() {
    return applied_to_4_year ;
}

bool Student::getIsVeteran() {
    return is_veteran ;
}

// Setters
void Student::setMajor(string new_major) {
    major = new_major ;
}

void Student::setCreditsReceived(int new_credits_received) {
    credits_received = new_credits_received ;
}

void Student::setAppliedTo4Year(bool new_has_applied) {
    applied_to_4_year = new_has_applied ;
}

void Student::setIsVeteran(bool new_is_veteran) {
    is_veteran = new_is_veteran ;
}

void Student::showInfo() {

    cout << "ID: " << getId() << " Name: " << getName() << " Address: " << getAddress() << endl ;
    cout << "	Phone: " << getPhone() << endl;
    cout << "	Major: " << getMajor() << " Credits: " << getCreditsReceived() << " 4-year?: ";
    
    if(getAppliedTo4Year())
    {
    	 cout << "yes";
	}
	else
	{
		cout << "no";
	}
	
	cout << " Veteran?: ";
	
	if(getIsVeteran())
	{
		cout << "yes\n";
	}
	else
	{
		cout << "no\n";
	}
    
    /**** COMPLETE THE OUTPUT ****/
}


