/**
* Name: Keith Skinner
* Lab: Lab 1 C Tutorial
* Date: 09/18/18
**/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "processor.h"

int cache_full(int last) {
	return (message_count != 0)
		&& (message_count > last)
		&& (message_count%CACHE_SIZE == 0);
}

void print_stats(int message_count, int batches, int counts[4]) {
	char * format =
		"Number of message batches: %d\n"
		"Messages processed:\n"
		"Total: %d\n"
		"Type 1 : %d\n"
		"Type 2 : %d\n"
		"Type 3 : %d\n"
		"Type 4 : %d\n";
	printf(format, batches,
		message_count, counts[0], counts[1], counts[2], counts[3]);
}

int main() {
	char input_buffer[BUFSIZ] = {0};
	int count = 0;
	int counts[4] = { 0 };
	int batches = 0;
	do {
		//should we dispatch the message cache?
		if (count == CACHE_SIZE) {
			message_dispatcher(count, counts);
			++batches;
			count = 0;
		}

		//prompt and get user input
		printf(": ");
		fgets(input_buffer, BUFSIZ, stdin);

		//should we end the session?
		char * end = strstr(input_buffer, "END");
		if (end != NULL)
			break;

		//add message to cache
		count = add_message_to_cache(count, input_buffer);
	} while (true);

	if (count != 0) {
		message_dispatcher(count, counts);
		++batches;
	}

	print_stats(message_count, batches, counts);
}
