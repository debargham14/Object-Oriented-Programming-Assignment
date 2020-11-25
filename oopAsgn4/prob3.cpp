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
			len++;
			i++;
		}
		for (i = 0; i < len; i++)	c[i] = s.c[i];
		c[len] = '\0';
	}

	//overloading the operator ==
	bool operator == (STRING s) {
		int i = 0;
		while (s.c[i] != '\0') {
			if (s.c[i] != c[i])
				return false;
			i++;
		}
		return true;
	}

	//bool oveloading the opeartor !=
	bool operator != (STRING s) {
		int i = 0;
		while (s.c[i] != '\0') {
			if (s.c[i] != c[i])
				return true;
		}
		return false;
	}

	//bool overloading the operator <
	bool operator < (STRING s) {
		int i = 0; bool flag = false;
		while (s.c[i] != '\0') {
			if (s.c[i] != c[i]) {
				flag = true;
				break;
			}
			i++;
		}
		if (flag == false)
			return false;
		else {
			if (c[i] < s.c[i])
				return true;
			else
				return false;
		}
	}

	//bool overloading the operator >
	bool operator > (STRING s) {
		int i = 0; bool flag = false;
		while (s.c[i] != '\0') {
			if (s.c[i] != c[i]) {
				flag = true;
				break;
			}
			i++;
		}
		if (flag == false)
		{
			if (c[i] != '\0')
				return true;
			else
				return false;
		}
		else {
			if (c[i] < s.c[i])
				return false;
			else
				return true;
		}
	}

	//bool overloading the operator <=
	bool operator <= (STRING s) {
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
	bool operator >= (STRING s) {
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
	STRING operator + (STRING s2) {
		int len = 0, i = 0;
		STRING s;
		while (c[i] != '\0') {
			s.c[len++] = c[i++];
		}
		i = 0;
		while (s2.c[i] != '\0') {
			s.c[len++] = s2.c[i++];
		}
		s.c[len] = '\0';
		return s;
	}
};

//driver function to utilise the classes
int main() {
	STRING s, s1;
	cin >> s;
	cout << s << "\n";

	s1 = s;
	// cout << s1;

	STRING s2 = (s + s1);
	cout << s2;
	return 0;
}