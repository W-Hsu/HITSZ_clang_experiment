#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int QUESTION_QUANTITY = 10;

void showFail(void);
void showSuc(void);

int main() {
	printf("Computer-Aided Instruction -- Simple Arithmetic in range [1,9]\n");
	printf("Version 2.0.0\n");
	printf("Number:190110728\n");
	printf("Subject No.4 - Program No.2\n");
	putchar('\n');

	int score = 0;
	int i = 0;
	srand(time(NULL));

	while(1) {
		for (i = 0; i < QUESTION_QUANTITY; i++) {
			int num1 = rand() % 9 + 1;
			int num2 = rand() % 9 + 1;
			int result = 0;
			short calculateType = rand() % 4;

			switch (calculateType) {
				case 0: /* Addition */
					result = num1 + num2;
					printf("%d + %d = ?\n", num1, num2);
					break;
				case 1: /* Subtraction */
					if (num2 > num1) {
						int temp = num1;
						num1 = num2;
						num2 = temp;
					}
					result = num1 - num2;
					printf("%d - %d = ?\n", num1, num2);
					break;
				case 2: /* Multiplication */
					result = num1 * num2;
					printf("%d * %d = ?\n", num1, num2);
					break;
				case 3: /* Division */
					if (num2 > num1) {
						int temp = num1;
						num1 = num2;
						num2 = temp;
					}
					result = num1 / num2;
					printf("%d / %d = ?", num1, num2);
					if (num1%num2 != 0) printf (" ......%d\n", num1%num2);
					else putchar('\n');
					break;
			}


			int input = 0;

			scanf("%d", &input);
			while (getchar() != '\n');

			if (input != result) showFail();
			else {
				showSuc();
				score += 10;
			}

		}

		printf("This time, your score is %d.\nYour Accuracy is %d%%\n", score, score);

		if (score>75) {
			printf ("Congrats! You jumped out the infinte loop thanks to your good grade!\n");
			printf ("Ding! break!\n");
			break;
		}
		else printf ("\nSorry, have another try...\n");
		score = 0;
	}
	return 0;
}

void showFail(void) {
	int i = rand() % 4;

	switch (i) {
		case 0: /* Addition */
			printf ("No. Please try next subject.\n");
			break;
		case 1: /* Subtraction */
			printf ("Wrong. Be careful.\n");
			break;
		case 2: /* Multiplication */
			printf ("Don't give up!\n");
			break;
		case 3: /* Division */
			printf ("Not correct. Keep trying.\n");
			break;
	}
}

void showSuc(void) {
	int i = rand() % 4;

	switch (i) {
		case 0: /* Addition */
			printf ("Very good!\n");
			break;
		case 1: /* Subtraction */
			printf ("Excellent!\n");
			break;
		case 2: /* Multiplication */
			printf ("Nice work!\n");
			break;
		case 3: /* Division */
			printf ("Keep up the good work!\n");
			break;
	}
}




