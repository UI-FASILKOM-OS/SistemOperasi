/*
 * Copyright (C) 2018-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2018-1 (midterm)
 * REV02 Fri Feb  7 01:36:13 WIB 2020
 * REV01 Thu Jan 17 13:51:44 WIB 2019
 * START Xxx Xxx XX XX:XX:XX XXX 2018
 * NOTE: ASCII 61H = a; 62H = b
 */

#include <stdio.h>

void main(void) {
   unsigned int   ii='a';
   unsigned char  ch='b';
   unsigned char* st="dcba";
   printf("START\n");
   printf(" ii    = %X or %c\n",   ii,  ii);
   printf(" ch    = %X or %c\n",   ch,  ch);
   printf("*st    = %X or %c\n",  *st, *st);
   printf(" st[2] = %X or %c\n", st[2], st[2]);
   printf("STOP\n");
}

