/*
 * Copyright (C) 2019-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: An introduction to function().
 * REV02 Fri Feb  7 01:33:02 WIB 2020
 * REV01 Tue Dec 10 10:51:54 WIB 2019
 * START Tue Feb 26 12:15:18 WIB 2019
 */

#include <stdio.h>
#include <stdlib.h>

int addone1 (int ii) {
   ii++;
   return ii;
}

int addone2 (int* iptr) {
   (*iptr)++;
   return *iptr;
}

int* addone3 (int* iptr) {
   (*iptr)++;
   return iptr;
}

void main(void) {
   int ii=1;
   printf("Addone1 %d -- %d \n", ii,  addone1(ii));
   printf("Addone1 %d -- %d \n", ii,  addone1(ii));
   printf("Addone1 %d -- %d \n", ii,  addone1(ii));
   printf("Addone2 %d -- %d \n", ii,  addone2(&ii));
   printf("Addone2 %d -- %d \n", ii,  addone2(&ii));
   printf("Addone2 %d -- %d \n", ii,  addone2(&ii));
   printf("Addone3 %d -- %d \n", ii, *addone3(&ii));
   printf("Addone3 %d -- %d \n", ii, *addone3(&ii));
   printf("Addone3 %d -- %d \n", ii, *addone3(&ii));
   system("echo This is echo from system. Cek demo.txt");
   system("echo This is echo from system. Cek demo.txt > demo.txt");
}

