#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define _VERSION "4.0"

#define MAX_STU_NUM 30
#define MAX_STR_LEN 30
#define MAX_SUBJECT_NUM 6 /* Stores Total Score in position 0 */

struct Student {
    unsigned ID;
    char Name[MAX_STR_LEN];
    int Scores[7];
};

typedef struct Student Student;

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

void showOneStudent_IDScoreName(int subjectQuantity, Student Stus[], int addr) {
    int i=0;
    printf ("Student %s , ID(Number) %d : \n", Stus[addr].Name, Stus[addr].ID);
    for (i=1 ; i<=subjectQuantity ; i++) printf ("Subject NO. %d -> Score : %3d\n", i, Stus[addr].Scores[i]);
    printf ("Total Score : %3d\n", Stus[addr].Scores[0]);
}

void showAll_IDScoreName(int studentQuantity, int subjectQuantity, Student Stus[]) {
    int i=0;
    for (i=0 ; i<studentQuantity ; i++) {
        putchar('\n');
        showOneStudent_IDScoreName(subjectQuantity, Stus, i);
    }
    return;
}

void inputNumScoreName(int *studentQuantity, int *subjectQuantity, Student Stus[]) {
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
        inputNumber(&Stus[i].ID, "ID(Number) > ");
        input_c_string(Stus[i].Name, "Name > ", MAX_STR_LEN);

        /* Score of each Subject */
        int j=0;
        for (j=1 ; j<=(*subjectQuantity) ; j++) {
            printf ("Enter Subject %d", j);
            inputNumber(&Stus[i].Scores[j], " > ");
        }
    }
    return;
}

void totalAverage_Subject(int studentQuantity, int subjectQuantity, Student Stus[]) {
    putchar ('\n');
    int i=0;
    for (i=1 ; i<=subjectQuantity ; i++) {
        printf ("Subject %d : \n", i);

        int total = 0;
        int j=0;
        for (j=0 ; j<studentQuantity ; j++) total+=Stus[j].Scores[i];
        printf ("Total : %d, Average : %.2f\n", total, (double)total/studentQuantity);
    }
}

void totalAverage_Student(int studentQuantity, Student Stus[]) {
    putchar ('\n');
    int i=0;
    for (i=0 ; i<studentQuantity ; i++) {
        printf ("Student %s , ID(Number) %d : \n", Stus[i].Name, Stus[i].ID);
        printf ("Total : %3d, Average : %.2f\n", Stus[i].Scores[0], (double)Stus[i].Scores[0]/studentQuantity);
    }
}

void swap(Student Stu[], int i) {
    Student _swap = Stu[i];
    Stu[i] = Stu[i+1];
    Stu[i+1] = _swap;
}

/* Sort by Score Section */
bool Score_Descend(int _Main[], int __Main[]) {
    if (_Main[0]<__Main[0]) return true;
    return false;
}

bool Score_Ascend(int _Main[], int __Main[]) {
    if (_Main[0]>__Main[0]) return true;
    return false;
}

void sortByScore(int studentQuantity, Student Stus[], bool (*cmp_type)(int [], int[])) {
    bool moved;
    do {
        moved = false;
        int i=0;
        for (i=0 ; i<studentQuantity-1 ; i++) {
            if (cmp_type(Stus[i].Scores, Stus[i+1].Scores)) {
                swap(Stus, i);
                moved = true;
            }
        }
    } while(moved);
}
/* End Sort by Score Section */

/* Sort by ID Section */
void sortByID(int studentQuantity, Student Stus[]) {
    bool moved;
    do {
        moved = false;
        int i=0;
        for (i=0 ; i<studentQuantity-1 ; i++) {
            if (Stus[i].ID>Stus[i+1].ID) {
                swap(Stus, i);
                moved = true;
            }
        }
    } while(moved);
}
/* End Sort by ID Section */

/* Sort by Name Section */
void sortByName(int studentQuantity, Student Stus[]){
    bool moved;
    do {
        moved = false;
        int i=0;
        for (i=0 ; i<studentQuantity-1 ; i++) {
            if (strcasecmp(Stus[i].Name, Stus[i+1].Name)>0) {
                swap(Stus, i);
                moved = true;
            }
        }
    } while(moved);
}
/* End Sort by Name Section */

