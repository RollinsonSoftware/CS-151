/* LinkedList.h - Generic class allowing representation of a linked list
 * Author:     Chris Merrill, Shachar Habusha, John Rollinson
 * Module:     13
 * Project:    Lab
 * Problem statement:  This file contains the definition for a generic
 *    Node class and a generic LinkedList class.  Enhance an generic LinkedList.h
 *    class with several functions to make the class more usable.
 *
 *    Functions should throw a run-time exception if there would be confusion between
 *    what is returned (successful) and something couldn't be returned.
 *
 * Algorithm:
 *    Classes already included are  Node<T> and LinkedList<T>
 *    Functions already given are:  full constructor, addFirst, addLast, add,
 *        getFirst, getLast(), get, indexOf, getSize, isEmpty, removeFirst,
 *        removeLast, and clear
 *
 *    Functions to be written are:
 *       x display, remove, removeAt, find, findLast, contains, and set
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <stdexcept>                          // catch run-time errors
using namespace std ;

/******************************
 *                            *
 *  Template for Node class   *
 *                            *
 ******************************/
template<class T>
class Node {
    public:
        T data ;                // value or object stored in the node
        Node<T> *next ;         // pointer to the next node

    // No-arg constructor
    Node() {
        next = nullptr  ;
    }

    // Constructor with one parameter
    Node(T myData) {
        this->data = myData ;   // stores value in node's data field
        next = nullptr ;
    }
} ;

/*****************************************
 *                                       *
 *   Template for the LinkedList class   *
 *                                       *
 *****************************************/
template<class T>
class LinkedList {

    private:
        Node<T> *head, *tail ;         // pointers to first and last nodes
        int size ;                       // number of nodes in this list

    public:

        // Prototypes of functions already present
        LinkedList() ;                           // constructor

        void addFirst(T myData) ;                // add an element to the list
        void addLast(T myData) ;
        void add(int index, T myData) ;

        T getFirst() ;                           // accessors
        T getLast() ;
        T get(int index) ;
        int indexOf(T myData) ;
        int getSize() ;
        bool isEmpty() ;

        T removeFirst() throw (runtime_error) ;  // remove an element or clear
        T removeLast() throw (runtime_error) ;
        void clear() ;

        // Function prototypes to be provided in this lab
        bool contains(T myData) ; //x
        int lastIndexOf(T myData) ; //x
        bool remove(T myData) ; //x
        T removeAt(int index) throw (runtime_error) ; //x
        T set(int index, T myData) ; //x
        void display() ; //x
} ;

/************************************
*                                   *
*     Function implementations      *
*                                   *
*************************************/

// Constructor
template<typename T>
LinkedList<T>::LinkedList() {                    // An empty list
    head = tail = nullptr ;
    size = 0 ;
}

// Add node to beginning of the list
template<typename T>
void LinkedList<T>::addFirst(T myData) {
    Node<T> *newNode = new Node<T>(myData) ;    // Create new node and ptr
    newNode->next = head ;                      // Assign value of head ptr to next ptr of new node
    head = newNode ;                            // Set head to point at new node
    size++ ;                                    // increment size of LinkedList

    if (tail == nullptr)
        tail = head ;                           // set tail ptr to new node if list was empty
}

// Add node to the end of the list
template<typename T>
void LinkedList<T>::addLast(T myData) {
    if (tail == nullptr) {                      // list is empty
        head = tail = new Node<T>(myData) ;     // point head and tail to new node
    } else {
        tail->next = new Node<T>(myData) ;      // create new node
        tail = tail->next ;                     // set tail ptr to new node
    }

    size++ ;
}

// Add node at specific index
template<typename T>
void LinkedList<T>::add(int index, T myData) {
    if (index == 0) {                           // add node at beginning of list
        addFirst(myData) ;
    } else if (index >= size) {                 // add node at end of list
        addLast(myData) ;
    } else {                                    // insert this element between two nodes
        Node<T> *current = head ;               // loop to node before this one
        for (int i = 1 ; i < index ; i++)
            current = current->next ;
        Node<T> *temp = current->next ;         // one after this one
        current->next = new Node<T>(myData) ;
        (current->next)->next = temp ;
        size++ ;
    }
}

// Get data from first node
template<typename T>
T LinkedList<T>::getFirst() {
    if (size == 0) {
        throw runtime_error("Index out of range") ; // no nodes in the list
    } else {
        return head->data ;                     //retrieve value in first node
    }
}

// Get data from last node
template<typename T>
T LinkedList<T>::getLast() {                    // no nodes in the list
    if (size == 0) {
        throw runtime_error("Index out of range") ; // retrieve value in last node
    } else {
        return tail->data ;
    }
}

// Get node at the specific index
template<typename T>
T LinkedList<T>::get(int index) {
    if (index < 0 || index > size - 1)
        throw runtime_error("Index out of range") ;

    Node<T> *current = head ;                // walk list
    for (int i = 0 ; i < index ; i++)
        current = current->next ;            // point to next node

    return current->data ;                   // get value if found
}

