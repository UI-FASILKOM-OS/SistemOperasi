/*
 * Copyright (C) 2017-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2017-1 (midterm)
 * REV03: Wed Feb 26 20:28:03 WIB 2020
 * REV02: Sun Feb 23 16:59:31 WIB 2020
 * REV01: Thu Jan 17 16:12:18 WIB 2019
 * START: Thu Mar 30 18:27:30 WIB 2017

 * INT is 32 bit little endian
 * 41H='A'; 42H='B'; 43H='C"; 44H='D'
 */

#include <stdio.h>
char chrary[]="ZZZZ ZZZZ ";
void main(void) {
   char  chrvar = 'M';
   int   intvar = 0x41424344;
   int*  intptr = (int*) chrary;
   printf("YY.     chrary=%p\n",  chrary);
   printf("ZZ.     intptr=%p\n",  intptr);
   printf("01.     chrvar=%c\n",  chrvar);
   printf("02.    *chrary=%c\n", *chrary);
   printf("03. str chrary=%s\n",  chrary);
   *intptr      =  intvar;
   printf("04. str chrary=%s\n",  chrary);
}


