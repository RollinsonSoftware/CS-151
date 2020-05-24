/* StringReplace.cpp - Replace all occurrences of one C-String with another
 * Author:     John A. Rollinson
 * Module:     Midterm
 * Project:    1
 * Problem statement: Replace all occurrences of one C-String with another C-String 
 * in an original C-String
 */
#include <iostream>
#include <cstring>

using namespace std;

// prototypes
string replaceSubstring(char *, char *,  char *);
string replaceSubstring(string, string, string);
//Size of all Strings
const int sizeofString = 250;

int main()
{
    char string1[sizeofString];
    char string2[sizeofString];
    char string3[sizeofString];

	while(true)
	{
		cout << "Enter string to search or \"0\" to quit (string 1):\n";
		cin.getline(string1,sizeofString);
		
		if(string1[0] == '0')
		{
			break;
		}
		else
		{			
			cout << "Enter the string you want to replace (string 2):\n";
			cin.getline(string2, sizeofString);
			
			cout << "Enter the string you want to replace it with (string 3):\n";
			cin.getline(string3, sizeofString);
			
			cout << "Your updated string is:\n";    
			cout << replaceSubstring(string1, string2, string3) << "\n" << endl;
		}
	}
    return 0;
}
string replaceSubstring( char * string1,  char * string2, char * string3)
{        
    char *occurrence = strstr(string1, string2);    
    string output = "";

    while(occurrence)
	{   
		output.append(string1, (occurrence - string1));
		output.append(string3, strlen(string3));
		string1 = string1 + (occurrence - string1) + strlen(string2);
		occurrence = strstr(string1, string2);
    }
    output.append(string1, strlen(string1));

    return output;
}   
