//
//  fixedXOR.c
//  cryptopals_all
//
//  Created by Matthew Charron on 5/12/18.
//  Copyright © 2018 Matthew Charron. All rights reserved.
//

#include "fixedXOR.h"


char* xor_two (char* in1, char* in2, int length){
    char* output;
    
    if (length %2 !=0){
        return NULL; //Invalid length
    }
    if (in1 == NULL ||in2 == NULL){
        return NULL;
    }
    output = malloc(sizeof(char)*length);
    
    //byte by byte XOR the inputs
    int outLength;
    uint8_t* arr1 = convertToBytes ( in1, length, &outLength);
    uint8_t* arr2 = convertToBytes ( in2, length, &outLength);
    
    for (int i=0; i< outLength; i++){
        uint8_t outval=0;
        
        outval = arr1[i] ^ arr2[i];
        
        //printf ("\ti:%d  outval:%d  ",i,outval);

        //convert outval to hex
        for (int j=i+1; j>=i; j--){
                output [j] = encoding_table_hex [outval % 16];
//                printf ("%c", output[j]);
                outval = (uint32_t) floor( outval / 16);
        }
        
//        printf ("\n");
    }
    
    
    
    
    return output;
}
