#include "main.h"
/*
Things to Improve:
- including the days the user has to study in schedule
- combine the tests they have to study for in a specific day
- ask the user for what day it is today and use that to say what days they should study
- clarify unit of time
- adding schedule.c and schedule.h
 */
int main(void) {
	int examnum;
    int daytoday;
	struct examinfo arr_examinfo[MAXTEST]; //making an array of structures
    struct dailytime arr_dailytime[7];
//will delete, this lets me write out days of week
    for (int z = SUN; z<=SAT; z++) {
        printf("%s\n",DAYS[z]);
    }

//getting information from user
    printf("What day of the week is today if Sunday = 0 and Saturday = 6?");
    scanf("%d", &daytoday);
    printf("%s\n", DAYS[daytoday]);//deleting later, just to help me for now
	printf("How many exams do you have? ");
	scanf("%d", &examnum);
	if (examnum > MAXTEST){ //making sure number of exams is under six
		printf("Please enter a value under 6: ");
		scanf("%d", &examnum);
	}
	for (int i=0; i< examnum; i++){ //storing information of each exam into structs
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
	if(arr_dailytime[j].freetime > 24){
		printf("You cannot have more than 24 hours in the day free. Please enter a valid number under 24: ");
		scanf("%d", &arr_dailytime[j].freetime);
    }
    }
//testing out if function sumdiff and importance work
printf("%d \n", sumdiff(examnum, arr_examinfo));
printf("%f \n", importance(1, examnum, arr_examinfo));

//storing information for the significance of each exam
for (int i=0; i<examnum; i++){
    if (arr_examinfo[i].examtime > 15 ){ //the significance of an exam decreases if you have a lot of time
        arr_examinfo[i].examdiff = arr_examinfo[i].examdiff/2; //i decrease the difficulty stored to make this change
        arr_examinfo[i].signif = importance(i, examnum, arr_examinfo); //this is where i store the significance into struct member "signif"

    }
    else if (arr_examinfo[i].examtime < 2){//the significance of an exam increases if you have very little time
        arr_examinfo[i].examdiff = 5;
        arr_examinfo[i].signif = importance(i, examnum, arr_examinfo);

    }
    else {
        arr_examinfo[i].signif = importance(i, examnum, arr_examinfo);

    }
}
//loop that tells the user their schedule per each day of the week
/*
for (int j=0; j<7; j++){
    if (arr_dailytime[j].freetime <= 1){ //if the user only has 1 hour on a day, they will only study for 1 test
        int maxsignif;
        maxsignif = maximportance(examnum, arr_examinfo);
        printf("On %s, you will study for 1 hour on exam %d \n", DAYS[j], maxsignif);    
        }
    else {
        for (int i=0; i<examnum; i++){
            float time;
            time=timestudying(i, j, arr_examinfo, arr_dailytime); 
            printf("On %s, you will study for %f hours on exam %d \n", DAYS[j], time, i+1);
        }
    }
}
*/
//loop that tells the user their schedule per each exam
for (int i=0; i<examnum; i++){
    printf("For Exam %d\n", i+1);
    for (int j= daytoday; j<7; j++){
        if (arr_examinfo[i].examtime <= 7){
            if (arr_dailytime[j].freetime = 0){
            }
            else if (arr_dailytime[j].freetime <= 1){
                int maxsignif = maximportance(examnum, arr_examinfo);
                printf("On %s, you will study for 1 hour\n", DAYS[j]);
            }
            else {
                float time = timestudying(i, j, arr_examinfo, arr_dailytime);
                printf("On %s, you will study for %f hours\n", DAYS[j], time);                
            } 
        }
        else {
            float time = timestudying(i, j, arr_examinfo, arr_dailytime);
            int weeksstudying = numweekstudying(i, arr_examinfo);
            int remainderofdays = remainderdaystudying(i, arr_examinfo);
            if (remainderofdays = 0)
                printf("On %s, you will study for %f hours for %d weeks\n", DAYS[j], time, weeksstudying);
            else {
                for (int k=0; k<remainderofdays; k++){
                    printf("On %s, you will study for %f hours for %d weeks\n", DAYS[j], time, weeksstudying+1);    
                }
                printf("On %s, you will study for %f hours for %d weeks\n", DAYS[j], time, weeksstudying);
            }
        }
        
    }
}  
   

return(0);
}
/*When I am writing functions, I use the name of the struct array declared earlier for simplicity reasons, but I can name 
"arr_examinfo" or "arr_dailytime" anything else */

int sumdiff(int numOfExams, struct examinfo arr_examinfo[MAXTEST]){
    int sum = 0;
    for (int i=0; i<numOfExams; i++){
        sum += arr_examinfo[i].examdiff;
    }
    return sum;
}
//function to create a measurement for how significant an exam is
float importance(int i, int numOfExams, struct examinfo arr_examinfo[MAXTEST]){
    float impval=0.0;
    impval = (float)(arr_examinfo[i].examdiff)/(sumdiff(numOfExams, arr_examinfo));
    return impval;
}
//function to decide which exam is the most important
float maximportance(int numOfExams, struct examinfo arr_examinfo[MAXTEST]){
    float max = 0.0;
    for (int i=0; i<numOfExams; i++){
        if (max < arr_examinfo[i].signif )
            max = arr_examinfo[i].signif;
    }
    return max; //find a way to return the letter with the highest signif
}
//function to decide how much time will be spent studying for exams on a given day
float timestudying(int i, int j, struct examinfo arr_examinfo[MAXTEST], struct dailytime arr_dailytime[7]){
    float timeforstudying;
    timeforstudying = arr_examinfo[i].signif * arr_dailytime[j].freetime;
     //add ability to round values, make them easier to read, and in minutes if necessary
    return timeforstudying; 
   
}
//function to determine how many weeks will be spent studying on a test, will only work if they have 7 or more days to study
int numweekstudying(int i, struct examinfo arr_examinfo[MAXTEST]){
    int numweeks;
    int remainder;
    numweeks = arr_examinfo[i].examtime/7;
    return numweeks;
}

int remainderdaystudying(int i, struct examinfo arr_examinfo[MAXTEST]){
    int remainder;
    remainder = arr_examinfo[i].examtime % 7;
    return remainder; 
}

  
 


















        

    

