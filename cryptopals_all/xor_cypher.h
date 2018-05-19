//
//  xor_cypher.h
//  cryptopals_all
//
//  Created by Matthew Charron on 5/12/18.
//  Copyright © 2018 Matthew Charron. All rights reserved.
//

#ifndef xor_cypher_h
#define xor_cypher_h

#include <stdio.h>
#include "base64.h"
#include "fixedXOR.h"
#include "helperFunctions.h"

char* xor_cypher (char* in, int length);
extern char letterfreq [12];
//ETAOINSHRDLU

#endif /* xor_cypher_h */
