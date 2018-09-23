/* 
for dailyLog.c 
*/

#define MAX_ENTRY_SZ 255

/***************************************************/	

int nullCheck(FILE * out) {
	if (out == NULL) {
	printf("No file to write to.\n");
	return 1;
	}
	else {
		return 0;
	}
}

/***************************************************/

// timeStamp function from wikipedia...
// https://en.wikipedia.org/wiki/C_date_and_time_functions

void timeStamp(FILE * out, char * logEntry) {
    time_t current_time;
    char* c_time_string;

    /* Obtain current time. */
    current_time = time(NULL);

    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Print to stdout. ctime() has already added a terminating newline character. */
    (void) fprintf(out, "%s", c_time_string);
    
    return;
}

/***************************************************/

void logEntry(FILE * out) {
	printf("Log Entry: ");
	char logEntry[MAX_ENTRY_SZ];
	fgets(logEntry, MAX_ENTRY_SZ, stdin);

	timeStamp(out, logEntry);

	fprintf(out, "%s", logEntry);
	fprintf(out, "\n");

	return;
}

/***************************************************/


// int checkArgCnt(n) {
// 	if (n != 1) {
// 		printf("Usage ./dailyLog\n");
// 		return 1;
// 	}
// 	else {
// 		return 0;
// 	}
// }
