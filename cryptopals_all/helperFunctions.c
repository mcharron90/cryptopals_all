//
//  helperFunctions.c
//  cryptopals_all
//
//  Created by Matthew Charron on 5/12/18.
//  Copyright © 2018 Matthew Charron. All rights reserved.
//

#include "helperFunctions.h"

void printCharArray (char* in, int len){
    for (int i=0; i < len; i++){
        printf ("%c",in[i]);
    }
    printf ("\n");
}

void print_u8_array (uint8_t* in, int len){
    //convert outval to hex
    for (int i=0; i< len; i++){
        uint8_t val = in[i];
        char output[2];
        for (int j=1; j>=0; j--){
            output[j] = encoding_table_hex [val % 16];
            val = (uint32_t) floor( val / 16);
        }
        for (int j=0; j<2; j++){
            printf ("%c", output[j]);
        }

    }
    printf ("\n");
    
}

uint8_t* convertToBytes (char* in1, int charLength, int* outLength){
    uint8_t val1=0;
    int byteLength = charLength/2;
    *outLength = byteLength;
    uint8_t* byteArray = (uint8_t*) malloc (sizeof (uint8_t) * byteLength);
    
    
    for (int i=0; i< charLength; i+=2){
        for (int j=i; j<(i+2); j++){
            if (in1[j] >= '0' && in1[j] <='9'){
                val1 = (val1 << 4) + (in1[j]-'0');
            } else if (in1[j] >='A' && in1[j] <='F'){
                val1 = (val1 << 4) + (in1[j]-'A' + 10);
            } else if (in1[j] >='a' && in1[j] <='f'){
                val1 = (val1 << 4) + (in1[j]-'a' + 10);
            }
        }
        byteArray[i/2] = val1;
    }
    return byteArray;
    
}
