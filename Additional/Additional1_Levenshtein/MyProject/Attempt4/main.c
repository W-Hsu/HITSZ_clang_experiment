#include "tree.h"

#include <string.h>
#include <stdbool.h>
#include <limits.h>

int min(int, int, int);

int Levenshtein(char*, char*);

int main() {
    tree *root = malloc(sizeof(tree));
    root->childQuantity = 0;
    addWord("../../Material/vocabulary.txt", root);
    
    FILE* fp_words = fopen("../../Material/words.txt", "r");
    FILE* fp_corr = fopen("../../Material/correction.txt", "w");
    
    while (!feof(fp_words)) {
        char oneLine[100] = {0};
        fgets(oneLine, 100, fp_words);
        
        char *pch = NULL;
        pch = strtok(oneLine, " /\n");
        int time = 0;
        while (pch != NULL)
        {
            int i=0;
            while (pch[i++]!='\0') if (pch[i]<0||pch[i]>127) goto NEXTWORD;
            
            if (SearchDict(root, pch)>0 || time==0) {
                if (time==0) fprintf (fp_corr, "%s ", pch);
                else if (time==1) fprintf (fp_corr, "%s ", pch);
                else fprintf(fp_corr, "%s/",pch);
                time++;
                continue;
            }
            
            int min = INT_MAX;
            char remember_entry[100] = {0};
            FILE *fp_vocab = fopen("../../Material/vocabulary.txt", "r");
            while(!feof(fp_vocab)) {
                char entry[100] = {0};
                
                fgets(entry, 100, fp_vocab);
                entry[strlen(entry)-1] = '\0';
                
                int now = Levenshtein(entry, pch);
                if (min>now) {
                    min = now;
                    strcpy(remember_entry, entry);
                }
                
                if (min==1) break;
            }
            if (time==1) fprintf (fp_corr, "%s ", remember_entry);
            else fprintf(fp_corr, "%s/",remember_entry);
            time++;
            
        NEXTWORD:
            pch = strtok(NULL, " /\n");
        }
    NEXTLINE:;
    }
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

int Levenshtein(char* A, char* B) {
    int i=0, j=0;
    int Alength = strlen(A), Blength = strlen(B);
    
    int Levenshtein[100][100];
    
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
