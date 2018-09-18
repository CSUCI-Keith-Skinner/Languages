<<<<<<< HEAD
//TODO: Add a function swap_strings() that will swap two strings. 
//		The new code should include:
//		 - a declaration of the new function,
//		 - declarations of two strings initialized to some arbitrary values, and
//		 - the definition of the function that swaps the strings.

=======
//
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79
#include <stdio.h>

void swap_integers(int *, int *);
void swap_strings(char **, char **);

int main() {
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
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void swap_strings(char ** s1, char ** s2) {
	char * temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}