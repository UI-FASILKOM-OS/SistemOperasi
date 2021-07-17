/*
 * Copyright (C) 2011-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV05 Tue Mar 24 17:35:08 WIB 2020
 * REV04 Wed Aug 29 18:36:15 WIB 2018
 * REV03 Tue Apr 17 09:32:14 WIB 2018
 * REV00 Xxx Sep 30 XX:XX:XX UTC 2015
 * START Xxx Mar 30 02:13:01 UTC 2011
 */

#include <stdio.h>
#include <stdlib.h>
#include "99-myutils.h"

#define R_REHAT 4000
#define R_READ  4000
#define R_JUMLAH   4

#define W_REHAT 2000
#define W_WRITE 2000
#define W_JUMLAH   3

#define aReader 0
#define aWriter 1

void* Reader (void* a) {
   int  my_ID;

   my_ID = getADDglobalID(aReader);
   printf   ("                        READER %d: SIAP  ******\n", my_ID);
   while (TRUE) {
      printf("                        READER %d: REHAT ******\n", my_ID);
      rehat_acak(R_REHAT);
      printf("                        READER %d: MAU  MEMBACA\n", my_ID);
      printf("                        ***** JUMLAH PEMBACA %d\n", startRead());
      printf("                        READER %d:=SEDANG==BACA\n", my_ID);
      rehat_acak(R_READ);
      printf("                        READER %d: SELESAI BACA\n", my_ID);
      printf("                        ***** SISA PEMBACA %d\n", endRead());
   }
}

void* Writer (void* a) {
   int  my_ID;

   my_ID = getADDglobalID(aWriter);
   printf   ("WRITER %d: SIAP  *******\n", my_ID);
   while (TRUE) {
      printf("WRITER %d: REHAT *******\n", my_ID);
      rehat_acak(W_REHAT);
      printf("WRITER %d: MAU   MENULIS\n", my_ID);
      startWrite();
      printf("WRITER %d:=SEDANG==NULIS\n", my_ID);
      rehat_acak(W_WRITE);
      endWrite();
      printf("WRITER %d: SELESAI NULIS\n", my_ID);
   }
}

int main(int argc, char * argv[])
{
   int ii;
   init_rw();
   init_globalID();
   for (ii = 0 ; ii < R_JUMLAH; ii++)
      daftar_trit(Reader);
   for (ii = 0 ; ii < W_JUMLAH; ii++)
      daftar_trit(Writer);
   jalankan_trit();
   beberes_trit("Selese...");
}

/*
# INFO: Readers - Writers with PTHREAD.
# INFO:                   Reader():        a Reader.
# INFO:                      startRead():  the Reader starts   reading.
# INFO:                      endRead():    the Reader finishes reading.
# INFO:                   Write():         a Writer.
# INFO:                      startWrite(): the Writer starts   writing.
# INFO:                      endWrite():   the Writer finishes writing.
# INFO:                   rehat_acak():    random stop.
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished.
 */

