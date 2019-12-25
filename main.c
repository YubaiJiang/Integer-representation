//
//  main.c
//  intrep
//
//  Created by Yubai Jiang on 6/12/19.
//  Copyright © 2019 Yubai Jiang. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "messages.h"
#include "read_integers.h"

int main(int argc, char * argv[]) {
    // insert code here...
    int valid_input = 1;
    unsigned int multi = 0;
    char * line = argv[2];
    if (argc < 2 || argc > 3)
    {
        valid_input = 0;
        fprintf(stderr, "Wrong number of inputs\n");
    }
    else if (argc == 2)
    {
        multi = 10;
        line = argv[1];
        char * c = argv[1];
        while (*c != '\0')
        {
            if (!isdigit(*c))
            {
                fprintf(stderr, "Invalid decimal number\n");
                valid_input = 0;
                break;
            }
            ++c;
        }
    }
    else if (strcmp(argv[1], "0") == 0)
    {
        multi = 8;
        char * c = argv[2];
        while (*c != '\0')
        {
            if (*c < '0' || '7' < *c)
            {
                fprintf(stderr, "Invalid octal number\n");
                valid_input = 0;
                break;
            }
            ++c;
        }
    }
    else if (strcmp(argv[1], "0b") == 0 || strcmp(argv[1], "0B") == 0)
    {
        multi = 2;
        char * c = argv[2];
        while (*c != '\0')
        {
            if (*c < '0' || '1' < *c)
            {
                fprintf(stderr, "Invalid binary number\n");
                valid_input = 0;
                break;
            }
            ++c;
        }
    }
    else if (strcmp(argv[1], "0x") == 0 || strcmp(argv[1], "0X") == 0)
    {
        multi = 16;
        char * c = argv[2];
        while (*c != '\0')
        {
            if (!(isdigit(*c) || ('A' <= *c && *c <= 'F') || ('a' <= *c && *c <= 'f')))
            {
                fprintf(stderr, "Invalid heximal number\n");
                valid_input = 0;
                break;
            }
            ++c;
        }
    }
    else
    {
        fprintf(stderr, "Invalid Usage\n");
        valid_input = 0;
    }
    
    if (!valid_input)
    {
        print_help_message();
        return 1;
    }
    
    unsigned int result = read_int(multi, line);
    
    print_integer_representation(result);
    
    return 0;
}
