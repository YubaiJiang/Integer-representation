//
//  read_integers.c
//  intrep
//
//  Created by Yubai Jiang on 7/12/19.
//  Copyright © 2019 Yubai Jiang. All rights reserved.
//

#include "read_integers.h"

unsigned int read_int (unsigned int multi, char * line)
{
    unsigned int result = 0;
    for (int i = 0; line[i] != '\0'; ++i)
    {
        unsigned int digit;
        if ('a' <= line[i] && line[i] <= 'f') digit = line[i] - 'a' + 10;
        else if ('A' <= line[i] && line[i] <= 'F') digit = line[i] - 'A' + 10;
        else digit = line[i] - '0';
        result = result * multi + digit;
    }
    
    return result;
}
