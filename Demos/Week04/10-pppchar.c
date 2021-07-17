/*
 * Copyright (C) 2018-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV03: Sun Feb 23 16:59:31 WIB 2020
 * REV02: Thu Oct  4 20:55:37 WIB 2018
 * START: Wed Oct  3 19:59:08 WIB 2018
 *
 */

#include <stdio.h>
/* Global Variables */
unsigned char    var_chr='a';
unsigned char*   pt1_chr=&var_chr;
unsigned char**  pt2_chr=&pt1_chr;
unsigned char*** pt3_chr=&pt2_chr;

void main(void) {
   printf("   var_chr=%c,      ADDR=%p\n",
              var_chr, &var_chr);
   printf("  *pt1_chr=%c,     VALUE=%p,     ADDR=%p\n",
             *pt1_chr,   pt1_chr, &pt1_chr);
   printf(" **pt2_chr=%c,  *pt2_chr=%p,    VALUE=%p,  ADDR=%p\n",
            **pt2_chr,  *pt2_chr,  pt2_chr, &pt2_chr);
   printf("***pt3_chr=%c, **pt3_chr=%p, *pt3_chr=%p, VALUE=%p, ADDR=%p\n", 
            ***pt3_chr, **pt3_chr, *pt3_chr,  pt3_chr, &pt3_chr);
}


