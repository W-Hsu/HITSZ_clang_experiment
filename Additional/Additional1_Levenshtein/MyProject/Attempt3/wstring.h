#ifndef wstring_h
#define wstring_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const int STRING_INIT_LEN = 15;

struct wString {
    char* get;
    int size;
    int buffer;
    int length;
    int wPointer;
    int rPointer;
};

typedef struct wString wString;

/*
 Update Metadata [ST]
 update metadata of a wString
 Not Complete Yet
 */
//void wUpdateMetas(wString* s) {
//
//}

void wPointerReset(wString* dst);

/* Basic Memory Operations */
/* /////////////////////// */
/* /////////////////////// */
/* /////////////////////// */

/*
 Resize: [ST]
 resize the string according to a given int (i.e. newSize)
 if the resized string container can't hold the original string, it's possible to lose data
 if pointers are larger than new size, then put them at the tail '\0'
 */
void wResize(wString* s, int newSize);

/*
 Fit Size: [DP] wResize
 resize the string according to its length
 */
void wFitSize(wString* s);

/*
 Add Memory: [DP] wResize
 add buffer in order to improve the efficiency of inputting
 */
void wAddMem(wString* s);

/* Constructors and Destructors */
/* //////////////////////////// */
/* //////////////////////////// */
/* //////////////////////////// */

/*
 Constructor 0: Initializer [ST]
 initialize the string with an 15-byte memory area.
 initialize the basic metas.
 */
void wInitString(wString* s, int bufferSize);

/*
 Constructor 1: Copyer [DP] wResize
 copy the contents and pointer position from src to dst
 dst will be resized as src
 */
void wCopyString(wString* dst, wString* src);

/*
 Constructor 2: Converter [DP] wResize
 */
void wSetString(wString* s, const char* src);

/*
 Destructor 0: [ST]
 free the memory allocated by Constructor in a wString
 !! IMPORTANT !!
 !! always explicitly call destructor before the program ends !!
 !! THIS IS NOT CPP !!
 */
void wFreeStringMem(wString* s);

/*
 Reconstructor: [DP] wFreeStringMem wInitString
 destroy the original char* and initialize another one
 */
void wClearString(wString* s);

/* Basic String Operations */
/* /////////////////////// */
/* /////////////////////// */
/* /////////////////////// */

char wPeek(wString* s, int offset);

void wInputString(wString* s);

void wInputString_fromFile(wString* s, FILE* fp);

/*
 Append String from stdin: [DP] wAddMem wFitSize
 */
void wAppString(wString* s);
/*
 Output String to stdout: [ST]
 output a string according to read pointer position
 */
void wOutputString(wString* s);

/*
 Output the Whole String to stdout: [ST]
 output the whole string regardless of read pointer position
 */
void wOutputString_all(wString* s);

/*
 Put a wString's substring into another wString: [DP] wResize wFitSize
 consider source's read pointer
 ignore destination's write pointer
 */
void wSubString(wString* src, wString* dst, int len);

bool wSubString_nextChar(wString* src, wString* dst, char end)

/*
 Peek the char Read Pointer now pointing: [ST]
 returns the char
 */

/* Pointer Operations */
/* ////////////////// */
/* ////////////////// */
/* ////////////////// */

/*
 Show the String rwPointer Position: [DP] wOutputString_all
 example:
    This is a testing string.
    r                        w
 or(r&w at the same position):
    This is a testing string.
              ^
 */
void wShowPointerPos(wString* s);
/*
 Set Write Pointer position: [ST]
 */
bool wSetwPointerPos(wString* s, int newPos);

/*
 Set Read Pointer position: [ST]
 */
bool wSetrPointerPos(wString* s, int newPos);

/*
 Set Write Pointer position manually: [DP] wShowPointerPos
 'a': move right
 'd': move left
 's': reset to original position
 'w': save and exit
 */
void wSetwPointerPos_Manual(wString* s);
/*
 Set Write Pointer position by searching a pattern: [DP] wShowPointerPos
 pointer will be set to the first character of the pattern
 use '.' to replace any one of the characters
 */
bool wSetwPointerPos_Pattern(wString* s, char* const c);

/*
 Set Read Pointer position manually: [DP] wShowPointerPos
 'a': move right
 'd': move left
 's': reset to original position
 'w': save and exit
 */
void wSetrPointerPos_Manual(wString* s);

/*
 Set Read Pointer position by searching a pattern: [DP] wShowPointerPos
 pointer will be set to the first character of the pattern
 use '.' to replace any one of the characters
 */
bool wSetrPointerPos_Pattern(wString* s, char* const c);
#endif
