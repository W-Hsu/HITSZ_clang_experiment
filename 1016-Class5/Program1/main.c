#include <stdio.h>
#include <stdbool.h>

#define MAX_STU_NUM 30

void showMenu() {
	printf ("1. Input record\n"
			"2. Calculate total and average score of course\n"
			"3. Sort in descending order by score\n"
			"4. Sort in ascending order by score\n"
			"5. Sort in ascending order by number\n"
			"6. Search by number\n"
			"7. Statistic analysis\n"
			"8. List record\n"
            "9. Show Menu\n"
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

void showNumberScore(int studentQuantity, int Num[], int Score[]) {
	int i=0;
	for (i=0 ; i<studentQuantity ; i++) printf ("Student Number : %d -> Score : %d\n", Num[i], Score[i]);
	return;
}

void inputNumScore(int *studentQuantity, int Num[], int Score[]) {
	inputNumber(studentQuantity, "Input student quantity > ");
    
    if (*studentQuantity>30) {
        printf ("30.\n");
        *studentQuantity = 30;
    }
	
	int i=0;
	for (i=0 ; i<(*studentQuantity) ; i++) {
		inputNumber(&Num[i], "Number > ");
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

void sortDescend(int studentQuantity, int sortedNum[], int sortedScore[]) {
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

				moved = true;
			}
		}
	} while(moved);

	showNumberScore(studentQuantity, sortedNum, sortedScore);
	return;
}

void sortAscend(int studentQuantity, int sortedNum[], int sortedScore[]) {
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

				moved = true;
			}
		}
	} while(moved);

	showNumberScore(studentQuantity, sortedNum, sortedScore);
	return;
}

void sortAscend_number(int studentQuantity, int sortedNum[], int sortedScore[]) {
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

				moved = true;
			}
		}
	} while(moved);

	showNumberScore(studentQuantity, sortedNum, sortedScore);
	return;
}

void sort(int studentQuantity, int Num[], int Score[], void (*fp)(int, int*, int*)) {
    int sortedNum[MAX_STU_NUM] = {0};
    int sortedScore[MAX_STU_NUM] = {0};

    int i=0;
    for (i=0 ; i<studentQuantity ; i++) {
        sortedNum[i] = Num[i];
        sortedScore[i] = Score[i];
    }
    
    (*fp)(studentQuantity, sortedNum, sortedScore);
    
    return;
}

void searchAndPrint(int studentQuantity, int Num[], int Score[], int key) {
	int addr=-1;
	int i=0;

    for (i=0 ; i<studentQuantity ; i++) if (Num[i]==key) {
        addr = i;
        break;
    }

	if (addr==-1) printf ("Not Found!\n");
	else printf ("Student Number : %d -> Score : %d\n", Num[addr], Score[addr]);

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
	int studentQuantity = 0;
	int Num[MAX_STU_NUM] = {0}, Score[MAX_STU_NUM] = {0};
    
    showMenu();
    
	while(true) {
		int cmd=-1;
        int key=0;
        
		inputNumber(&cmd, "Please enter your choice > ");

		switch(cmd) {
			case 1:
                inputNumScore(&studentQuantity, Num, Score);
				break;
			case 2:
                totalAverage(studentQuantity, Score);
				break;
			case 3:
				sort(studentQuantity, Num, Score, sortDescend);
				break;
			case 4:
                sort(studentQuantity, Num, Score, sortAscend);
                break;
            case 5:
                sort(studentQuantity, Num, Score, sortAscend_number);
                break;
            case 6:
                inputNumber(&key, "(search) ");
                searchAndPrint(studentQuantity, Num, Score, key);
                break;
            case 7:
                statisticAnalysis(studentQuantity, Score);
                break;
            case 8:
                showNumberScore(studentQuantity, Num, Score);
                break;
            case 9:
                showMenu();
                break;
            case 0:
                printf("Exit.\n");
                goto END;
            default:
                printf("%d : Command not found.\n", cmd);
		}
	}
END:
    return 0;
}
