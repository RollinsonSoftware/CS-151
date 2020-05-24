#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <cstdlib>
#include "BoundsException.h"
using namespace std ;

template <class T>
class SimpleVector {

private:
    T *aptr ;
    int arraySize ;
    int numElements ; 
    void subError() ;                     // Handles subscripts out of range

public:
    SimpleVector()                        // Default constructor
        { aptr = 0 ; arraySize = 0 ;}
    SimpleVector(int) ;                   // Constructor
    SimpleVector(int, int) ;			  // String Constructor
    SimpleVector(const SimpleVector &) ;  // Copy constructor
    ~SimpleVector() ;                     // Destructor
    int size()
        { return arraySize ; }
    T &operator[](const int &) ;          // Overloaded [] operator
    void push_back(T) ;
    void print() ;
    T pop_back() ;
} ;

//*************************************************************
//         Default Constructor for SimpleVector class                 *
// Sets the size of the array and allocates memory for it.    *
//*************************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s) {

	numElements = 0 ;
    arraySize = s ;
    aptr = new T [s] ;

    for (int count = 0 ; count < arraySize ; count++)
        *(aptr + count) = 0 ;
}

//*************************************************************
//         String Constructor for SimpleVector class                 *
// Sets the size of the array and allocates memory for it.    *
//*************************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s, int isString) {
	
	numElements = 0 ;
    arraySize = s ;
    aptr = new T [s] ;

    for (int count = 0 ; count < arraySize ; count++)
        *(aptr + count) = "empty." ;
}

//************************************************
// Copy Constructor for SimpleVector class       *
//************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {

    arraySize = obj.arraySize ;
    numElements = obj.numElements ;
    aptr = new T [arraySize] ;
    for(int count = 0 ; count < arraySize ; count++)
        *(aptr + count) = *(obj.aptr + count) ;
}

//***************************************
// Destructor for SimpleVector class    *
//***************************************
template <class T>
SimpleVector<T>::~SimpleVector() {

    if (arraySize > 0)
        delete [] aptr ;
}

//*************************************************************
//              SubError function                             *
// Displays an error message and terminates the program when  *
// a subscript is out of range.                               *
//*************************************************************
template <class T>
void SimpleVector<T>::subError() {

    cout << "ERROR: Subscript out of range.\n" ;
    exit(0) ;
}

//*************************************************************
//             Overloaded [] operator                         *
// This function returns a reference to the element           *
// in the array indexed by the subscript.                     *
//*************************************************************
template <class T>
T &SimpleVector<T>::operator[](const int &sub) {

    if (sub < 0 || sub >= arraySize)
        subError() ;
    return aptr[sub] ;
}

//**************************************************************
//                   push_back                                 *
// The push_back function pushes its argument onto the back    *
// Of the vector.                                              *
//**************************************************************
template <class T>
void SimpleVector<T>::push_back(T val) 
{
	if(numElements < arraySize) //Array is not full.
	{
		// Copy the argument value to the first open index of the array.
		*(aptr + numElements) = val ;
		
		//Update the number of filled indicies in the array:
		numElements++ ;
	}
	else //Array is full, re-allocate and throw a BoundsException.
	{
		// Allocate a new array 1 element larger than the current one.
		T *tempPtr = new T [arraySize + 1] ;
		
		// Copy the current array contents to the new array
		for(int count = 0 ; count < arraySize ; count++)
		    *(tempPtr + count) = *(aptr + count) ;
		
		// Copy the argument value to the end of the array
		*(tempPtr + arraySize) = val ;
		
		// Get rid of the old array
		if (arraySize > 0)
		    delete [] aptr ;
		
		// Make aptr point to the new array
		aptr = tempPtr ;
		
		// Adjust arraySize
		arraySize++ ;
		
		//Update the number of filled indicies in the array:
		numElements++ ;
		
		throw BoundsException(3);
	}
}

//****************************************************
//               pop_back                            *
// The pop_back function removes the last element    *
// Of the vector. It also returns that value.        *
//****************************************************
template <class T>
T SimpleVector<T>::pop_back() 
{
    if (numElements == 0)
    {
        throw BoundsException(2);
    }
    else
    {
        // Save the last value in the array
        T lastValue = aptr[arraySize - 1] ;

        // Allocate a new array 1 element smaller than the current one.
        T *tempPtr = new T [arraySize - 1] ;

        // Copy the current array contents (except the last element)
        // to the new array
        for(int count = 0 ; count < (arraySize - 1) ; count++)
            *(tempPtr + count) = *(aptr + count) ;

        // Get rid of the old array
        delete [] aptr ;

        // Make aptr point to the new array
        aptr = tempPtr ;

        // Adjust arraySize
        arraySize-- ;
        
        //Update the number of filled indicies in the array:
		numElements-- ;

        return lastValue ;
    }
}
//****************************************************
//               print                               *
// Prints all the contents of the vector.            *
//****************************************************
template <class T>
void SimpleVector<T>::print()
{
	cout << "Index \t Value" << endl;
	cout << "----------------" << endl;
	for(int counter = 0; counter < arraySize; counter++)
	{
		cout << counter << " \t " << *(aptr + counter) << endl;
	}
}
#endif
