/* PeopleTester.cpp - Create objects of subclasses to PersonAtMCC class
 * Author:     John Rollinson
 * Module:     7
 * Project:    Lab, Part 1
 * Problem statement:  Create a parent class PersonAtMCC with subclass for
 *    Students, Staff, and Instructors.
 *
 * Algorithm:
 *   1.  Create two student objects for Amelia Earhart and Muhammed Ali
 *   2.  Create an instructor object for Juanita
 *   3.  Create a Staff object for Eliot Ness
 *   4.  Create a PersonAtMCC (the parent) object for Ralph Kramden
 
Create a Dev-C++ project, download those program files and place into your project
The Staff, Instructor, and Student classes should be children of the PersonAtMCC class. 
Fix the declaration of those three files (in Staff.h, Instructor.h, and Student.h) to convey this. 
Allow public access to PersonAtMCC in all three children.
Write the missing constructors in Staff.cpp, Instructor.cpp, and Student.cpp. Use setters for 
properties in the parent class, and assignment statements for properties in the child class.
In PeopleTester.cpp, complete the definitions of the students, instructor, staff member, and 
another person using the data below.
Fix the showInfo function in all four class.
Under the information for Ralph Kramden, add a statement that runs the PersonAtMCC class 
(the base class) version of showInfo for Ms. Earhart.
 */

#include "PersonAtMCC.h"
#include "Student.h"
#include "Staff.h"
#include "Instructor.h"
#include <iostream>
using namespace std ;

int main() {

    // Create Student objects for Amerlia Earhart and Muhammed Ali.
    Student *amelia = new Student(940392,
                                "Amelia Earhart",
                                "123 Main Street, Oceanside, CA",
                                "760.213.4930",
                                "Computer Science",
                                240,
                                true,
                                true) ;
    Student *muhammed = new Student(840392,
									"Muhammed Ali",
									"294A West 4th Ave., Escondido, CA",
									"760.294.4932",
									"Math",
									134,
									false,
									false) ;


    // Show the information for both students
    cout << "*** TWO STUDENTS ***\n" << endl ;
    amelia->showInfo() ;
    muhammed->showInfo() ;

    // How about a friendly instructor?
    Instructor *professorJudy = new Instructor(6294032,
												"Juanita Ramirez",
												"843 C St., Apt 43, San Diego, CA",
												"619.427.4933",
												"English",
												false,
												59.85,
												160) ;

    cout << "\n*** A FRIENDLY INSTRUCTOR ***\n" << endl ;
    professorJudy->showInfo() ;

    // And the facilities guy
    Staff *elliot = new Staff(84920493,
								"Eliot Ness",
								"15 East Ramona Way, Ramona, CA",
								"760.583.3911",
								"x5923",
								"Nov. 15, 2015",
								49.25) ;

    cout << "\n*** STAFF MEMBER ***\n" << endl ;
    elliot->showInfo() ;

    // Finally just a plain old PersonAtMCC
    PersonAtMCC *ralph = new PersonAtMCC(10000000,
											"Ralph Kramden",
											"999 Yellow Brick Road",
											"555-BANG-ZOOM") ;
											
    cout << "\n*** JUST ANOTHER PERSON AT MCC ***\n" << endl ;
    ralph->showInfo() ;
	
	cout << "\n*** BASE CLASS SHOWINFO FOR MS. EARHART ***\n" << endl ;
	amelia->PersonAtMCC::showInfo() ;
	
    system("pause") ;
    return 0 ;
}
