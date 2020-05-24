#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include "Country.h"
using namespace std;

// John Rollinson CS151 1/29/2020

// Class Country
Country::Country()
{
	set_name("defualt");
	set_population(0);
	set_area(0);
}
Country::Country(string n, int p, long a)
{
	set_name(n);
	set_population(p);
	set_area(a);
}
Country::~Country() { }

// Setter Functions
void Country::set_name(string n)
{
    name = n;
}
void Country::set_population(int p)
{
    population = p;
}
void Country::set_area(long a)
{
    area = a;
}
// Getter functions
string Country::get_name()
{
    return name;
}
int Country::get_population()
{
    return population;
}
long Country::get_area()
{
    return area;
}
// Declaring Global vector of output class
vector<Country> countries;
// Initialization function for adding data to the vector
void initialize()
{
    Country c;

    c.set_name("Argentina");
    c.set_population(43132);
    c.set_area(1074000);
    countries.push_back(c);

    c.set_name("Bolivia");
    c.set_population(10520);
    c.set_area(424200);
    countries.push_back(c);

    c.set_name("Brazil");
    c.set_population(204519);
    c.set_area(3286000);
    countries.push_back(c);

    c.set_name("Chile");
    c.set_population(18006);
    c.set_area(292260);
    countries.push_back(c);

    c.set_name("Columbia");
    c.set_population(48529);
    c.set_area(448800);
    countries.push_back(c);

    c.set_name("Ecuador");
    c.set_population(16279);
    c.set_area(109843);
    countries.push_back(c);

    c.set_name("Guyana");
    c.set_population(747);
    c.set_area(83000);
    countries.push_back(c);
    
    c.set_name("Paraguay");
    c.set_population(7003);
    c.set_area(157048);
    countries.push_back(c);

    c.set_name("Peru");
    c.set_population(31153);
    c.set_area(496200);
    countries.push_back(c);

    c.set_name("Suriname");
    c.set_population(560);
    c.set_area(63252);
    countries.push_back(c);

    c.set_name("Uruguay");
    c.set_population(3310);
    c.set_area(68037);
    countries.push_back(c);

    c.set_name("Venezuela");
    c.set_population(30620);
    c.set_area(353831);
    countries.push_back(c);
}

// Compare function to sort our vector of Countries
bool compare(Country c1, Country c2)
{
    return (c1.get_area() < c2.get_area());
}

// Main function to call above functions and display results
int main()
{

    // Initializing data
    initialize();

    // Sorting the vector with respect to area
    sort(countries.begin(), countries.end(), compare);

    // Definig variables to calculate Total
    long populationTotal = 0;
    long long areaTotal = 0;

    // These functions are used to display datain correct format
    // ,ie, with correct allignment and padding
    cout.width(15);
    cout << left << "Name";
    cout.width(12);
    cout << right << "Population";
    cout.width(12);
    cout << right << "Area" << endl;
    cout << "-----------------------------------------" << endl;

    // Using for loop to display all data
    for (int i = 0; i < countries.size(); i++)
    {
    	cout.width(15);
        cout << left << countries.at(i).get_name();
        cout.width(12);
        cout << right << countries.at(i).get_population();
        cout.width(12);
        cout << right << countries.at(i).get_area();
        cout << endl;

        // Calculating total
        populationTotal += countries.at(i).get_population();
        areaTotal += countries.at(i).get_area();
    }

    // Displaying total values
    cout << endl;
    cout.width(15);
    cout << left << "Total";
    cout.width(12);
    cout << right << populationTotal;
    cout.width(12);
    cout << right << areaTotal << endl;

    return 0;
}
