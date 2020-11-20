#include<iostream>
using namespace std;

//checking function overloading
void f(int var1, char var2) {
	cout << "inside(int, char)";
}

void f(char var1, int var2) {
	cout << "inside(char, int)";
}


int main () {
	int in = 1;
	char ch1 = 'a', ch2 = 'b';
	float f1 = 10.1, f2 = 5.12;
	f(in, ch1);

	//these two function call leads to ambiguity for choosing the correct function
	// f(ch1, ch2);
	// f(f1, f2);
	return 0;
}
