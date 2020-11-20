#include<stdlib.h>
#include<stdio.h>


int (*arrayOfPointers(int n, int m)) []  {

	int (*p)[5];
	//for (int i = 0; i < m; i++)	*(p + i) = (int*)malloc(n * sizeof(int));

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
	printf("Enter the number of rows and columns of the array --> ");

	scanf("%d %d", &n, &m);

	int (*p)[5] = arrayOfPointers(n, m);

	printf("Entered elements are --> ");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("%d ", *(*(p + i) + j));


	return 0;
}