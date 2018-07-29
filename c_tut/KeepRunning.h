
#ifndef KEEPRUNNING_H
#define KEEPRUNNING_H

#include <stdio.h>
#include <stdlib.h>

void keep_console_open() {
	//msvc is stupid for this reason only.
	do { getchar(); } while (getchar() != '\n');
}

void KeepRunning(void) {
	printf(
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"~~~~~~  DELETE KeepRunning CODE  ~~~~~~\n"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	atexit(keep_console_open);
}

#endif //KEEPRUNNING_H