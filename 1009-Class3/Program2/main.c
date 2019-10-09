#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    printf("Number:190110728\n");
	printf("Subject No.3 - Program No.3\n\n");

	int judge = 0, i = 0, sum = 1;

	while (!scanf("%d", &judge) || judge <= 0) { // Pay attention of short out
		while (getchar()!='\n');
		printf ("invalid input, try again.\n");
	}

	for (i = 2; i < judge ; i++) if (judge%i == 0) sum += i;

	if (sum==judge) printf("%d is a perfect number.\n", judge);
	else printf("%d is NOT a perfect number.\n", judge);

	return 0;
}
