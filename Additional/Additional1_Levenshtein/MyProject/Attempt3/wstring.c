

/*
 Update Metadata [ST]
 update metadata of a wString
 Not Complete Yet
 */
//void wUpdateMetas(wString* s) {
//
//}

void wPointerReset(wString* dst) {
    dst -> rPointer = 0;
    dst -> wPointer = dst -> length;
}

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
void wResize(wString* s, int newSize) {
    s->get = realloc(s->get, newSize);
    s->size = newSize;
    
    if (s->length+1 > s->size) {
        s->length = s->size-1;
        s->get[s->length] = '\0';
    }
    
    if (s->wPointer > s->length) {
        s->wPointer = s->length;
    }
    
    if (s->rPointer > s->length) {
        s->rPointer = s->length;
    }
}

/*
 Fit Size: [DP] wResize
 resize the string according to its length
 */
void wFitSize(wString* s) {
    wResize(s, s->length+1);
}

/*
 Add Memory: [DP] wResize
 add buffer in order to improve the efficiency of inputting
 */
void wAddMem(wString* s) {
    wResize(s, s->size+s->buffer);
}

/* Constructors and Destructors */
/* //////////////////////////// */
/* //////////////////////////// */
/* //////////////////////////// */

/*
 Constructor 0: Initializer [ST]
 initialize the string with an 15-byte memory area.
 initialize the basic metas.
 */
void wInitString(wString* s, int bufferSize) {
    s -> get = malloc(STRING_INIT_LEN);
    s -> size = STRING_INIT_LEN;
    s -> buffer = bufferSize;
    s -> length = 0;
    s -> wPointer = 0;
    s -> rPointer = 0;
}

/*
 Constructor 1: Copyer [DP] wResize
 copy the contents and pointer position from src to dst
 dst will be resized as src
 */
void wCopyString(wString* dst, wString* src) {
    wResize(dst, src->size);
    strcpy(dst->get, src->get);
    dst->wPointer = src->wPointer;
    dst->rPointer = src->rPointer;
}

/*
 Constructor 2: Converter [DP] wResize
 */
void wSetString(wString* s, const char* src) {
    int i=0, srcSize=0;
    for (srcSize=0 ; src[srcSize]!='\0' ; srcSize++);
    wResize(s, srcSize);
    
    for (i=0 ; src[i]!='\0' ; i++) s->get[i] = src[i];
    s -> get[i] = '\0';
    s -> length = i;
    s -> wPointer = i;
    s -> rPointer = 0;
}

/*
 Destructor 0: [ST]
 free the memory allocated by Constructor in a wString
 !! IMPORTANT !!
 !! always explicitly call destructor before the program ends !!
 !! THIS IS NOT CPP !!
 */
void wFreeStringMem(wString* s) {
    free(s->get);
}

/*
 Reconstructor: [DP] wFreeStringMem wInitString
 destroy the original char* and initialize another one
 */
void wClearString(wString* s) {
    wFreeStringMem(s);
    wInitString(s, s->buffer);
}

/* Basic String Operations */
/* /////////////////////// */
/* /////////////////////// */
/* /////////////////////// */

char wPeek(wString* s, int offset) {
    if (s->rPointer+offset < 0) return '\0';
    else if (s->rPointer+offset > s->length) return '\0';
    else return s->get[s->rPointer+offset];
}

void wInputString(wString* s) {
    char buffer = '\0';
    bool loop = true;
    while(loop) {
        if (s->wPointer>=s->size-2) wAddMem(s); /* allocate buffer */

        buffer = getchar(); /* input */

        /*
         see whether it is an ASCII char:
            if so, write to the current wPointer position and immediately increase the wPointer position.
            if not, do nothing and goes to the next loop.
			if read '\n' or '\t', the loop will not go on.
         */
        if (buffer<0 || buffer>127) continue;
        else if (buffer!='\n' && buffer!='\t') s->get[s->wPointer++] = buffer;
        else {
            loop=false;
            s->wPointer++;
        }
        
        /* now, the wPointer position changes to the next char */

		if (!loop) {
            s->get[--s->wPointer] = '\0'; /* if input ends, put '\0' at the end */
			s->length = s->wPointer;
		}
    }
    wFitSize(s);
}

void wInputString_fromFile(wString* s, FILE* fp) {
    char buffer = '\0';
    bool loop = true;
    while(loop) {
        if (s->wPointer>=s->size-2) wAddMem(s); /* allocate buffer */

        buffer = fgetc(fp); /* input */

        /*
         see whether it is an ASCII char:
            if so, write to the current wPointer position and immediately increase the wPointer position.
            if not, do nothing and goes to the next loop.
            if read '\n' or '\t', the loop will not go on.
         */
        if (buffer<0 || buffer>127) continue;
        else if (buffer!='\n' && buffer!='\t') s->get[s->wPointer++] = buffer;
        else {
            loop=false;
            s->wPointer++;
        }
        
        /* now, the wPointer position changes to the next char */

        if (!loop) {
            s->get[--s->wPointer] = '\0'; /* if input ends, put '\0' at the end */
            s->length = s->wPointer;
        }
    }
    wFitSize(s);
}

