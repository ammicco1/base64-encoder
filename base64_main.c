#include "base64_enc.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    char *base64, *decoded;
    char str[__MAX_LEN__], str64[__MAX_64_LEN__], path[60];
    int choise;
    FILE *file; 

    while(1){
        printf("\n---------------------------------------------\n");
        printf("\nWHAT DO YOU WANT TO DO?\n");
        printf("\t- 1:  ENCODE A STRING IN BASE64\n");
        printf("\t- 2:  DECODE A BASE64 STRING\n");
        printf("\t- 3:  DECODE A FILE\n");
        printf("\n---------------------------------------------\n");

        scanf(" %d", &choise); fflush(stdin);

        switch(choise){
            case 1: printf("\nINSERT THE STRING TO ENCODE: "); scanf("%[^\n]", str);
                    base64 = encode_base64(str); printf("\nYOUR STRING: %s\nBASE64 STRING: %s\n", str, base64); break;
            case 2: printf("\nINSER THE STRING TO DECODE: "); scanf("%s", str64);
                    decoded = decode_base64(str64); printf("\nBASE64 ENCODED STRING: %s\nDECODED STRING: %s\n", str64, decoded); break;
            case 3: printf("\nINSERT THE PATH OF THE FILE: "); scanf("%[^\n]", path); file = fopen(path, "r");
                    while(!feof(file)){
                        fscanf(file, "%s", str64); 
                        decoded = decode_base64(str64);
                        printf("%s\n", decoded);
                    } break;
            default: printf("WRONG CHOISE"); break;
        }
    } 

    return 0;
}