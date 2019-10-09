#include <stdio.h>
#include "wstring.h"

int min(int a, int b, int c);

/*
 Calculate The Levenshtein distance of s1 and s2
 */
int Levenshtein(wString* s1, wString* s2);

int main() {
    freopen("/Users/willxu/Programming/HITSZ_clang_experiment/Additional/Additional1_Levenshtein/Material/words.txt", "r", stdin);
    int i=0;
    wString String1, LineNum, words[5];
    wInitString(&String1, 10);
    wInitString(&LineNum, 5);
    for(i=0 ; i<5 ; i++) wInitString(&words[i], 5);
    
    while (i++<50) {
        wClearString(&String1);
        wInputString(&String1);
        wOutputString(&String1);
    }
    
    wFreeStringMem(&String1);
    wFreeStringMem(&LineNum);
    for(i=0 ; i<5 ; i++) FreeStringMem(&words[i]);
    
    return 0;
}

int min(int a, int b, int c) {
    int minimum = 0;
    if (a>=b) {
        if (b>=c)
            return c;
        else
            return b;
    }
    else {
        if (a>=c)
            return c;
        else
            return a;
    }
}

/*
 Calculate The Levenshtein distance of A and B
 */
int Levenshtein(wString* s1, wString* s2) {
    int i=0, j=0;
    
    int Levenshtein[s1->length+1][s2->length+1];
    
    for (i=0 ; i<=s1->length ; i++) Levenshtein[i][0] = i;
    for (j=0 ; j<=s2->length ; j++) Levenshtein[0][j] = j;
    
    for (i=1 ; i<=s1->length ; i++) for (j=1 ; j<=s2->length ; j++) {
        if (s1->get[i]==s2->get[j]) Levenshtein[i][j] = min(Levenshtein[i-1][j]+1, Levenshtein[i][j-1]+1, Levenshtein[i-1][j-1]);
        else Levenshtein[i][j] = min(Levenshtein[i-1][j]+1, Levenshtein[i][j-1]+1, Levenshtein[i-1][j-1]+1);
    }
    
    return Levenshtein[s1->length][s2->length];
}
