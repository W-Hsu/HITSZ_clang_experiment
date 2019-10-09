#include <stdio.h>

int main() {
    printf("Number:190110728\n");
    printf("Subject No.3 - Program No.3\n\n");
    
    long double sum=1, grain=1;
    int i=0;

    for (i=1 ; i<64 ; i++) {
        grain *= 2;
        sum += grain;
    }

    sum /= 1.42e8;

    printf("%Lf\n", sum);
    return 0;
}
