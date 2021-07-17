/*
 * Copyright (C) 2017-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2017-2 (midterm)
 * REV04 Fri Feb  7 01:35:02 WIB 2020
 * REV03 Thu Jan 17 13:56:03 WIB 2019
 * REV02 Tue Aug 28 13:31:19 WIB 2018
 * START Mon Oct 16 21:15:03 WIB 2017
 */

#include <stdio.h>

char globalChar='a';

char* getGlobal(void) {
   char* charPTR=&globalChar;
   printf("getGlobal1 %c\n", globalChar);
   *charPTR='b';
   printf("getGlobal2 %c\n", *charPTR);
   return charPTR;
}

void main (void) {
   char localChar='c';
   printf("==== main1 %c\n", localChar);
   localChar=*getGlobal();
   printf("==== main2 %c\n", localChar);
}

/*
 * TAKE NOTE (ZA)
 * Line 25: mengambil local char pada fungsi yaitu c
 * Line 26: memanggil fungsi getGlobal()
 * Line 17: mengambil global char yaitu a
 * Line 19: mengganti chartPTR dari a menjadi b
 * Line 27: menggambil local char terakhir yaitu b
 */

