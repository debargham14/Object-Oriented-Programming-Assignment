#include<iostream>
using namespace std;

struct types {
	char ch;
	int in;
	float fl;
	double dou;

	types(char t1, int t2, float t3, double t4) {
		ch = t1;
		in = t2;
		fl = t3;
		dou = t4;
	}
};

//two functions with different argument list to do test function overloading
void f(int var) {
	cout << "inside f(int)\n";
}

void f(float var) {
	cout << "inside f(float)";
}

int main() {
	double d = 10.1234567;
	types ty('a', 5, 10.12, d);

	//testing f(int) and f(float)
	f(ty.ch);
	f(ty.in);
	f(ty.fl);
	//f(ty.dou); // causes ambiguity
	return 0;
}


//for double type variable since there is a  scope for both conversion and promotion
//the set contains both the functions f(int) and f(float) and thereby leading to ambiguity
