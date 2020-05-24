/** Set.java - Emulates a set in C++
 * Author:     Chris Merrill, Shachar Habusha, John Rollinson
 * Module:     15
 * Project:    Demonstration
 * Problem statement:  Use a linked list to create a class template which
 *      performs the following set functions:
 *
 *    constructor - creates an empty set
 *    contains - returns true if an item is in the set (uses = operator)
 *    insert - adds an item (in sorted order) to the set (duplicates not allowed)
 *    display - shows the contents of the set on the screen
 *    toVector - returns a vector with the elements contained in the set
 *    setUnion - returns another set containing all items from two sets
 *    setIntersect - returns another sets containing items only in both sets
 */

#ifndef SET_LINKEDLIST_H
#define SET_LINKEDLIST_H
#include <iostream>
#include <vector>
using namespace std ;


// Node for each element in the set
template<typename T>
struct SetNode {

    T data ;
    SetNode *next ;

    SetNode(T new_data, SetNode *link) {     // full constructor
        data = new_data ;
        next = link ;
    }
} ;

template<class T>
class Set {

    private:
        SetNode<T> *head ;

    public:
        Set() ;                               	// no-arg constructor
        bool contains(T search_item) const ;	// checks if an item is contained in the set.
        bool insert(T new_item) ;				// inserts an item into the set.
        Set<T> setIntersect(Set<T> other_set) const ;
        Set<T> setUnion(Set<T> other_set) const ;
        void display() const ;
        vector<T> * toVector() const ;
        
        //1.Create a new function named  minus  with the following heading:
        Set<T> minus(Set<T> other_set);
        
        //2.Create an  equals  function which returns true if all of the elements 
		// in the calling set are in the set passed as a parameter, and vice versa.  
        bool equals(Set<T> other_set);  
        
        //Helper function for testing and output.
        void print(Set<T> parameterSet);
} ;

// No-argument constructor creates an empty set (linked list)
template<class T>
Set<T>::Set() {
    head = nullptr ;
}

// Returns true if the set contains a specified data element
template<typename T>
bool Set<T>::contains(T search_item) const {
    SetNode<T> *ptr = head ;
    while (ptr != nullptr) {
        if (ptr->data == search_item) {
            return true ;
        }
        ptr = ptr->next ;
    }
    return false ;
}

// Function to add a name to a sorted list.
template<typename T>
bool Set<T>::insert(T new_item) {

    if (contains(new_item))
        return false ;                    // already in the list

    // Add to front of the list of if the list is empty or comes before first item
    if (head == nullptr || (head->data > new_item)) {
        head = new SetNode<T>(new_item, head) ;
        return true ;                    // item was added
    }

    // Find the position to insert.  Keep pointers before and after insertion point
    SetNode<T> *after = head ;               // will come after the new node
    SetNode<T> *before = nullptr ;           // node prior to the insertion point
    while (after != nullptr && after->data <= new_item) {
        before = after ;
        after = after->next ;
    }
    before->next = new SetNode<T>(new_item, after) ;
    return true ;
}

// Create a third set which is the intersection of two other sets
// Intersection will contain only those elements in both sets
template<typename T>
Set<T> Set<T>::setIntersect(Set<T> other_set) const {

    Set<T> common_set ;     // New set to return
    SetNode<T> *pos = head ;
    while (pos != nullptr) {
        if (other_set.contains(pos->data))
            common_set.insert(pos->data) ;
        pos = pos->next ;
    }
    return common_set ;
}

// Return the union of this set with another set
template<typename T>
Set<T> Set<T>::setUnion(Set<T> other_set) const {

    Set<T> union_set ;     // new set to be returned

    // Add contains of calling object set to the new set
    SetNode<T> *pos = head ;
    while (pos != nullptr) {
        union_set.insert(pos->data) ;
        pos = pos->next ;
    }

    // Add the elements of the "other_set", avoid duplicates
    pos = other_set.head ;
    while (pos != nullptr) {
        union_set.insert(pos->data) ;
        pos = pos->next ;
    }
    return union_set ;
}

template<typename T>
void Set<T>::display() const {
    SetNode<T> *ptr = head ;
    while (ptr != nullptr) {
        cout << "\"" << ptr->data << "\", ";
        ptr = ptr->next ;
    }
}

template<typename T>
vector<T> * Set<T>::toVector() const {
    vector<T> *items = new vector<T>() ;
    SetNode<T> *ptr = head ;
    while (ptr != nullptr) {
        items->push_back(ptr->data) ;
        ptr = ptr->next ;
    }
    return items ;
}
/*
performs the difference operation described above, where the new set returned 
from the function contains all of the elements in calling set minus any element 
also in other_set.
*/
template<typename T>
Set<T> Set<T>::minus(Set<T> other_set) 
{
	Set<T> newSet ;     // new set to be returned
	SetNode<T> *ptr = head ;
	
	while(ptr != nullptr)
	{	
		if(!other_set.contains(ptr->data))
		{	
			newSet.insert(ptr->data);
		}
		ptr = ptr->next ;
	}
	return newSet;
}
/*
equals  function which returns true if all of the elements 
in the calling set are in the set passed as a parameter, and vice versa.
*/
template<typename T>
bool Set<T>::equals(Set<T> other_set)
{
	vector<T> *A = this->toVector();
 	
	vector<T> *B = other_set.toVector();
 	
	if(A->size() != B->size())
	{	
 		return false;
	} 
	SetNode<T> *ptr = head ;
 	
	while(ptr != nullptr)
	{	
		if(!other_set.contains(ptr->data))
		{	
			return false;
		}
		ptr = ptr->next ;
	}
	return true;
}
//Helper method for output in the main function and testing.
template<typename T>
void Set<T>::print(Set<T> parameterSet)
{
	//difference
	cout << "{";
	this->display();
	cout << "} minus {";
	parameterSet.display();
	cout << "} = {";
	
	Set<T> difference = this->minus(parameterSet);	
	difference.display();
	cout << "}" << endl;
	
	//intersection
	cout << "{";
	this->display();
	cout << "} intersect {";
	parameterSet.display();
	cout << "} = {";
	
	Set<T> intersect = this->setIntersect(parameterSet);	
	intersect.display();
	cout << "}" << endl;
	
	//(A-B) union (A intersect B)
	cout << "{";
	difference.display();
	cout << "} union {";
	intersect.display();
	cout << "} = {";
	
	Set<T> original = difference.setUnion(intersect);	
	original.display();
	cout << "}" << endl;
	
	//Checking equality.
	cout << "{";
	this->display();
	cout << "} == {";
	original.display();
	cout << "}?" << endl;
	
	if(this->equals(original))
	{
		cout << "The sets ARE equal." << endl;
	}
	else
	{
		cout << "The sets ARE NOT equal." << endl;
	}
}
#endif
