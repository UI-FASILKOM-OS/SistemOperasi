/*
 * Copyright (C) 2018-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2018-1 (midterm)
 * REV03 Fri Feb  7 01:35:38 WIB 2020
 * REV02 Thu Jan 17 13:56:47 WIB 2019
 * START Mon Apr 30 10:32:01 WIB 2018
 */

#include <stdio.h>

void main(void) {
   char string[]="HALLO";
   printf("START\n");
   printf("%s\n",  string);
   printf("%c\n", *string);
   printf("%c\n",  string[1]);
   printf("STOP\n");
}

