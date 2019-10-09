#ifndef Levenshtein_h
#define Levenshtein_h

/*
 returns the smallest in the three
 */
int min(int a, int b, int c);

/*
 input a 50-character-string
 returns length of the string
 */
int stringInput(char in[50]);

/*
 Calculate The Levenshtein distance of A and B
 */
int Levenshtein(char A[50], int Alength, char B[50], int Blength);

#endif
