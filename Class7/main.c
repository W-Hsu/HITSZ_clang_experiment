#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define _VERSION "3.0"

#define MAX_STU_NUM 30
#define MAX_STR_LEN 30
#define MAX_SUBJECT_NUM 6 /* Stores Total Score in position 0 */

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
			"2. Calculate total and average score of every course\n"
            "3. Calculate total and average score of every student\n"
			"4. Sort in descending order by total score of every student\n"
			"5. Sort in ascending order by total score of every student\n"
			"6. Sort in ascending order by number\n"
			"7. Sort in dictionary order by name\n"
			"8. Search by number\n"
			"9. Search by name\n"
			"10. Statistic analysis for every course\n"
			"11. List record\n"
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
    
    /* deal with '\n' at the end */
    int i=0;
    for (i=0 ; sp[i]!='\n' ; i++);
    sp[i] = '\0';
    
	return;
}

void showNumberScoreName(int studentQuantity, int subjectQuantity, int Num[], int Score[][MAX_SUBJECT_NUM+1], char Name[][MAX_STR_LEN]) {
	int i=0, j=0;
    for (i=0 ; i<studentQuantity ; i++) {
        putchar('\n');
        printf ("Student %s , Number %d : \n", Name[i], Num[i], Score[i][j]);
        for (j=1 ; j<=subjectQuantity ; j++) printf ("Subject NO. %d -> Score : %3d\n", j, Score[i][j]);
        printf ("Total Score : %3d\n", Score[i][0]);
    }
	return;
}

void inputNumScoreName(int *studentQuantity, int *subjectQuantity, int Num[], int Score[][MAX_SUBJECT_NUM+1], char Name[][MAX_STR_LEN]) {
	inputNumber(studentQuantity, "Input student quantity > ");
    inputNumber(subjectQuantity, "Input subject quantity > ");
    
    if (*studentQuantity>MAX_STU_NUM) {
        printf ("Maximum Student Quantity : %d.\n", MAX_STU_NUM);
        *studentQuantity = MAX_STU_NUM;
    }
    
    if (*subjectQuantity>MAX_SUBJECT_NUM) {
        printf ("Maximum Subject Quantity : %d.\n", MAX_SUBJECT_NUM);
        *subjectQuantity = MAX_SUBJECT_NUM;
    }
	
	int i=0;
	for (i=0 ; i<(*studentQuantity) ; i++) {
        putchar('\n');
        /* Student Basic Info */
        printf ("Input NO. %d : \n", i+1); /* Good Looking */
		inputNumber(&Num[i], "Number > ");
		input_c_string(Name[i], "Name > ", MAX_STR_LEN);
        
        /* Score of each Subject */
        int j=0;
        for (j=1 ; j<=(*subjectQuantity) ; j++) {
            printf ("Enter Subject %d", j);
            inputNumber(&Score[i][j], " > ");
        }
	}

	return;
}

void totalAverage_Subject(int studentQuantity, int subjectQuantity, int Score[][MAX_SUBJECT_NUM+1]) {
    int i=0;
    for (i=1 ; i<=subjectQuantity ; i++) {
        printf ("Subject %d : \n", i);
        
        int total = 0;
        int j=0;
        for (j=0 ; j<studentQuantity ; j++) total+=Score[j][i];
        printf ("Total : %d, Average : %.2f\n", total, (double)total/studentQuantity);
    }
}

void totalAverage_Student(int studentQuantity, int subjectQuantity, int Num[], int Score[][MAX_SUBJECT_NUM+1], char Name[][MAX_STR_LEN]) {
    int i=0;
    for (i=0 ; i<studentQuantity ; i++) {
        printf ("Student %s , Number %d : \n", Name[i], Num[i]);
        printf ("Total : %3d, Average : %.2f\n", Score[i][0], (double)Score[i][0]/studentQuantity);
    }
}

bool sortAscend_1di(int *_Main, int i) {
    if (_Main[i]>_Main[i+1]) return true;
    return false;
}

bool sortDescend_2di(int _Main[][MAX_SUBJECT_NUM+1], int i) {
    if (_Main[i][0]<_Main[i+1][0]) return true;
    return false;
}

bool sortAscend_2di(int _Main[][MAX_SUBJECT_NUM+1], int i) {
    if (_Main[i][0]>_Main[i+1][0]) return true;
	return false;
}

