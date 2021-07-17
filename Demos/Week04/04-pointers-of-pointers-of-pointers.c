/*
 * Copyright (C) 2016-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV06: Sun Feb 23 16:59:31 WIB 2020
 * REV05: Tue Oct  1 11:37:10 WIB 2019
 * REV04: Tue Aug 28 18:40:36 WIB 2018
 * REV03: Tue Oct  3 20:49:01 WIB 2017
 * START: Tue Sep 20 17:00:52 WIB 2016
 */

#include <stdio.h>
#define HEAD1 "  VARIABLE  +++ ADDRESS ++ + VALUE(CH) ++\n"

/* Global Variables */
unsigned char   varchr0='a';
unsigned char*  ptrchr0=&varchr0;
unsigned char** ptrptr0=&ptrchr0;
unsigned char*** ppptr0=&ptrptr0;

void main(void) {
   printf(HEAD1);
   printf("  varchr0 = %14p %#7X (%c)\n", &varchr0,   varchr0, varchr0);
   printf("  ptrchr0 = %14p %14p\n",      &ptrchr0,   ptrchr0);
   printf("  ptrptr0 = %14p %14p\n",      &ptrptr0,   ptrptr0);
   printf("   ppptr0 = %14p %14p\n",       &ppptr0,   ppptr0);
   printf("  *ppptr0 = %14p %14p\n",        ppptr0,  *ppptr0);
   printf(" **ppptr0 = %14p %14p\n",       *ppptr0, **ppptr0);
   printf("***ppptr0 = %14p %#7X (%c)\n", **ppptr0,***ppptr0,***ppptr0);
}

/*
 * TAKE NOTE (MIK)
 * Line 26 : ppptr0 akan menyimpan alamat dari ptrptr0
 * Line 42 : ppptr0 akan berisi alamat dari ptrptr0,
 * &ppptr0 akan berisi alamat dari ppptr0, dan
 * *ppptr0 akan berisi isi dari
 * ptrptr0 yang mana adalah alamat dari ptrchr0.
 */

