/*
 * Copyright (C) 2018-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2018-2 (midterm)
 * REV02: Sun Feb 23 16:59:31 WIB 2020
 * REV01: Thu Jan 17 15:57:47 WIB 2019
 * START: Xxx Xxx XX XX:XX:XX XXX 2018
 *
 * long int = 64 bits
 */

#include <stdio.h>

unsigned char  string[]="0123456789ABCDE";
unsigned long  longst=(unsigned long) string;
unsigned char* achar;

void main(void) {
   achar=(unsigned char*) &longst;
   printf("(0) %p\n",  string);
   printf("(1) %p\n", &longst);
   printf("(2) %p\n",  &achar);
   printf("(3) %p\n",   achar);
   printf("(4) %#X\n", *achar);
   printf("(5) %#16.16lx\n",longst);
}

