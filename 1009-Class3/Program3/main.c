#include <stdio.h>

int main() {
    long double sum=1, grain=1;
    int i=0;

    for (i=1 ; i<64 ; i++) {
        grain *= 2;
        sum += grain;
    }

    sum /= 1.42e8;

    printf("%Lf", sum);
    return 0;
}
