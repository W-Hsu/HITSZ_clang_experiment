#include <stdio.h>

const int Number = 190110728;
const int Subject = 2;

int main()
{
    printf("Number:%d\nSubject:%d\n\n", Number, Subject);
    int i=0, j=0;
    for (i=0 ; i<8 ; i++) {
    	if (i%2 != 0) printf(" ");
		for (j=0 ; j<8 ; j++) printf("A ");
		printf("\n");
	}
	return 0;
}
