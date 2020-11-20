#include<stdio.h>
#include<stdlib.h>

//function to implement two-d array as array of pointers
void arrayOfPointers(int n, int m) {
	int *p[5]; //array of pointers
	for (int i = 0; i < n; i++)	*(p + i) = (int*)malloc(m * sizeof(int));

	printf("Enter the elements of the array --> ");

	for (int i = 0; i < n; i++) {
		printf("Enter the elements of the %d row --> ", i + 1);
		for (int j = 0; j < m; j++) {
			scanf("%d", &p[i][j]);
		}
	}

	//printing elements in the form of array of integers
	printf("Entered elements are (for array of pointers) --> ");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}

//function to implment two-d array as pointer to array
int (*pointerToArray(int n, int m)) []  {

	int (*p)[5];
	

	int arr[5][5];
	for (int i = 0; i < n; i++) {
		printf("Enter the elements of the %d row -- ", i + 1);
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	p = arr;
	return p;
}

int main() {

	int n, m;
	printf("Enter the number of rows and columns of the matrix --> ");
	scanf("%d %d", &n, &m);

	//call to array of pointers
	//arrayOfPointers(n, m);

	//call to the pointerToArray function
	int (*p)[5] = pointerToArray(n, m);

	printf("Entered elements are --> ");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", *(*(p + i) + j));

		return 0;
	}
