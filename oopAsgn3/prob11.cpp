#include<iostream>
#define MAX_SIZE 100
using namespace std;

//designing the class applicant to perform the relevant operation
class APPLICANT {
	static int lastId; //static variable declared to implement the auto increment feature
	int id;
	char name[20];
	int score;

public:
	//method to recieve applicant data
	void receiveData() {
		cout << "Enter the name of the applicant :- ";
		cin >> name;
		cout << "Enter the score of the student :- ";
		cin >> score;
		id = ++lastId; //auto increment feature enbaled using static data member
	}

	//show applicant data
	void showData() {
		cout << "Id of the student :- " << id << "\n";
		cout << "Name of the student :- " << name << "\n";
		cout << "Score of the student :- " << score << "\n";
	}

	//use of static data member is made to make it independent of the instance and can be called wihtout the use of object
	static void totalCount() {
		cout << "Total number of students registered so far :- " << lastId << "\n";
	}
};

int APPLICANT::lastId = 0;

int main() {
	//defining instances to use the methods
	APPLICANT a1, a2;

	a1.receiveData();
	a2.receiveData();

	a1.showData();
	a2.showData();

	APPLICANT::totalCount();
	return 0;
}


