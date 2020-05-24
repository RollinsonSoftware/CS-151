/* CustomerSort.cpp - Create a sorted index of pointers into an array of Customer structures
 * Author:     John A. Rollinson
 * Module:     Midterm
 * Project:    3
 * Problem statement:  Create an array of 10 Customer structures, then create an array of
 *    pointers to those structures when traversed by index, will list the customers sorted 
 *    by descending balance due (highest balance first).
 *
 */
#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

struct Customer 
{
    string name;
    double balance;

    Customer(string name, double balance)
    {
    	this->name = name;
    	this->balance = balance;
	}
};

const int SIZE = 10;

int main() {
    
    // Create an array of 10 Customer objects in random order
    Customer data[] = {
        Customer("XYZ Company", 2043.51),
        Customer("Diddy Daddy", 5178.31),
        Customer("Everready", 29240.25),
        Customer("Washburn Ltd.", 13195.40),
        Customer("Joe Jackson", 1442.00),
        Customer("BubbleWorks", -295.40),
        Customer("Alex P. Jones", 6110.68),
        Customer("Sammy Sosa", 999.99),
        Customer("Timberworks", 17201.89),
        Customer("Microvision", 14040.71)
    } ;
    
    // Create an array pData of pointers into the data array and initialize
    // so that pData[k] points to data[k]
    Customer *pData[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
    	pData[i] = &data[i];
	}
    
    // Sort the pData array so that the Customer with the largest balance is
    // first, and the Customer with the smallest balance is last
    for(int i = 0; i < SIZE - 1; i++)
    {
    	for(int j = 0; j < SIZE - i - 1; j++)
    	{
    		if(pData[j]->balance < pData[j + 1]->balance)
    		{
    			Customer *temp = pData[j];
    			pData[j] = pData[j + 1];
    			pData[j + 1] = temp;
			}
		}
	}
    
    // Print the Customer structures in the order in which they appear in pData
    cout << "      Name          Balance" << endl
         << "----------------  -----------" << endl
         << fixed << setprecision(2);
         
    for(int i = 0; i < SIZE; i++)
    {
    	cout << left << setw(15) << pData[i]->name << "   " << pData[i]->balance << endl;
    	//cout << data[i].name << "   " << data[i].balance << endl;
	}
	
	return 0;
}