// Get the index of a specific node
template<typename T>
int LinkedList<T>::indexOf(T myData) {
    Node<T> *current = head ;
    for (int i = 0 ; i < size ; i++) {
        if (current->data == myData)        // walk list to find value
            return i ;
        current = current->next ;
    }
    return -1 ;                             // return -1 if value not found
}


// Get the number of nodes in the list (number added - number removed)
template<typename T>
int LinkedList<T>::getSize() {
    return size ;
}

// Remove first node from list
template<typename T>
T LinkedList<T>::removeFirst() throw (runtime_error) {
    if (size == 0) {
        throw runtime_error("No nodes in the list") ;
    } else {
        Node<T> *temp = head ;             // create new ptr temp - point to same place as head
        head = head->next ;                // point to the next object beyond the first
        size-- ;
        if (head == nullptr) {
            tail = nullptr ;
        }
        T myData = temp->data ;
        delete temp ;                      // delete node temp is pointing to
        return myData ;                    // may or may not use this value
    }
}

// Remove last node from the list
template<typename T>
T LinkedList<T>::removeLast() throw (runtime_error) {
    if (size == 0) {
        throw runtime_error("No nodes in the list") ;
    } else if (size == 1) {
        Node<T> *temp = head ;
        head = tail = nullptr ;
        size = 0 ;
        T myData = temp->data ;
        delete temp ;                          // delete node temp is pointing to
        return myData ;                        // may or may not use this value
    } else {
        Node<T> *current = head ;              // set current to point at what head points at
        for (int i = 0 ; i < size - 2 ; i++)   // walk list moving current ptr to end
            current = current->next ;

        Node<T> *temp = tail ;
        tail = current ;
        tail->next = nullptr ;
        size-- ;
        T myData = temp->data ;
        delete temp ;
        return myData ;
    }
}

// Clear the list - takes time but frees up memory
template<typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {          // if still a node in list
        Node<T> *temp = head ;         // set temp ptr to what head points at
        head = head->next ;            // point head at next node
        delete temp ;                  // delete the node temp is pointing to
    }
    head = tail = nullptr ;            // the empty list
    size = 0 ;
}

// See if the list is empty
template<typename T>
bool LinkedList<T>::isEmpty() {
    cout << "in isEmpty(), size is now " << size ;
    return head == nullptr ;                   // no nodes in list
}

//Displays node
template<typename T>
void LinkedList<T>::display(){
		
		if(this->head == nullptr){
			cout << "(null)";
		} 
		      
	    for (int i = 0; i < this->getSize(); i++){
        
			cout<< this->get(i) << " ";
		}
            
        cout << endl;
		return;
	}
	
//Removing Node with a specific data point
template<typename T>
bool LinkedList<T>::remove(T myData){
	
	Node<T> *current = this->head ; 
	  
	for(int i = 0; i < this->getSize(); i++ ){
		
		if(this->get(i) == myData){
			
			
			
			if(i == 0){
				
				this->head = current->next;
			}else if(i == this->getSize()){
				
				this->removeLast();
				
			}else{
				Node<T> *before = this->head ;
				
				for (int j = 0 ; j < i-1 ; j++){
					before = before->next ;	
				}
				
            		
            	before->next = current->next;
									
			}
			delete(current);
			this->size--;	
			return true;
			
		}
		current = current->next ;
	}
	
	return false;	
}

//Removing Node in a specific location
template<typename T>
T LinkedList<T>::removeAt(int myData) throw (runtime_error){
	
		T dummy;
		if(myData > this->getSize()){
			
			throw runtime_error("Data too big:(") ;
		}
		else if(myData == 0){
			
			dummy = this->head->data;	
			this->head = this->head->next;
		}else if(myData == this->getSize()){
			
			dummy = this->get(this->getSize());	
			this->removeLast();
				
		}else{
			Node<T> *current = this->head;
			Node<T> *before;
				
			for (int j = 0 ; j < myData; j++){
				before = current;
				current = current->next ;	
			}				
            
			dummy = current->data;	
           	before->next = current->next;									
		}
		
		return dummy;
}


//Finding the last index of a specific data element
template<typename T>
int LinkedList<T>::lastIndexOf(T myData){
	
	int location = -1;
	for(int i = 0; i < this->getSize(); i++){
		
		if(myData == this->get(i)){
			
			location = i;
		}
	}
	
	return location;
}


//Determine if the list contains a specific data element
template<typename T>
bool LinkedList<T>::contains(T myData) {

	for(int i = 0; i < this->getSize(); i++){
		
		if(myData == this->get(i)){
			
			return true;
		}
	}
	
	return false;
}

template<typename T>
T LinkedList<T>:: set(int index, T myData){
	
	if (index == 0) {                           // Replace with first
	  
	  	Node<T> *place = new Node<T>(myData);
		place->next = this->head->next;
		this->head = place;
        return true;
    }else if(index >= this->getSize()){
		return false;
		
	} else {                                    // insert this element between two nodes
        	
			Node<T> *current = this->head;
			Node<T> *before;
			Node<T> *place = new Node<T>(myData);
				
			for (int j = 0 ; j < index; j++){
				before = current;
				current = current->next ;	
			}				
            
				
           	before->next = place;
           	place->next = current->next;
           	
           	
        return true;
    }
}
#endif
