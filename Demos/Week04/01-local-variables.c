/*
 * Copyright (C) 2016-2021 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV07: Fri 02 Apr 07:41:21 WIB 2021
 * REV06: Tue 23 Mar 09:56:51 WIB 2021
 * REV05: Sun 23 Feb 16:59:31 WIB 2020
 * REV04: Tue 28 Aug 18:40:36 WIB 2018
 * REV03: Tue 03 Oct 19:12:30 WIB 2017
 * START: Tue 20 Sep 17:00:52 WIB 2016
 */

#include <stdio.h>
#define HEAD1 "VARIABLE  +++  VALUE +CHR+ +++  ADDRESS +++\n"

void main(void) {
   /* Local Variables in Stack Segment */
   unsigned char varchr0='a';
   unsigned char varchr1='b';
   unsigned char varchr2='c';
   unsigned char varchr3='d';
   unsigned char varchr4='e';
   unsigned char varchr5='f';
   unsigned char varchr6='g';
   unsigned char varchr7='h';

   printf(HEAD1);
   printf("varchr0 = %#10X = %c   %16p\n", varchr0, varchr0, &varchr0);
   printf("varchr1 = %#10X = %c   %16p\n", varchr1, varchr1, &varchr1);
   printf("varchr2 = %#10X = %c   %16p\n", varchr2, varchr2, &varchr2);
   printf("varchr3 = %#10X = %c   %16p\n", varchr3, varchr3, &varchr3);
   printf("varchr4 = %#10X = %c   %16p\n", varchr4, varchr4, &varchr4);
   printf("varchr5 = %#10X = %c   %16p\n", varchr5, varchr5, &varchr5);
   printf("varchr6 = %#10X = %c   %16p\n", varchr6, varchr6, &varchr6);
   printf("varchr7 = %#10X = %c   %16p\n", varchr7, varchr7, &varchr7);
}

/*
 * TAKE NOTE (AII & MIM)
 * A global variable is a variable that is declared outside all functions. 
 * A local variable can only be used in the function where it is declared. 
 * A global variable can be used in all functions.
 * varchr0 until varchr7 are local char variables.
 * 
 * This program will print the values of local variables along with their address.
 * %#10X specify hex ASCII value of a char.
 * &varchr0 will return the address of varable varchr0.
 *
 * Variabel HEAD1 dapat diakses di dalam fungsi main karena merupakan 
 * Global Variable, sehingga perintah printf dapat dijalankan.
 *
 * Variable varchr0 sampai varchr7 hanya dapat diakses di dalam 
 * fungsi main karena merupakan Local Variable. 
 *
 * Apabila di luar fungsi terdapat perintah printf(varchar0),
 * maka perintah tersebut tidak dapat berjalan karena tidak ada akses 
 * untuk mengambil nilai dari varchar0 yang merupakan Local Variable 
 * di dalam fungsi main.
 */

