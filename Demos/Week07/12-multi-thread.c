/*
 * Copyright (C) 2017-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV02 Wed Mar 25 09:45:51 WIB 2020
 * REV01 Wed Aug 29 18:33:51 WIB 2018
 * START Mon Nov 27 10:19:59 WIB 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"
#define  NTHREAD      8
#define  RECDEEP      8
#define  LOOP1  100
#define  LOOP2  100
#define  LOOP3  100

volatile unsigned share=0;
unsigned multiloop(int recursive) {
   sleep(1);
   unsigned dummy = share;
   for (int ii; ii<LOOP1; ii++) {
      for (int jj; jj<LOOP2; jj++) {
         for (int kk; kk<LOOP3; kk++) {
            dummy++;
         }
      }
   }
   share = dummy;
   if (recursive-- < 0)
      return share;
   else
      return multiloop(recursive);
}

void* thread (void* a) {
   printf("Start Thread %8.8X ...\n", share);
   share=multiloop(RECDEEP);
   printf("Stop  Thread %8.8X ...\n", share);
}

void main(void) {
   printf("This is MAIN\n");
   for (int ii=0;ii<NTHREAD;ii++)
      daftar_trit  (thread);
   jalankan_trit ();
   beberes_trit  ("TREXIT!");
}

/*
# INFO: PTHREAD: See also "99-myutils.c" and "99-myutils.h"
# INFO:                   Terdapat perbedaan nilai "share" antar "thread()".
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished.
 */

