#include "base64_enc.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    char *base64;
    char str[__MAX_LEN__];

    while(1){
        printf("\n---------------------------------------------\n");
        printf("\nINSERT THE STRING TO ENCODE: "); fgets(str, __MAX_LEN__, stdin);
        printf("\n---------------------------------------------\n");

        base64 = encode_base64(str);

        printf("\nYOUR STRING: %s\nBASE64 STRING: %s\n", str, base64);
    } 

    return 0;
}
