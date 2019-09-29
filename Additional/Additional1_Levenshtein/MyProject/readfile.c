#include <stdio.h>

/*
 Read a text file line per line
 Each line will be read in a 100(99)-character array
 */
int main() {
    FILE* vocabulary = fopen("../words.txt", "r");
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

//int readVocabulary
