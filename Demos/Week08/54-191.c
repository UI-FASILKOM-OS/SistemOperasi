/*
 Copyright 2019-2020 Rahmat M. Samik-Ibrahim
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

 REV02 Wed Mar 25 11:56:58 WIB 2020
 REV01 Mon Oct 28 21:11:13 WIB 2019
 START Wed May 08 09:06:00 WIB 2019

# INFO: UAS 2019-1 (final term)
# INFO:                   To run:   ./54-191 

*/

// WARNING: NO ERROR CHECK! ////////////
// exit(STATUS)    == exit with STATUS
// memcpy(*d,*s,n) == copy n from s to d
// mmap()    == creates a new memory map
// usleep(DELAY1MS) == sleep 1 MS
//
//   To run: ./54-191
//
// 
#define TURNS    15
#define LAP      25
#define DELAY1MS 901
#define DELAY    DELAY1MS*20

// ==============
typedef  struct {
   char motoGP[35];
   int  countLap;
} drivers;
drivers  D[]={
    {"(93) M Marquez    - Honda  ", 0}
   ,{"(42) A Rins       - Suzuki ", 0}
   ,{"(04) A Dovizioso  - Ducati ", 0}
   ,{"(46) V Rossi      - Yamaha ", 0}
   ,{"(09) D Petrucci   - Ducati ", 0}
   ,{"(12) M Vinales    - Yamaha ", 0}
   ,{"(43) J Miller     - Ducati ", 0}
   ,{"(30) T Nakagami   - Honda  ", 0}
   ,{"(35) C Crutchlow  - Honda  ", 0}
   ,{"(21) F Morbidelli - Yamaha ", 0}
   ,{"(44) P Espargaro  - KTM    ", 0}
   ,{"(41) A Espargaro  - Aprilia", 0}
   ,{"(21) F Quartararo - Yamaha ", 0}
   ,{"(99) J Lorenzo    - Honda  ", 0}
   ,{"(63) F Bagnaia    - Ducati ", 0}
   ,{"(36) J Mir        - Suzuki ", 0}
   ,{"(88) M Oliveira   - KTM    ", 0}
   ,{"(05) J Zarco      - KTM    ", 0}
   ,{"(06) S Bradl      - Honda  ", 0}
   ,{"(29) A Iannone    - Aprilia", 0}
   ,{"(53) T Rabat      - Ducati ", 0}
   ,{"(17) K Abraham    - Ducati ", 0}
   ,{"(55) H Syahrin    - KTM    ", 0}
   ,{"(38) B Smith      - Aprilia", 0}
};

#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define SIZEofD  (int) sizeof(D)
#define SIZEofD0 (int) sizeof(D[0])
#define NDRIVERS SIZEofD/SIZEofD0
typedef struct {
  sem_t    mutex;
  sem_t    turns[TURNS];
  pid_t    relPID;
  volatile int rTime;
  drivers  D[NDRIVERS];
} shareMem;
#define MSIZE (int) sizeof(shareMem)
#define MAXSEM   2
#define MUTEX    1
#define PROTECT PROT_READ | PROT_WRITE
#define VISIBLE MAP_SHARED|MAP_ANONYMOUS

shareMem* mymap;
// ==============
void init(void) {
   printf("[1000] INIT:  %d %d %d %d\n",
      SIZEofD, SIZEofD0, NDRIVERS, MSIZE);
   mymap=mmap(NULL, MSIZE, PROTECT, 
              VISIBLE, 0, 0);
   for (int ii=0; ii<TURNS; ii++) {
      sem_init (&(mymap->turns[ii]),
                1, MAXSEM);
   }
   sem_init (&(mymap->mutex),1,MUTEX);
   mymap->rTime=0;
   mymap->relPID=getpid() - 1000;
   memcpy(mymap->D, D, sizeof(D));
   printf("[1000] INIT:  END\n");
}   
// ======================
void motoGP(int number) {
   pid_t relPID=getpid()-mymap->relPID;
   while(mymap->D[number].countLap<LAP){
      for (int ii=0; ii<TURNS; ii++) {
         usleep(DELAY);
         sem_wait (&(mymap->turns[ii]));
         sem_post (&(mymap->turns[ii]));
      }
      mymap->rTime++;
      mymap->D[number].countLap++;
   }
   sem_wait (&(mymap->mutex));
   printf("[%d] %s Lap %2d rTime %3d\n",
      relPID, mymap->D[number].motoGP,
      mymap->D[number].countLap,
      mymap->rTime++);
   fflush(NULL);
   sem_post (&(mymap->mutex));
   exit (0);
}
// ==============
void main(void) {
   init();
   printf("[1000] motoGP:START\n");
   for (int ii=0; ii<NDRIVERS; ii++) {
      if(!fork()) motoGP(ii); 
      usleep(DELAY1MS);
   }
   printf("[1000] motoGP:RACING\n");
   for (int ii=0; ii<NDRIVERS; ii++)
      wait(NULL);
   printf("[1000] motoGP:FINISH\n");
   exit (0);
}

