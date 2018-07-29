#include "processor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int message_count = 0;

void message_dispatcher(int counts[4]) {
	putchar('\n');
	for (int i = 0; i < CACHE_SIZE; ++i)
		process_message(&(message_cache[i]), counts);
	putchar('\n');
}

void process_message(MESSAGE * message, int counts[4]) {
	counts[message->type - 1]++;
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
		printf("Unsupported type %d\n",
			message->type);
	}
}

void add_message_to_cache(char * buf) {
	MESSAGE * msg = &(message_cache[message_count]);
	char * data = buf;
	msg->type = strtol(buf, &data, 10);
	if (TYPE1 <= msg->type && msg->type <= TYPE4) { //valid type.
		switch (msg->type) {
		case TYPE1:
			msg->data.type1 = (char *)malloc(strlen(data) + 1);
			break;
		case TYPE2:
			sscanf(data, "%d %d %d %d %d",
				&(msg->data.type2[0]),
				&(msg->data.type2[1]),
				&(msg->data.type2[2]),
				&(msg->data.type2[3]),
				&(msg->data.type2[4]));
			break;
		case TYPE3:
			sscanf(data, "%f %f %f %f",
				&(msg->data.type3[0]),
				&(msg->data.type3[1]),
				&(msg->data.type3[2]),
				&(msg->data.type3[3]));
			break;
		case TYPE4:
			sscanf(data, "%5c %5c %5c %5c %5c",
				msg->data.type4[0],
				msg->data.type4[1],
				msg->data.type4[2],
				msg->data.type4[3],
				msg->data.type4[4]);
			break;
		default:
			return;
		}
		++message_count;
	}
}