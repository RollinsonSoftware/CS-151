/*
File name: Lab7.cpp

Purpose/Problem:
In this lab, you will create four classes:

a parent class named Animal
a Bird class that is a child of Animal
a Dog class that is a child of Animal
a class named Lab7 which contains the main function and creates an Animal, a Dog, and a Bird object

Author: John Rollinson, CS151

Module #: 7
Lab #: 2

Algorithm:
The Animal class has:

one instance member, a private string variable named name.
a single constructor that takes one argument, a string, used to set the instance member using a member initialization list, then prints the message
  The Animal <its name> has been created..  
“getter” and “setter” functions for the instance member name
a no-argument function named sleep that prints the message
  The Animal <its name> is asleep.  
a no-argument function named makeNoise that prints the message
  The Animal <its name> is making a noise.  
a showInfo function that prints: “The Animal <its name>”.
Notice that there are NO references to the Dog or the Bird classes in Animal.

The Bird class:

is a child of the Animal class
has no instance members
has a single constructor that takes one argument, a string used to set the instance member of its parent (use member initialization list), then prints the message
  A Bird <its name> has been created.  
has a no-argument function named makeNoise that prints the message
  The Bird <its name> is chirping.  
has a showInfo function that prints
  The Bird <its name>  
The Dog class:

is a child of the Animal class
has one instance member, a private string named breed.
has a single constructor that takes two arguments, a string used to set the instance member of its parent, and another string used to set the instance member of this object (breed) using a member initialization list. It also prints the message
  A Dog <its name> of breed  has been created.  
has “getter” and “setter” functions for the instance member breed
has a no-argument function named makeNoise that prints the message
  The Dog <its name> is barking.  
has a showInfo function that prints
  The Dog <its name> of breed ts breed>.  
The Lab7 class contains a main function which:

creates an Animal object with a name “Oscar”.
creates a Dog object with a name “Inka” and a breed “Mutt”
creates a Bird object with a name “Tweety”
uses the showInfo function to print Oscar, Inka, and Tweety
causes Oscar, Inka, and Tweety each to make a noise
causes Oscar, Inka, and Tweety each to go to sleep
*/

/*
Lab Questions:
1. What is/are the names of the base classes?

There is only 1 base class in this program, which is the class Animal

2. What is/are the names of the derived classes?

There are 2 derived classes in this program, which are the class Dog and the class Bird.

3. Does Animal have a parent class?

No, the class Animal is the base class. However there may be a relation similar to java where all
user defined classes are derived classes of the class Object, but I was unable to confirm this online. 

4. Is the function showInfo() overridden? Is makeNoise? Is sleep?

Both the functions showInfo() and makeNoise() are overriden in both the Dog class and the Bird class
but the sleep() function is not overriden, it is only defined once in the base class Animal.

5. If the instance member name in the Animal class were made protected (instead of private), 
	would you need to use getters and setters in the showInfo function of the child classes Bird 
	and Dog? What if the instance members were left private, but the the access modifier to the 
	Animal class in both child classes were made protected?
	
   If the instance member name in the Animal class were made protected instead of private, then you
   would not need to user getters and setter in the showInfo function of the child classes Bird and Dog.
   If the instance members were left private, but the access modifiers the Animal class is both child
   classes were made protected then you would need to use the getters to access the instance members of
   the base class.
*/
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

class Animal
{
	private:
		string name;
	public:
		Animal(string name) : name(name)
		{
			cout << "The Animal " << getName() << " has been created." << endl;		
		}
		//Setters and Getters:
		string getName()
		{
			return this -> name;	
		}
		void setName(string name)
		{
			this -> name = name;
		}
		//Other Functions:
		void sleep()
		{
			cout << "The Animal " << getName() << " is asleep." << endl;
		}
		void makeNoise()
		{
			cout << "The Animal " << getName() << " is making a noise." << endl;
		}
		void showInfo()
		{
			cout << "The Animal " << getName() << "." << endl;
		}
};
class Bird : public Animal
{
	private:
		//No instance variables
	public:
		Bird(string name) : Animal(name)
		{
			cout << "The Bird " << getName() << " has been created." << endl;
		}
		void makeNoise()
		{
			cout << "The Bird " << getName() << " is chirping." << endl;
		}
		void showInfo()
		{
			cout << "The Bird " << getName() << "." << endl;
		}
};
class Dog : public Animal
{
	private:
		string breed;
	public:
		Dog(string name, string breed) : Animal(name)
		{
			setBreed(breed);
			cout << "The Dog " << getName() << " of breed " << getBreed() << " has been created." << endl;
		}
		//Getter and Setters:
		string getBreed()
		{
			return this -> breed;	
		}
		void setBreed(string breed)
		{
			this -> breed = breed;	
		}
		//Other functions:
		void makeNoise()
		{
			cout << "The Dog " << getName() << " is barking." << endl;
		}
		void showInfo()
		{
			cout << "The Dog " << getName() << " of breed " << getBreed() << "." << endl;
		}
};
int main(int argc, char** argv) 
{
	Animal *test1 = new Animal("Oscar");
	Dog *test2 = new Dog("Inka", "Mutt");
	Bird *test3 = new Bird("Tweety");
	
	cout << "\n*** SHOW INFO FOR EACH OBJECT ***\n" << endl;
	test1->showInfo();
	test2->showInfo();
	test3->showInfo();
	
	cout << "\n*** MAKE NOISE FOR EACH OBJECT ***\n" << endl;
	test1->makeNoise();
	test2->makeNoise();
	test3->makeNoise();
	
	cout << "\n*** GO TO SLEEP FOR EACH OBJECT ***\n" << endl;
	test1->sleep();
	test2->sleep();
	test3->sleep();
	
	return 0;
}
