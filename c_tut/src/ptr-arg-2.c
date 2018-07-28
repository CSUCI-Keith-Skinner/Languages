#include <stdio.h>

void swap_integers(int *, int *);

int main() {
    int num1 = 5, num2 = 10;

    swap_integers(&num1, &num2);
    printf("num1 = %d and num2 = %d\n", num1, num2);

    return 0;
}

void swap_integers(int *n1, int *n2) { /* passed and returned by using values of pointers */
    int temp;

    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
