/*
 * Copyright (C) 2016-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * TAKE NOTE(TA)
 * file tidak terbuka dan akan memberikan output :
 * fopen error...
 * karena file yang ingin kita buka adalah untuk dibaca ("r")
 * maka file nya harus sudah ada (exist)
 *
 * REV04 Tue Nov 26 11:37:57 WIB 2019
 * REV03 Wed Aug 29 20:55:23 WIB 2018
 * REV02 Thu Oct  5 10:17:47 WIB 2017
 * START Tue Sep 27 12:07:42 WIB 2016
 *
 * Compare: File Pointer (FP) vs File Descriptor (FD)
 *
 */

#define	FILE4 "demo-file4.txt"
#include <stdio.h>
#include <stdlib.h>

void main(void) {
   FILE* fp;  
   int   cc;

   printf ("*** Open and listing file %s ***\n\n", FILE4);
   if ((fp=fopen(FILE4, "r")) == NULL) {
      printf("fopen error...\n");
      exit(1);
   }
   while((cc=fgetc(fp)) != EOF) {
      printf("%c", cc);
   }
   printf("\n");
   fclose(fp);
}
