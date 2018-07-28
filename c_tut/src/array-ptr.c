#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void print_arr1(int arr[]) {
    printf("My array by array:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d\n", arr[i]);
}

void print_arr2(int arr[]) {
    printf("My array by pointer:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d\n", *(arr+i));
}

void print_arr3(int *arr) {
    printf("My array by pointer:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d\n", arr[i]);
}

void print_arr4(int *arr) {
    printf("My array by pointer:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d\n", *(arr+i));
}

int main(int argc, char const *argv[]) {
    int a[SIZE] = {0, 1, 2, 3, 4};
    print_arr1(a);
    print_arr2(a);
    print_arr3(a);
    print_arr4(a);

    int b[] = {0, 1, 2, 3, 4};
    print_arr1(b);
    print_arr2(b);
    print_arr3(b);
    print_arr4(b);

    int *c = (int *) malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++)
        *(c + i) = i; // OR: c[i] = i;
    print_arr1(c);
    print_arr2(c);
    print_arr3(c);
    print_arr4(c);

    return 0;
}