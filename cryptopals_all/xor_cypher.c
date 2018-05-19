//
//  xor_cypher.c
//  cryptopals_all
//
//  Created by Matthew Charron on 5/12/18.
//  Copyright © 2018 Matthew Charron. All rights reserved.
//

#include "xor_cypher.h"

char* xor_cypher (char* in, int length){
    //Try to XOR with all characters from 'a' to 'z' first
//    char start = 'a';
    char* listOuts [256];
//    int scores [256];
    int outCount = 0;
    char letters[length];
    for (int i=0; i < 256; i++){
        printf ("xor_cypher xor with 0x%x\n", i );
        //Fill letters array
        for (int j=0; j< length; j+=2){
            letters[j+1]=encoding_table_hex[i%16];
//            printf ("MOD :%d;  DIV:%d\n",i%16, (int)floor(i/16));
            letters[j]  =encoding_table_hex[(int)floor(i/16)];
        }

        printf ("letters:\n");
        printCharArray(letters, length);
        
        listOuts[outCount] = xor_two (in, letters, length);
        printCharArray(listOuts[outCount], length);
        printf("\n");
        outCount ++;
        //Score each result
        //ideally here use a hash map, but not in C right now
        for (int j = 0; j < length; j++){
            //go through each letter and score it
            
            
        }
    }
    
    
    
    return NULL;//FIXME
}
