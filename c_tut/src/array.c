// TODO - DONE: Modify array.c so that the program reads a number of doubles from the standard input and
// computes their average. The number of the doubles to process should be read from the standard input.
// It will be followed by the corresponding number of doubles. Your program should create an array with
// MAX_NUM_OF_CELLS many elements, but then verify that the number entered by the user is no larger than
// the limit. If it is, then a warning message should be printed, and the number should be assumed to be
// the said MAX_NUM_OF_CELLS.

#include <stdio.h>

#define MAX_NUM_OF_CELLS 128

int main(void) {

    double number[MAX_NUM_OF_CELLS];
	int count = 0;
	double avg = 0.0;
	
	while (count <= 0) {
		printf("Provide a desired positive number of doubles?\n");
		scanf("%d", &count);
	}

	if (count > MAX_NUM_OF_CELLS) {
		printf("WARNING. Value above %d. Note that value has been set to %d.\n",
			MAX_NUM_OF_CELLS, MAX_NUM_OF_CELLS);
		count = MAX_NUM_OF_CELLS;
	}
	
	printf("\nProvide the doubles?\n");
	for (int index = 0; index < count; ++index) {
		scanf("%lf", &number[index]);
		//Rolling average.
		avg += (number[index] - avg) / (index+1);
	}

	printf("\nData:");
	for (int index = 0; index < count; ++index)
		printf(" %.1lf", number[index]);
    printf("\nAverage: %.1lf\n", avg);

    return 0;
}
