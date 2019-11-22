//
//  main.c
//  Vigenere Cipher
//
//  Created by william on 2019/9/24.
//  Copyright © 2019 William. All rights reserved.
//

#include <stdio.h>

int stringInput(char in[100]) {
    int Length = 0;
    for (Length=0 ; ; Length++) {
        scanf("%c", &in[Length]);
        
        if (!(in[Length]>=0&&in[Length]<=126))
            Length--;
        
        if (in[Length]=='\n' || in[Length]==' ' || in[Length]=='\t') {
            in[Length] = '\0';
            break;
        }
        if (Length>98) break;
    }
    return Length;
}

int main(void) {
    char PlainText[100];
    char CryptedText[100];
    char Keyword[20];
    int PlainTextSize=0, KeywordSize=0;
    printf("Input Plain Text > \n");
    stringInput(PlainText);
    printf("Input Keyword > \n");
    stringInput(Keyword);
    
    for (int i=0 ; PlainText[i]!='\0' ; i++)
        PlainTextSize++;
    
    for (int i=0 ; Keyword[i]!='\0' ; i++)
        KeywordSize++;
    
    printf ("Plain Text : \n");
    puts(PlainText);
    
    printf ("Keychain : \n");
    for (int i=0 ; PlainText[i]!='\0' ; i++)
        printf ("%c", Keyword[i%KeywordSize]);
    
    printf ("\n");
    
    for (int i=0 ; PlainText[i]!='\0' ; i++)
        CryptedText[i] = (((PlainText[i]-97) + (Keyword[i%KeywordSize]-97))%26) + 97;
    printf("Encycrypted Text : \n");
    puts(CryptedText);
    
    for (int i=0 ; CryptedText[i]!='\0' ; i++) {
        PlainText[i] = (((CryptedText[i]-97) - (Keyword[i%KeywordSize]-97)+26)%26) + 97;
//        BUG: CryptedText[i]<Keyword[i%KeywordSize]
//        printf("%d ", (CryptedText[i]-97));
    }
    
    printf("Decrypted plain Text : \n");
    puts(PlainText);
    
    return 0;
}
