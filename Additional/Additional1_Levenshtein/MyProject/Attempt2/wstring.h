#ifndef wstring_h
#define wstring_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const int STRING_INIT_LEN = 15;
//const int MEM_BUFFERSIZE = 10;

struct wString;

typedef struct wString wString;

void wInitString(wString* s, int bufferSize);

void wFitSize(wString* s);

void wAddMem(wString* s);

void wInputString(wString* s);

void wOutputString(wString* s);

void wShowPointerPos(wString* s);

void wSetPointerPos_end(wString* s);

void wSetPointerPos_begin(wString* s);

void wSetPointerPos(wString* s);

void wSetPointerPos_Pattern(wString* s, char* const c);

void wSetString(wString* s, const char* src);

char* const getLoc(wString* s);

void wFreeStringMem(wString* s);

void wClearString(wString* s);

#endif
