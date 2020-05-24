/*DayOfYear.cpp, contians implementation of DayOfYear class and overloaded operators
 * Author:     John Rollinson
 * Module:     6
 * Project:    Homework, Part 1 and 2
 */
#include "DayOfYear.h"
#include <array>
#include <string>
#include <boost/algorithm/string.hpp>

DayOfYear::DayOfYear(int day)
{
	this -> day = day;
}

int DayOfYear::getDay()
{
	return this -> day;
}

std::ostream & operator<<(std::ostream &out, const DayOfYear &output)
{
	int check = output.day;
	
	if(check > 0 && check <= 31) // JAN
	{ 
		out << output.months[0] << " " << check;
		return out; // repeated return statements to return answer as soon as correct
	} 
	else if(check > 31 && check <= 59) // FEB
	{ 
		out << output.months[1] << " " << check - 31;
		return out; 
	} 
	else if (check > 59 && check <= 90) // MAR
	{ 
		out << output.months[2] << " " << check - 59;
		return out;
	} 
	else if (check > 90 && check <= 120) // APR
	{ 
		out << output.months[3] << " " << check - 90;
		return out;
	} 
	else if (check > 120 && check <= 151) // MAY
	{ 
		out << output.months[4] << " " << check - 120;
		return out;
	}
	else if (check > 151 && check <= 181) //JUN
	{ 
		out << output.months[5] << " " << check - 151;
		return out;
	} 
	else if (check > 181 && check <= 212) // JUL
	{ 
		out << output.months[6] << " " << check - 181;
		return out;
	}
	else if (check > 212 && check <= 243) // AUG
	{ 
		out << output.months[7] << " " << check - 212;
		return out;
	}
	else if (check > 243 && check <= 273) // SEP
	{ 
		out << output.months[8] << " " << check - 243;
		return out;
	}
	else if (check > 273 && check <= 304) // OCT
	{ 
		out << output.months[9] << " " << check - 273;
		return out;
	} 
	else if (check > 304 && check <= 334) // NOV
	{ 
		out << output.months[10] << " " << check - 304;
		return out;
	} 
	else if (check > 334 && check <= 365) // DEC
	{ 
		out << output.months[11] << " " << check - 334;
		return out;
	} 
	else 
	{
		out << "\nInvalid Day of the Year.\n";
		return out;
	}
}

DayOfYear::DayOfYear(std::string month, int day)
{	
	//convert month passed to all upper case
	for(int i = 0; i < month.length(); i++)
	{
		boost::to_upper(month);
	}
	
	if (month == "JANUARY") 
	{
		if (day <= 0 || day > 31)
		{
			std::cout << "\nError, invalid day entered.\n";
		}
		else
		{
			this -> day = day;
		}
	} 
	else if (month == "FEBRUARY") 
	{
		if (day <= 0 || day > 28)
		{
			std::cout << "\nError, invalid day entered.\n";
		}
		else
		{
			this -> day = day + 31;
		}
	} 
	else if (month == "MARCH") 
	{
		if (day <= 0 || day > 31)
		{
			std::cout << "\nError, invalid day entered.\n";
		}
		else
		{
			this -> day = day + 59;
		}
	} 
	else if (month == "APRIL") 
	{
		if (day <= 0 || day > 30)
		{
			std::cout << "\nError, invalid day entered.\n";
		}
		else
		{
			this -> day = day + 90;
		}
	} 
	else if (month == "MAY") 
	{
		if (day <= 0 || day > 31)
		{
			std::cout << "\nError, invalid day entered.\n";
		}
		else
		{
			this -> day = day + 120;
		}
	} 
	else if (month == "JUNE") 
	{
		if (day <= 0 || day > 30)
		{
			std::cout << "\nError, invalid day entered.\n";
		}
		else
		{
			this -> day = day + 151;
		}
	} 
	else if (month == "JULY") 
	{
		if (day <= 0 || day > 31)
		{
			std::cout << "\nError, invalid day entered.\n";
		}
		else
		{
			this -> day = day + 181;
		}
	} 
	else if (month == "AUGUST") 
	{
		if (day <= 0 || day > 31)
		{
			std::cout << "\nError, invalid day entered.\n";
		}
		else
		{
			this -> day = day + 212;
		}
	} 
	else if (month == "SEPTEMBER") 
	{
		if (day <= 0 || day > 30)
		{
			std::cout << "\nError, invalid day entered.\n";
		}
		else
		{
			this -> day = day + 243;
		}
	}
	else if (month == "OCTOBER") 
	{
		if (day <= 0 || day > 31)
		{
			std::cout << "\nError, invalid day entered.\n";
		}
		else
		{
			this -> day = day + 273;
		}
	} 
	else if (month == "NOVEMBER") 
	{
		if (day <= 0 || day > 31)
		{
			std::cout << "\nError, invalid day entered.\n";
		}
		else
		{
			this -> day = day + 304;
		}
	} 
	else if (month == "DECEMBER") 
	{
		if (day <= 0 || day > 31)
		{
			std::cout << "\nError, invalid day entered.\n";
		}
		else
		{
			this -> day = day + 334;
		}
	} 
	else // Month name not valid
	{ 
		std::cout << "\nError, invalid month entered.\n";
		exit(1);
	}
}

DayOfYear DayOfYear::operator++() // pre
{
	day = (day % 365) + 1;
	return *this;
}

DayOfYear DayOfYear::operator++(int) // post
{
	DayOfYear nextDay = *this;
	nextDay.day = (day % 365) + 1;
	
	return nextDay;
}

DayOfYear DayOfYear::operator--() // pre
{
	day = day-1;
	
	if(day == 0)
	{
		day = 365;
	}
	
	return *this;
}

DayOfYear DayOfYear::operator--(int) // post
{
	DayOfYear yesterday = *this;
	yesterday.day--;
	
	if(yesterday.day == 0)
	{
		yesterday.day == 365;
	}
	
	return yesterday;
}

const std::string DayOfYear::months[] = {"January","February","March","April","May","June",
											"July","August","September","October","November",
											"December"};
											
const int DayOfYear::days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

