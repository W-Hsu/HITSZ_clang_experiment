#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "wstring.h"

struct wString {
	char* get;
	int size;
    int buffer;
	int length;
	int wPointer;
};

typedef struct wString wString;


/*
 initialize the string with an 15-byte memory area.
 initialize the basic metas.
 */
void wInitString(wString* s, int bufferSize) {
	s -> get = malloc(STRING_INIT_LEN);
	s -> size = STRING_INIT_LEN;
    s -> buffer = bufferSize;
	s -> length = 0;
	s -> wPointer = 0;
}

/*
 resize the string according to its length
 */
void wFitSize(wString* s) {
    s->get = realloc(s->get, s->length+1);
}

/*
 Add buffer in order to improve the efficiency of inputting
 */
void wAddMem(wString* s) {
    s->get = realloc(s->get, s->size+s->buffer);
    s->size += s->buffer;
}

/*
 input a string
 */
void wInputString(wString* s) {
    char buffer = '\0';
    bool loop = true;
	while(loop) {
		if (s->wPointer==s->size-2) wAddMem(s); /* allocate buffer */

		buffer = getchar(); /* input */

        /*
         see whether it is an ASCII char:
            if so, increase the wPointer position.
            if not, do nothing and goes to the next loop.
         */
		if (buffer<0 || buffer>127) continue;
        else if (buffer!='\n' && buffer!='\t') s->get[s->wPointer++] = buffer;
        else loop=false;
        
        /* now, the wPointer position changes to the next char */
        
        if (s->wPointer+1 > s->length) {
            s->length++; /* if went beyond the end, update the length */
            if (!loop) s->get[s->wPointer] = '\0'; /* if input ends, add '\0' to the end */
        }
	}
    wFitSize(s);
}

/*
 output a string
 */
void wOutputString(wString* s) {
	int i=0;
	for (i=0 ; s->get[i]!='\0' ; i++) printf("%c", s->get[i]);
	putchar('\n');
}

/*
 show the string wPointer position
 example:
    This is a testing string.
                             ^
 */
void wShowPointerPos(wString* s) {
	int i=0;
	wOutputString(s);
	for (i=0 ; i<s->wPointer ; i++) putchar(' ');
	putchar('^');
    putchar('\n');
}

void wSetwPointerPos_end(wString* s) {
    s -> wPointer = s->length+1;
}

void wSetwPointerPos_begin(wString* s) {
    s -> wPointer = 0;
}

void wSetwPointerPos(wString* s) {
	fflush(stdin);
	int origwPointerPos = s->wPointer;
	while (true) {
		char movement='a';
		wShowPointerPos(s);
		movement = getchar();
		while (getchar()!='\n');

		if (movement=='a' && s->wPointer>0) s->wPointer--;
		else if (movement=='d' && s->wPointer < s->size) s->wPointer++;
		else if (movement=='s') {
			s->wPointer = origwPointerPos;
			printf("Write Pointer has been reset.");
		}
		else if (movement=='w') {
			printf("Write pointer position updated successfully.\n");
			break;
		}
		putchar('\n');
	}
	
}

void wSetwPointerPos_Pattern(wString* s, char* const c) {
	int i=0, j=0;
	bool flag = false;
	for (i=0 ; i<s->length && !flag ; i++) {
		for (j=0 ; c[j]!='\0' ; j++) {
			if (c[j]=='.') flag = true;
			else if (s->get[i+j]!=c[j]) {
				flag = false;
				break;
			}
			flag = true;	
		}
	}
	if (flag) {
		s->wPointer = --i;
		printf("Pattern \"%s\" Matched.\n", c);
		wShowPointerPos(s);
	}
	else {
		printf("Pattern Unmatched.\n");
		wShowPointerPos(s);
	}
}

void wSetString(wString* s, const char* src) {
	int i=0, srcSize=0;
	for (srcSize=0 ; src[srcSize]!='\0' ; srcSize++);
    if (srcSize > s->size) {
        s->get = realloc(s->get, srcSize);
        s->size = srcSize;
    }
	for (i=0 ; src[i]!='\0' ; i++) s->get[i] = src[i]; 
	s -> get[i] = '\0';
	s -> length = i;
	s -> wPointer = i;
}

void wFreeStringMem(wString* s) {
	free(s->get);
}

void wClearString(wString* s) {
    wFreeStringMem(s);
    wInitString(s, s->buffer);
}
