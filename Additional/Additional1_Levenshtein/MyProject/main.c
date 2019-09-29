#pragma once
#include <stdio.h>
#include <string.h>
#include "Levenshtein.h"
#include "analyzeline.h"

const int WORDS_PER_LINE_M = 5;
const int WORDS_LEN_M = 20;

void putLine(char words[WORDS_PER_LINE_M+1][WORDS_LEN_M]) {
    int i=0, j=0;
    for (i=0 ; i<WORDS_PER_LINE_M+1 && words[i][0]!='\0' ; i++) {
        if (i=0) {
            for (j=0 ; j<WORDS_LEN_M && words[i][j]!='\0' ; j++) printf ("%c", words[i][j]);
            putchar(' ');
        }
        else {
            if (i!=1) putchar('/');
            for (j=0 ; j<WORDS_LEN_M && words[i][j]!='\0' ; j++) printf ("%c", words[i][j]);
        }
    }
    putchar('\n');
}

int main() {
    FILE* vocabularyFile = fopen("../src/vocabulary.txt", "r");
    FILE* wordsFile = fopen("../src/words.txt", "r");
    freopen("../src/words_correction.txt", "w", stdout);
    
    while (!feof(wordsFile)) {
        /*
         Read a text file line per line
         Each line will be read in a 100(99)-character array
         */
        char rawString[100]; /* Stores the raw string */
        char (*words)[WORDS_LEN_M]; /* Stores the words analyzed */
        int i=0; /* define loop controls */
        
        fgets(rawString, 100, wordsFile);
        
        for (i=0 ; rawString[i]!='\n' && i<100 ; i++); /* Make sure raw string has an end */
        rawString[i] = '\0';
        
        words = analyzeLine(rawString); /* Save the analyzed results */
        
        for (i=1 ; words[i][0]!='\0' || i!=5 ; i++) {
            int Alen=0, Blen=0, minimumEditDistance=4096;
            for (Alen=0 ; words[i][Alen]!='\0' ; Alen++); /* count word's length */
            
            char Nearest[WORDS_LEN_M];
            while (!feof(vocabularyFile) || min!=0) {
                int EditDist=0;
                /* Read Vocabulary one by one */
                char wordInVocabulary[WORDS_LEN_M];
                fgets(wordInVocabulary, WORDS_LEN_M, vocabularyFile);
                for (i=0 ; wordInVocabulary[i]!='\n' && i<WORDS_LEN_M ; i++); /* count word in vocabulary's length */
                wordInVocabulary[i] = '\0';
                
                for (Blen=0 ; wordInVocabulary[Blen]!='\0' ; Blen++);
                
                EditDist = Levenshtein(words, Alen, wordInVocabulary, Blen);
                if (EditDist>=min) continue;
                else if (EditDist=0) minimumEditDistance=0;
                else {
                    minimumEditDistance = EditDist;
                    strcpy(&words[i][0], wordInVocabulary);
                }
            }
            putLine(words);
        }
    }
    return 0;
}

//int readVocabulary
