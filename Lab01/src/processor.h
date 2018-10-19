/**
* Name: Keith Skinner
* Lab: Lab 1 C Tutorial
* Date: 09/18/18
**/

#ifndef PROCESSOR_H
#define PROCESSOR_H

typedef enum {
	TYPE1 = 1,
	TYPE2,
	TYPE3,
	TYPE4
} TYPE;

typedef struct {
	TYPE type;
	union {
		char * type1;
		int    type2[5];
		float  type3[4];
		char   type4[5][6];
	} data;
} MESSAGE;

#define CACHE_SIZE 2
MESSAGE message_cache[CACHE_SIZE];
extern int message_count;

void message_dispatcher(int count, int counts[4]);
void process_message(MESSAGE * message);
int add_message_to_cache(int count, char * buf);


#endif //PROCESSOR_H