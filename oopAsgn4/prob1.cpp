//necessary header files 
#include<iostream>
#define MAX_SIZE 100
using namespace std;

class APPLICANT;
class ListOfApplicants; //fwd declarartions done

//designing the class withdraw
class WITHDRAW{
	int accNo;
	int amount;

public:
	//designing a method to get the withdraw details data
	void getData(APPLICANT&);

	//update balance to be called by the withdraw object
	void updateBalance(APPLICANT&);
};

//designing the class applicant
class APPLICANT{
	int accNo;
	int balance;
public:
	//relevant constructor
	APPLICANT() {
		accNo = -1;
		balance = -1;
	}
	//function to get the relevant applicant details
	void getData() {
		cout << "Enter the Account Number :- ";
		cin >> accNo;
		cout << "Enter the Current Balance :- ";
		cin >> balance;
	}
	//method to print the applicant data
	void showData() {
		cout << "Account Number :- " << accNo << "\n";
		cout << "Available Balance :- " << balance << "\n";
	}

	//friend functions to support withdraw operation
	friend void WITHDRAW::updateBalance(APPLICANT&);
	friend void WITHDRAW::getData(APPLICANT&);

	friend class ListOfApplicants; //making the list of applicants class friend
};
APPLICANT dummy; // to return incase if function reaches end without returning anything

//defining the method update balance
void WITHDRAW::updateBalance(APPLICANT& obj) {
	if(obj.balance > amount) { // if the amount to be withdrawn is present
		//perform the relevant operation
		obj.balance -= amount;
		cout << "Withdraw Successful !\n";
	}
	else {
		cout << "Insufficient Balance ! Cannot withdraw\n";
		return;
	}
}

//designing the class applicant list to maintain a list of applicants
class ListOfApplicants{
	int count = -1;
	APPLICANT arr[MAX_SIZE];//creating an array of appli
public:
	//method to add a new applicant
	void addApplicant() {
		int flag = 0;
		APPLICANT obj;
		obj.getData();
		for(int i = 0; i <= count; i++) { //check the uniqueness of the account
			if(arr[i].accNo == obj.accNo){ //if account already exists
				cout << "Account already exists !\n";
				flag = 1;
			}
		}
		if(!flag) { //if account does not exists add the account
			arr[++count] = obj;
		}
	}

	//method to display an applicant by account number if existing  
	void displayByAccNo(int val) {
		int flag = 0;
		for(int i = 0; i <= count; i++) {	//iterating over all the accounts
			if(arr[i].accNo == val) {
				cout << "Account Found ! Here are the details :- \n";
				arr[i].showData();
				flag = 1;
			}
		}
		if(flag == 0)
			cout << "Account Does Not exists !\n";
	} 

	//method to search by acc number 
	bool searchByAccNo(int val){ //return true/flase depending upon whether account exists or not
		for(int i = 0; i <= count; i++) {
			if(arr[i].accNo == val)
				return 1;
		}
		return 0;
	} 

	// returning the account (object reference) that matches a particular account number  
	APPLICANT& retObject(int val) {
		for(int i = 0; i <= count; i++) {	
			if(arr[i].accNo == val)
				return arr[i];
		}
		return dummy; //returning dummy object
	}

	//method to display all the accounts
	void displayAll() {
		cout << "Details Of All Acounts are ------- \n";
		for(int i = 0; i <= count; i++){
			arr[i].showData();
			cout << "---------------------------------------\n";
		}
	}
};

//implmenting the function getdata
void WITHDRAW::getData(APPLICANT& obj) {
	accNo = obj.accNo;
	cout << "Enter the amount to be withDrawn :- ";
	cin >> amount;
}

//driver code to implment the same
int main() {
	ListOfApplicants obj;
	while(1) {
		//menu driven code to implment the functionalities
		cout << "1. add Acount\n2. display account\n3. display All accounts\n4. withdraw\n5. eixt\n";
		int ch;
		cin >> ch;	//receiving the user choice 

		switch(ch) {
			case 1:
				obj.addApplicant(); // to add an applicant 
				break;
			case 2:
				int accountNo;
				cout << "Enter the account number :- ";
				cin >> accountNo;
				obj.displayByAccNo(accountNo);	// to diplay an account by the given account number
				break;
			case 3:
				obj.displayAll();	// to diplay all the accounts
				break;
			case 4:
				cout << "Enter the account Number :- ";
				cin >> accountNo;	// to withdraw from particular account
				if(obj.searchByAccNo(accountNo)){ //if account exists then withdraw from the account 
					WITHDRAW w; //declaring withou object
					w.getData(obj.retObject(accountNo));
					w.updateBalance(obj.retObject(accountNo)); //call of the update Balance by the withdraw object
				}
				else {	// if account does not exist 
					cout << "Account Doesn't exist !\n";
				}
				break;
			case 5:
				exit(0); 
				//exit out of the system
		}
	}
	return 0;
}