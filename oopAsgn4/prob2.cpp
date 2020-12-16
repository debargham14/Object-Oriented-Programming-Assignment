#include<iostream>
using namespace std;

//definition of class complex
class COMPLEX {
	int re, im;
public:
	//defining a default constructor
	COMPLEX (const int &r = 0, const int &i = 0) {
		re = r;
		im = i;
	}
	//copy constructir defined for initialization and assignment purposes
	COMPLEX(const COMPLEX &c) {
		re = c.re;
		im = c.im;
	}

	//opeartor overloading for >> opeartor
	friend void operator >> (istream &is, COMPLEX &c) { //defined as a friend function so that it can be used the way desired
		cout << "Enter the real and imaginary part respectively :- ";
		is >> c.re >> c.im;
	}//returning istream type object

	//operator overloading for << operator
	friend ostream& operator << (ostream &os, COMPLEX &c) {
		os << "Real :- " << c.re << "\n";
		os << "Imaginary :- " << c.im << "\n";
		return os;
	}//returning ostream object reference 

	//overloading operator +
	friend COMPLEX operator+(COMPLEX c1, COMPLEX c) {
		COMPLEX ans;
		ans.re = c1.re + c.re;
		ans.im = c1.im + c.im;

		return ans; //returning object of type complex
	}

	//overloading - operator to enable the operation of subtraction
	COMPLEX operator-(COMPLEX c) {
		COMPLEX ans;
		ans.re = re - c.re;
		ans.im = im - c.im;

		return ans;
	}
};

//driver code to implement the above class
int main() {
	COMPLEX c1(1, 1), c2(2, 4);
	cin >> c1;	//cin --> object of istream class, c1 ->object of COMPLEX class
	cin >> c2;
	COMPLEX c7 = c1; //check the copy constructor
	COMPLEX c3 = c1 + c2;
	COMPLEX c4 = c1 - c2;
	COMPLEX c5 = 7 + c1; //due to default constructor is defined and friend function 
						//is used , it is able to add an integer with complex value
	cout << c3;	//cout  object refrence of the ostream class, c3 -> object of COMPLEX CLASS
	cout << c4;	
	cout << c5;
	cout << c7;
	return 0;
}