bool sortDict_name(char sortedName[][MAX_STR_LEN], int i) {
    if (strcasecmp(sortedName[i], sortedName[i+1])>0) return true;
    return false;
}

void swap(int sortedNum[], int sortedScore[][MAX_SUBJECT_NUM+1], char sortedName[][MAX_STR_LEN], int i) {
    int _swap[MAX_SUBJECT_NUM+1] = {0};
    memcpy(_swap, sortedScore[i], sizeof(int)*(MAX_SUBJECT_NUM+1));
    memcpy(sortedScore[i], sortedScore[i+1], sizeof(int)*(MAX_SUBJECT_NUM+1));
    memcpy(sortedScore[i+1], _swap, sizeof(int)*(MAX_SUBJECT_NUM+1));

    int __swap = sortedNum[i];
    sortedNum[i] = sortedNum[i+1];
    sortedNum[i+1] = __swap;
    
    char swap_name[MAX_STR_LEN];
    strncpy(swap_name, sortedName[i], MAX_STR_LEN);
    strncpy(sortedName[i], sortedName[i+1], MAX_STR_LEN);
    strncpy(sortedName[i+1], swap_name, MAX_STR_LEN);
}

void sort_1di(int studentQuantity, int _Main[], int Sub1[][MAX_SUBJECT_NUM+1], char Sub2[][MAX_STR_LEN], bool (*cmp)(int*, int)) {
    bool moved = false;
    do {
        moved = false;
        int i=0;
        for (i=0 ; i<studentQuantity-1 ; i++) {
            if (cmp(_Main, i)) {
                swap(_Main, Sub1, Sub2, i);
                moved = true;
            }
        }
    } while(moved);
}

void sort_2di(int studentQuantity, int _Main[][MAX_SUBJECT_NUM+1], int Sub1[], char Sub2[][MAX_STR_LEN], bool (*cmp)(int**, int)) {
    
    bool moved = false;
    do {
        moved = false;
        int i=0;
        for (i=0 ; i<studentQuantity-1 ; i++) {
            if (cmp(_Main, i)) {
                swap(Sub1, _Main, Sub2, i);
                moved = true;
            }
        }
    } while(moved);
}

void sort_2dc(int studentQuantity, char _Main[][MAX_STR_LEN], int Sub1[], int Sub2[], bool (*cmp)(char**, int)) {
    bool moved = false;
    do {
        moved = false;
        int i=0;
        for (i=0 ; i<studentQuantity-1 ; i++) {
            if (cmp(_Main, i)) {
                swap(Sub1, Sub2, _Main, i);
                moved = true;
            }
        }
    } while(moved);
}

void searchAndPrint(int studentQuantity, int subjectQuantity, int Num[], int Score[][MAX_SUBJECT_NUM+1], char Name[][MAX_STR_LEN], int key) {
    
    sort_2di(studentQuantity, Score, Num, Name, sortDescend_2di); /* Sort by total score first */
    
	int addr=-1;
	int i=0;

    for (i=0 ; i<studentQuantity ; i++) if (Num[i]==key) {
        addr = i;
        break;
    }

	if (addr==-1) printf ("Not Found!\n");
    else {
        printf ("Student %s , Number %d , ranking %d : \n", Name[i], Num[i], i+1);
        int j=0;
        for (j=1 ; j<=subjectQuantity ; j++) printf ("Subject NO. %d -> Score : %3d\n", j, Score[i][j]);
        printf ("Total Score : %3d\n", Score[i][0]);
    }

	return;
}

void searchAndPrint_name(int studentQuantity, int subjectQuantity, int Num[], int Score[][MAX_SUBJECT_NUM+1], char Name[][MAX_STR_LEN], char key_name[]) {
    
    sort_2di(studentQuantity, Score, Num, Name, sortDescend_2di); /* Sort by total score first */
    
	int addr=-1;
	int i=0;

    for (i=0 ; i<studentQuantity ; i++) if (!strcasecmp(Name[i], key_name)) {
        addr = i;
        break;
    }

	if (addr==-1) printf ("Not Found!\n");
    else {
        printf ("Student %s , Number %d , ranking %d : \n", Name[i], Num[i], i+1);
        int j=0;
        for (j=0 ; j<subjectQuantity ; j++) printf ("Subject NO. %d -> Score : %3d\n", j, Score[i][j]);
        printf ("Total Score : %3d\n", Score[i][0]);
    }
}

