/* Staff.cpp - Function definition file for Staff, child of PersonAtMCC
 * Author:     John Rollinson
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Staff.h"
#include <iostream>
using namespace std ;

/**** WRITE THE MISSING CONSTRUCTOR, USE MEMBER INITIALIZATION ****/
//Full constructor:
Staff::Staff(long id, string name, string address, string phone, string ext, string hire, double pay)
{
	setId(id);
	setName(name);
	setAddress(address);
	setPhone(phone);
	
	this -> extension = ext;
	this -> hire_date = hire;
	this -> pay_rate = pay;
}
// Getters for this class only
string Staff::getExtension() {
    return extension ;
}

string Staff::getHireDate() {
    return hire_date ;
}

double Staff::getPayRate() {
    return pay_rate ;
}

// Setters for this class only
void Staff::setExtension(string new_extension) {
    extension = new_extension ;
}

void Staff::setHireDate(string new_hire_date) {
    hire_date = new_hire_date ;
}

void Staff::setPayRate(double new_pay_rate) {
    pay_rate = new_pay_rate ;
}

void Staff::showInfo() {
    cout << "ID: " << getId() << " Name: " << getName() << " Address: " << getAddress() << endl ;
    cout << "	Phone: " << getPhone() << endl;
    cout << "	Extension: " << getExtension() << " Hire Date: " << getHireDate() << " Pay-Rate: $" << getPayRate() << endl;

    /**** COMPLETE THE OUTPUT ****/
}

