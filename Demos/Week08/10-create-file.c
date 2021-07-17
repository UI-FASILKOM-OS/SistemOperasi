/*
 * Copyright (C) 2018-2020 Rahmat M. Samik-Ibrahim
 * You are free to SHARE (copy and redistribute the material in any medium or 
 * format) and to ADAPT (remix, transform, and build upon the material for any 
 * purpose, even commercially).  This program is distributed in the hope that 
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV02 Sat Apr 11 17:30:25 WIB 2020
 * REV01 Thu Nov 15 09:51:28 WIB 2018
 * START Wed Nov 14 20:30:05 WIB 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef  struct {
   char  mystring[16];
   int   myint;
   char  ends[2];
} myshare;

#define MYFLAGS  O_CREAT|O_RDWR
char*   sfile="demo-file.bin";

void main(void) {
   printf("Create shared file \"%s\"\n", sfile);
   int ssize=sizeof(myshare);
   myshare* mymap=malloc(ssize);
   strcpy((char*) mymap,"AAAAAAAAAABBBBBBZZZZ\n");
   int fd=open(sfile,MYFLAGS,S_IRWXU);
   write(fd,mymap,ssize);
   close(fd);
   printf("Please check  file \"%s\"\n", sfile);
}

