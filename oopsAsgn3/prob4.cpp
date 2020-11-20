#include<iostream>
using namespace std;

//max function to return the pointer as the argument
int max(int &a, int &b) {
	return (a > b ? a : b);
}


int main() {
	int first, second;
	cout << "Enter the first and the second numbers respectively :- ";
	cin >> first >> second;

	int c = max(first, second);
	cout << "The max out of two numbers is :- " << c;
}