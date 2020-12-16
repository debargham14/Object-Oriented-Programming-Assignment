#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "oop1.h" // including the required header file


//driver code to utilise the header file
int main() {

	//menu based program to utilise the aove features again and again
	while (1) {
		int ch;
		//menu display code
		printf("Enter the opeartion you would like to perform \n 1. Add a new Student \n 2. Display Records existing students \n 3. Search Record against a Roll Number \n 4. Delete the Record of a student \n 5. Edit a record \n 6. exit \n");
		//menu display ends here
		
		scanf("%d", &ch);
		switch (ch) {
		case 1: addStudent();
			break;
		case 2: displayAll();
			break;
		case 3: search();
			break;
		case 4: delete();
			break;
		case 5: edit();
			break;
		case 6: exit(0);
			break;
		}
	}
	return 0;
}

