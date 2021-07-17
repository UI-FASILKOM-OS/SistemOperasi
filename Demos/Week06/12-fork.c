/*
 * Copyright (C) 2017-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV07 Tue Mar 24 16:37:32 WIB 2020
 * REV06 Wed Aug 29 16:11:46 WIB 2018
 * REV03 Wed Nov  1 13:32:11 WIB 2017
 * START Wed May  3 20:56:05 WIB 2017
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void waitAndPrintPID(void) {
   wait(NULL);
   printf("PID: %d\n", getpid());
   fflush(NULL);
}

void main(int argc, char *argv[]) {
   int rc, status;

   waitAndPrintPID();
   rc = fork();
   waitAndPrintPID();
   if (rc == 0) {
      fork();
      waitAndPrintPID();
      execlp("./00-show-pid", "00-show-pid", NULL);
   }
   waitAndPrintPID();
}

/*
# INFO: System call "fork()"
 */

