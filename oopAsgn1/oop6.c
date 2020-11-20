#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person {
	int age;
	char name[100];
};

// compare function for the qsort
int comp(void const* a, void const* b) {
	struct person* A = (struct person *)a;
	struct person* B = (struct person *)b;

	return (A->age > B->age);
}

//function to take the number of persons as input
void numberOfPersons(int *n) {
	printf("Enter the number of persons -- ");
	scanf("%d", n);
}


//accepting the details of the person
void acceptDetails(int n, struct person* p)
{
	printf("Enter the names and age of every person -- \n");
	for (int i = 0; i < n; i++) {
		char name[100];
		printf("Enter the name %d -- ", i + 1);
		scanf("%s", name);
		strcpy(p[i].name, name);
		printf("Enter the age %d -- ", i + 1);
		scanf("%d", &p[i].age);
	}
}

//sorting the list on the basis of age
void sortByAge(int n, struct person* p) {
	qsort(p, n, sizeof(struct person), comp);
}

void printData(struct person* p, int n) {
	printf("The list generated after sorting on the basis of age");
	for (int i = 0; i < n; i++) {
		printf("%d. %s %d\n", i + 1, p[i].name, p[i].age);
	}
}
int main() {
	int n;
	numberOfPersons(&n);

	struct person* p = (struct person*)malloc(n * sizeof(struct person));
	acceptDetails(n, p);

	sortByAge(n, p);
	//print the final list
	printData(p, n);

	return 0;
}
