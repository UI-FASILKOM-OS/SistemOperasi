/*
 * Copyright (C) 2016-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2016-2 (midterm)
 * REV01: Sun Feb 23 16:59:31 WIB 2020
 * START: Xxx Xxx XX XX:XX:XX XXX 2016
 * Assume (&ptrchr is 0x7FFFEEDDCCBB, order of bytes: little-endian) */
#define LINES  3
#include <stdio.h>
void printeq(int lines) {
   while (lines-- > 0 ) printf("= = ");
   printf("\n");
}
void main(void) {
   int             ii;
   unsigned char   dummy  = 'a';
   unsigned char*  ptrchr = &dummy;

   printeq(LINES);
   printf(" dummy:  %c\n", dummy);
   printf("*ptrchr: %c\n", *ptrchr);
   printeq(LINES);
   printf("%p\n", &ptrchr);
   printeq(LINES);
   ptrchr = (char*) &ptrchr;
   for (ii=0; ii<6; ii++) {
      printf("%X ", *ptrchr);
      ptrchr++;
   }
   putchar('\n');
   printeq(LINES);
}

