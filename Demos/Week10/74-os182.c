/*
 * Copyright (C) 2018-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 * REV07 Wed Mar 25 16:53:56 WIB 2020
 * REV06 Tue Nov 26 11:39:10 WIB 2019
 * REV03 Sun Dec 16 22:10:40 WIB 2018
 * START Thu Dec 12 19:55:08 WIB 2018

# INFO: UAS 2018-2 (final term)
# INFO:                   To run:   ./74-182

 */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FLAGS O_RDWR|O_CREAT|O_TRUNC
#define MODES 0644

#define FILE3 "74-os182-demo3.txt"
#define FILE4 "74-os182-demo4.txt"

void main(void) {
   printf("See %s and %s\n", FILE3, FILE4);
   int fd3 = open (FILE3,FLAGS,MODES);
   int fd4 = open (FILE4,FLAGS,MODES);
   dprintf(fd3, "fd%d\n", fd3);
   dprintf(fd4, "fd%d\n", fd4);
   close(STDOUT_FILENO); // STDOUT = 1
   int fd1 = dup(fd3);
   close(STDERR_FILENO); // STDERR = 2
   int fd2 = dup(fd4);
   dprintf(fd1, "fd%d\n", fd1);
   dprintf(fd2, "fd%d\n", fd2);
   close (fd1);
   close (fd2);
   close (fd3);
   close (fd4);
}
