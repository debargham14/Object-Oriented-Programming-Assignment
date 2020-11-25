#include<stdio.h>
#include<stdlib.h>



//function to take the number of persons as input
void numberOfPersons(int *n) {
	printf("Enter the number of persons -- ");
	scanf("%d", n);
}

//function to take the list of persons name as input
void names_and_ageOfPersons(int n, char** names, int* arr) {

	for (int i = 0; i < n; i++) {
		printf("Enter the name of %d person --> ", i + 1);
		scanf(" %[^\n]s", names[i]);
		printf("Enter the age of the %d person --> ", i + 1);
		scanf("%d", &arr[i]);
	}
}


//sort function to sort by age (simple bubble sort)
void sortByAge(int n, char** names, int* age) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (age[j + 1] < age[j]) {
				//swap the age
				{
					int temp = age[j];
					age[j] = age[j + 1];
					age[j + 1] = temp;
				}
				//swap the names
				{
					char* name = names[j];
					names[j] = names[j + 1];
					names[j + 1] = name;
				}
			}
		}
	}
}



int main() {
	int n;
	numberOfPersons(&n);



	char **names = (char**)malloc(n * sizeof(char*));
	int *age     = (int *)malloc(n * sizeof(int));

	printf("Enter the names and age of the persons -- \n");
	for (int i = 0; i < n; i++) {
		*(names + i) = (char*)malloc(100 * sizeof(char));
	}

	names_and_ageOfPersons(n, names, age);

	//sorting the values in terms of ascending order of age
	sortByAge(n, names, age);

	printf("Sorting by age generates the following arrangement ---------------------------- \n");
	for (int i = 0; i < n; i++) {
		printf("%d. %s %d\n", i + 1, names[i], age[i]);
	}


	return 0;
}
