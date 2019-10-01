#include <stdio.h>

int main() {
    char words[2][5];
    char** ptr = words;
    
    printf ("%lld\n", ptr);
    
    scanf ("%c", &ptr[0]);
    
    printf ("%c", ptr[0][0]);
    return 0;
}

//int readVocabulary
