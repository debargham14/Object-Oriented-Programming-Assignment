#include<stdio.h>

int main() {
    int a = 10;
    int *p = &a;
    int *pp = p;
    
    printf("%d %d %d", a, *p, *pp);
    return 0;
}
