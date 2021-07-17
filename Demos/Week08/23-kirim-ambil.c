/*
 Copyright (C) 2013-2018 CC BY-SA 3.0
 adapted from https://stackoverflow.com/
 questions/5656530/
 how-to-use-shared-memory-with-linux-in-c

 Copyright 2018-2020 Rahmat M. Samik-Ibrahim
 You are free to SHARE (copy and 
 redistribute the material in any medium
 or format) and to ADAPT (remix, 
 transform, and build upon the material 
 for any purpose, even commercially).
 This program is distributed in the hope 
 that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied 
 warranty of MERCHANTABILITY or FITNESS 
 FOR A PARTICULAR PURPOSE.

 * REV09 Sat Apr 11 17:34:23 WIB 2020
 * REV08 Wed Aug 29 20:42:05 WIB 2018
 * REV07 Wed Apr 25 09:28:14 WIB 2018
 * START Xxx Xxx XX XX:XX:XX WIB 2013
 */

// DO NOT USE THE SAME SEMAPHORE NAME!!!!
// Replace "demo" with your own SSO name.
#define SEM_SYN_KRAM    "/syn-KRAM-demo"
#define SEM_SYN_AMKR    "/syn-AMKR-demo"
#define SEM_MUTEX       "/sm_mutex-demo"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

// Shared Memory: R/W with no name.
#define PROT    (PROT_READ | PROT_WRITE)
#define VISIBLE (MAP_ANON  | MAP_SHARED)

#define KIRIM 0
#define AMBIL 1
#define LOOP  2

typedef struct {
   int    produk;
   int    turn;
   int    loop;
}  buffer;

// KRAM: Kirim-Ambil; AMKR: Ambil-Kirim
sem_t*    sync_KRAM;
sem_t*    sync_AMKR;
sem_t*    sem_mutex;

// WARNING: NO ERROR CHECK! ////////////
void persiapan(buffer* buf) {
   buf->loop   = 0;
   buf->produk = 0;
   buf->turn   = AMBIL;
   sync_KRAM   = sem_open(SEM_SYN_KRAM, 
                     O_CREAT, 0600, 0);
   sync_AMKR   = sem_open(SEM_SYN_AMKR, 
                     O_CREAT, 0600, 0);
   sem_mutex   = sem_open(SEM_MUTEX, 
                     O_CREAT, 0600, 1);
   printf("PR KIRIMAN AWAL: %d\n",
                           buf->produk);
}

void kirim (buffer* buf) {
   printf("KR KIRIM PID[%d]\n",getpid());
   sem_post(sync_KRAM);
   sem_wait(sync_AMKR);
   int krLoop = 0;
   while (buf->turn != KIRIM)
      ;
   while (buf->loop < LOOP) {
      krLoop++;
      sem_wait(sem_mutex);
      if (buf->turn == KIRIM) {
         buf->turn = AMBIL;
         printf("KR %d\n",++(buf->produk));
      }
      sem_post(sem_mutex);
   }
   wait(NULL);
   printf("KR LOOPS = %d\n", krLoop);
}

void ambil (buffer* buf) {
   sem_wait(sync_KRAM);
   sem_post(sync_AMKR);
   printf("AM AMBIL PID[%d]\n",getpid());
   int amLoop = 0;
   while (buf->loop < LOOP+1) {
      amLoop++;
      sem_wait(sem_mutex);
      if(buf->turn == AMBIL) {
         buf->turn = KIRIM;
         printf("AM %d\n", buf->produk);
         buf->loop++;
      }
      sem_post(sem_mutex);
   }
   printf("AM LOOPS = %d\n", amLoop);
}

// WARNING: NO ERROR CHECK! ////////////
void main(void) {
   printf("STARTING PID[%d]\n", getpid());
   buffer* shrbuf = mmap(NULL,
                    sizeof(buffer), PROT, 
                    VISIBLE, 0, 0);
   persiapan(shrbuf);
   if (fork()) kirim (shrbuf); //Parent
   else        ambil (shrbuf); //Child
   sem_unlink(SEM_SYN_KRAM);
   sem_unlink(SEM_SYN_AMKR);
   sem_unlink(SEM_MUTEX);
   printf("STOP PID[%d]\n", getpid());
}

/*
 * TAKE NOTE (RMS)
 * TESTED ON WSL Windows 10:
 
 $ ./23-kirim-ambil 
 STARTING PID[241]
 PR KIRIMAN AWAL: 0
 KR KIRIM PID[241]
 AM AMBIL PID[242]
 AM 0
 KR 1
 AM 1
 KR 2
 AM 2
 AM LOOPS = 66
 STOP PID[242]
 KR LOOPS = 32
 STOP PID[241]
 $

 */

