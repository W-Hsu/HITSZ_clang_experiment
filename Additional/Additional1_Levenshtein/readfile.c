#include <stdio.h>

int main() {
    FILE* vocabulary = fopen("./words.txt", "r");
    while (!feof(vocabulary)) {
        char c[100];
        int i=0;
        fgets(c, 100, vocabulary);
        for (i=0 ; c[i]!='\n' && i<100 ; i++);
        c[i] = '\0';
        printf ("%s\n", c);
    }
    return 0;
}

