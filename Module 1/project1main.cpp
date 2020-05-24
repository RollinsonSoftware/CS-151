#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> //needed for random numbers (rand and srand)
#include <ctime>
#include <algorithm>

// John Rollinson CS151 1/29/2020

using namespace std;

int main()
{
	vector<int> intVector;
	unsigned seed; //random generator seed
	
	//using the time function to get a "seed" value for srand.
	srand(time(NULL));
	
	cout << "The size of the vector is now: " << intVector.size() << endl;
	
	for(int i = 0; i < 30; i++)
	{
		int value = ((rand() % RAND_MAX + 1) % 10 + 1);
		
		int index = 0;
		vector<int>::iterator it;
		
		for(it = intVector.begin(); it != intVector.end(); it++)
		{
			if((*it) <= value)
			{
				break;
			}
			index++;
		}
		intVector.insert(intVector.begin() + index, value);
	}
	
	cout << "The size of the vector is now: " << intVector.size() << endl;
	cout << "Vector contents: " << endl;
	
	//Printing in ascending order
	vector<int>:: reverse_iterator it;
	
	while(intVector.size() > 0)
	{
		//output
		it = intVector.rbegin();
		cout << (*it) << ", ";
		//removal
		intVector.pop_back();
	}

	cout << "\nThe size of the vector is now: " << intVector.size() << endl;
	
	return 0;
}

