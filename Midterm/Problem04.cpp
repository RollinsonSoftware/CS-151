/* Inheritance.cpp - Create a Person / Teacher / MathTeacher hierarchy of classes
 * Author:     Chris Merrill and John Rollinson
 * Module:     Midterm
 * Project:    4
 * Problem statement: Create a hierarchy of Person / Teacher / MathTeacher, each
 *   with a profession (string) and age (int) stored in Person, and which inherit
 *   getters and setters for those two properties.  In addition, the Teacher
 *   and MathTeacher classes have a "teach" method.
 */

#include <iostream>
using namespace std;

class Person 
{
    private:
        string profession;
        int age;
    public:
        // Add constructor which takes a profession and age, and uses an initialization
        // list to initialize both instance members
        Person(string profession , int age) : profession(profession), age(age)
		{
			
		}
        // Add getters and setters
        void setProfession(string profession)
		{	
        	this->profession = profession;
		}
		void setAge(int age)
		{	
			this->age = age;
		}
		string getProfession()
		{	
			return profession;
		}
		int getAge()
		{	
			return age;
		}
};
class Teacher : public Person  // make a child of Person
{                 
    private:
		//Nothing!
    public:
        // Add a constructor which takes an age, calls Person constructor with "Teacher" as profession
    	Teacher(int age) : Person("Teacher", age)
		{
			
		}
        // Add another constructor which takes both a profession and an age, then passes
        // both up to Person constructor 
    	Teacher(string profession , int age) : Person(profession , age)
		{
			
		}
        // Create a function teach() which prints on the console:
        //      The <profession> is teaching
        void teach()
		{	
        	cout << "The " << this->getProfession() << " is teaching"<< endl;
		}
};
class MathTeacher : public Teacher // make a child of Teacher
{            
    private:
		//Nothing!
    public:
        // Add a constructor which takes an age, calls Teacher constructor with "Math Teacher" as profession
        MathTeacher(int age):Teacher("Math Teacher", age)
		{
			
		}
};
int main() 
{
	// Create a Person object, a Teacher object, and a MathTeacher object
	Person person("Worker", 27);
    Teacher teacher(42);
    MathTeacher mathTeacher(39);

    cout << "The person's profession is: " << person.getProfession()
         << " and is " << person.getAge() << " years old" << endl;
         
    cout << "The teacher's profession is: " << teacher.getProfession()
         << " and is " << teacher.getAge() << " years old" << endl;
         
    cout << "The mathTeacher's profession is: " << mathTeacher.getProfession()
         << " and is " << mathTeacher.getAge() << " years old" << endl << endl;

    teacher.teach();
    mathTeacher.teach();

    return 0;
}
