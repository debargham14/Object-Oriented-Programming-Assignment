#include<iostream>
using namespace std;

//designing the class array to perform the relevant operations
class ARRAY {
	int *p;
	int size;
public:
	//constrcutor to initialise the array
	ARRAY(int s = 0) {
		if (s == 0) {
			size = s;
			p = NULL;
		}
		else {
			size = s;
			p = new int[size];
			for (int i = 0; i < size; i++)	p[i] = 0;
		}
	}
	//defining the copy constructor
	ARRAY(const ARRAY& a) {
		size = a.size;
		if (size == 0)
			p = NULL;
		else {
			p = new int[size]; //creating a new array
			for (int i = 0; i < size; i++)	p[i] = a.p[i];
		}
	}

	//copy constructor to copy an array
	ARRAY(int *arr, int n) {
		size = n;
		if (size == 0)
			p = NULL;
		else {
			p = new int[size]; //creating a new array
			for (int i = 0; i < n; i++)	p[i] = arr[i];
		}
	}

	//overloading the >> to take the array as input
	friend void operator >> (istream &is, ARRAY& a) {
		for (int i = 0; i < a.size; i++)	is >> a.p[i];
	}

	//operator << overloaded to display the array
	friend ostream& operator << (ostream &os, ARRAY a) {
		for (int i = 0; i < a.size; i++)	os << a.p[i] << " ";
		return os;
	}

	//operator overloading + to add the two array
	void operator =  (ARRAY &b) {
		size =  b.size;
		if (size == 0) {
			p = NULL;
		}
		else {
			p = new int[size];
			for (int i = 0; i < b.size; i++)	p[i] = b.p[i];
		}
	}

	//operator overloading + to add the contents of two array
	friend ARRAY operator + (ARRAY &a, ARRAY &b) {
		ARRAY c(a.size > b.size ? a.size : b.size);
		if (a.size < b.size)
		{
			for (int i = 0; i < a.size; i++)	c.p[i] = a.p[i] + b.p[i];
			for (int i = a.size; i < b.size; i++)	c.p[i] = b.p[i];
		}
		else {
			for (int i = 0; i < b.size; i++)	c.p[i] = a.p[i] + b.p[i];
			for (int i = b.size; i < a.size; i++)	c.p[i] = b.p[i];
		}
		return c;
	}

	//operator overloading for [] so that array can be accessed as a[idx] for array being an object of the array class
	int& operator [] (int idx) {
		return p[idx];
	}

	//overloadinf the operator * to support multiplication of an array with integers
	friend ARRAY operator * (ARRAY &a, int x) {
		ARRAY c(a.size);
		for (int i = 0; i < a.size; i++)	c.p[i] = a.p[i] * x;
		return c;
	}
	friend ARRAY operator * (int x, ARRAY &a) {
		ARRAY c(a.size);
		for (int i = 0; i < a.size; i++)	c.p[i] = a.p[i] * x;
		return c;
	}

	//destructor is used to set the memory free
	~ARRAY() {
		delete[] p;
	}
};

//driver code to implment the above class
int main() {
	int n;
	cout << "Enter the number of elements of the array :- ";
	cin >> n;
	ARRAY a(n), b;	//initialising the array using copy constructor
	cout << "Enter the array :- ";
	cin >> a;	//taking input of an array
	cout << "Your Entered Array is :- ";
	cout << a << "\n";	//displaying the array
	b = a; //copying an array bytewise
	cout << "A check to the copy function :- ";
	cout << b << "\n";

	ARRAY c = a + b; //adding the contents of two array
	c[0] = 1000; // check the [] operator in the ARRAY
	cout << "A check to the add function :- ";
	cout << c << "\n";

	ARRAY d = 5 * c; //multiplying the content of array with constant variable
	cout << "A check to the multiply function :- ";
	cout << d << "\n";
	return 0;
}