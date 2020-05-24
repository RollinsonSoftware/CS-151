/*
File name: project1Main.cpp

Purpose/Problem:
A program that processes an input file and produces an output file is called a filter. 
Write a program that asks the user for two filenames. The first file will be opened for 
input, and the second file will be opened for output . (It will be assumed that the first 
file contains sentences that end with a period.) The program will read the contents of the 
first file and change all the letters other than the first letter of sentences to lowercase. 
The first letter of each sentence should be made uppercase. The revised contents should be 
stored in the second file.

Author: John Rollinson, CS151

Module #: 9
Homework #: 1

Algorithm:
Prompt the user to enter the string names of the input text file and output text file.
Open the input file and output file streams.
Check to see if input files were found, before filtering the data.
If any of the input or output file streams failed to open then exit the program.
Looping through the entire textfile with the input file stream, read in one char per
	loop iteration.
Check to see if the current character is white space, if it is then print as is with the
	output file stream.
Using a control variable to keep track of if the input file stream has read a period "."
If the character is the first character in the sentence, then convert it to uppercase and
	print it to the output text file.
If the character is not the first character of the sentence, then convert it to lowercase
	and print it to the output text file.
Close all file streams before ending the program.
*/

//Header Files
#include <fstream>
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, 
system("pause") or input loop */

//Closes both input and output file streams and pauses the program.
void close(fstream &inputFileStream, fstream &outputFileStream)
{
	//Closing the file streams and pausing the program.
	inputFileStream.close();
	outputFileStream.close();
	system("pause");
}

int main(int argc, char** argv) 
{
	fstream inputFileStream, outputFileStream;
	string inFilePath, outFilePath;
	
	bool sentenceStart;
	char currentChar;
	
	//For testing:
	//inFilePath = "A Study In Scarlet.txt";
	//outFilePath = "lowerCase.txt";
	
	cout << "Please enter the input file path: ";
	cin >> inFilePath;
	
	cout << "Please enter the output file path: ";
	cin >> outFilePath;
	
	inputFileStream.open(inFilePath, ios::in);
	outputFileStream.open(outFilePath, ios::out);
	
	if(!inputFileStream)
	{
		cout << "ERROR: File not found..." << endl;
		close(inputFileStream, outputFileStream);
		return 0;
	} 
	sentenceStart = true;
	
	inputFileStream.get(currentChar);
	while(!inputFileStream.fail())
	{
		if(currentChar == ' ' || currentChar == '\t' || currentChar == '\n') //Whitespaces.
		{
			outputFileStream.put(currentChar);
		}
		else if(sentenceStart) //current char is at the start of a sentence.
		{
			outputFileStream.put(toupper(currentChar));
			sentenceStart = false;
		}
		else //Generic char found.
		{
			outputFileStream.put(tolower(currentChar)); 
		}
		
		//Found the end of the sentence. 
		if(currentChar == '.')
		{
			sentenceStart = true;
		}
		inputFileStream.get(currentChar);
	}
	close(inputFileStream, outputFileStream);
	return 0;
}
