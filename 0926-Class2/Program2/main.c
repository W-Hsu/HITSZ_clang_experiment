#include <stdio.h>
#include <math.h>

void showInfo() {
	/* Subject µÚ¼¸´Î¿Î  */ 
	printf("Number:190110728\n");
	printf("Subject No.2 - Program No.2\n\n");
}

int main() {
	showInfo(); 
	int triangle[3] = {0, 0, 0};
	int i=0;

	/* input length of 3 edges */
	for (i=0 ; i<3 ; i++) {
		printf("Enter length of No.%d edge:\n", i+1);
		for (; !scanf("%d", &triangle[i]) ;) {
			while (getchar()!='\n');
			printf("illegal value entered! Try again!\n");
		}
	}

	/* see if the 3 edges can form a triangle */
	if ((triangle[0]>=triangle[1]+triangle[2]) || (triangle[1]>=triangle[0]+triangle[2]) || (triangle[2]>=triangle[0]+triangle[1])) {
		printf ("NOT A TRIANGLE!!!\n");
		return -1;
	}
	printf ("A triangle, it is.\n");

	/* calculate the area using Helen(?) formula and then print it out */
	float p = 0;
	for(i=0 ; i<3 ; i++) p += triangle[i];
	p /= 2;
	float Area = p;
	for(i=0 ; i<3 ; i++) Area *= (p-triangle[i]);
	Area = sqrt(Area);
	printf("Ah... And I believe its area is %f", Area);

	/* exit "Happy-ever-after-ly" */
	return 0;
}
