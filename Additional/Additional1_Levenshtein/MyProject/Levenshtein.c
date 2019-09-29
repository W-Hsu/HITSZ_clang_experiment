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
 input a 50-character-string
 returns length of the string
 */
int stringInput(char in[50]) {
    int Length = 0;
    for (Length=0 ; ; Length++) {
        scanf("%c", &in[Length]);
        
        if (!(in[Length]>=0&&in[Length]<=126))
            Length--;
        
        if (in[Length]=='\n' || in[Length]==' ' || in[Length]=='\t') {
            in[Length] = '\0';
            break;
        }
        if (Length>48) break;
    }
    fflush(stdin);
    return Length;
}

/*
 Calculate The Levenshtein distance of A and B
 */
int Levenshtein(char* A, int Alength, char* B, int Blength) {
	int i=0, j=0;
	
	int Levenshtein[WORDS_LEN+1][WORDS_LEN+1];
    
    for (i=0 ; i<=Alength ; i++) Levenshtein[i][0] = i;
    for (j=0 ; j<=Blength ; j++) Levenshtein[0][j] = j;
    
//    for (i=0 ; i<=Alength ; i++) {
//        for (j=0 ; j<=Blength ; j++) {
//            printf ("%2d", Levenshtein[i][j]);
//        }
//        putchar('\n');
//    }
    
    for (i=1 ; i<=Alength ; i++) for (j=1 ; j<=Blength ; j++) {
        if (A[i]==B[j]) Levenshtein[i][j] = min(Levenshtein[i-1][j]+1, Levenshtein[i][j-1]+1, Levenshtein[i-1][j-1]);
        else Levenshtein[i][j] = min(Levenshtein[i-1][j]+1, Levenshtein[i][j-1]+1, Levenshtein[i-1][j-1]+1);
    }
    
    return Levenshtein[Alength][Blength];
}

int main() {
    char S[50], T[50];
    int Slen = stringInput(S);
    int Tlen = stringInput(T);
    
    int k=0, l=0;
//    for (k=0 ; putchar(S[k])!='\0' ; k++);
//    for (k=0 ; putchar(T[k])!='\0' ; k++);
    
    printf("%d", Levenshtein(S, Slen, T, Tlen));
    
    return 0;
}
