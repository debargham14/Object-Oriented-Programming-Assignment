#include<iostream>
#define MAX_SIZE 100
using namespace std;

//defining the class STUDENT
class STUDENT {
	static int lastRoll; // to include the auto increment feature
	int roll;
	char name[20], course[20], admDate[20];
	bool scorePresent = false;
	int score[5];

public:
	//method to take admission when a new student comes
	void getAdm() {
		roll = ++lastRoll;
		cout << "Enter the name of the student :- ";
		scanf(" %[^\n]s", name);
		cout << "Enter the course name :- ";
		scanf(" %[^\n]s", course);
		cout << "Enter the date of admission in dd/mm/yy format :- ";
		cin >> admDate;
	}

	//method to get score of the students in 5 different subjects
	void getScore() {
		scorePresent = true;
		for (int i = 0; i < 5; i++) {
			cout << "Enter the marks of sub" << i + 1 << " :- ";
			cin >> score[i];
		}
	}

	//method to cheeck whether score is present or not
	bool scorePres() {
		return scorePresent == true;
	}

	//method to display the student data
	void showData() {
		cout << "Roll of the student :- " << roll << "\n";
		cout << "Name of the student :- " << name << "\n";
		cout << "Admission Date :- " << admDate << "\n";
		cout << "Course enrolled :- " << course << "\n";
	}

	//method to display the marks of the students
	void displayMarks() {
		for (int i = 0; i < 5; i++) {
			cout << "Marks obtained in sub " << i + 1 << " :- " << score[i] << "\n";
		}
	}

	//static method to get acess to the number of students without the invoking 0bject
	static void totalCount() {
		cout << "The total number of students registered :- " << lastRoll << "\n";
	}
};

int STUDENT::lastRoll = 0;

//making the utility function a bit more interactive
int main() {

	STUDENT s1;
	s1.getAdm();

	char ch;
	cout << "Do you want to enter the score of the candidate (y/n) :- ";
	cin >> ch;

	if (ch == 'y' || ch == 'Y')
	{
		s1.getScore();
	}
	s1.showData();


	if (s1.scorePres()) {
		s1.displayMarks();
	}

	//display the total number of students registered
	STUDENT::totalCount();
	return 0;
}