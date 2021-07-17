/*
 * Copyright (C) 2019-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 * REV03 Sun May  3 09:17:12 WIB 2020
 * REV02 Wed Mar 25 17:00:18 WIB 2020
 * REV01 XXX Dec 17 20:00:00 WIB 2019
 * START XXX Dec 16 15:55:00 WIB 2019

# INFO: UAS 2019-2 (final term)
# INFO:                   To run:   ./76-192

 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define FILE    "76-os192-demo.txt"

void main(void) {
   printf("See %s\n", FILE);
   printf ("OUT=%d\n", STDOUT_FILENO);
   close(STDOUT_FILENO);
   int fd1 = open (FILE, O_RDWR | 
              O_CREAT | O_TRUNC, 0644);
   int fd2 = dup2(fd1, 9);
   printf(         "A\n"); 
   fprintf(stdout, "B\n"); 
   dprintf(fd2,    "fd1=%d\nfd2=%d\n", 
                            fd1, fd2);
}

