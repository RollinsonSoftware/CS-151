#ifndef COUNTRY
#define COUNTRY
#include<string>

using namespace std;

class Country
{
	//Instance vars.
	private:
		string name;
	    int population;
	    long area;
    
	//Constructors/ Destructors.
	public:
		Country();
		Country(string, int, long);
		~Country();
		
		//Setters and Getters.
		void set_name(string);
		string get_name();
		
		void set_population(int);
		int get_population();
		
		void set_area(long);
		long get_area();
};
#endif
