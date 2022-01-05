#include "base64_enc.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    char *base64, *decoded;
    char str[__MAX_LEN__], tmp[__MAX_LEN__], tmp64[__MAX_64_LEN__], str64[__MAX_64_LEN__];
    int choise, i;

    while(1){
        printf("\n---------------------------------------------\n");
        printf("\nWHAT DO YOU WANT TO DO?\n");
        printf("\t- 1:  ENCODE A STRING IN BASE64\n");
        printf("\t- 2:  DECODE A BASE64 STRING\n");
        printf("\n---------------------------------------------\n");

        scanf(" %d", &choise); fflush(stdin);

        switch(choise){
            case 1: printf("\nINSERT THE STRING TO ENCODE: "); fgets(tmp, __MAX_LEN__, stdin); for(i = 0; i < str_len(tmp) - 1; i++){str[i] = tmp[i];}
                    base64 = encode_base64(str); printf("\nYOUR STRING: %s\nBASE64 STRING: %s\n", str, base64); break;
            case 2: printf("\nINSER THE STRING TO DECODE: "); fgets(tmp64, __MAX_64_LEN__, stdin); for(i = 0; i < str_len(tmp64) - 1; i++){str64[i] = tmp64[i];}
                    decoded = decode_base64(str64); printf("\nBASE64 ENCODED STRING: %s\nDECODED STRING: %s\n", str64, decoded); break;
            default: printf("WRONG CHOISE"); break;
        }
    } 

    return 0;
}
