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
	temp.num += b*temp.denom;
	
	return temp;
}

Fraction Fraction::add(const int &b, const Fraction &a)
{
	Fraction temp = a;
	temp.num += b*temp.denom;

	return temp;
}

int main(int argc, char **argv)
{
	Fraction temp1(1, 2), temp2(3, 4), temp3(7, 8), temp4(4, 9);

	if (temp2 > temp1)
	{
		temp1.print();
		cout << " is larger than ";
		temp2.print();
	}
	else
	{
		temp1.print();
		cout << " is smaller than ";
		temp2.print();
	}
	cout << endl;

	temp1.print();
		cout << " + 1 = ";
	temp3 = temp3.add(temp1, 1);
		temp3.print();
	cout << endl;


	cout << "1 + ";
	temp1.print();
	cout << " = ";
	temp4 = temp4.add(1, temp1);
	temp4.print();
	cout << endl;

	return 0;
}