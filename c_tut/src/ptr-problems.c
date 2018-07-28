#include <stdio.h>
#include <stdlib.h>

void do_something_incorrect(int *ptr);
void do_something_correctly(int **ptr);

int main() {
    int *p = NULL;

    do_something_incorrect(p); // try to comment this out if you get a runtime error
    printf("Result from dosomething: %d\n", *p);     /* will this work ? */

    do_something_correctly(&p);
    printf("Result from dosomething: %d\n", *p);     /* will this work ? */

    return 0;
}

void do_something_incorrect(int *ptr) { // will compile, but it's not correct and may crash
    int temp = 32 + 12;

    ptr = &(temp); // returning the pointer to a local variable that is not valid after the return
}

void do_something_correctly(int **ptr) { // will be fine
    *ptr = (int *) malloc(sizeof(int)); // the pointer is valid after return

    **ptr = 32 + 12;
}