void searchAndPrint(int studentQuantity, int subjectQuantity, Student Stus[], unsigned key) {

    sortByScore(studentQuantity, Stus, Score_Ascend); /* Sort by total score first */

    int addr=-1;
    int i=0;

    for (i=0 ; i<studentQuantity ; i++) if (Stus[i].ID==key) {
            addr = i;
            break;
        }

    if (addr==-1) printf ("Student Not Found!\n");
    else showOneStudent_IDScoreName(subjectQuantity, Stus, addr);

    return;
}

void searchAndPrint_name(int studentQuantity, int subjectQuantity, Student Stus[], char key_name[]) {

    sortByScore(studentQuantity, Stus, Score_Ascend); /* Sort by total score first */

    int addr=-1;
    int i=0;

    for (i=0 ; i<studentQuantity ; i++) if (!strcasecmp(Stus[i].Name, key_name)) {
            addr = i;
            break;
        }

    if (addr==-1) printf ("Student Not Found!\n");
    else showOneStudent_IDScoreName(subjectQuantity, Stus, addr);
}

void statisticAnalysis(int studentQuantity, int subjectQuantity, Student Stus[]) {
    int _subjectNO = 0;
    for (_subjectNO=1 ; _subjectNO<=subjectQuantity ; _subjectNO++) {
        int wellDone=0, good=0, medium=0, pass=0, failed=0;

        int i=0;
        for (i=0 ; i<studentQuantity ; i++) {
            if (Stus[i].Scores[_subjectNO]>=90) wellDone++;
            else if (Stus[i].Scores[_subjectNO]>=80) good++;
            else if (Stus[i].Scores[_subjectNO]>=70) medium++;
            else if (Stus[i].Scores[_subjectNO]>=60) pass++;
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
    Student Stus[MAX_STU_NUM];

    int i=0, j=0;

    showMenu();

    while(true) {
        int cmd=-1;
        int key=0;
        char key_name[MAX_STR_LEN];

        inputNumber(&cmd, "Please enter your choice > ");

        switch(cmd) {
            case 1:
                inputNumScoreName(&studentQuantity, &subjectQuantity, Stus);
                /* Quietly add total score to the end of the Score array */
                for (i=0 ; i<studentQuantity ; i++) {
                    Stus[i].Scores[0]+=Stus[i].Scores[j];
                    for (j=1 ; j<=subjectQuantity ; j++) Stus[i].Scores[0]+=Stus[i].Scores[j];
                }
                break;
            case 2:
                totalAverage_Subject(studentQuantity, subjectQuantity, Stus);
                break;
            case 3:
                totalAverage_Student(studentQuantity, Stus);
                break;
            case 4:
                sortByScore(studentQuantity, Stus, Score_Descend);
                showAll_IDScoreName(studentQuantity, subjectQuantity, Stus);
                break;
            case 5:
                sortByScore(studentQuantity, Stus, Score_Ascend);
                showAll_IDScoreName(studentQuantity, subjectQuantity, Stus);
                break;
            case 6:
                sortByID(studentQuantity, Stus);
                showAll_IDScoreName(studentQuantity, subjectQuantity, Stus);
                break;
            case 7:
                sortByName(studentQuantity, Stus);
                showAll_IDScoreName(studentQuantity, subjectQuantity, Stus);
                break;
            case 8:
                inputNumber(&key, "(search by number) ");
                unsigned _key = (unsigned)key;
                searchAndPrint(studentQuantity, subjectQuantity, Stus, _key);
                break;
            case 9:
                input_c_string(key_name, "(search by name) ", MAX_STR_LEN);
                searchAndPrint_name(studentQuantity, subjectQuantity, Stus, key_name);
                break;
            case 10:
                statisticAnalysis(studentQuantity, subjectQuantity, Stus);
                break;
            case 11:
                showAll_IDScoreName(studentQuantity, subjectQuantity, Stus);
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