/*
 Append String from stdin: [DP] wAddMem wFitSize
 */
void wAppString(wString* s) {
    char buffer = '\0';
    bool loop = true;
    while(loop) {
        if (s->wPointer>=s->size-2) wAddMem(s); /* allocate buffer */

        buffer = getchar(); /* input */

        /*
         see whether it is an ASCII char:
            if so, write to the current wPointer position and immediately increase the wPointer position.
            if not, do nothing and goes to the next loop.
			if read '\n' or '\t', the loop will not go on.
         */
        if (buffer<0 || buffer>127) continue;
        else if (buffer!='\n' && buffer!='\t') s->get[s->wPointer++] = buffer;
        else {
            loop=false;
            s->wPointer++;
        }
        
        /* now, the wPointer position changes to the next char */
        
        if (s->wPointer > s->length) {
            s->length++; /* if went beyond the end, update the length */
            if (!loop) s->get[--s->wPointer] = '\0'; /* if input ends, put '\0' at the end */
        }
    }
    wFitSize(s);
}

/*
 Output String to stdout: [ST]
 output a string according to read pointer position
 */
void wOutputString(wString* s) {
    int i=0;
    for (i=s->rPointer ; s->get[i]!='\0' ; i++) printf("%c", s->get[i]);
}

/*
 Output the Whole String to stdout: [ST]
 output the whole string regardless of read pointer position
 */
void wOutputString_all(wString* s) {
    int i=0;
    for (i=0 ; s->get[i]!='\0' ; i++) printf("%c", s->get[i]);
}

/*
 Put a wString's substring into another wString: [DP] wResize wFitSize
 consider source's read pointer
 ignore destination's write pointer
 */
void wSubString(wString* src, wString* dst, int len) {
    int i=0, j=0;
    wResize(dst, len+1);
    for (i=src->rPointer ; i<src->length&&i<src->rPointer+len ; i++,j++) {
        dst->get[j] = src->get[i];
    }
    src -> rPointer = i;
    dst -> length = j;
    wPointerReset(dst);
    wFitSize(dst);
}

bool wSubString_nextChar(wString* src, wString* dst, char end) {
    int i=0, j=0;
    
    for (i=0 ; wPeek(src, i)!=end && wPeek(src, i)!='\0' ; i++);
    
    if (i==0) return false;
    else {
        wSubString(src, dst, i);
        return true;
    }
}

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
void wShowPointerPos(wString* s) {
    int i=0, showedPointerNum=0;
    wOutputString_all(s);
    putchar('\n');
    for (i=0 ; i<s->length/*??*/ || showedPointerNum!=2 ; i++) {
        if (i==s->rPointer && i==s->wPointer)  {
            putchar('^');
            showedPointerNum = 2;
        }
        else if (i==s->rPointer) {
            putchar('r');
            showedPointerNum += 1;
        }
        else if (i==s->wPointer) {
            putchar('w');
            showedPointerNum += 1;
        }
        else putchar(' ');
    }
    putchar('\n');
}

/*
 Set Write Pointer position: [ST]
 */
bool wSetwPointerPos(wString* s, int newPos) {
    if (newPos > s->length) return false;
    else {
        s -> wPointer = newPos;
        return true;
    }
}

/*
 Set Read Pointer position: [ST]
 */
bool wSetrPointerPos(wString* s, int newPos) {
    if (newPos > s->length) return false;
    else {
        s -> rPointer = newPos;
        return true;
    }
}

/*
 Set Write Pointer position manually: [DP] wShowPointerPos
 'a': move right
 'd': move left
 's': reset to original position
 'w': save and exit
 */
void wSetwPointerPos_Manual(wString* s) {
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

/*
 Set Write Pointer position by searching a pattern: [DP] wShowPointerPos
 pointer will be set to the first character of the pattern
 use '.' to replace any one of the characters
 */
bool wSetwPointerPos_Pattern(wString* s, char* const c) {
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
        return true;
    }
    else {
        return false;
    }
}

/*
 Set Read Pointer position manually: [DP] wShowPointerPos
 'a': move right
 'd': move left
 's': reset to original position
 'w': save and exit
 */
void wSetrPointerPos_Manual(wString* s) {
    fflush(stdin);
    int origrPointerPos = s->rPointer;
    while (true) {
        char movement='a';
        wShowPointerPos(s);
        movement = getchar();
        while (getchar()!='\n');

        if (movement=='a' && s->rPointer>0) s->rPointer--;
        else if (movement=='d' && s->rPointer < s->size) s->rPointer++;
        else if (movement=='s') {
            s->rPointer = origrPointerPos;
            printf("Read Pointer has been reset.");
        }
        else if (movement=='w') {
            printf("Read pointer position updated successfully.\n");
            break;
        }
        putchar('\n');
    }
    
}

/*
 Set Read Pointer position by searching a pattern: [DP] wShowPointerPos
 pointer will be set to the first character of the pattern
 use '.' to replace any one of the characters
 */
bool wSetrPointerPos_Pattern(wString* s, char* const c) {
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
        s->rPointer = --i;
        return true;
    }
    else {
        return false;
    }
}
