// Inheritance-Constructors.cpp : Defines the entry point for the console application.
//
/*
constructors are in derived class. No argument constructor can be used from based class, however more complext 
constructors have to be used inside derived class

*/
#include "stdafx.h"
#include <iostream>
class Counter
{
protected:					// this is NOT private but protected!!
	unsigned int count;		// count
public:
	Counter() : count()		// constructor no arguments
	{}
	Counter(int counter_) : count(counter_)	// constructor 1 argument
	{}
	unsigned int getCount() const			// return count
	{
		return count;
	}
	Counter operator ++ ()					// increase count - prefix
	{
		return Counter(++count);
	}
};

class CountDown : public Counter
{
public:
	CountDown() : Counter()				//Constructor NO arguments
	{}
	CountDown(int counter_) : Counter(counter_)	// Constructor 1 argument
	{}
	CountDown operator -- ()			// Decrease count (prefix)
	{
		return CountDown(--count);
	}
};

int main()
{
	CountDown c1;			//class CountDown
	CountDown c2(100);

	std::cout << "\nc1= " << c1.getCount();	// display
	std::cout << "\nc2= " << c2.getCount(); // display

	++c1; ++c1; ++c1;						// increase c1
	std::cout << "\nc1= " << c1.getCount();	// display

	--c2; --c2;
	std::cout << "\nc2= " << c2.getCount();	// display
	
	CountDown c3 = --c2;					// create C3 from c2
	std::cout << "\nc3= " << c3.getCount();	// display



	system("pause");
    return 0;
}

