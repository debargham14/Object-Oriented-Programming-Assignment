#include<iostream>
using namespace std;

//swapping two numbers wihtout the use of pointers
struct numbers {
	int first;
	int second;
};

numbers swapValues(numbers source) {
	int temp = source.first;
	source.first = source.second;
	source.second = temp;

	return source;
}


int main() {
	numbers n;

	cout << "Enter the first number :- ";
	cin >> n.first;

	cout << "Enter the second number :- ";
	cin >> n.second;

	n = swapValues(n);

	cout << "The first and the second numbers are :- " << n.first << " " << n.second;
	return 0;
}