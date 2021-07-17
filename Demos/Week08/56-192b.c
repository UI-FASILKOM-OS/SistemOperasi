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

 * REV02 Wed Mar 25 12:16:00 WIB 2020
 * REV01 XXX Dec 15 15:05:00 WIB 2019
 * START XXX Dec 09 16:28:00 WIB 2019

# INFO: UAS 2019-2 (final term)
# INFO:                   Run from: ./54-192a

*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MYFLAGS     O_CREAT | O_RDWR
#define MYPROTECT PROT_READ | PROT_WRITE
#define MYVISIBILITY          MAP_SHARED
#define SFILE            "demo-file.bin"

typedef  struct {
   sem_t  sync1;
   sem_t  sync2;
   pid_t  relative;
} myshare;

myshare* mymap;

void flushprintf(char* tag){
   printf("PIDr[%d] %s\n", 
      getpid() + mymap->relative, tag);
   fflush(NULL);
}

void main(int argc, char* argv[]) {
   int fd   =open(SFILE,MYFLAGS,S_IRWXU);
   int ssize=sizeof(myshare);
   mymap=mmap(NULL, ssize, MYPROTECT, 
              MYVISIBILITY, fd, 0);
   flushprintf("START");
   if(argc == 1) {
      if (!fork()) {
         sem_post (&(mymap->sync1));
         sem_wait (&(mymap->sync2));
         flushprintf("FORK CHILD");
      } else {
         sem_wait (&(mymap->sync1));
         flushprintf("FORK PARENT");
         sem_post (&(mymap->sync2));
      }
      execlp(argv[0], argv[0], "XYZZY", NULL);
   } 
   wait(NULL);
   flushprintf("EXIT");
}

