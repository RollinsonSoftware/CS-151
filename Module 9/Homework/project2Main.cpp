/*
File name: project1Main.cpp

Purpose/Problem:
Write a program that uses a structure to store the following inventory information in a file:

Item description
Quantity on hand
Wholesale cost
Retail cost
Date added to inventory
The program should have a menu that allows the user to perform the following tasks:

add new records to the file.
display any record in the file.
change any record in the file.

Author: John Rollinson, CS151

Module #: 9
Homework #: 2

Algorithm (for the main function):
Display menu options for user and loop for input as to what they would like to do.
Use a switch for built in error checking on menu selection.
Close all file streams before exiting the program. 
*SEE EACH METHOD FOR ITS OWN DOCUMENTATION*
*/

//Header Files
#include <fstream>
#include <iostream>

using namespace std;

//Constants
const int SIZE = 50;

//Inventory Structure
typedef struct Inventory
{
    char description[50], date[10];
    int quantity;
    double wholesale, retail;
} Invent; //Declaring a type so I can use this short hand version instead of the whole word.

//Prototypes (helper functions):
bool isValidDate(string date);
Inventory getUserInput();

//Functions:
/*
Takes in a file stream as the only parameter.
Opens the file stream to inventory binary file.
*/
void openFile(fstream &file)
{
    file.open("Inventory.dat", ios::out | ios::in | ios::binary);
    if(file.fail())
    {
        file.open("Inventory.dat", ios::out | ios::in | ios::binary | ios::trunc);
        if(file.fail())
        {
        	cout << "ERROR: File not found, shutting down...";
        	exit(0);
        }
        else
        {
        	//File was found.
        	return;	
		}
    }
    else
    {
    	//File was found.
    	return;
	}
}
/*
Takes in a file stream as the only parameter.
Appends a new inventory record to the binary file, while performing error checking on
the user input.
*/
void add(fstream &file)
{
    file.clear();
    file.seekp(0,ios::end); //Moving the file pointer to the end of the file to append.
    
    Invent item = getUserInput(); //Reading user input.
    
    file.write((char *)&item, sizeof(item)); //Write content of struct Inventory to file
}
/*
Takes in a file stream as the only parameter.
Looks up a record in the file, and displays it to the console.
*/
void display(fstream &file)
{
    Invent item;
    
    //Clearing any error flags that might have accumulated.
    file.clear();
    
    //Moving the file pointer to the beginning of the file.
    file.seekg(0,ios::beg);
    
    //Keeps track of the number of inventory records.
    int recordNum = 0;
    
    while(file.read((char *)&item, sizeof(item)))
    {
    	//Finding the total number of inventory records.
		recordNum++;
	}
    if(recordNum == 0) //Inventory is empty.
    {
        cout << "\nERROR:Record not found or inventory file is empty.";
        return;
    }
    else
    {
        cout << "\nEnter the number of the record you want to display: (1 to " << recordNum << "): ";
        //recordNum is now being used to store the number of the record that is going to be changed.
		cin >> recordNum; 
        //Clearing any error flags that might have accumulated.
		file.clear();
        //Moving the file pointer to the beginning of the file.
        file.seekg(0,ios::beg);
        int index = 0;
        
        //Looking for record based on its ID value.
        while(file.read((char *)&item, sizeof(item)))
        {
            index++;
            if(index == recordNum) //If index == recordNum then print that record and return
            {
                cout << "\nDescription: " << item.description;
                cout << "\nQuantity: " << item.quantity;
                cout << "\nWholesale price: $" << item.wholesale;
                cout << "\nRetail price: $" << item.retail;
                cout << "\nDate: " << item.date << endl;
                return;
            }
        }
    }
}
/*
Takes in a file stream as the only parameter.
Looks up a record in the file, edits the record entry and appends it to the binary file.
*/
void modify()
{
	Invent item; //Modified data is collected here before being appended to the file
    fstream file; //Declaring new file stream.
    openFile(file); //Opening the file. 
    
    //Clearing any error flags that might have accumulated.
    file.clear();
    
    //Moving the file pointer to the beginning of the file.
    file.seekg(0,ios::beg);
    
    //Temp storage for records that are being modified.
    fstream tempStream("temp.dat", ios::binary | ios::out);
    
    int recordNum = 0;
    while(file.read((char *)&item, sizeof(item))) 
	{
		//Finding the total number of records in the inventory.
        recordNum++;
    }
    if(recordNum == 0)
    {
        cout << "\nERROR:Record not found or inventory file is empty.";
        return;
    }
    else
    {
        cout << "\nEnter the number of the record you want to change: (1 to " << recordNum << "): ";
        //recordNum is used to store the number of the record that is going to be changed.
		cin >> recordNum; 
        //Clearing any error flags that might have accumulated.
		file.clear();
        //Moving the file pointer to the beginning of the file.
        file.seekg(0,ios::beg);
        int index = 0;
        
        while(file.read((char *)&item, sizeof(item)))
        {
            index++;
            if(index == recordNum) //If index == recordNum, then modify data first then write to temp.dat
            {
                item = getUserInput();
            }
            tempStream.write((char *)&item, sizeof(item));
        }
    }
    //Closing file streams and removing temporary binary file.
    file.close();
    tempStream.close();
    remove("Inventory.dat");
    rename("temp.dat", "Inventory.dat");
}
int main()
{
    fstream file;
    openFile(file);
    int option = 0;
    
    while(option != 4)
    {
		cout << "\n=====MENU-OPTION=====" << endl;
		cout << "1. Add a new inventory record." << endl;
		cout << "2. Display an existing inventory record." << endl;
		cout << "3. Edit an existing inventory record." << endl;
		cout << "4. Exit the program." << endl;
		
		cout << "\nMake a selection (1 - 4): ";
        cin >> option;
        
        switch(option)
        {
            case 1: 
				add(file);
				break;
            case 2: 
				display(file);
				break;
            case 3: 
				file.close();
            	modify();
            	openFile(file);
            	break;
            case 4: 
				break;
            default: 
				cout << "\nInvalid selection, you must choose (1-4)!" << endl;
        }
    }
    file.close();
    system("pause");
    return 0;
}
//Helper Functions:
/*
Handles all user input with error checking.
Reads in all the required information from the user to make a new inventory struct
Then returns the new struct that was created with the collected input.
*/
Inventory getUserInput()
{
	Invent item;
	cout << "\nEnter the NEW record data:";
    
    cout << "\nItem description: ";
    cin.ignore();
	cin.getline(item.description, SIZE);
	
	cout << "Date(MM/DD/YYYY): ";
	cin.getline(item.date, SIZE);
	
	while(!isValidDate(item.date)) //Error checking.
	{
		cout << "ERROR: Invalid date entry." << endl;
		cout << "Enter todays date (MM/DD/YYYY): ";
		cin.getline(item.date, SIZE);
	}
	
	cout << "Item quantity: ";
	cin >> item.quantity;
	while(item.quantity < 0) //Error checking.
	{
		cout << "ERROR: Quantity must NOT be negative." << endl;
		cout << "Item quantity: ";
		cin >> item.quantity;
	}
	
	cout << "Wholesale cost: $";
	cin >> item.wholesale;
	while(item.wholesale < 0) //Error checking.
	{
		cout << "Error: Wholesale cost must NOT be negative." << endl;
		cout << "Wholesale cost: $";
		cin >> item.wholesale;
	}
	
	cout << "Retail cost: $";
	cin >> item.retail;
	while(item.retail < 0) //Error checking.
	{
		cout << "Error: Retail cost must NOT be negative." << endl;
		cout << "Retail cost: $";
		cin >> item.retail;
	}
	return item;
}
/*
Takes in a string argument as the only parameter.
Checks to see if the given date matches the correct format.
Returns true if it does and false otherwise.
*/
bool isValidDate(string date)
{
	if(date.length() == 9)
	{
		date = "0" + date;
	}
	if(date.length() != 10)
	{
		return false;
	}
	for(unsigned int i = 0; i < date.length(); i++)
	{
		if(i == 2 || i == 5)
		{
			if(date[i] !='/')
			{
				return false;
			}
			continue;
		}
		if(!isdigit(date[i]))
		{
			return false;
		}
	}
	return true;
}
