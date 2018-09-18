//TODO - DONE: Modify the code in if-then-else.c, so the value of level is read from the standard input.
#include <stdio.h>

#define DANGERLEVEL 5    /* C Preprocessor -
			- substitution on appearance */

/* like Java ‘final’ */
int main(void) {
    float level = 1;
	printf("Danger Level: ");
	scanf("%f", &level);
    /* if-then-else as in Java */

    if (level <= DANGERLEVEL) /*replaced by 5*/
        printf("Low on gas!\n");
    else
        printf("Good driver !\n");

    return 0;
}
