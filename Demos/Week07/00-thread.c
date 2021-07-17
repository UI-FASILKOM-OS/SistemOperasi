/*
 * Copyright (C) 2015-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV11 Tue Mar 24 17:03:47 WIB 2020
 * REV10 Thu Nov 15 19:29:46 WIB 2018
 * REV02 Tue Apr 18 15:28:19 WIB 2017
 * REV01 Wed Nov  2 11:49:30 WIB 2016
 * START Xxx Sep 30 XX:XX:XX UTC 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "99-myutils.h"

volatile int loop  = 6; // display 6 times
volatile int share = 0; // start share=0

// fflush() I/O before sleep() 
void  flushsleep(int ii) {
   fflush(NULL);
   sleep (ii  );
}

// THREAD#1: start share=1000 --> share++
void* thread1 (void* a) {
   printf("THREAD#1-PID[%5.5d]\n", getpid());
   flushsleep(1);
   rehat_acak(100);
   share = 1000;
   while (loop > 0) {
      rehat_acak(100);
      share++;
   }
}

// THREAD#2: start share=2000 --> share--
void* thread2 (void* a) {
   printf("THREAD#2-PID[%5.5d]\n", getpid());
   flushsleep(1);
   rehat_acak(100);
   share = 2000;
   while (loop > 0) {
      rehat_acak(100);
      share--;
   }
}

// THREAD#3: display "share" every 1 second
void* thread3 (void* a) {
   printf("THREAD#3-PID[%5.5d]\n", getpid());
   while (loop-- > 0) {
      printf("---SHARE----+%5.5d+\n", share);
      flushsleep(1);
   }
}

// MAIN: start share=0
void main(void) {
   printf("---MAIN--PID[%5.5d]\n", getpid());
   daftar_trit   (thread1);
   daftar_trit   (thread2);
   daftar_trit   (thread3);
   jalankan_trit ();
   beberes_trit  ("------------  Done.");
}

/*
# INFO: PTHREAD: See also "99-myutils.c" and "99-myutils.h"
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished
 */

