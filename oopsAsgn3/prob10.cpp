#include<iostream>
#include<cstdlib>
#define MAX_SIZE 100
using namespace std;

//class stack implemented to perform push and pop operation and to
//check overflow and underflow condition
class stack {
	int top = -1;
	int arr[MAX_SIZE];

public:
	stack() {
		top = -1;
	}
	void push();
	void pop();
	void viewStack();
};

//function definition to implement the push function
void stack::push() {
	int ele;
	cout << "Enter the element to be pushed :- ";
	cin >> ele;

	//stack overflow condition
	if (top == MAX_SIZE - 1) {
		cout << "Stack Overflow ! Can't perform push operation";
		return;
	}
	else {
		//top incremented and element inserted
		arr[++top] = ele;
		cout << "Element pushed successfully";
	}
}

//function definition to implement the pop function
void stack::pop() {
	//stack underlow condition
	if (top == -1) {
		cout << "Stack underflow ! element cannot be popped";
		return;
	}
	else {
		//top element popped out of the stack (LIFO)
		int x = arr[top];
		top--;
		cout << "The top element " << x << " popped successfully";
	}
}

//function to traverse the stack
void stack::viewStack() {
	//stack underflow cond
	if (top == -1) {
		cout << "Stack underflow! no elements to display";
		return;
	}
	else {
		int noe = top;
		for (int i = top; i >= 0; i--)	cout << arr[i] << " ";
		cout << "\n";
	}
}

int main() {
	stack s;

	//menu driven code to implement operations of stack
	while (1) {
		int ch;
		cout << "1.Push 2.Pop 3.viewStack 4.exit :- ";
		cin >> ch;

		switch (ch) {
		case 1:
			s.push();
			break;
		case 2:
			s.pop();
			break;
		case 3:
			s.viewStack();
			break;
		case 4:
			exit(0);

		}
	}


	return 0;
}