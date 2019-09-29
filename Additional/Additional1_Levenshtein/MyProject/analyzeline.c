#include "analyzeline.h"
#include "GlobalVariables.h"
/*
 Global Variables WORDS_PER_LINE and WORDS_LEN are defined in "GlobalVariables.h"
 */
/*
 Analyze a string patterned "XXXX YYYY/ZZZZ/AAAA/BBBB"
 XXXX will be considered as line number, WORDS_PER_LINE characters at most
 YYYY, ZZZZ, AAAA, BBBB will be considered as words, WORDS_LEN words at most and WORDS_PER_LINE characters per word at most (including '\0')
 Returns the pointer -> first element of an char[WORDS_PER_LINE+1][WORDS_LEN] array
    array[0][*] stores Line Number
    array[1][*] ~ array[WORDS_LEN-1][*] contains words, if (No Words) the first element will be set to '\0'
 */
char* analyzeLine(char inputLineString[100]) {
	int i=0, j=0; /* declare loop controls */
    int inputLocation = 0; /* "location pointer" of inputLineString */
	char words[WORDS_PER_LINE+1][WORDS_LEN];
    
    for (i=0 ; i<WORDS_PER_LINE ; i++) words[i][0]='\0'; /* initialize the array with '\0' */
    
    for (i=0 ; i<WORDS_LEN ; ++i) {
        words[0][i] = inputLineString[inputLocation++];
        if (words[0][i]==' ') {
            words[0][i] = '\0';
            inputLocation++;
            break;
        }
    }

	for (i=1 ; i<=WORDS_PER_LINE ; i++)
		for (j=0 ; j<WORDS_LEN ; j++) {
            words[i][j] = inputLineString[inputLocation++];
        	
            /* No need, Chinese-char-detect-and-ignore is done when "readfile" */
//        	if (!(words[i][j]>=0&&words[i][j]<=126))
//            	j--;
        
            if (words[i][j]=='\0') {
                goto READ_LOOP_END;
            }
			else if (words[i][j]=='/') {
                words[i][j] = '\0';
				break;
			}
		}
READ_LOOP_END:
    return words;
};
