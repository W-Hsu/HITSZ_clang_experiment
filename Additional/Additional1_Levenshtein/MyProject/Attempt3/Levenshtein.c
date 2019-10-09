#include "Levenshtein.h"

/*
 returns the smallest in the three
 */
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
int Levenshtein(wString* a, wString* b) {
	int i=0, j=0;
	
	int Levenshtein[a->length+1][b->length+1];
    
    for (i=0 ; i<=a->length ; i++) Levenshtein[i][0] = i;
    for (j=0 ; j<=b->length ; j++) Levenshtein[0][j] = j;
    
    for (i=1 ; i<=a->length ; i++) for (j=1 ; j<=b->length ; j++) {
        if (a->get[i]==b->get[j]) Levenshtein[i][j] = min(Levenshtein[i-1][j]+1, Levenshtein[i][j-1]+1, Levenshtein[i-1][j-1]);
        else Levenshtein[i][j] = min(Levenshtein[i-1][j]+1, Levenshtein[i][j-1]+1, Levenshtein[i-1][j-1]+1);
    }
    
    return Levenshtein[a->length][b->length];
}
