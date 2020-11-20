#include<iostream>
#define MAX_SIZE 100
using namespace std;

//defining the class applicant
class APPLICANT {
	static int lastId;
	int id;
	char name[30];
	int score;

public:

	void receiveData();
	void showData();
	static void showCount();
};

//function to receive the data
void APPLICANT::receiveData() {
	id = ++lastId;
	cout << "Enter the name :- ";
	cin >> name;

	cout << "Enter the score :- ";
	cin >> score;
}

//function to show the data
void APPLICANT::showData() {
	cout << "Appliaction Id" << id << "\n";
	cout << "Name of the student :- " << name << "\n";
	cout << "Score of the applicant :- " << score << "\n";
}

//function to show the applicant count
void APPLICANT::showCount() {
	cout << "The number of registered applicants = " << lastId << "\n";
}



int main() {

	cout << "Enter 1 to enter applicant data and 0 to stop entering data";
	int ch, i = 0;

	APPLICANT a[MAX_SIZE];
	while (1) {
		cin >> ch;
		if (!ch) {
			break;
		}
		else {
			a[i].receiveData();
			i++;
		}
	}

	APPLICANT::showCount();

	for (int j = 0; j < i; j++) {
		cout << "Details of applicant " << i + 1 << "--------\n";
		a[i].showData();
	}


	return 0;
}