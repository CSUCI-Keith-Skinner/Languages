//
#include <../KeepRunning.h> //delete
#include <stdio.h>

void swap_integers(int *, int *);
void swap_strings(char **, char **);

int main() {
	KeepRunning();//delete
    int num1 = 5, num2 = 10;

    swap_integers(&num1, &num2);
    printf("num1 = %d and num2 = %d\n", num1, num2);

	char * str1 = "Take me home";
	char * str2 = "country road";
	swap_strings(&str1, &str2);
	printf("%s %s", str2, str1);

    return 0;
}

void swap_integers(int *n1, int *n2) { /* passed and returned by using values of pointers */
    int temp;

    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void swap_strings(char ** s1, char ** s2) {
	char * temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}