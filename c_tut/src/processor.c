#include "processor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int message_count = 0;

void message_dispatcher(int count, int counts[4]) {
	putchar('\n');
	for (int i = 0; i < count; ++i) {
		++message_count;
		MESSAGE * msg = &message_cache[i];
		++counts[msg->type - 1];
		process_message(msg);
	}
	putchar('\n');
}

void process_message(MESSAGE * message) {
	switch (message->type) {
	case TYPE1:
		printf("TYPE 1: %s\n",
			message->data.type1);
		free(message->data.type1);
		break;
	case TYPE2:
		printf("TYPE 2: %d,%d,%d,%d,%d\n",
			message->data.type2[0],
			message->data.type2[1],
			message->data.type2[2],
			message->data.type2[3],
			message->data.type2[4]);
		break;
	case TYPE3:
		printf("TYPE 3: %f/%f/%f/%f\n",
			message->data.type3[0],
			message->data.type3[1],
			message->data.type3[2],
			message->data.type3[3]);
		break;
	case TYPE4:
		printf("TYPE 4: %5s %5s %5s %5s %5s\n",
			message->data.type4[0],
			message->data.type4[1],
			message->data.type4[2],
			message->data.type4[3],
			message->data.type4[4]);
		break;
	default:
		; // do nothing.
	}
}

int add_message_to_cache(int count, char * buf) {

	MESSAGE * msg = &(message_cache[count]);
	char * data = buf;
	msg->type = strtol(buf, &data, 10);
	int length = 0;
	++data; //skip first space
	switch (msg->type) {
	case TYPE1:
		++count;
		length = strlen(data);
		data[length - 1] = '\0'; //get rid of stupid '\n' that fgets leaves instead of ignoring. >:(
		// gets removed in C11. sad days.
		(msg->data).type1 = (char *)calloc(1, length);
		strcpy(msg->data.type1, data);
		break;
	case TYPE2:
		++count;
		sscanf(data, "%d %d %d %d %d",
			&(msg->data.type2[0]),
			&(msg->data.type2[1]),
			&(msg->data.type2[2]),
			&(msg->data.type2[3]),
			&(msg->data.type2[4]));
		break;
	case TYPE3:
		++count;
		sscanf(data, "%f %f %f %f",
			&(msg->data.type3[0]),
			&(msg->data.type3[1]),
			&(msg->data.type3[2]),
			&(msg->data.type3[3]));
		break;
	case TYPE4:
		++count;
		sscanf(data, "%5c %5c %5c %5c %5c",
			msg->data.type4[0],
			msg->data.type4[1],
			msg->data.type4[2],
			msg->data.type4[3],
			msg->data.type4[4]);
		break;
	default:
		printf("Unsupported type %d\n",
			msg->type);
	}
	return count;
}