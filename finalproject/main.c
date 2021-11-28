#include "main.h"

int main(void) {
	int examnum;
	struct examinfo arr_examinfo[MAXTEST]; //making an array of structures
    struct dailytime arr_dailytime[7];

    for (int z = SUN; z<=SAT; z++) {
        printf("%s\n",DAYS[z]);
    }


	printf("How many exams do you have? ");
	scanf("%d", &examnum);
	if (examnum > MAXTEST){ //making sure number of exams is under six
		printf("Please enter a value under 6: ");
		scanf("%d", &examnum);
	}
	for (int i=0; i< examnum; i++){ //storing information of each exam
		printf("How hard is exam %d on a scale of 1 to 5? ", i+1);
		scanf("%d", &arr_examinfo[i].examdiff);
            if (arr_examinfo[i].examdiff > 5){
                printf("Please enter a valid number: ");
                scanf("%d", &arr_examinfo[i].examdiff);
            }
		printf("How much time do you have to study for exam %d? ", i+1);
		scanf("%d", &arr_examinfo[i].examtime);
            if (arr_examinfo[i].examtime > 30){
                printf("You have a lot of time, please enter a value under 31: ");
                scanf("%d", &arr_examinfo[i].examtime);    
            }
	}

    for (int j=0; j < 7; j++){ //storing information for free time
        printf("How much free time do you have on %s, in hours? ", DAYS[j]);
        scanf("%d", &arr_dailytime[j].freetime);
    }
   
printf("%d \n", sumdiff(examnum, arr_examinfo));
printf("%f \n", importance(1, examnum, arr_examinfo));



return(0);
}

int sumdiff(int numOfExams, struct examinfo arr_examinfo[MAXTEST]){
    int sum = 0;
    for (int i=0; i<numOfExams; i++){
        sum += arr_examinfo[i].examdiff;
    }
    return sum;
}

float importance(int i, int numOfExams, struct examinfo arr_examinfo[MAXTEST]){
    float impval=0.0;
    impval = (float)(arr_examinfo[i].examdiff)/(sumdiff(numOfExams, arr_examinfo));
    return impval;
}






  
 


















        

    

