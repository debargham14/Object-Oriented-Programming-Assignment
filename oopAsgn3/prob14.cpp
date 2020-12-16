#include <iostream>

using namespace std;

class ItemList; //fwd declaration of the item list class
//designing the class item
class Item {
	//required data member
	int itemcode;
	char name[30];
	int rate;
	int quantity;
	Item* next;
public:
	Item()//constructor to initialise the variable
	{
		itemcode = rate = quantity = -1;
		next = NULL;
	}
	friend class ItemList; //declaring the list of itesm class as friend so that it can acess the private data members
	void getInput();//method to take a function as input
};
//defining the method to take an item as input
void Item::getInput()
{
	cout << "Enter item code: \n";
	cin >> itemcode;
	cout << "Enter item name: \n";
	scanf(" %[^\n]s", name);
	cout << "Enter rate: \n";
	cin >> rate;
	cout << "Enter quantity available: \n";
	cin >> quantity;
	next = NULL;
}
//designing the class item list
class ItemList {
	Item* head;//head to linked list to support a list type structure
public:
	ItemList() //required constructor
	{
		head = NULL;
	}
	Item* getHead(); //method o get the first item
	bool search(int code);	//method to search an item based on item code
	void screen(); //dsiplay the opereation that can be performed
	void addItem();	//method to add an item
	void updateItem();	//method to update an item
	void deleteItem(); //method to delete an item
	void displayItemDetails(); //method to display item details
};

//method to get the haed
Item* ItemList::getHead()
{
	return head;
}
//methof to search an item
bool ItemList::search(int code)
{
	Item *temp = head;
	while (temp != NULL) {	//iterate till it becomes null
		if (temp->itemcode == code) {	//if exists
			cout << "Found an item with item code " << code << ".\n";
			return true;
		}
		temp = temp->next;
	}	//item not found
	cout << "Item with item code " << code << " couldn\'t be found.\n";
	return false;
}
//displaying the list of operations
void ItemList::screen()
{
	cout << "\n";
	if (head == NULL) {
		cout << "Currently the item list is empty.\n";
		cout << "Press 1 to add an item.\n";
		cout << "Press 2 to exit.\n";
	} else {
		cout << "Press 1 to add an item.\n";
		cout << "Press 2 to delete an item.\n";
		cout << "Press 3 to display details of an item.\n";
		cout << "Press 4 to update an item (update rate / restock / issue).\n";
		cout << "Press 5 to exit.\n";
	}
}
//method to add an item into the list
void ItemList::addItem()
{
	Item *newItem = new Item;
	newItem->getInput();
	if (head == NULL) {
		head = newItem;
		return;
	}
	Item *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newItem;
}
//method to update an item in the list
void ItemList::updateItem()
{	//display the types of updates that can be performed
	cout << "What update you want to do?\n";
	cout << "Press 1 to update rate of an item.\n";
	cout << "Press 2 to restock an item.\n";
	cout << "Press 3 to issue some item.\n";
	int choice;	//enter the choice of update
	cin >> choice;
	int code;
	int updrate, delqty;
	switch (choice) {
	case 1: //update the rate of an item with a new rate
		cout << "Enter item code of the item whose rate you want to update: \n";
		cin >> code;
		if (search(code)) {
			cout << "Enter new rate: \n";
			cin >> updrate;
			Item* temp = head;
			while (temp != NULL) {
				if (temp->itemcode == code) {
					temp->rate = updrate; //change the rate with the new rate
					break;
				}
				temp = temp->next;//moving to the next node in the list
			}
		} else {//invalid item code
			cout << "Enter a valid item code.\n";
		}
		break;
	case 2: //restocking the previous items with a quantity
		cout << "Enter item code of the item which you want to restock: \n";
		cin >> code;
		if (search(code)) {
			cout << "Enter quantity you\'ll restock: \n";
			cin >> delqty;
			Item* temp = head;
			while (temp != NULL) {//it will append the new quantity to the previous quantity
				if (temp->itemcode == code) {
					temp->quantity += delqty;
					cout << "Restock done successfully.\n";
					break;
				}
				temp = temp->next;
			}
		} else {	//invalid item code
			cout << "Enter a valid item code.\n";
		}
		break;
	case 3: //to issue an item
		cout << "Enter item code of the item which you want to issue: \n";
		cin >> code;
		if (search(code)) { //search the availability
			cout << "Enter quantity you want to issue: \n";
			cin >> delqty;
			Item* temp = head;
			while (temp != NULL) {
				if (temp->itemcode == code) {
					if (temp->quantity >= delqty) { //withdraw qty from the prev qty
						temp->quantity -= delqty;
						cout << delqty << " items issued.\n";
					} else {
						cout << "Enough items are not available.\n";
					}
					break;
				}
				temp = temp->next;
			}
		} else {//item to be issued not found
			cout << "Enter a valid item code.\n";
		}
		break;
	default: // invalid choice entered
		cout << "Invalid Choice.\n";
		break;
	}

}
//method to delete and item present in the list
void ItemList::deleteItem()
{
	Item *temp = head, *prev;
	int itemcode; //taking the item code to be deleted
	cout << "\n Enter itemcode to be deleted: ";
	cin >> itemcode;

	if (temp->itemcode == itemcode) {//if the top node is the the item to be deleted
		head = temp->next;
		printf("Successfully deleted.\n");
		return;
	}
	while (temp != NULL && temp->itemcode != itemcode) {//else if the top node is not the node to be deleted
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {//if invalid item code is entered
		printf("itemcode couldn\'t be found.\n");
		return;
	}
	prev->next = temp->next;
	delete temp;
	printf("Successfully deleted.\n");
}
//display the item present in the list according to the code entered by the individual
void ItemList::displayItemDetails()
{
	cout << "Enter item code whose details you want to see: \n";
	int code;
	cin >> code;
	if (search(code)) {//item to be displayed exists
		Item* temp = head;
		while (temp != NULL) {
			if (temp->itemcode == code) {//di8splay the details
				cout << "\nItem Code: " << temp->itemcode << "\n";
				cout << "Item Name: " << temp->name << "\n";
				cout << "Rate: " << temp->rate << "\n";
				cout << "Available Quantity: " << temp->quantity << "\n";
				break;
			}
			temp = temp->next;
		}
	} else {	//item to be displayed does not exists
		cout << "Enter a valid item code.\n";
	}
}
//driver code to implement the above classes
signed main() {
	//declaring the item list object to create a list of items
	ItemList ll;
	do {//menu driven driver code to implement all the functionalities
		ll.screen();
		int choice;
		cin >> choice;
		if (ll.getHead() == NULL) {
			switch (choice) {
			case 1:	ll.addItem();
				break;
			case 2: exit(0);
			}
		} else {
			switch (choice) {
			case 1:	ll.addItem();	//add an item into the list
				break;
			case 2:	ll.deleteItem();	//delete an item from the list
				break;
			case 3:	ll.displayItemDetails();	//display the item details
				break;
			case 4:	ll.updateItem();	//update an item present in the list (update can be of three types :- 1. update/restock/issue)
				break;
			case 5:	exit(0);	//exit out of the programme
			}
		}
	} while (1);

	return 0;
}