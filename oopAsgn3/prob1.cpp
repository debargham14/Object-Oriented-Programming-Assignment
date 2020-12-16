#include<iostream>
//defining the max macro
#define max(a, b) (a > b ? a : b)
using namespace std;


int main() {
	//usage of max macro on numbers
	int a, b;
	cout << "Enter the Two Numbers : ";
	cin >> a >> b;
	cout << max(a, b);

	//usage of max macro on char* types variable
	char word1[20];
	char word2[30];
	cout << "Enter Two Words : ";
	cin >> word1 >> word2;
	cout << max(word1, word2);

	return 0;
}

//while applying the macro on integer variable it returns the correct ouput while on applying
//it on char* type argument it always returns the second word entered.