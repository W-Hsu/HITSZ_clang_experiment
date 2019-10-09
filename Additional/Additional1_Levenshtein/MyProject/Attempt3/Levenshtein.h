#ifndef Levenshtein_h
#define Levenshtein_h
#include "wstring.h"

/*
 returns the smallest in the three
 */
int min(int a, int b, int c);

/*
 Calculate The Levenshtein distance of A and B
 */
int Levenshtein(wString* a, wString* b);

#endif
