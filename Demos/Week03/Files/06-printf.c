/*
 * Copyright (C) 2016-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: Week02 printf() examples.
 * REV01 Sun Feb 23 16:41:33 WIB 2020
 * START Tue Dec 10 10:58:24 WIB 2019
 */

#include <stdio.h>

void main (void) {
   int               jj = 74;         // Integer

   printf("(%%d)     jj = (%d)\n",    jj);
   printf("(%%5d)    jj = (%5d)\n",   jj);
   printf("(%%1d)    jj = (%1d)\n",   jj);
   printf("(%%-5d)   jj = (%-5d)\n",  jj);
   printf("(%%5.5d)  jj = (%5.5d)\n", jj);
   printf("(%%5.3d)  jj = (%5.3d)\n", jj);
   printf("(%%c)     jj = %c\n",      jj);
   printf("(%%x)     jj = %x\n",      jj);
   printf("(%%#x)    jj = %#x\n",     jj);
   printf("(%%X)     jj = %X\n",      jj);
   printf("(%%#X)    jj = %#X\n",     jj);
   printf("(%%o)     jj = %o\n",      jj);
   printf("(%%#o)    jj = %#o\n",     jj);

   short             sii    = 1;
   unsigned short    usii   = sii * -1;
   printf("short     %hd |||| unsigned short     %hu\n", sii, usii);

   int               ii     = 1;
   unsigned          uii    = ii * -1;
   printf("int       %d |||| unsigned           %u\n", ii, uii);

   long              lii    = 1;
   unsigned long     ulii   = lii * -1;
   printf("long      %ld |||| unsigned long      %lu (%#lX)\n", lii, ulii, ulii);

   long long         llii   = 1;
   unsigned long long ullii = llii * -1;
   printf("long long %lld |||| unsigned long long %llu (%#llX)\n", llii, ullii, ullii);

   float            ff    = 123456789.12345678;
   printf("float       %f (%e)\n", ff, ff);
   double            dff  = 123456789.12345678;
   printf("double      %lf (%le)\n", dff, dff);
   long double       ldff = 123456789.12345678;
   printf("long double %Lf (%Le)\n", ldff, ldff);

   char        ch='A';
   unsigned char uch = (unsigned char) -191;
   printf("char %c (%d) |||| unsigned char       %c (%u)\n", ch, ch, uch, uch);

#define STRING "123456789ABCDEF\n"

   char  dd[]=STRING;
   long  size=sizeof(STRING);
   printf(STRING);
   printf("One  more time:\n%sSIZE=%ld\n", dd, size);
   printf("dd[]= %c%c%c ... %c\n", dd[0], 
           dd[1], dd[2], dd[size-3]);
}

