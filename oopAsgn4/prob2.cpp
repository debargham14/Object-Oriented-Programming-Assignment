#include<iostream>
using namespace std;

//definition of class complex
class COMPLEX {
	int re, im;
public:
	//defining a default constructor
	COMPLEX (int r = 0, int i = 0) {
		re = r;
		im = i;
	}

	//opeartor overloading for >> opeartor
	friend istream operator >> (istream &is, COMPLEX &c) { //defined as a friend function so that it can be used the way desired
		cout << "Enter the real and imaginary part respectively";
		is >> c.re >> c.im;
	}//returning istream type object

	//operator overloading for << operator
	friend ostream operator << (ostream &os, COMPLEX &c) {
		os << "Real :- " << c.re << "\n";
		os << "Imaginary :- " << c.im << "\n";
	}//returning ostream type object

	//overloading operator +
	COMPLEX operator+(COMPLEX c) {
		COMPLEX ans;
		ans.re = re + c.re;
		ans.im = im + c.im;

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
	COMPLEX c3 = c1 + c2;
	COMPLEX c4 = c1 - c2;
	COMPLEX c5 = c1 + 7;

	cout << c3;	//cout --> object of the ostream class, c3 -> object of COMPLEX CLASS
	cout << c4;
	cout << c5;
	return 0;
}