#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define _VERSION "2.0" 

#define MAX_STU_NUM 30
#define MAX_STR_LEN 30

void showinfo() {
	printf ("Student Score Management System, Version "
			_VERSION
			"\nCopyleft (c) 2019 XUWENHAO_190110728\n"
			"This software is a free software distributed under GPLv3 with absolutely NO WARRANTY!\n\n");
}

void showMenu() {
	printf (
			"All Possible Commands:\n"
			"1. Input record\n"
			"2. Calculate total and average score of course\n"
			"3. Sort in descending order by score\n"
			"4. Sort in ascending order by score\n"
			"5. Sort in ascending order by number\n"
			"6. Sort in dictionary order by name\n"
			"7. Search by number\n"
			"8. Search by name\n"
			"9. Statistic analysis\n"
			"10. List record\n"
            "0. Exit\n");
	return;
}

void inputNumber(int *p, const char* prompt) {
	printf(prompt);
	while(!scanf("%d", p)) {
		printf(prompt);
		while(getchar()!='\n');
	}
	return;
}

void input_c_string(char *sp, const char* prompt, int len) {
	printf(prompt);
	while(getchar()!='\n'); 
	if (len>MAX_STR_LEN) len=MAX_STR_LEN; /* prevent overflow */
	fgets(sp, len, stdin);
	return;
}

void showNumberScoreName(int studentQuantity, int Num[], int Score[], char Name[][MAX_STR_LEN]) {
	int i=0;
	for (i=0 ; i<studentQuantity ; i++) printf ("Student %s\tNum : %d -> Score : %d\n", Name[i], Num[i], Score[i]);
	return;
}

void inputNumScoreName(int *studentQuantity, int Num[], int Score[], char Name[][MAX_STR_LEN]) {
	inputNumber(studentQuantity, "Input student quantity > ");
    
    if (*studentQuantity>30) {
        printf ("30.\n");
        *studentQuantity = 30;
    }
	
	int i=0;
	for (i=0 ; i<(*studentQuantity) ; i++) {
		inputNumber(&Num[i], "Number > ");
		input_c_string(Name[i], "Name > ", MAX_STR_LEN);
		inputNumber(&Score[i], "Score > ");
	}

	return;
}

void totalAverage(int studentQuantity, int Score[]) {
	int total=0;
	double average=0;
	
    int i=0;
	for (i=0 ; i<studentQuantity ; i++) total += Score[i];
	average = (double)total / studentQuantity;

	printf ("Total Score : %d\nAverage Score : %.2f\n", total, average);
	return;
}

void sortDescend(int studentQuantity, int sortedNum[], int sortedScore[], char sortedName[][MAX_STR_LEN]) {
	bool moved = false;
	do {
		moved = false;
		int i=0;
		for (i=0 ; i<studentQuantity-1 ; i++) {
			if (sortedScore[i]<sortedScore[i+1]) {
				int swap = 0;
				swap = sortedScore[i];
				sortedScore[i] = sortedScore[i+1];
				sortedScore[i+1] = swap;

				swap = sortedNum[i];
				sortedNum[i] = sortedNum[i+1];
				sortedNum[i+1] = swap;
				
				char swap_name[MAX_STR_LEN];
				strncpy(swap_name, sortedName[i], MAX_STR_LEN);
				strncpy(sortedName[i], sortedName[i+1], MAX_STR_LEN);
				strncpy(sortedName[i+1], swap_name, MAX_STR_LEN);

				moved = true;
			}
		}
	} while(moved);

	showNumberScoreName(studentQuantity, sortedNum, sortedScore, sortedName);
	return;
}

void sortAscend(int studentQuantity, int sortedNum[], int sortedScore[], char sortedName[][MAX_STR_LEN]) {
	bool moved = false;
	do {
		moved = false;
		int i=0;
		for (i=0 ; i<studentQuantity-1 ; i++) {
			if (sortedScore[i]>sortedScore[i+1]) {
				int swap = 0;
				swap = sortedScore[i];
				sortedScore[i] = sortedScore[i+1];
				sortedScore[i+1] = swap;

				swap = sortedNum[i];
				sortedNum[i] = sortedNum[i+1];
				sortedNum[i+1] = swap;
				
				char swap_name[MAX_STR_LEN];
				strncpy(swap_name, sortedName[i], MAX_STR_LEN);
				strncpy(sortedName[i], sortedName[i+1], MAX_STR_LEN);
				strncpy(sortedName[i+1], swap_name, MAX_STR_LEN);

				moved = true;
			}
		}
	} while(moved);

	showNumberScoreName(studentQuantity, sortedNum, sortedScore, sortedName);
	return;
}

void sortAscend_number(int studentQuantity, int sortedNum[], int sortedScore[], char sortedName[][MAX_STR_LEN]) {
	bool moved = false;
	do {
		moved = false;
		int i=0;
		for (i=0 ; i<studentQuantity-1 ; i++) {
			if (sortedNum[i]>sortedNum[i+1]) {
				int swap = 0;
				swap = sortedScore[i];
				sortedScore[i] = sortedScore[i+1];
				sortedScore[i+1] = swap;

				swap = sortedNum[i];
				sortedNum[i] = sortedNum[i+1];
				sortedNum[i+1] = swap;
				
				char swap_name[MAX_STR_LEN];
				strncpy(swap_name, sortedName[i], MAX_STR_LEN);
				strncpy(sortedName[i], sortedName[i+1], MAX_STR_LEN);
				strncpy(sortedName[i+1], swap_name, MAX_STR_LEN);

				moved = true;
			}
		}
	} while(moved);

	showNumberScoreName(studentQuantity, sortedNum, sortedScore, sortedName);
	return;
}

