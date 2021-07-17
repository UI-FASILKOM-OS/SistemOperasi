/*
 * Copyright (C) 2019-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2019-2 (midterm)
 * REV01 Fri Feb  7 01:17:56 WIB 2020
 * START Tue Oct 22 18:54:00 WIB 2019
 */

#include <stdio.h>
int aa=0;
int* function(int* bb) {
   return bb;
}
void main (void) {
   int cc=aa++;
   printf("START\n");
   printf("1. aa = %d\n", aa);
   printf("2. *function()=%d\n", *function(&cc));
   printf("3. cc = %d\n", ++cc);
   printf("STOP\n");
}

