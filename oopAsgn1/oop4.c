//necessary header files
#include<stdio.h>
#include<stdlib.h>

//function to accept dimensions
void acceptDimension(int *n, int *m) {
	printf("Enter the number of rows and columns of the array -- ");
	scanf("%d %d", n, m);
}

int (*arr)[c];
int *arr[r];

//function to accept the two dimensional array of variable length
int** inputMatrix(int n, int m) {
	int** arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		*(arr + i) = (int*)malloc(m * sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		printf("Enter the elements of the %d row -- ", i + 1);
		for (int j = 0; j < m; j++) {
			scanf("%d", (arr[i] + j));
		}
		printf("\n");
	}

	return arr;
}

//function to print the matrix
void printMatrix(int n, int m, int** arr) {
	printf("The elements of the matrix are --");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d " , *(*(arr + i) + j));
		}
		printf("\n");
	}
}

//driver function to call the utility functions
int main() {
	int n, m;
	acceptDimension(&n, &m);

	int **arr = inputMatrix(n, m);
	printMatrix(n, m, arr);
	return 0;
}
