#include<iostream>
using namespace std;

class linkedList;

//defining class node with single data member and a self referencial pointer
class Node {
	int data;
	Node* next;
	friend class linkedList; //class linkedList is made friend so that it can access every private data members of node
public:
	//relevant constructor
	Node(int x) {
		data = x;
		next = NULL;
	}
};

//defining class linkedList
class linkedList {
	Node* head = NULL;
public:
	//method to check whether node formation is successful or not
	bool checkNode(Node* ptr) {
		if (ptr == NULL) {
			cout << "Node cannot be created sorry ! program aborting ";
			return false;
		}
		return true;
	}

	//method to insert node at the begining of the list
	void insertBeg(int ele) {
		Node* ptr = new Node(ele);
		if (!checkNode(ptr))
			exit(0);

		if (head == NULL)
			head = ptr;
		else {
			ptr->next = head;
			head = ptr;
		}
	}

	//mehtod to traverse the list
	void traverse() {
		if (head == NULL)
		{
			cout << "Nothing to show list is empty" << "\n";
			return;
		}
		else {
			Node* ptr = head;
			while (ptr != NULL) {
				cout << ptr->data << "->";
				ptr = ptr->next;
			}
		}
	}

	//method to insert at the end of the list
	void insertEnd(int ele) {
		Node* ptr = new Node(ele);
		if (!checkNode(ptr)) {
			exit(0);
		}
		else {
			if (head == NULL) {
				head = ptr;
			}
			else {
				Node* curr = head;
				while (curr->next != NULL) {
					curr = curr->next;
				}
				curr->next = ptr;
			}
		}
	}

	//methd defined to delete the entire list
	void deleteList() {
		Node* curr = head;
		while (curr != NULL) {
			Node* ptr = curr;
			curr = curr->next;
			delete(ptr);
		}
		delete(curr);
		cout << "List deleted successfully !\n";
	}

};

//driver code to implement the linkedList class
int main() {
	linkedList l1;
	int n;
	cout << "Enter the number of terms :- ";
	cin >> n;

	while (n--) {
		char ch;
		cout << "You want to link a node at the end or the begining (e / b) :- ";
		cin >> ch;
		int ele;
		cout << "Enter the value of the node :- ";
		cin >> ele;
		if (ch == 'e' || ch == 'E')
			l1.insertEnd(ele);
		else
			l1.insertBeg(ele);
	}

	//function call made to traverse the list
	l1.traverse();

	l1.deleteList(); //function call made to delete the entire list
	return 0;
}