//
//  main.c
//  cryptopals_all
//
//  Created by Matthew Charron on 5/12/18.
//  Copyright © 2018 Matthew Charron. All rights reserved.
//

#include <stdio.h>
#include "base64.h"
#include "fixedXOR.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char input [] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    int length = 96;
    int* out_length = malloc (sizeof(int));
    
    
    char * out = hex_to_base64 (input, length, out_length);
    
    printf ("hex_to_base64 Out:");
    for (int i=0; i < *out_length; i++)
    {
        printf ("%c",out[i]);
    }
    printf ("\n\n");
    
    
    char xor1 [] = "1c0111001f010100061a024b53535009181c";
    char xor2 [] = "686974207468652062756c6c277320657965";

    char * out_xor = xor_two (xor1, xor2, 36);
    
    printf ("xor_two Out:");
    for (int i=0; i < 36; i++)
    {
        printf ("%c",out_xor[i]);
    }
    printf ("\n\n");
    
    
    
    
    
    return 0;
}
