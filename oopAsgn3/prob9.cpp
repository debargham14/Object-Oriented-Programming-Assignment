#include<iostream>
using namespace std;

//designing the class time
class TIME {

private :
	int hour, min, sec, type;
	string suff;
public :
	//constructor
	TIME() {
		suff = "na";
	}
	//function to load the data
	void loadData() {
		int type;
		cout << "Select the format (1. 24 hrs / 2. (am/pm) ) you want to enter the data :- ";
		cin >> type;

		switch (type) {
		case 1:
			cout << "Enter the hour minutes and seconds respectively :- ";
			cin >> hour >> min >> sec;
			{
				if (sec >= 60) {
					//placing the excess seconds under min
					int extra = sec - (sec / 60) * 60;
					min += (sec) / 60;
					sec = extra;
				}
				if (min >= 60) {
					//placing the excess minutes under hours
					int extra = (min - (min / 60) * 60);
					hour += min / 60;
					min = extra;
				}
			}
			break;
		case 2:
			cout << "Enter the hour minutes seconds and time suff respectively :- ";
			cin >> hour >> min >> sec >> suff;

			if (hour)
			{
				if (sec >= 60) {
					//placing the excess seconds under min
					int extra = sec - (sec / 60) * 60;
					min += (sec) / 60;
					sec = extra;
				}

				if (min >= 60) {
					//placing the excess minutes under hours
					int extra = (min - (min / 60) * 60);
					hour += min / 60;
					min = extra;
				}
			}
		}
	}

	//function to show the data
	void showData() {
		if (suff == "na") {
			cout << "Your entered time is :- " << hour << ":" << min << ":" << sec << "\n";
		}
		else {
			cout << "Your entered time is :- " << hour << ":" << min << ":" << sec << " " << suff << "\n";
		}
	}

	//function to add the minute
	void addMinute();
};

//function declared to add extra minutes
void TIME::addMinute() {
	if(suff == "na"){
		if(hour == 24){
			cout << "Sorry minutes cannot be added !";
			return;
		}
		else{
			int m;
			cout << "Enter the minutes you wish to add :- ";
			cin >> m;
			int h = m / 60;
			m -= (h * 60);
			if(hour + h > 24){
				cout << "Sorry minutes addition not feasible !";
				return;
			}
			else if(hour + h == 24 && (m > 0 || sec > 0)){
				cout << "Sorry minutes addition not feasible !";
				return;
			}
			else{ 
				hour += h;
				min += m;
			}
		}
	}
	else {
		if(hour == 12){
			cout << "Sorry minutes cannot be added !";
			return;
		}
		else{
			int m;
			cout << "Enter the minutes you wish to add :- ";
			cin >> m;
			int h = m / 60;
			m -= (h * 60);
			if(hour + h > 12){
				cout << "Sorry minutes addition not feasible !";
				return;
			}
			else if(hour + h == 12 && (m > 0 || sec > 0)){
				cout << "Sorry minutes addition not feasible !";
				return;
			}
			else{ 
				hour += h;
				min += m;
			}
		}
	}
}

int main() {
	TIME t1;
	t1.loadData();
	t1.showData();
	t1.addMinute();
	t1.showData();
	return 0;
}