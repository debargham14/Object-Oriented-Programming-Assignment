//using the required classes
#include<iostream>
#include<string.h>

using namespace std;

class STRING {
	char c[100];
public:

	//operator overloading >> to take the string as input
	friend void operator >> (istream &is, STRING &s) {
		is >> s.c;
	}

	//operator overloading << to display the string as output
	friend ostream& operator << (ostream &os, STRING &s) {
		os << s.c;
		return os;
	}

	//overloading the operator = to copy one string into another
	void operator = (STRING s) {
		int len = 0, i = 0;
		while (s.c[i] != '\0')
		{
			len++;	//incrementing the length
			i++;
		}
		for (i = 0; i < len; i++)	c[i] = s.c[i]; //copying the string character by character
		c[len] = '\0'; //ending the string with the NULL character
	}

	//overloading the operator ==
	bool operator == (STRING s) { //method to check the equality of two strings
		int i = 0;
		while (s.c[i] != '\0') {
			if (s.c[i] != c[i])	//if unequal characters occur
				return false;
			i++;
		}
		//else no unequal characters
		return (c[i] == '\0');
	}

	//bool oveloading the opeartor !=
	bool operator != (STRING s) { //method to check the unequality of the two strings
		int i = 0;
		while (s.c[i] != '\0') {
			if (s.c[i] != c[i])		//if inequality arises
				return true;
			i++;
		}
		return false; //else return false
	}

	//bool overloading the operator <
	bool operator < (STRING s) { //method to find whether first string is smaller than the second
		int i = 0; bool flag = false;
		while (s.c[i] != '\0') {	//compare till the second string reaches a NULL character
			if (s.c[i] != c[i]) {
				flag = true;	//when inequlaity arises break
				break;
			}
			i++;
		}
		if (flag == false) // if flag is false that means either
			return false;	//the first string is longer or both are equal
		else {//else check  the unequal characters
			if (c[i] < s.c[i]) //first string is shorter
				return true;
			else
				return false;	//second string is shorter
		}
	}

	//bool overloading the operator >
	bool operator > (STRING s) {//method to find whether first string is greater than the second
		int i = 0; bool flag = false;
		while (s.c[i] != '\0') {	//compare till the second string reaches the NULL character
			if (s.c[i] != c[i]) {	// inequality arises
				flag = true;
				break;
			}
			i++;
		}
		//if flag is false then either first string longer or equal
		if (flag == false)
		{
			if (c[i] != '\0')	//if equal return false;
				return true;
			else
				return false;
		}
		else {
			if (c[i] < s.c[i] || c[i] == '\0')// comapare the unequal characters
				return false;
			else
				return true;
		}
	}

	//bool overloading the operator <=
	bool operator <= (STRING s) {	//same as that of the < operator except the fact it also checks equality
		int i = 0; bool flag = false;
		while (s.c[i] != '\0') {
			if (s.c[i] != c[i]) {
				flag = true;
				break;
			}
			i++;
		}
		if (flag == false && c[i] == '\0' && s.c[i] == '\0')
			return true;
		else {
			if (c[i] < s.c[i])
				return true;
			else
				return false;
		}
	}

	//bool overloading the operator >=
	bool operator >= (STRING s) {	//same as that of the > operator except the fact it also checks equality
		int i = 0; bool flag = false;
		while (s.c[i] != '\0') {
			if (s.c[i] != c[i]) {
				flag = true;
				break;
			}
			i++;
		}
		if (flag == false)
			return true;
		else {
			if (c[i] > s.c[i])
				return true;
			else
				return false;
		}
	}

	//desingning the operator +
	STRING operator + (STRING s2) { //method to concatenate the two entered strings
		int len = 0, i = 0;
		STRING s;
		while (c[i] != '\0') {	//fetching the characters of the first string
			s.c[len++] = c[i++];
		}
		i = 0;
		while (s2.c[i] != '\0') {	//fetching the characters of the second string
			s.c[len++] = s2.c[i++];
		}
		s.c[len] = '\0';	//setting the last character of the string to NULL
		return s; //returning the concatenated string
	}
};

//driver function to utilise the classes and the defined methods and the attributes
int main() {
	STRING s2, s1, s3;	//defining the strings
	//menu8 driven code to check the operators
	while (1) {
		cout << "1. concatenation\n2. <=\n3. >=\n4. <\n5. >\n6. ==\n7. !=\n8. exit\n";
		int ch;
		cin >> ch;

		switch (ch) {
		case 1: cout << "Enter the first string :- ";
			cin >> s1;
			cout << "Enter the second string :- ";
			cin >> s2;
			s3 = s1 + s2;
			cout << "The concatnated string is :- " << s3 << "\n";
			break;
		case 2: cout << "Enter the first string :- ";
			cin >> s1;
			cout << "Enter the second string :- ";
			cin >> s2;
			cout << (s1 <= s2);
			cout << "\n";
			break;
		case 3: cout << "Enter the first string :- ";
			cin >> s1;
			cout << "Enter the second string :- ";
			cin >> s2;
			cout << (s1 >= s2);
			cout << "\n";
			break;
		case 4: cout << "Enter the first string :- ";
			cin >> s1;
			cout << "Enter the second string :- ";
			cin >> s2;
			cout << (s1 < s2);
			cout << "\n";
			break;
		case 5: cout << "Enter the first string :- ";
			cin >> s1;
			cout << "Enter the second string :- ";
			cin >> s2;
			cout << (s1 > s2);
			cout << "\n";
			break;
		case 6: cout << "Enter the first string :- ";
			cin >> s1;
			cout << "Enter the second string :- ";
			cin >> s2;
			cout << (s1 == s2);
			cout << "\n";
			break;
		case 7: cout << "Enter the first string :- ";
			cin >> s1;
			cout << "Enter the second string :- ";
			cin >> s2;
			cout << (s1 == s2);
			cout << "\n";
			break;
		case 8: exit(0);
		}
	}

	return 0;
}