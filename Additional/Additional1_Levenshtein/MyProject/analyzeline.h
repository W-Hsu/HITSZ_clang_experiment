#ifndef analyzeline_h
#define analyzeline_h
//#include "GlobalVariables.h"

/*
Analyze a string patterned "XXXX YYYY/ZZZZ/AAAA/BBBB"
XXXX will be considered as line number, WORDS_PER_LINE characters at most
YYYY, ZZZZ, AAAA, BBBB will be considered as words, WORDS_LEN words at most and WORDS_PER_LINE characters per word at most (including '\0')
Returns the pointer -> first element of an char[WORDS_PER_LINE+1][WORDS_LEN] array
   array[0][*] stores Line Number
   array[1][*] ~ array[WORDS_LEN-1][*] contains words, if (No Words) the first element will be set to '\0'
*/

char** analyzeLine(char* inputLineString);
#endif
