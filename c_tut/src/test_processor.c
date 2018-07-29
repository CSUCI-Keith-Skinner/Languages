
#include <../KeepRunning.h>
#include <stdio.h>
#include <string.h>
#include "processor.h"

int cache_full(int last) {
	return (message_count != 0)
		&& (message_count > last)
		&& (message_count%CACHE_SIZE == 0);
}

void print_stats(int counts[4]) {
	char * format =
		"Number of message batches: %d\n"
		"Messages processed :\n"
		"Total: %d\n"
		"Type 1 : %d\n"
		"Type 2 : %d\n"
		"Type 3 : %d\n"
		"Type 4 : %d\n";
	int batches = (message_count / CACHE_SIZE) +
		(message_count%CACHE_SIZE != 0) ? 1 : 0;
	printf(format, batches,
		message_count, counts[0], counts[1], counts[2], counts[3]);
}

int main() {
	char * input_buffer[BUFSIZ] = { NULL };
	int last_process = 0;
	int counts[4] = { 0 };
	while (strcmp("END", input_buffer) != 0) {
		if (cache_full(last_process)) {
			message_dispatcher(message_cache);
			last_process = message_count;
		}
		printf(": ");
		gets(input_buffer, BUFSIZ, stdin);
		add_message_to_cache(input_buffer);
	}
	if (message_count > last_process)
		message_dispatcher(message_cache);

	print_stats(counts);
}