void sortDict_name(int studentQuantity, int sortedNum[], int sortedScore[], char sortedName[][MAX_STR_LEN]) {
	bool moved = false;
	do {
		moved = false;
		int i=0;
		for (i=0 ; i<studentQuantity-1 ; i++) {
			if (strcasecmp(sortedName[i], sortedName[i+1])>0) {
				int swap = 0;
				swap = sortedScore[i];
				sortedScore[i] = sortedScore[i+1];
				sortedScore[i+1] = swap;

				swap = sortedNum[i];
				sortedNum[i] = sortedNum[i+1];
				sortedNum[i+1] = swap;
				
				char swap_name[MAX_STR_LEN];
				strncpy(swap_name, sortedName[i], MAX_STR_LEN);
				strncpy(sortedName[i], sortedName[i+1], MAX_STR_LEN);
				strncpy(sortedName[i+1], swap_name, MAX_STR_LEN);

				moved = true;
			}
		}
	} while(moved);

	showNumberScoreName(studentQuantity, sortedNum, sortedScore, sortedName);
	return;
}

void sort(int studentQuantity, int Num[], int Score[], char Name[][MAX_STR_LEN], void (*fp)(int, int*, int*, char[][MAX_STR_LEN])) {
    int sortedNum[MAX_STU_NUM] = {0};
    int sortedScore[MAX_STU_NUM] = {0};
    char sortedName[MAX_STU_NUM][MAX_STR_LEN] = {0};

    int i=0;
    for (i=0 ; i<studentQuantity ; i++) {
        sortedNum[i] = Num[i];
        sortedScore[i] = Score[i];
        strncpy(sortedName[i], Name[i], MAX_STR_LEN);
    }
    
    (*fp)(studentQuantity, sortedNum, sortedScore, sortedName);
    
    return;
}

void searchAndPrint(int studentQuantity, int Num[], int Score[], char Name[][MAX_STR_LEN], int key) {
	int addr=-1;
	int i=0;

    for (i=0 ; i<studentQuantity ; i++) if (Num[i]==key) {
        addr = i;
        break;
    }

	if (addr==-1) printf ("Not Found!\n");
	else printf ("Student %s\tNum : %d -> Score : %d\n", Name[i], Num[i], Score[i]);

	return;
}

void searchAndPrint_name(int studentQuantity, int Num[], int Score[], char Name[][MAX_STR_LEN], char key_name[]) {
	int addr=-1;
	int i=0;

    for (i=0 ; i<studentQuantity ; i++) if (!strcasecmp(Name[i], key_name)) {
        addr = i;
        break;
    }

	if (addr==-1) printf ("Not Found!\n");
	else printf ("Student %s\tNum : %d -> Score : %d\n", Name[i], Num[i], Score[i]);

	return;
}

void statisticAnalysis(int studentQuantity, int Score[]) {
	int wellDone=0, good=0, medium=0, pass=0, failed=0;
	int i=0;

	for (i=0 ; i<studentQuantity ; i++) {
		if (Score[i]>=90) wellDone++;
		else if (Score[i]>=80) good++;
		else if (Score[i]>=70) medium++;
		else if (Score[i]>=60) pass++;
		else failed++;
	}

	printf ("Well Done (90-100) : %d student(s), %.2f%%\nGood (80-89) : %d student(s), %.2f%%\nMedium (70-79) : %d student(s), %.2f%%\nPass (60-69) : %d student(s), %.2f%%\nFailed (0-59) : %d student(s), %.2f%%\n",
				wellDone, 100.0 * wellDone / studentQuantity,
				good, 100.0 * good / studentQuantity,
				medium, 100.0 * medium / studentQuantity,
				pass, 100.0 * pass / studentQuantity,
				failed, 100.0 * failed / studentQuantity
				);
		
	return;
}

int main() {
	showinfo();
	int studentQuantity = 0;
	int Num[MAX_STU_NUM] = {0}, Score[MAX_STU_NUM] = {0};
	char Name[MAX_STU_NUM][MAX_STR_LEN] = {0};
    
    showMenu();
    
	while(true) {
		int cmd=-1;
        int key=0;
        char key_name[MAX_STR_LEN];
        
		inputNumber(&cmd, "Please enter your choice > ");

		switch(cmd) {
			case 1:
                inputNumScoreName(&studentQuantity, Num, Score, Name);
				break;
			case 2:
                totalAverage(studentQuantity, Score);
				break;
			case 3:
				sort(studentQuantity, Num, Score, Name, sortDescend);
				break;
			case 4:
                sort(studentQuantity, Num, Score, Name, sortAscend);
                break;
            case 5:
                sort(studentQuantity, Num, Score, Name, sortAscend_number);
                break;
            case 6:
                sort(studentQuantity, Num, Score, Name, sortDict_name);
                break;
            case 7:
                inputNumber(&key, "(search by number) ");
                searchAndPrint(studentQuantity, Num, Score, Name, key);
                break;
            case 8:
                input_c_string(key_name, "(search by name) ", MAX_STR_LEN);
                searchAndPrint_name(studentQuantity, Num, Score, Name, key_name);
                break;
            case 9:
            	statisticAnalysis(studentQuantity, Score);
                break;
            case 10:
                showNumberScoreName(studentQuantity, Num, Score, Name);
                break;
            case 0:
                printf("Exit.\n");
                goto END;
            default:
                showMenu();
		}
	}
END:
    return 0;
}
