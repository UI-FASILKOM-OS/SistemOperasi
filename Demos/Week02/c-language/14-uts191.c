/*
 * Copyright (C) 2019-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2019-1 (midterm)
 * REV02 Fri Feb  7 01:36:54 WIB 2020
 * START Mon Mar 24 23:47:00 WIB 2019
 */

// Rahmat M. Samik-Ibrahim 
// Clue: ASCII ’a’ is 0x61.
#include <stdio.h>
void main (void) {
   unsigned char ch1='a', ch2='y', ch3='z';
   printf("START\n");
   printf("1) ch1 = %c or ASCII %#X\n", ch1, ch1);
   ch1 = ch1 + ch3 - ch2;
   printf("2) ch1 = %c or ASCII %#X\n", ch1, ch1);
   printf("STOP\n");
}

