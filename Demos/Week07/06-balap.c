/*
 * Copyright (C) 2012-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06 Tue Mar 24 19:07:30 WIB 2020
 * REV05 Mon Feb 11 15:44:22 WIB 2019
 * REV03 Tue Apr 17 09:34:02 WIB 2018
 * START Xxx Mar 30 02:13:01 UTC 2012
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"

#define lamaRehat  250
#define jmlPembalap 12
sem_t start1, start2, mutex1, mutex2;

void* bandar (void* a) {
   for (int ii=0; ii<jmlPembalap; ii++)
      sem_wait (&start1);
   printf ("Bandar Siap!\n");
   fflush(NULL);
   for (int ii=0; ii<jmlPembalap; ii++)
      sem_post (&start2);
}

int idmaster = 1;
int juara    = 1;
int menang   = TRUE;

void* pembalap (void* a) {
   int id;
   sem_wait (&mutex);
   id = idmaster++;
   sem_post (&mutex);

   printf ("Pembalap %2.2d Siap!\n",id);
   sem_post (&start1);
   sem_wait (&start2);
   rehat_acak(lamaRehat);
   sem_wait (&mutex1);
   rehat_acak(lamaRehat);
   sem_wait (&mutex2);
   if (menang==TRUE) printf("HORE, pemain");
   else printf("Aduh, pemain");
   printf(" %2.2d juara %2.2d!\n",id,juara++);
   menang = FALSE;
   rehat_acak(lamaRehat);
   sem_post (&mutex2);
   rehat_acak(lamaRehat);
   sem_post (&mutex1);
}

void main(void) {
   sem_init (&mutex,  0, 1);
   sem_init (&mutex1, 0, 1);
   sem_init (&mutex2, 0, 1);
   sem_init (&start1, 0, 0);
   sem_init (&start2, 0, 0);
   daftar_trit (bandar);
   for (int ii=0; ii<jmlPembalap; ii++)
      daftar_trit (pembalap);
   jalankan_trit ();
   beberes_trit ("Selese...");
}

/*
# INFO: RACING with PTHREAD: pembalap():   a racer.
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished.
# INFO:                   sem_init():      init a semaphore.
# INFO:                   sem_wait():      wait a semaphore.
# INFO:                   sem_post():      signal a semaphore.
 */

