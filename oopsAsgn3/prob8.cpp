#include<iostream>
using namespace std;

struct student {
	int roll, score;

	void loadData() {
		cout << "Enter the roll and the score of the student respectively :- ";
		cin >> roll >>  score;
		cout << "\n";
	}
	void showData() {
		cout << "The roll and the score of the student is :- " << roll << " " << score;
	}
};

void modifyScore(student s1) {
	int ms;
	cout << "Enter the modified score :- ";
	cin >> ms;
	s1.score = ms;

	cout << "The roll and modified score is :- " << s1.roll << " " << s1.score << "\n";
}

int main() {
	student s1;
	s1.loadData();
	s1.showData();

	modifyScore(s1);
	//cout << "The roll and modified score is :- " << s1.roll << " " << s1.score << "\n";
	return 0;
}