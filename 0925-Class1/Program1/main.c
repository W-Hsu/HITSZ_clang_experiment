#include <stdio.h>
#include <stdlib.h>

const int Number = 190110728;
const int Subject = 1;

int main()
{
    printf("Number:%d\nSubject:%d\n\n", Number, Subject);

    char A=0;
    short B=0;
    int C=0;
    short int D=0;
    float E=0;
    double F=0;

    printf("Please input char A:");
    scanf("%c", &A);
    printf ("char A = \'%c\', size of char is %lu\n", A, sizeof(A));
    while (getchar()!='\n');

    printf("Please input short B:");
    scanf("%hd", &B);
    printf ("short B = %hd, size of short is %lu\n", B, sizeof(B));
    while (getchar()!='\n');

    printf("Please input int:");
    scanf("%d", &C);
    printf ("int C = %d, size of int is %lu\n", C, sizeof(C));
    while (getchar()!='\n');

    printf("Please input short int:");
    scanf("%hd", &D);
    printf ("short int D = %hd, size of short int is %lu\n", D, sizeof(D));
    while (getchar()!='\n');

    printf("Please input float:");
    scanf("%f", &E);
    printf ("float E = %.2f, size of float is %lu\n", E, sizeof(E));
    while (getchar()!='\n');

    printf("Please input double:");
    scanf("%lf", &F);
    printf ("double F = %.2f, size of double is %lu\n", F, sizeof(F));
    while (getchar()!='\n');

    return 0;
}
