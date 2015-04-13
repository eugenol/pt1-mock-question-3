///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name:
// Student No:
// Date: 
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

// ***** QUESTION 3 ******
// Question 3 has 3 parts
// 3.1 Using the MINIMAL "Fraction" class provided, overload the greater than operator to work with
//     objects of class Fraction as a NON-MEMBER FUNCTION.   You may modify the Fraction class to 
//     demonstrate friendship.  DO NOT USE FLOATING POINT MATH!!!
// 3.2 Overload two functions called "add" which take two arguements, an integer and a fraction (in 
//     either order) and return a fraction.  
// 3.3 create a driver program to test your overloaded > operators and your overloaded 

class Fraction {
private:
	int num;				// numerator;
	int denom;				// denominator;
public:
	Fraction(int n, int d) : num(n), denom(d) { };
	void print() { cout << num << "/" << denom; };

	friend bool operator>(Fraction LHS, Fraction RHS);
	Fraction add(const Fraction &, const int &);
	Fraction add(const int &, const Fraction &);
};

bool operator>(Fraction LHS, Fraction RHS)
{
	if (LHS.num*RHS.denom > RHS.num*LHS.denom)
		return true;
	else
		return false; 
}

Fraction Fraction::add(const Fraction &a, const int &b)
{
	Fraction temp = a;
	temp.num = b*temp.denom;
	
	return temp;
}

Fraction Fraction::add(const int &b, const Fraction &a)
{
	Fraction temp = a;
	temp.num = b*temp.denom;

	return temp;
}