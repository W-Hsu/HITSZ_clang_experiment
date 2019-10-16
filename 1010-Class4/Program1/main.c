#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int MAXIMUM_TRY_TIME = 3;
const int QUESTION_QUANTITY = 10;

int main() {
    printf("Computer-Aided Instruction -- Multiplication in range [1,9]\n");
    printf("Version 1.0.0\n");
    printf("Number:190110728\n");
	printf("Subject No.4 - Program No.1\n");
	putchar('\n');

	int score=0;
	int i=0, j=0;
	srand(time(NULL));


	for (i=0 ; i<QUESTION_QUANTITY ; i++) {
		int num1 = rand() % 9 + 1;
		int num2 = rand() % 9 + 1;
		int result = num1 * num2;
		int tryTime=0, input=0;

		do {
			tryTime++;
			printf ("%d * %d = ?\n", num1, num2);

			scanf ("%d", &input);
			while (getchar()!='\n');

			if (input != result) {
				if (tryTime<3) printf ("Wrong! Please Try Again!\n");
				else printf ("Wrong! Try Next Subject!\n");
			}
			else {
				printf ("Right.\n");
				score += 10;
			}
		} while(tryTime<3 && input!=result);
	}

	printf ("Your Final Score is %d.\nYour Accuracy is %d%%\n", score, score);

	return 0;
}
