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
    for (int i=0; i< length; i+=2){
        uint8_t val1=0, val2=0, outval=0;
        for (int j=i; j<(i+2); j++){
            if (in1[j] >= '0' && in1[j] <='9'){
                val1 = (val1 << 4) + (in1[j]-'0');
            } else if (in1[j] >='A' && in1[j] <='F'){
                val1 = (val1 << 4) + (in1[j]-'A' + 10);
            } else if (in1[j] >='a' && in1[j] <='f'){
                val1 = (val1 << 4) + (in1[j]-'a' + 10);
            }
            
            if (in2[j] >= '0' && in2[j] <='9'){
                val2 = (val2 << 4) + (in2[j]-'0');
            } else if (in2[j] >='A' && in2[j] <='F'){
                val2 = (val2 << 4) + (in2[j]-'A' + 10);
            } else if (in2[j] >='a' && in2[j] <='f'){
                val2 = (val2 << 4) + (in2[j]-'a' + 10);
            }
        }
        
        outval = val1 ^ val2;
        
        printf ("\ti:%d  outval:%d  ",i,outval);

        //convert outval to hex
        for (int j=i+1; j>=i; j--){
                output [j] = encoding_table_hex [outval % 16];
                printf ("%c", output[j]);
                outval = (uint32_t) floor( outval / 16);
        }
        
        printf ("\n");
    }
    
    
    
    
    return output;
}
