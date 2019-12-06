//
//  messages.c
//  intrep
//
//  Created by Yubai Jiang on 6/12/19.
//  Copyright © 2019 Yubai Jiang. All rights reserved.
//

#include <stdio.h>

#include "messages.h"

#define MAX_LINE 1024

void print_help_message()
{
    char * lines [MAX_LINE] = {NULL};
    
    char ** ptr = lines;
    *(ptr++) = "Usage: intrep <flag> <unsiged integer>";
    *(ptr++) = "<flag>:\n0b -> binary\n0x -> heximal\n0 -> octal\nno flag -> decimal";
    *(ptr++) = "<unsigned integer>:\nonly take unsigned integers.\ncan have A-F if input is hexdecimal";
    
    for (int i = 0; lines[i] != NULL; ++i) printf("%s\n", lines[i]);
}

void print_integer_representation(unsigned int result)
{
    printf("   %u\n", result);
    printf("0  %o\n", result);
    printf("0x %x\n", result);
    printf("0b ");
    
    int found = 0;
    
    for (int i = 8 * 4 - 1; i >= 0; --i)
    {
        if (result & (1 << i))
        {
            found = 1;
            putchar('1');
        }
        else
        {
            if (found || i == 0) putchar ('0');
        }
    }
    
    putchar('\n');
    
}
