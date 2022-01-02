#include "binary_enc.h"
#include "base64_enc.h"
#include <stdio.h>
#include <stdlib.h>

char alfabeto[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J','K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j','k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
    '+', '/'
};

char *encode_base64(char string[]){
    const int l = str_len(string); /* lenght of the string to encode */ 
    int *tmp, *dec, **six_gr; /* six_gr contains is a matrix that constains the group of 6 bits, dec contains the decimal numbers from those groups */
    int i, j, z = 0, len;
    int bin[l][8]; /* contains all the string in binary */ 
    int tot[l * 8]; /* contains all the string in binary in one line */ 
    char *str; /* final base64 string */

    /* convert all the string in binary and create a matrix with a binary value in an array for all the char in the string */
    for(i = 0; i < l; i++){
        for(j = 0; j < 8; j++){
            tmp = binary_enc((int) string[i]);
            tmp = to_ascii(tmp, tmp[0]);
            bin[i][j] = tmp[j];
        }
    }

    j = -1;

    /* insert all the convertion in a single line */
    for(i = 0; i < l * 8; i++){
        if(i % 8 == 0){
            j++;
            z = 0;
        }
        tot[i] = bin[j][z];
        z++;
    }

    /* calculate how many six groups of bits are necessary */
    len = ((sizeof(tot) / sizeof(int)) / 6);
    if((sizeof(tot) / sizeof(int)) % 6 != 0){
        len++;
    }

    /* allocate the 6group matrix */
    six_gr = (int **) malloc(len * sizeof(int*));
    if(six_gr == NULL){
        return NULL;
    }

    for(i = 0; i < len; i++){
        six_gr[i] = (int *) malloc(6 * sizeof(int));
        if(six_gr[i] == NULL){
            return NULL;
        }
    }

    /* all the matrix initializate to 0 */
    for(i = 0; i < len; i++){
        for(j = 0; j < 6; j++){
            six_gr[i][j] = 0;
        }
    }

    z = 0;

    /* create the six groups */
    for(i = 0; i < len; i++){
        for(j = 0; j < 6; j++){
            if(z == sizeof(tot) / sizeof(int)){
                break;
            }
            six_gr[i][j] = tot[z];
            z++;
        }
    }

    dec = (int *) malloc(sizeof(int) * len);
    if(dec == NULL){
        return NULL;
    }

    /* convert all the 6group in decimal */
    for(i = 0; i < len; i++){
        dec[i] = binary_dec(six_gr[i], 6);
    }

    str = (char *) malloc(sizeof(char) * len);
    if(str == NULL){
        return NULL;
    }

    /* create the base64 string from the alphabet */
    for(i = 0; i < len; i++){
        str[i] = alfabeto[dec[i]];
    }

    return str;
}

int str_len(char string[]){
    int i = 0; 

    while(string[i] != '\0'){
        i++;
    }

    return i;
}