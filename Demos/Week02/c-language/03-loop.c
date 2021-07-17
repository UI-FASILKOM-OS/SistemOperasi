/*
 * Copyright (C) 2013-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: a loop example.
 * REV05 Fri Feb  7 01:26:38 WIB 2020
 * REV03 Tue Aug 28 13:31:19 WIB 2018
 * START 2013
 */

#define LINETXT "==========\n"
#define OLOOPTXT "OL [%4.4d]\n"
#define OLOOP  4
#define ILOOP  3

#include <stdio.h>
void main(void) {
   int ii, jj;
   printf(LINETXT);
   for (ii=0; ii<OLOOP; ii++) {
      printf(OLOOPTXT, ii);
      for (jj=0; jj<ILOOP; jj++) {
         printf("    IL[%d]\n",jj);
      }
   }
   printf(LINETXT);
}

/*
 * TAKE NOTE(AII)
 * Looping in c is similar to looping in java
 *
 * The outer loop will execute the block 
 * including the inner loop 
 * 4 times as declared at the beginning in 
 * variable OLOOP.
 * 
 * The inner loop will print to console 3 times as declared
 * at the beginning in variable ILOOP
 */

