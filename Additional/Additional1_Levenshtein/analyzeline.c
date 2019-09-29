#include <stdio.h>

const int LINENUM_LEN = 6;
const int WORDS_PER_LINE = 5;
const int WORDS_LEN = 15;

int main() {
	int i=0, j=0;
	char lineNumber[LINENUM_LEN];
	char words[WORDS_PER_LINE][WORDS_LEN];
    for (i=0 ; i<WORDS_PER_LINE ; i++) words[i][0]='\0';
    
    for (i=0 ; i<LINENUM_LEN ; ++i) {
		scanf("%c", &lineNumber[i]);
        if (lineNumber[i]==' ') {
            lineNumber[i] = '\0';
            break;
        }
//        printf("1.%d\n", i);
    }

	for (i=0 ; i<WORDS_PER_LINE ; i++)
		for (j=0 ; j<WORDS_LEN ; j++) {
			scanf("%c", &words[i][j]);
        	
        	if (!(words[i][j]>=0&&words[i][j]<=126))
            	j--;
        
        	if (words[i][j]=='\n') {
            	words[i][j] = '\0';
            	goto READ_LOOP_END;
        	}
			else if (words[i][j]=='/') {
                words[i][j] = '\0';
				break;
			}
		}
READ_LOOP_END:
    putchar('\n');
    putchar('\n');
    
    for (i=0 ; lineNumber[i]!='\0' ; i++)
        putchar(lineNumber[i]);
    putchar('\n');
    putchar('\n');
    
    for (i=0 ; i<WORDS_PER_LINE ; i++) {
        if (words[i][0] == '\0') break;
		for (j=0 ; words[i][j]!='\0' ; j++) {
			putchar(words[i][j]);
		}
        putchar('\n');
    }
	return 0;
			
}

