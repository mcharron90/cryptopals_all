//
//  fixedXOR.h
//  cryptopals_all
//
//  Created by Matthew Charron on 5/12/18.
//  Copyright © 2018 Matthew Charron. All rights reserved.
//

#ifndef fixedXOR_h
#define fixedXOR_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static char encoding_table_hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

char* xor_two (char* in1, char* in2, int length);

#endif /* fixedXOR_h */
