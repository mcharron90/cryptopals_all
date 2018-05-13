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
