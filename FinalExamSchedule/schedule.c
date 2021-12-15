#include "schedule.h"

int schedule(void) { 
	int examnum; //saira
    int daytoday; //saira
	struct examinfo arr_examinfo[MAXTEST]; //making an array of structures, saira
    struct dailytime arr_dailytime[7]; //saira
    char* DAYS[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
//getting information from user
    printf("What day of the week is today if Sunday = 0 and Saturday = 6? "); //isabel
    scanf("%d", &daytoday); 
	printf("How many exams do you have coming up? "); //saira
	scanf("%d", &examnum); 
	if (examnum > MAXTEST){ //making sure number of exams is under six
		printf("Please enter a value under 6: "); 
		scanf("%d", &examnum); 
	}
	for (int i=0; i< examnum; i++){ //storing information of each exam into structs, saira
		printf("How hard is exam %d on a scale of 1 to 5? ", i+1); 
		scanf("%f", &arr_examinfo[i].examdiff);
            if (arr_examinfo[i].examdiff > 5){
                printf("Please enter a valid number: ");
                scanf("%f", &arr_examinfo[i].examdiff);
            }
		printf("How much time do you have to study for exam %d, in days? ", i+1);
		scanf("%d", &arr_examinfo[i].examtime);
            if (arr_examinfo[i].examtime > 30){
                printf("You have a lot of time, please enter a value under 31: ");
                scanf("%d", &arr_examinfo[i].examtime);    
            }
	}
//saira
    for (int j=0; j < 7; j++){ //storing information for free time
        printf("How much free time do you have on %s, in hours? ", DAYS[j]);
        scanf("%d", &arr_dailytime[j].freetime);
    }
//saira
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


//loop that tells the user their schedule per each exam
for (int i=0; i<examnum; i++){
    printf("For Exam %d\n", i+1);
    if (arr_examinfo[i].examtime <= 7){
        for (int j=daytoday; j < arr_examinfo[i].examtime + daytoday; j++){ //isabel
            if (arr_dailytime[j].freetime == 0){//saira
            }
            if (arr_dailytime[j].freetime > 0) {//saira
                float time = timestudying(i, j, arr_examinfo, arr_dailytime);
                if (j<7){
                    printf("On %s, you will study for %.2f hours\n", DAYS[j], time);
                }
                if (j>7){
                    printf("On %s, you will study for %.2f hours\n", DAYS[j-7], time);
                }
               
            } 
        }
    }
    else {
        for (int j=daytoday; j<7; j++){//isabel
            float time = timestudying(i, j, arr_examinfo, arr_dailytime);
            int weeksstudying = numweekstudying(i, arr_examinfo);
            int remainderofdays = remainderdaystudying(i, arr_examinfo);
            if (remainderofdays = 0)
                printf("On %s, you will study for %.2f hours for %d weeks\n", DAYS[j], time, weeksstudying);
            else {
                for (int k=0; k<remainderofdays; k++){
                    printf("On %s, you will study for %.2f hours for %d weeks\n", DAYS[j], time, weeksstudying+1);    
                }
                printf("On %s, you will study for %.2f hours for %d weeks\n", DAYS[j], time, weeksstudying);
            }
        }
        for (int j=0; j<daytoday; j++){//isabel
            float time = timestudying(i, j, arr_examinfo, arr_dailytime);
            int weeksstudying = numweekstudying(i, arr_examinfo);
            int remainderofdays = remainderdaystudying(i, arr_examinfo);
            if (remainderofdays = 0)
                printf("On %s, you will study for %.2f hours for %d weeks\n", DAYS[j], time, weeksstudying);
            else {
                for (int k=0; k<remainderofdays; k++){
                    printf("On %s, you will study for %.2f hours for %d weeks\n", DAYS[j], time, weeksstudying+1);
                }
                printf("On %s, you will study for %.2f hours for %d weeks\n", DAYS[j], time, weeksstudying);
             }
        }
        }
    }
  
return(0);
}
/*When I am writing functions, I use the name of the struct array declared earlier for simplicity reasons, but I can name 
"arr_examinfo" or "arr_dailytime" anything else */

//saira
int sumdiff(int numOfExams, struct examinfo arr_examinfo[MAXTEST]){ 
    int sum = 0;
    for (int i=0; i<numOfExams; i++){
        sum += arr_examinfo[i].examdiff;
    }
    return sum;
}

//saira
//function to create a measurement for how significant an exam is
float importance(int i, int numOfExams, struct examinfo arr_examinfo[MAXTEST]){
    float impval=0.0;
    impval = (float)(arr_examinfo[i].examdiff)/(sumdiff(numOfExams, arr_examinfo));
    return impval;
}

//saira
//function to decide which exam is the most important
float maximportance(int numOfExams, struct examinfo arr_examinfo[MAXTEST]){
    float max = 0.0;
    for (int i=0; i<numOfExams; i++){
        if (max < arr_examinfo[i].signif )
            max = arr_examinfo[i].signif;
    }
    return max; //find a way to return the letter with the highest signif
}

//saira
//function to decide how much time will be spent studying for exams on a given day
float timestudying(int i, int j, struct examinfo arr_examinfo[MAXTEST], struct dailytime arr_dailytime[7]){
    float timeforstudying;
    timeforstudying = arr_examinfo[i].signif * arr_dailytime[j].freetime;
     //add ability to round values, make them easier to read, and in minutes if necessary
    return timeforstudying; 
   
}

//saira
//function to determine how many weeks will be spent studying on a test, will only work if they have 7 or more days to study
int numweekstudying(int i, struct examinfo arr_examinfo[MAXTEST]){
    int numweeks;
    int remainder;
    numweeks = arr_examinfo[i].examtime/7;
    return numweeks;
}
//saira
int remainderdaystudying(int i, struct examinfo arr_examinfo[MAXTEST]){
    int remainder;
    remainder = arr_examinfo[i].examtime % 7;
    return remainder; 
}

  
 


















        

    

