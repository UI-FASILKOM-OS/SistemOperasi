/*
 * Copyright (C) 2015-2018 CC BY-SA 3.0 adapted from https://stackoverflow.com/
 *            questions/32205396/share-posix-semaphore-among-multiple-processes
 * Copyright (C) 2018-2020 Rahmat M. Samik-Ibrahim (slightly modified)
 * You are free to SHARE (copy and redistribute the material in any medium or 
 * format) and to ADAPT (remix, transform, and build upon the material for any 
 * purpose, even commercially).  This program is distributed in the hope that 
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV04 Sat Apr 11 17:30:03 WIB 2020
 * REV03 Wed Aug 29 20:39:16 WIB 2018
 * REV02 Wed Apr 18 22:02:52 WIB 2018
 * START Xxx Xxx XX XX:XX:XX WIB 2015
 */

#define SEM_NAME "/semaphore-demo-rms46"
/* ATTN:
   Replace the "rms46" part in SEM_NAME with your userid!
   "Dead semaphores" are lingering in folder "/dev/shm/".
   If you are the owner, you can delete "dead semaphores" manually.
 * *************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SEM_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)
#define INITIAL_VALUE 0

#define CHILD_PROGRAM "./21-child"
#define CHILDREN     2

int main(void) {
   size_t ii;
   pid_t  pids[CHILDREN], mypid=getpid();

   /* We initialize the semaphore counter to 1 (INITIAL_VALUE) */
   sem_t *semaphore = sem_open(SEM_NAME, O_CREAT | O_EXCL, SEM_PERMS, INITIAL_VALUE);

   if (semaphore == SEM_FAILED) {
      perror("sem_open(3) error");
      sem_unlink(SEM_NAME); 
      exit(EXIT_FAILURE);
   }
   for (ii = 0; ii < sizeof(pids)/sizeof(pids[0]); ii++) {
      if ((pids[ii] = fork()) < 0) {
         perror("fork(2) failed");
         exit(EXIT_FAILURE);
      } else if (pids[ii] == 0) {
         if (execl(CHILD_PROGRAM, CHILD_PROGRAM, NULL) < 0) {
            perror("execl(2) failed");
            exit(EXIT_FAILURE);
         }
      }
      printf("Parent PID[%d] creates child PID[%d]\n", mypid, pids[ii]);
   }
   printf("Parent PID[%d] signals [%s]\n", mypid, SEM_NAME);
   sem_post(semaphore);
   for (ii = 0; ii < sizeof(pids)/sizeof(pids[0]); ii++)
      wait(NULL);
   if (sem_unlink(SEM_NAME) < 0)
      perror("sem_unlink(3) failed");
   printf("Parent PID[%d] says Good Bye!\n", mypid);
   return 0;
}

/*
 * TAKE NOTE (RMS)
 * TESTED ON WSL Windows 10:
 
 $ ./20-parent 

 Parent PID[185] creates child PID[186]
 Parent PID[185] creates child PID[187]
 Parent PID[185] signals [/semaphore-demo-rms46]
 Child  PID[186] is UP!
 Child  PID[187] is UP!
 Child  PID[187] is inside  the Critical Section
 Child  PID[187] is outside the Critical Section
 Child  PID[186] is inside  the Critical Section
 Child  PID[186] is outside the Critical Section
 Child  PID[186] is inside  the Critical Section
 Child  PID[186] is outside the Critical Section
 Child  PID[187] is inside  the Critical Section
 Child  PID[187] is outside the Critical Section
 Parent PID[185] says Good Bye!

 $

*/

