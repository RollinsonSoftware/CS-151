/* PersonAtMCC.cpp - Function definitions for parent class
 * Author:     John Rollinson
 * Module:     7
 * Project:    Lab, Part 1
 * Description:  Function definitions for parent class
 */

#include "PersonAtMCC.h"
#include <iostream>
using namespace std ;

/**** WRITE THE MISSING CONSTRUCTORS, USE MEMBER INITIALIZATION ****/
//defualt
PersonAtMCC::PersonAtMCC()
{
	setId(0);
	setName("John Doe");
	setAddress("1234 Hill Top Lane");
	setPhone("760-123-4567");
}
//id and name constructor
PersonAtMCC::PersonAtMCC(long id, string name)
{
	setId(id);
	setName(name);
	setAddress("1234 Hill Top Lane");
	setPhone("760-123-4567");
}
//full constructor
PersonAtMCC::PersonAtMCC(long id, string name, string address, string phone)
{
	setId(id);
	setName(name);
	setAddress(address);
	setPhone(phone);
}
// getters and setters
long PersonAtMCC::getId() {
    return id ;
}

string PersonAtMCC::getName() {
    return name ;
}

string PersonAtMCC::getAddress() {
    return address ;
}

string PersonAtMCC::getPhone() {
    return phone ;
}

// Setters
void PersonAtMCC::setId(long new_id) {
    id = new_id ;
}

void PersonAtMCC::setName(string new_name) {
    name = new_name ;
}

void PersonAtMCC::setAddress(string new_address) {
    address = new_address ;
}

void PersonAtMCC::setPhone(string new_phone) {
    phone = new_phone ;
}

void PersonAtMCC::showInfo() {
	cout << "ID: " << getId() << " Name: " << getName() << " Address: " << getAddress() << endl ;
    cout << "	Phone: " << getPhone() << endl << endl;

    /**** COMPLETE THE OUTPUT ****/
}
