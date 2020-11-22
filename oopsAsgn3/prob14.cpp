#include<iostream>
#define MAX_SIZE 100
using namespace std;

class SALES; //forward declaration for the sales class

//defining the ITEM class
class ITEM {
	static int lastId;
	static int icodeList[MAX_SIZE];
	int icode;
	char name[30];
	int rate;
	int qty;

public:
	//defining the method getData
	void getData() {

		cout << "Enter the item code :- ";
		cin >> icode;

		icodeList[lastId] = icode;
		lastId++;
		//checking validity for the icode among all the items entered
		for (int i = 0; i < lastId - 1; i++) {
			if (icodeList[i] == icode)
			{
				cout << "An item with the same item code already exists";
				return; // if present then return
			}
		}
		//else take the rest detials
		cout << "Enter the item name :- ";
		scanf(" %[^\n]s", name);
		cout << "Enter the rate of the item :- ";
		cin >> rate;
		cout << "Enter the quantity of the item :- ";
		cin >> qty;
	}

	//defining the method showData
	void showData() {
		cout << "Item code :- " << icode << "\n";
		cout << "Item Name :- " << name << "\n";
		cout << "Rate of the item :- " << rate << "\n";
		cout << "Quantity of item available :- " << qty << "\n";
		cout << "------------------------------------------------------------------\n";
	}

	//defining the method to modify the rate (mutuator function)
	void changeRate() {
		int newRate = 0;
		cout << "Enter the new Rate :- ";
		cin >> newRate;
		rate = newRate;
	}

	//will be declared as friend function later inside class SALES
	//defining the update stock function to change the quantity
	void updateStock(SALES &s);
};
int ITEM::lastId = 0;
int ITEM::icodeList[MAX_SIZE] = {0};

//defining the class SALES
class SALES {
	int icode;
	int sold;
	int bought;


public:
	friend void ITEM::updateStock(SALES &s);

	//defining the method get Data to recieve the sales data
	void getData() {
		cout << "Enter the icode :- ";
		cin >> icode;

		cout << "Enter the qty of item to be sold :- ";
		cin >> sold;
		cout << "Enter the qty of item to be bought :- ";
		cin >> bought;
	}

	//defining the method showSalesInfo to show the sales record
	void showSalesInfo() {
		cout << "Item code of the item sold :- " << icode << "\n";
		cout << "Amount sold :- " << sold << "\n";
		cout << "Amount bought :- " << bought << "\n";
		cout << "---------------------------------------------------\n";
	}
};

//defining the update stock function after all relevant infos are known
void ITEM::updateStock(SALES &s) {
	if (s.icode == icode) {
		qty -= s.sold;	//sub the sold amount
		qty += s.bought; //adding the bought amount;
	}
	else {
		cout << "Icode doesn't match !";
		return;
	}
}

//driver function to check the above classes
int main() {
	ITEM it; // instance of item created
	it.getData();
	it.showData();

	SALES s; // instance of sales created
	s.getData();
	s.showSalesInfo();

	it.updateStock(s); //updating the stock
	it.showData();//display again

	it.changeRate(); //change the rate
	it.showData(); //display again
	return 0;
}