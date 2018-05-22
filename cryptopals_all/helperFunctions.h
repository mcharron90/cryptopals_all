//
//  helperFunctions.h
//  cryptopals_all
//
//  Created by Matthew Charron on 5/12/18.
//  Copyright © 2018 Matthew Charron. All rights reserved.
//

#ifndef helperFunctions_h
#define helperFunctions_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printCharArray (char* in, int len);
void print_u8_array (uint8_t* in, int len);
uint8_t* convertToBytes (char* in1, int charLength, int* outLength);

static char encoding_table_hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

#endif /* helperFunctions_h */
