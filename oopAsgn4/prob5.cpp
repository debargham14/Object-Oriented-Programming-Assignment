#include<iostream>
#include<string.h>
using namespace std;

//designing the class STRING
class STRING {
	int* cnt;
	char* s;
public:
	//implmenting the default constructor
	STRING (const char* val = "\0") {
		cnt = new int;
		*cnt = 1;
		s = new char[strlen(val) + 1];
		strcpy(s, val);
	}

	//implementing the copy constructor to create different memory locations for different objects
	STRING(const STRING& str) {
		s = str.s;
		cnt = str.cnt;
		(*cnt)++;
	}

	//assignment operator to avoid double freeing of the tcache
	void operator = (const STRING& str) {
		if (s != "\0") {
			(*cnt)--;
			if (*cnt == 0)
			{
				delete cnt;
				delete[] s;
			}
		}
		cnt = str.cnt;
		s = str.s;
		(*cnt)++;
	}

	//overloading the opeartor >> to take a string as input
	friend void operator >> (istream& is, STRING& str) {
		is >> str.s;
	}

	//overlodig the operator << to show the string as output
	friend ostream& operator << (ostream& os, STRING& str) {
		os << str.s;
		return os;
	}

	//method to concatenate the strings
	STRING operator + (STRING const& str) {
		STRING str1;
		str1.s = new char[strlen(str.s) + strlen(s) + 1];
		int i = 0, j = 0;
		while (s[i] != '\0') {
			str1.s[i] = s[i];
			i++;
		}
		while (str.s[j] != '\0') {
			str1.s[i] = str.s[j];
			j++;
			i++;
		}
		cout << str1.s << " ";
		return str1;
	}

	//overloading the operator ==
	bool operator == (STRING str) { //method to check the equality of two strings
		int i = 0;
		while (str.s[i] != '\0') {
			if (str.s[i] != s[i])	//if unequal characters occur
				return false;
			i++;
		}
		//else no unequal characters
		return (s[i] == '\0');
	}

	//bool oveloading the opeartor !=
	bool operator != (STRING str) { //method to check the unequality of the two strings
		int i = 0;
		while (str.s[i] != '\0') {
			if (str.s[i] != s[i])		//if inequality arises
				return true;
			i++;
		}
		return false; //else return false
	}

	bool operator < (STRING str) { //method to find whether first string is smaller than the second
		int i = 0; bool flag = false;
		while (str.s[i] != '\0') {	//compare till the second string reaches a NULL character
			if (str.s[i] != s[i]) {
				flag = true;	//when inequlaity arises break
				break;
			}
			i++;
		}
		if (flag == false) // if flag is false that means either
			return false;	//the first string is longer or both are equal
		else {//else check  the unequal characters
			if (s[i] < str.s[i]) //first string is shorter
				return true;
			else
				return false;	//second string is shorter
		}
	}

	//bool overloading the operator >
	bool operator > (STRING str) {//method to find whether first string is greater than the second
		int i = 0; bool flag = false;
		while (str.s[i] != '\0') {	//compare till the second string reaches the NULL character
			if (str.s[i] != s[i]) {	// inequality arises
				flag = true;
				break;
			}
			i++;
		}
		//if flag is false then either first string longer or equal
		if (flag == false)
		{
			if (s[i] != '\0')	//if equal return false;
				return true;
			else
				return false;
		}
		else {
			if (s[i] < str.s[i] || s[i] == '\0')// comapare the unequal characters
				return false;
			else
				return true;
		}
	}

	//bool overloading the operator <=
	bool operator <= (STRING str) {	//same as that of the < operator except the fact it also checks equality
		int i = 0; bool flag = false;
		while (str.s[i] != '\0') {
			if (str.s[i] != s[i]) {
				flag = true;
				break;
			}
			i++;
		}
		if (flag == false && s[i] == '\0' && str.s[i] == '\0')
			return true;
		else {
			if (s[i] < str.s[i])
				return true;
			else
				return false;
		}
	}

	//bool overloading the operator >=
	bool operator >= (STRING str) {	//same as that of the > operator except the fact it also checks equality
		int i = 0; bool flag = false;
		while (str.s[i] != '\0') {
			if (str.s[i] != s[i]) {
				flag = true;
				break;
			}
			i++;
		}
		if (flag == false)
			return true;
		else {
			if (s[i] > str.s[i])
				return true;
			else
				return false;
		}
	}
	//destrutor to free the space previously allocated
	~STRING () {
		(*cnt)--;
		if (*cnt == 0) {
			delete[] s;
			delete cnt;
		}
	}
};

int main() {
	STRING s1;	//defining the strings
	//menu8 driven code to check the operators
	STRING s3("Debargha");
	cin >> s1;
	cout << s1 << "\n";
	STRING s2(s1);
	cout << s2 << "\n";
	s1 = s3;
	cout << s1 << "\n";
	return 0;
}