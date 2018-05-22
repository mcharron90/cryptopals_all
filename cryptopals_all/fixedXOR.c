//
//  fixedXOR.c
//  cryptopals_all
//
//  Created by Matthew Charron on 5/12/18.
//  Copyright © 2018 Matthew Charron. All rights reserved.
//

#include "fixedXOR.h"


uint8_t* xor_two (char* in1, char* in2, int length, int * outLength){
    uint8_t* output;
    
    if (length %2 !=0){
        return NULL; //Invalid length
    }
    if (in1 == NULL ||in2 == NULL){
        return NULL;
    }
    
    //byte by byte XOR the inputs
    int arrLength;
    uint8_t* arr1 = convertToBytes ( in1, length, &arrLength);
    uint8_t* arr2 = convertToBytes ( in2, length, &arrLength);
    
    output = malloc(sizeof(uint8_t) * arrLength);

    for (int i=0; i< arrLength; i++){
        output[i] = arr1[i] ^ arr2[i];
    }
    
//    print_u8_array (output, arrLength);
    
    
    *outLength = arrLength;
    free (arr1);
    free (arr2);
    
    return output;
}
