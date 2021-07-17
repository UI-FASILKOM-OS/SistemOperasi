/*
 * Copyright (C) 2016-2021 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV06: Tue 23 Mar 10:14:44 WIB 2021
 * REV05: Sun Feb 23 16:59:31 WIB 2020
 * REV04: Tue Aug 28 18:40:36 WIB 2018
 * REV03: Tue Oct  3 20:30:14 WIB 2017
 * START: Tue Sep 20 17:00:52 WIB 2016
 */

#include <stdio.h>
#define HEAD1 "VARIABLE  +++  VALUE +CHR+   +ADDRESS +         +POINTS TO+ \n"

/* Global Variables */
unsigned char   varchr0='a';
unsigned char   varchr1='b';
unsigned char   varchr2='c';
unsigned char   varchr3='d';
unsigned char*  ptrchr0=&varchr0;
unsigned char*  ptrchr1=&varchr1;
unsigned char*  ptrchr2=&varchr2;
unsigned char*  ptrchr3=&varchr3;
unsigned char** ptrptr0=&ptrchr0;
unsigned char** ptrptr1=&ptrchr1;
unsigned char** ptrptr2=&ptrchr2;
unsigned char** ptrptr3=&ptrchr3;

void main(void) {
   printf(HEAD1);
   printf("varchr0 = %#10X = %c     %16p\n",  varchr0, varchr0,  &varchr0);
   printf("varchr1 = %#10X = %c     %16p\n",  varchr1, varchr1,  &varchr1);
   printf("varchr2 = %#10X = %c     %16p\n",  varchr2, varchr2,  &varchr2);
   printf("varchr3 = %#10X = %c     %16p\n",  varchr3, varchr3,  &varchr3);
   printf("ptrchr0 = %16p %16p %8c\n",    ptrchr0, &ptrchr0, *ptrchr0);
   printf("ptrchr1 = %16p %16p %8c\n",    ptrchr1, &ptrchr1, *ptrchr1);
   printf("ptrchr2 = %16p %16p %8c\n",    ptrchr2, &ptrchr2, *ptrchr2);
   printf("ptrchr3 = %16p %16p %8c\n",    ptrchr3, &ptrchr3, *ptrchr3);
   printf("ptrptr0 = %16p %16p %8p\n",    ptrptr0, &ptrptr0, *ptrptr0);
   printf("ptrptr1 = %16p %16p %8p\n",    ptrptr1, &ptrptr1, *ptrptr1);
   printf("ptrptr2 = %16p %16p %8p\n",    ptrptr2, &ptrptr2, *ptrptr2);
   printf("ptrptr3 = %16p %16p %8p\n",    ptrptr3, &ptrptr3, *ptrptr3);
}

/*
 * TAKE NOTE (MIK)
 * Line 22 : ptrptr0 akan menyimpan alamat dari ptrchr0
 * Line 37 : ptrptr0 akan berisi alamat dari ptrchr0,
 * &ptrptr0 akan berisi alamat dari ptrptr0, dan
 * *ptrptr0 akan berisi isi dari
 * &ptrchr0 yang mana adalah alamat dari varchr0
 */

