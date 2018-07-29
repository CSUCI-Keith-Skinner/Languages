//TODO - DONE : The new program should: Read words from the standard input in a loop until a word END is read count all read words store the words in an array of strings print the number of read words in the first line followed by the whole array with one word per line.

#include <../KeepRunning.h> //delete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORDS_COUNT 1024
#define BUFFER_COUNT 1024

int main(void) 
{
	KeepRunning(); //delete

	char ** words = (char **)malloc(WORDS_COUNT * sizeof(char*));
	char input[1024] = { NULL };
	int count = 0;

	printf("Enter words\n");
	while (scanf("%s", input) && strcmp(input, "END") != 0) {
		int length = strlen(input);
		words[count] = malloc(length + 1);
		strcpy(words[count], input);
		++count;
	}

	if (count != 0) {
		printf("\nThe following %d words have been read\n", count);
		for (int i = 0; i < count; ++i)
			printf("%s\n", words[i]);
	}
	else
		printf("\nNo word were read\n");
	return 0;
}