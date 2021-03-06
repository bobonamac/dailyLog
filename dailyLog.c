/* 
appends prompted text to dailyLog.txt 
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bob.h"

int main(void)
{
	FILE * out = fopen("dailyLog.txt", "a");
	
	if (nullCheck(out) == 1) {
		return 1;
	}

	logEntry(out);

	fclose(out);

	return 0;
}
