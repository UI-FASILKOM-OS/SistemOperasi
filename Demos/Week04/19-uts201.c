/*
 * Copyright (C) 2020-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2020-1 (midterm)
 * REV01: Mon Oct 12 11:46:02 WIB 2020
 * START: Tue Mar 10 17:15:52 WIB 2020
 */

/* 
This Clue #1 - Clue #5:
=======================
1: All strings end with 0x00.
2: All arrays start with index 0.
3: Address=64 bit Little ENDIAN.
4: ASCII ’0’ is 0x30.
5: ASCII ’A’ is 0x41.
The program output (subject to memory alocation):
=====================
1. 0X000056553B970804
2. 0X000056553BB71018
3. 0X000056553BB71010
4. 0X000056553BB71016
5. 0X45 E
6. 0X30 0
7. 0X000056553B970805
8. 0X31 1
=====================
*/

#include <stdio.h>
#include <string.h>
typedef unsigned long UL;
char* stringptr="0123456";
char  string1[]="89ABCDE";

void main(void) {
    printf("1. %#16.16lX\n", (UL)  stringptr);
    printf("2. %#16.16lX\n", (UL) &stringptr);
    printf("3. %#16.16lX\n", (UL) &string1[0]);

    printf("4. %#16.16lX\n", (UL) &string1[6]);
    printf("5. %#X %c\n",  string1[6], string1[6]);
    printf("6. %#X %c\n", *stringptr, *stringptr);
    stringptr++;
    printf("7. %#16.16lX\n", (UL)  stringptr);
    printf("8. %#X %c\n", *stringptr, *stringptr);
}

