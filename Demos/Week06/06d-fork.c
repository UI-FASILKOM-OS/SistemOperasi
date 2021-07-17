/*
 * Copyright (C) 2005-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV09 Tue Mar 24 16:28:08 WIB 2020
 * REV08 Tue Apr  2 12:17:22 WIB 2019
 * REV06 Wed Aug 29 16:11:46 WIB 2018
 * REV05 Wed Nov  1 13:34:33 WIB 2017
 * REV00 Mon Oct 24 10:43:00 WIB 2016
 * START 2005
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*************************************************** main ** */
void main(void) {
   pid_t val1, val2, val3;
   val3 = val2 = val1 = 1000;
   printf("PID==[%5.5d] ==== ======= ==== =======\n", getpid());
   // THREE FORK()s //
   fflush(NULL);
   val1 = fork();
   wait(NULL);
   val2 = fork();
   wait(NULL);
   val3 = fork();
   wait(NULL);
   printf("VAL1=[%5.5d] VAL2=[%5.5d] VAL3=[%5.5d]\n", val1, val2, val3);
}

/*
# INFO: System call "fork()"
# INFO:                   Compare 
# INFO:                      "06a-fork.c" [no    fork()],
# INFO:                      "06b-fork.c" [one   fork()],
# INFO:                      "06c-fork.c" [two   fork()s],
# INFO:                      "06d-fork.c" [three fork()s],
 */

