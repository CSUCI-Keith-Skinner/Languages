#include <stdio.h>

void change(int **ptr);

int i;
int j;

int main() {
    i = 5;
    j = 10;
    int *ptr_i = &i;

    printf("Before: %d\n", *ptr_i);
    change(&ptr_i);
    printf("After: %d\n", *ptr_i);

    return 0;
}

void change(int **ptr) { /* pointer to a pointer */

    *ptr = &j;
}

