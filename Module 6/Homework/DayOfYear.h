/*DayofYear.h, header file for DayOfYearClass
 * Author:     John Rollinson
 * Module:     6
 * Project:    Homework, Part 1 and 2
 */
#ifndef DAY_OF_YEAR_H
#define DAY_OF_YEAR_H
#include <ostream>
#include <string>
#include <algorithm>
#include <iostream>

class DayOfYear
{
	private:
		int day;
		
	public:
		DayOfYear(int);
		DayOfYear(std::string,int);
		
		int getDay();
		
		friend std::ostream &operator<<(std::ostream &,const DayOfYear &output);
		
		DayOfYear operator++(); // pre
		DayOfYear operator++(int); // post
		
		DayOfYear operator--(); // pre
		DayOfYear operator--(int);	// post
			
		const static std::string months[]; 
		const static int days_in_months[];
};
#endif
