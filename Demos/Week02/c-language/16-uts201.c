/*
 * Copyright (C) 2020-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2020-1 (midterm)
 * REV02 Mon Oct 12 11:28:15 WIB 2020
 * REV01 Thu Mar 12 10:16:24 WIB 2020
 * START Tue Mar 10 15:01:58 WIB 2020
 */

#include <stdio.h>

int returnInt(int ii) {
   return ii;
}

char returnChar(char cc) {
   return cc;
}

void main(void) {
    int ii=0x41424344;
    printf("returnChar=%c\n",
            returnChar((char) ii));
    printf("returnChar=%#x\n", 
      (int) returnChar((char) ii));
    printf("returnInt==%c\n",  
     (char) returnInt(ii));
    printf("returnInt==%#x\n",
            returnInt(ii));
}