void statisticAnalysis(int studentQuantity, int subjectQuantity, int Score[][MAX_SUBJECT_NUM+1]) {
    int _subjectNO = 0;
    for (_subjectNO=1 ; _subjectNO<=subjectQuantity ; _subjectNO++) {
        int wellDone=0, good=0, medium=0, pass=0, failed=0;
        
        int i=0;
        for (i=0 ; i<studentQuantity ; i++) {
            if (Score[i][_subjectNO]>=90) wellDone++;
            else if (Score[i][_subjectNO]>=80) good++;
            else if (Score[i][_subjectNO]>=70) medium++;
            else if (Score[i][_subjectNO]>=60) pass++;
            else failed++;
        }

        putchar('\n');
        printf ("Subject NO. %d Statistic Analysis : \n", _subjectNO);
        printf ("Well Done (90-100) : %d student(s), %.2f%%\nGood (80-89) : %d student(s), %.2f%%\nMedium (70-79) : %d student(s), %.2f%%\nPass (60-69) : %d student(s), %.2f%%\nFailed (0-59) : %d student(s), %.2f%%\n",
                    wellDone, 100.0 * wellDone / studentQuantity,
                    good, 100.0 * good / studentQuantity,
                    medium, 100.0 * medium / studentQuantity,
                    pass, 100.0 * pass / studentQuantity,
                    failed, 100.0 * failed / studentQuantity
                    );
    }
        return;
}

int main() {
	showinfo();
	int studentQuantity = 0, subjectQuantity = 0;
	int Num[MAX_STU_NUM] = {0}, Score[MAX_STU_NUM][MAX_SUBJECT_NUM+1] = {0};
	char Name[MAX_STU_NUM][MAX_STR_LEN] = {0};
    
    int i=0, j=0;
    
    showMenu();
    
	while(true) {
		int cmd=-1;
        int key=0;
        char key_name[MAX_STR_LEN];
        
		inputNumber(&cmd, "Please enter your choice > ");

		switch(cmd) {
			case 1:
                inputNumScoreName(&studentQuantity, &subjectQuantity, Num, Score, Name);
                for (i=0 ; i<studentQuantity ; i++) for (j=1 ; j<=subjectQuantity ; j++) Score[i][0]+=Score[i][j]; /* Quietly add total score to the end of the Score array */
				break;
			case 2:
                totalAverage_Subject(studentQuantity, subjectQuantity, Score);
				break;
            case 3:
                totalAverage_Student(studentQuantity, subjectQuantity, Num, Score, Name);
                break;
			case 4:
				sort_2di(studentQuantity, Score, Num, Name, sortDescend_2di);
                showNumberScoreName(studentQuantity, subjectQuantity, Num, Score, Name);
				break;
			case 5:
                sort_2di(studentQuantity, Score, Num, Name, sortAscend_2di);
                showNumberScoreName(studentQuantity, subjectQuantity, Num, Score, Name);
                break;
            case 6:
                sort_1di(studentQuantity, Num, Score, Name, sortAscend_1di);
                showNumberScoreName(studentQuantity, subjectQuantity, Num, Score, Name);
                break;
            case 7:
                sort_2dc(studentQuantity, Name, Num, Score, sortDict_name);
                showNumberScoreName(studentQuantity, subjectQuantity, Num, Score, Name);
                break;
            case 8:
                inputNumber(&key, "(search by number) ");
                searchAndPrint(studentQuantity, subjectQuantity, Num, Score, Name, key);
                break;
            case 9:
                input_c_string(key_name, "(search by name) ", MAX_STR_LEN);
                searchAndPrint_name(studentQuantity, subjectQuantity, Num, Score, Name, key_name);
                break;
            case 10:
            	statisticAnalysis(studentQuantity, subjectQuantity,Score);
                break;
            case 11:
                showNumberScoreName(studentQuantity, subjectQuantity, Num, Score, Name);
                break;
            case 0:
                printf("Exit.\n");
                goto END;
            default:
                showMenu();
		}
        putchar('\n');
	}
END:
    return 0;
}
