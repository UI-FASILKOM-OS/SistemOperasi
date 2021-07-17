/*
 * Copyright (C) 2016-2021 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV07: Fri 02 Apr 07:37:07 WIB 2021
 * REV06: Tue 23 Mar 10:01:44 WIB 2021
 * REV05: Sun 23 Feb 16:59:31 WIB 2020
 * REV04: Tue 28 Aug 18:40:36 WIB 2018
 * REV03: Tue 03 Oct 19:55:56 WIB 2017
 * START: Tue 20 Sep 17:00:52 WIB 2016
 */

#include <stdio.h>
#define HEAD1 "VARIABLE  +++  VALUE +CHR+   +ADDRESS +         +POINTS TO+ \n"

/* Global Variables */
unsigned char  varchr0='a';
unsigned char  varchr1='b';
unsigned char  varchr2='c';
unsigned char  varchr3='d';
unsigned char* ptrchr0=&varchr0;
unsigned char* ptrchr1=&varchr1;
unsigned char* ptrchr2=&varchr2;
unsigned char* ptrchr3=&varchr3;

void main(void) {
   printf(HEAD1);
   printf("varchr0 = %#10X = %c   %16p\n", varchr0, varchr0, &varchr0);
   printf("varchr1 = %#10X = %c   %16p\n", varchr1, varchr1, &varchr1);
   printf("varchr2 = %#10X = %c   %16p\n", varchr2, varchr2, &varchr2);
   printf("varchr3 = %#10X = %c   %16p\n", varchr3, varchr3, &varchr3);
   printf("ptrchr0 = %16p %16p %5c\n",  ptrchr0, &ptrchr0, *ptrchr0);
   printf("ptrchr1 = %16p %16p %5c\n",  ptrchr1, &ptrchr1, *ptrchr1);
   printf("ptrchr2 = %16p %16p %5c\n",  ptrchr2, &ptrchr2, *ptrchr2);
   printf("ptrchr3 = %16p %16p %5c\n",  ptrchr3, &ptrchr3, *ptrchr3);
}

/*
 * TAKE NOTE (SA)
 * Pada demo ini kita diajak untuk memahami apa kegunaan dari pointer * dan &. 
 * * berguna ketika kita ingin mengakses value dari suatu variabel dengan menggunakan pointer
 * & berguna ketika kita ingin mengakses alamat dari variabel yang diinginkan
 * Bisa dilihat contoh penggunaannya:
 * pada line 18 pointr ptchr0 menyimpan alamat dari variabel varchr0
 * pada line 25 terdapat &varchr0, maka itu artinya outputnya adalah alamat dari varchr0
 * pada line 29 terdapat ptchr0. karena pointer ptchr0 mengarah pada 
 *    alamat dari variabel varchr0 maka outputnya adalah alamat dari variabel varchr0. 
 *    lalu ada &ptchr0 karena menggunakan & maka outputnya adalah alamat dari variabel 
 *    ptchr0. lalu ada *ptchr0. karena menggunakan * maka artinya kita akan mengambil 
 *    value dari alamat yang diarahkan oleh ptchr0. karena ptchr0 mengarah ke alamat 
 *    varchr0 mak dari itu outputnya adalah value dari varchr0 
 */

