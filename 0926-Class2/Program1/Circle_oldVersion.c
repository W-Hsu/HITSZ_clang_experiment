#include <stdio.h>

#define PI 3.14159
const float PAI = 3.14159;

int main() {
	float radius=0, SuperficialArea=0, volume=0;
	
	/* Enter Radius */ 
	printf("Enter Radius:\n"); 
	for (; !scanf("%f", &radius) ;) {
		while (getchar()!='\n');
		printf("Radius illegal entered! Try again!\n");
	}
		
	/* using "macro" PI */
	SuperficialArea = 4 * PI * radius * radius;
	volume = 3.0 / 4 * PI * radius * radius * radius;
	printf ("Superficial Area: %f\nVolume: %f\n\n", SuperficialArea, volume);
	
	SuperficialArea = volume = 0;
	
	/* using "const" PI */
	SuperficialArea = 4 * PAI * radius * radius;
	volume = 3.0 / 4 * PAI * radius * radius * radius;
	printf ("Superficial Area: %f\nVolume: %f\n\n", SuperficialArea, volume);
	
	return 0;
}
