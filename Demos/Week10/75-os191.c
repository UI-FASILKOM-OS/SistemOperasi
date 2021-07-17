/*
 * Copyright (C) 2019-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 * REV02 Wed Mar 25 16:55:03 WIB 2020
 * REV01 Tue Nov 26 11:25:54 WIB 2019
 * START Wed May 15 12:40:00 WIB 2019

# INFO: UAS 2019-1 (final term)
# INFO:                   To run:   ./75-191

 */

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FILE    "75-os191-demo.txt"
#define STRING1 "AAABBBCCC"
#define STRING2 "DDDEEEFFF"
#define STRING3 "GGGHHHIII"

void main(void) {
   printf("See %s\n", FILE);
   int fd1=open(FILE, 
       O_CREAT|O_TRUNC|O_RDWR, 0644);
   int fd2=open(FILE, 
       O_CREAT|O_TRUNC|O_RDWR, 0644);
   int fd3=open(FILE, 
       O_CREAT|O_TRUNC|O_RDWR, 0644);
   write (fd1,STRING1, 9);
   write (fd2,STRING2, 6);
   write (fd3,STRING3, 3);
   close(fd1);
   close(fd2);
   close(fd3);
}
