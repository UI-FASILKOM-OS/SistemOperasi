/*
 * Copyright (C) 2018-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * You are free to SHARE (copy and 
 * redistribute the material in any medium
 * or format) and to ADAPT (remix, 
 * transform, and build upon the material 
 * for any purpose, even commercially).
 * This program is distributed in the hope 
 * that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS 
 * FOR A PARTICULAR PURPOSE.
 *
 * REV06 Wed Mar 25 16:52:55 WIB 2020
 * REV05 Tue Nov 26 11:39:10 WIB 2019
 * REV03 Wed Aug 29 20:55:23 WIB 2018
 * START Thu Mar 30 16:56:54 WIB 2017

# INFO: UAS 2018-1 (final term)
# INFO:                   To run:   ./73-181

 * fd2 = dup(fd1)  duplicates fd1 to fd2
 * O_RDWR   Open the file so that it can 
            be read from and written to.
 * O_TRUNC  Initially clear all data from 
            the file.
 * O_CREAT  If the file does not exist, 
            create it. 
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define FLAGS O_RDWR|O_TRUNC|O_CREAT
#define FILE "73-os181-demo.txt"

static char* str1 = "AAAAAAAAAA";
static char* str2 = "BBBBB";

void main(void) {
   int fd1, fd2, fd3;
   printf("See also file %s\n", FILE);
   /* STDIN=0, STDOUT=1, STDERR=2,
      fd1,fd2,fd3  will be 3,4,and 5 */
   fd1=open(FILE, FLAGS, 0644);
   fd2=open(FILE, FLAGS, 0644);
   fd3=dup(fd1);
   dprintf(fd1,"%s",        str1);
   dprintf(fd2,"X%dX%dX%dX",fd1,fd2,fd3);
   dprintf(fd3,"%s",        str2);
   close(fd1);
   close(fd2);
   close(fd3);
}
