#include<iostream>
#ifndef BOUNDSEXCEPTION_H
#define BOUNDSEXCEPTION_H

using namespace std;

class BoundsException
{
	public:
		BoundsException(int i)
		{
			switch(i)
			{
				case 1:
					cout << "Error! The array index is out of range!" << endl;
					break;
				case 2:
					cout << "Error! The array is empty!" << endl;
					break;
				case 3:
					cout << "Error! The array is full!" << endl;
					break;
				default:
					cout << "Unknown error, occured, shutting down..." << endl;
					exit(1);
			}
		}
};
#endif

