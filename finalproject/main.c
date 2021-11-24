#include "main.h"

int main(void) {
	int examnum;
	struct examinfo arr_examinfo[MAXTEST]; //making an array of structures
    struct dailytime arr_dailytime[7];

    for (int z = SUN; z<=SAT; z++) {
        printf("%s\n",DAYS[z]);
    }

/*
	printf("How many exams do you have? ");
	scanf("%d", &examnum);
	if (examnum > MAXTEST){ //making sure number of exams is under six
		printf("Please enter a value under 6: ");
		scanf("%d", &examnum);
	}
	for (int i=1; i<= examnum; i++){ //storing information of each exam
		printf("How hard is exam %d on a scale of 1 to 5? ", i);
		scanf("%d", &arr_examinfo[i].examdiff);
		printf("How much time do you have to study for exam %d? ", i);
		scanf("%d", &arr_examinfo[i].examtime);
	}
    for (int j=1; j <= 7; j++){ //storing information for free time
        printf("How much free time do you have on day %d of the week? ", j);
        scanf("%d", &arr_dailytime[j].freetime);
    }
*/

}

