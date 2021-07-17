/*
 * Copyright (C) 2019-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2019-1 (midterm)
 * REV01: Sun Feb 23 16:59:31 WIB 2020
 * REV00 Tue Oct  1 11:34:55 WIB 2019
 * START Fri Mar 15 13:52:00 WIB 2019
 */

#include <stdio.h>
char  ch_array[]="abcdefg";
char* ch_pointer="ABCDEFG";

void main(void) {
   printf(" &ch_array[0]=%p\n", &ch_array[0]);
   printf("  ch_array[0]=%c\n",  ch_array[0]);
   ch_pointer = ch_pointer + 5;
   printf(" &ch_pointer =%p\n", &ch_pointer);
   printf("  ch_pointer =%p\n",  ch_pointer);
   printf(" *ch_pointer =%c\n", *ch_pointer);
}

/*
This Clue #1 - Clue #4:
=======================
1: All strings end with 0x00
2: Address=64 bit Little ENDIAN
3: ASCII ’A’ is 0x41
4: ASCII ’a’ is 0x61
5: Initially: addresses 0x556677889900-1F=0x00

This is the Program Output:
===========================
 &ch_array[0]=0x556677889910
  ch_array[0]=0
 &ch_pointer =0x556677889918
  ch_pointer =0x556677889909
 *ch_pointer =F
*/

