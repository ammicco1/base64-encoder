#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* the function returns an array that contains the binary number, on the index 0 there's the lenght of the number */

int *binary_enc(int n){
    int i, j, l = 0, tmp = n;
    int *bin, *tmp_a;

    for(i = 0; tmp > 0; i++){    
        tmp = tmp / 2; 
        l++;   
    }    

    bin = malloc(sizeof(int) * (l + 1));
    if(bin == NULL){
        return NULL;
    }

    tmp_a = malloc(sizeof(int) * (l + 1));
    if(tmp_a == NULL){
        return NULL;
    }

    bin[0] = l;

    tmp = n;

    for(i = 0; n > 0; i++){
        tmp_a[i] = n % 2;    
        n = n / 2;    
    }

    j = l - 1;

    for(i = 1; i <= l; i++){
        bin[i] = tmp_a[j];    
        j--; 
    }

    return bin;
}

int binary_dec(int bin[], int l){
    int i, j = 0, num = 0; 

    for(i = l - 1; i >= 0; i--){
        num += bin[i] * pow(2, j);
        j++;
    }

    return num;
}

int *to_ascii(int n[], int l){
    int i, j = 1;
    int *ascii = malloc(sizeof(int) * 8);
    if(ascii == NULL){
        return NULL;
    }

    for(i = 0; i < 8; i++){
        ascii[i] = 0;
    }

    for(i = 8 - l; i < 8; i++){
        ascii[i] = n[j];
        j++;
    }

    return ascii;
}