#include<iostream>
#include<string.h>

using namespace std;

//date checker can be implemented later

class TRANSACTION;	//forward declaration
//defining the class TRANSACTION
class BALANCE {
	int accNo;
	int balance;
	char dateOfLastUpd[10];

public:
	//defining the method getDATA
	void getData() {
		cout << "Enter the account Number :- ";
		cin >> accNo;
		cout << "Enter the balance :- ";
		cin >> balance;

		cout << "Enter date (dd/mm/yy):- ";
		cin >> dateOfLastUpd;
	}
	//defining the mehod show data;
	void showData() {
		cout << "The account number of the person :- " << accNo << "\n";
		cout << "Available Balance :- " << balance << "\n";
		cout << "Date of Last Update :- " << dateOfLastUpd << "\n";
		cout << "---------------------------------------------------\n";
	}

	//defining the prototype of update balance method;
	void updateBalance(TRANSACTION &t);
};

//defining the class transaction
class TRANSACTION {
	int accNo;
	char dateOfTran[10];
	int amount;
	char type;

public:
	friend void BALANCE::updateBalance(TRANSACTION &t); //declaration of member function as friend
	//defining the get data method
	void getData() {
		cout << "Enter the account number :- ";
		cin >> accNo;
		cout << "Enter the date of transaction (dd/mm/yy) :- ";
		cin >> dateOfTran;
		cout << "Enter the amount :- ";
		cin >> amount;
		cout << "Enter the transaction type (w/d):- ";
		cin >> type;
	}

	//show data method required
	void showData() {
		cout << "The account number :- " << accNo << "\n";
		cout << "Date of transaction :- " << dateOfTran << "\n";
		cout << "Type of transaction :- " << type << "\n";
		cout << "------------------------------------------------------\n";
	}
};

//defining the class balance
void BALANCE::updateBalance(TRANSACTION &t) {
	if (t.accNo == accNo) {
		if (t.type == 'W' || t.type == 'w') {
			if (balance < t.amount) {
				cout << "Sufficient Balance not available :- ";
				return;
			}
			else {
				//withdrawal operation
				cout << "Transaction successful " << "\n";
				balance -= t.amount;
				strcpy(dateOfLastUpd, t.dateOfTran);
				showData();
				return;
			}
		}
		else {
			//deposit operation
			cout << "Transaction successful " << "\n";
			balance += t.amount;
			strcpy(dateOfLastUpd, t.dateOfTran);
			showData();
			return;
		}
	}
	else {
		//mismatch alert
		cout << "Account number mismatch !";
		return;
	}
}

//driver code to implment the classes
int main() {
	BALANCE b; //creating an instance of balance
	b.getData();
	b.showData();

	TRANSACTION t;
	t.getData();
	t.showData();

	//call to update balance function is made
	b.updateBalance(t);
	return 0;
}