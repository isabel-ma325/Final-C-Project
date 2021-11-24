#include <stdio.h>

#define MAXTEST 5
#define MAXTIME 30

enum daysOfWeek { SUN, MON, TUE, WED, THU, FRI, SAT };

char* DAYS[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

/* structure to store info for each exam*/
struct examinfo {
	int examtime;
	int examdiff;
    float signif;
};

/* structure to store how much free time there is */
struct dailytime {
	int freetime;
};
