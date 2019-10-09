#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int);

int main() {
    printf("Number:190110728\n");
	printf("Subject No.3 - Program No.1\n\n");

	int judge = 0, i = 0;
	bool firstFlag = true;

	while (!scanf("%d", &judge) || judge <= 0) { // Pay attention of short out
		while (getchar()!='\n');
		printf ("invalid input, try again.\n");
	}


	if (isPrime(judge)) {
		printf("%d is a prime number.\n", judge);
		return 0;
	}

	for (i = 2; i <= judge ; i++) {
		if (isPrime(i)) {
			while (judge%i == 0) {
				if (firstFlag) {
					printf("%d = %d", judge, i);
					firstFlag = false;
				}
				else printf(" * %d", i);
				judge /= i;

			}
		}
	}

    putchar('\n');
	return 0;
}

bool isPrime(int judge) {
	if (judge == 2) return true;

	int i = 0;

	for (i = 2; i <= ceil(sqrt(judge)); i++) {
		if (judge%i == 0) return false;
	}
	return true;
}
