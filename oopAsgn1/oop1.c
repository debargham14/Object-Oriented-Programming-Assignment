#include<stdio.h>

int main() {
	int a = 10; //integer type variable
	int *p = &a;	//pointer to integer type variable
	int **pp = &p;	// pointer to pointer to integer type variable

	printf("%d %d %d", a, *p, **pp);
	return 0;
}
