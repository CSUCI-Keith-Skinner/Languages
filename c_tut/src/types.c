// TODO - DONE : Modify the code in types.c, so that the program asks also for the number of faculty, and then prints the student-to-faculty ratio for CSUCI. You will need to modify the types of the variables and use proper format string in printf(), so the precision is limited to one position after the dot.
#include <stdio.h>

int main(void) {
	int nstudents = 0; /* Initialization, required */
    printf("How many students does CSUCI have?: ");
    scanf("%d", &nstudents);  /* Read input */
    printf("CSUCI has %d students.\n", nstudents);
	
	
	int nfaculty = 0;
	printf("How many faculty does CSUCI have?: ");
	scanf("%d", &nfaculty);
	printf("CSUCI has a student-to-faculty ratio of %.1f", (float)(nstudents) / nfaculty);
    return 0;
}
