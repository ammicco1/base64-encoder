#include "base64_enc.h"
#include <stdlib.h>
#include <stdio.h>

#define __MAX_PATH__ 60

int main(){
    char *base64, *decoded;
    char str[__MAX_LEN__], str64[__MAX_64_LEN__], path[__MAX_PATH__];
    int choise;
    FILE *file, *wfile; 

    while(1){
        printf("\n---------------------------------------------\n");
        printf("\nWHAT DO YOU WANT TO DO?\n");
        printf("\t- 1:  ENCODE A STRING IN BASE64\n");
        printf("\t- 2:  DECODE A BASE64 STRING\n\n");
        printf("\t- 3:  ENCODE A STRING INTO A FILE\n");
        printf("\t- 4:  DECODE A FILE\n\n");
        printf("\t- 5:  ENCODE A FILE INTO A FILE\n");
        printf("\t- 6:  DECODE A FILE INTO A FILE\n");
        printf("\n---------------------------------------------\n");

        scanf(" %d", &choise); fflush(stdin);

        switch(choise){
            case 1: printf("\nINSERT THE STRING TO ENCODE: "); scanf(" %[^\n]", str);
                    base64 = encode_base64(str); printf("\nYOUR STRING: %s\nBASE64 STRING: %s\n", str, base64); break;
            case 3: printf("\nENCODE INTO A FILE, INSERT THE PATH OF THE FILE: "); scanf(" %[^\n]", path); wfile = fopen(path, "w");
                    printf("\nINSERT THE STRING TO ENCODE: "); scanf(" %[^\n]", str);
                    base64 = encode_base64(str); fprintf(wfile, "%s", base64); fclose(wfile); break;
            case 2: printf("\nINSER THE STRING TO DECODE: "); scanf(" %s", str64);
                    decoded = decode_base64(str64); printf("\nBASE64 ENCODED STRING: %s\nDECODED STRING: %s\n", str64, decoded); break;
            case 4: printf("\nINSERT THE PATH OF THE FILE: "); scanf(" %[^\n]", path); file = fopen(path, "r");
                    while(!feof(file)){
                        fscanf(file, " %s", str64);
                        decoded = decode_base64(str64);
                        printf("%s\n", decoded);
                    } fclose(file); break;
            case 5: printf("\nINSERT THE PATH OF THE FILE TO ENCODE: "); scanf(" %[^\n]", path); file = fopen(path, "r");
                    printf("INSERT THE PATH OF THE FILE TO WRITE: "); scanf(" %[^\n]", path); wfile = fopen(path, "w");
                    while(!feof(file)){
                        fscanf(file, " %[^\n]", str);
                        base64 = encode_base64(str);
                        fprintf(wfile, "%s", base64);
                    } fclose(file); fclose(wfile); 
                    printf("DONE!"); break;
            case 6: printf("\nINSERT THE PATH OF THE FILE TO DECODE: "); scanf(" %[^\n]", path); file = fopen(path, "r");
                    printf("INSERT THE PATH OF THE FILE TO WRITE: "); scanf(" %[^\n]", path); wfile = fopen(path, "w");
                    while(!feof(file)){
                        fscanf(file, " %s", str64);
                        decoded = decode_base64(str64);
                        fprintf(wfile, "%s", decoded);
                    } fclose(file); fclose(wfile); break;
            default: printf("WRONG CHOISE"); break;
        }
    } 

    return 0;
}