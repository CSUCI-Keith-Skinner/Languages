// Extend the code in file.c, so that the program reads the data
// from the data.txt file and writes it to a new file.
// The name of the new file should be requested from the user.
#include <stdio.h>

#define FILE_NAME "data.txt"
#define BUFFER_SIZE 1024
#define INPUT_FILE_ERROR 1
#define OUTPUT_FILE_ERROR 2

int main(void) {

	/* file handles */
	FILE * input_file = fopen(FILE_NAME, "r");
	if (input_file == NULL)
		return INPUT_FILE_ERROR;

	char buffer[BUFFER_SIZE];
	printf("Enter a file name: ");
	gets_s(buffer, BUFFER_SIZE);
	FILE * output_file = fopen(buffer, "w");
	if (output_file == NULL) {
		fclose(input_file);
		return OUTPUT_FILE_ERROR;
	}
	while (fgets(buffer, BUFFER_SIZE, input_file))
		fputs(buffer, output_file);

	fclose(input_file);
	fclose(output_file);
	printf("Done.\n");
    return 0;
}
