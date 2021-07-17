/*
 * Copyright (C) 2018-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
# INFO: TBA
 * REV02: Sun Feb 23 16:59:31 WIB 2020
 * REV01: Thu Oct  4 20:54:14 WIB 2018
 * START: Thu Oct  4 10:49:54 WIB 2018
 *
 */


#include <stdio.h>
unsigned int     int0=0x41424344;
unsigned int     int1=0x45464748;
unsigned int     int2=0x61626364;
unsigned char    terminal=0;
unsigned int*    pt1_int;
unsigned char*   pt1_char;

void main(void) {
   int ii;
   printf("ADDRESSES of int0=%p, int1=%p, int2=%p\n", 
           &int0, &int1, &int2);
   printf("VALUES    of int0=%X, int1=%X, int2=%X\n",  
           int0,  int1,  int2);
   pt1_int=&int0;
   printf("The ADDRESS of pt1_int is  %p\n", &pt1_int);
   for (ii=0; ii<3; ii++, pt1_int++) {
      printf("pt1_int=%p, *pt1_int=%X\n", pt1_int, *pt1_int);
   }
   printf("The ADDRESS of pt1_char is %p, terminal is %p\n", &pt1_char, &terminal);
   pt1_char = (char *) &int0;
   printf("*pt1_char   =%c\n",  *pt1_char);
   printf(" pt1_char[5]=%c\n", pt1_char[5]);
   printf(" pt1_char   =%s\n",   pt1_char);
   pt1_char=&terminal;
   printf("*pt1_char=%2.2X (%p)\n", *pt1_char, pt1_char);
   pt1_char--;
   printf("*pt1_char=%2.2X (%p)\n", *pt1_char, pt1_char);
   pt1_char--;
   printf("*pt1_char=%2.2X (%p)\n", *pt1_char, pt1_char);
   pt1_char -= 5;
   printf("*pt1_char=%2.2X (%p)\n", *pt1_char, pt1_char);
}


