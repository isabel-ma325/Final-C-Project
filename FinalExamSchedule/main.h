#include <stdio.h>

#define MAXTEST 5
#define MAXTIME 30

enum daysOfWeek { SUN, MON, TUE, WED, THU, FRI, SAT };

char* DAYS[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

/* structure to store info for each exam*/
struct examinfo { // ExamInfo
	int examtime; // examTime -> timeUntilExamInDays
	float examdiff; // examDifficulty
    float signif; 
};

/* structure to store how much free time there is */
struct dailytime {
	int freetime;
};

/*Creating a fxn to determine the sum of all exam difficulties*/
int sumdiff(int numOfExams, struct examinfo arr_examinfo[MAXTEST]);
float importance(int i, int numOfExams, struct examinfo arr_examinfo[MAXTEST]);
float maximportance(int numOfExams, struct examinfo arr_examinfo[MAXTEST]);
float timestudying(int i, int j, struct examinfo arr_examinfo[MAXTEST], struct dailytime arr_dailytime[7]);
int numweekstudying(int i, struct examinfo arr_examinfo[MAXTEST]);
int remainderdaystudying(int i, struct examinfo arr_examinfo[MAXTEST]);
