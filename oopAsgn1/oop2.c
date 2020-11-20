#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of elements in the array -- ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array -- ");
    
    for(int i = 0; i < n; i++) {
	scanf("%d", (arr + i));
    }
    printf("Your elements are -- ");
    for(int i = 0; i < n; i++) printf("%d ", *(arr + i));

    return 0;
}
