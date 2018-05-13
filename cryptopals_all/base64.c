//
//  base64.c
//  cryptopals_all
//
//  Created by Matthew Charron on 5/12/18.
//  Copyright © 2018 Matthew Charron. All rights reserved.
//

#include "base64.h"




//INITALLY ASSUME no 0x at beginning; also should not care about case of letters
char* hex_to_base64 (char* in, int in_len, int* out_len){
    *out_len=0;
    // Calculate the length of the output
    if (in_len %2 == 1)
        return NULL; // invalid length of hex input
    //Bytes in hex then 4 chars per 24-bits
    *out_len=(int) ceil((double)((in_len / 2) / 3) * 4);
    char* output = malloc (sizeof(char) * (*out_len));
    
    //Operate every 3 bytes
    int output_index = 0;
    for (int i=0; i<in_len; i+=6){
        uint32_t val=0;
        //Convert hex chars into bytes
        for (int j = i; (j < (i+6) && j < in_len); j++){
            if (in[j] >= '0' && in[j] <='9'){
                val = (val << 4) + (in[j]-'0');
            } else if (in[j] >='A' && in[j] <='F'){
                val = (val << 4) + (in[j]-'A' + 10);
            } else if (in[j] >='a' && in[j] <='f'){
                val = (val << 4) + (in[j]-'a' + 10);
            }
        }
        printf ("val:%d\n",val);
        
        //Convert bytes into output base64 chars
        for (int j = output_index+3; j >= output_index ; j--){
            if (val > 0){
            output [j] = encoding_table [val % 64];
            val = (uint32_t) floor( val / 64);
            } else{
                //Add '=' as padding
                output[j]= '=';
            }
        }
        output_index += 4;
    }
    

    return output;
}
