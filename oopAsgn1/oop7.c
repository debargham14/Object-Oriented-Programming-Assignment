#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct student {
	int roll, score;
	char name[100];
	struct student* next;
};

typedef struct student* ss;

//creting a new student record
ss getNewStudent(int roll, char *name, int score) {
	ss s1 = (ss)malloc(sizeof(struct student));
	s1->roll = roll;
	strcpy(s1->name, name);
	s1->score = score;
	s1->next = NULL;

	return s1;
}

//adding a new student
ss add(ss head) {
	int roll, score; char name[100];

	printf("Enter the roll name and score of the student -- ");
	scanf("%d %s %d", &roll, name, &score);

	ss s = getNewStudent(roll, name, score);
	if (head == NULL) {
		head = s;
	}
	else {
		ss curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = s;
	}

	return head;
}

//deleting a new student
ss delete_record(ss head) {
	int roll;
	printf("Enter the roll of the student to be deleted -- ");
	scanf("%d", &roll);

	if (head == NULL)
	{
		/* code */
		printf("Recorded to be deleted not found -- \n");
		return head;
	}
	else {
		if (head->roll == roll) {
			ss s = head;
			head = head->next;
			free(s);
		}
		else {
			ss curr = head;
			int flag = 0;
			while (curr->next != NULL) {
				if (((curr->next)->roll) == roll)
				{
					flag = 1;
					break;
				}
				curr = curr->next;
			}
			//printf("%d", flag);
			if (flag == 0) {
				if (curr->roll == roll) {
					free(curr);
					printf("Record deleted successfully -- \n");
					return head;
				}
				else {
					printf("Record Not Found -- \n");
					return head;
				}
			}
			else {
				ss s = curr->next;
				curr->next = s->next;
				free(s);
				printf("Record deleted successfully -- \n");
				return head;
			}
		}
	}
}

//printing the list of the students
void printList(ss head) {
	if (head == NULL) {
		return;
	}
	else {
		ss curr = head;
		printf("Name     Roll    Score\n");
		printf("-----------------------------------------\n");
		while (curr != NULL) {
			printf("%s %d %d\n", curr->name, curr->roll, curr->score);
			curr = curr->next;
		}
	}
}


int main() {
	ss head = NULL;

	head = add(head);
	head = add(head);
	head = add(head);
	head = add(head);

	printList(head);

	head = delete_record(head);
	printList(head);
	return 0;
}