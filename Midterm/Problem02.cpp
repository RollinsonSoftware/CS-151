/* FileReverse.cpp - Create a sorted index of pointers into an array of Customer structures
 * Author:     John A. Rollinson
 * Module:     Midterm
 * Project:    2
 * Problem statement: Write a program which takes an input an existing text file, then appends 
 * all of the characters in that file to the end of the file in reverse order.
 */
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void reverse(string);

int main(int argc, char** argv) 
{
		
	// passing first text file's text through reverse function
	char file[50];
	cout << "Enter name of text file including .txt entension (or 'q' to quit): ";
	cin.getline(file , 50);

	if ((strcmp(file, "Q") == 0) || (strcmp(file, "q") == 0)) 
	{ 
		system("pause") ;            
		return 0 ;        
	}
	
	reverse(file);
	
	system("pause");
	return 0;
}
	
void reverse(string file_name)
{
	char character;
	long position;
	ifstream inputFile;
	ofstream outputFile;
	
	inputFile.open(file_name, ios::in);
	inputFile.seekg(-1,ios::end);
	
	position = inputFile.tellg();
	
	outputFile.open(file_name, ios::app);
	inputFile.seekg(position);
	
	while(position >= 0) 
	{
		// reading from the file	
		inputFile.get(character);
		
		// appending to the file
		if(character != '\n')
		{	
			outputFile.put(character);
			position --;
		}
		else
		{
			outputFile.put('\n');
			position = position - 2;
		}			
		inputFile.seekg(position);
	}
	inputFile.close();
	outputFile.close();
}
