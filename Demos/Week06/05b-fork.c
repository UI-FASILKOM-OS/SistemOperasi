/*
 * Copyright (C) 2016-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV08 Tue Mar 24 13:59:07 WIB 2020
 * REV07 Tue Jan 22 20:45:06 WIB 2019
 * REV06 Wed Aug 29 16:11:46 WIB 2018
 * REV04 Wed Nov  1 13:31:31 WIB 2017
 * START Mon Oct 24 09:42:05 WIB 2016
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void) {
   printf("Start:           PID[%5.5d] PPID[%5.5d]\n", getpid(), getppid());
   fflush(NULL);
   if (fork() == 0) {
      execlp("./00-show-pid", "00-show-pid", NULL); // ** LOOK THIS! **
      printf("Child:           ");                  // Never Executed!
   } else {
      wait(NULL);
      printf("Parent:          ");
   }
   printf(        "PID[%5.5d] PPID[%5.5d]  <<< <<< <<<\n", getpid(), getppid());
}

/*
# INFO: System call "fork()" and "execlp()"
# INFO:                   Compare "05a-fork.c" and "05b-fork.c".
# INFO:                   See also "00-show-pid.c" and system call "execlp()".
 */


