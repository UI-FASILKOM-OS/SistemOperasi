/*
 * Copyright (C) 2018-2020 Rahmat M. Samik-Ibrahim
 * You are free to SHARE (copy and redistribute the material in any medium or 
 * format) and to ADAPT (remix, transform, and build upon the material for any 
 * purpose, even commercially).  This program is distributed in the hope that 
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV02 Sat Apr 11 17:30:55 WIB 2020
 * REV01 Thu Nov 15 11:16:22 WIB 2018
 * START Wed Nov 14 20:30:05 WIB 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#define MYFLAGS      O_RDWR
#define MYPROTECTION PROT_READ|PROT_WRITE
#define MYVISIBILITY MAP_SHARED
char*  sfile="demo-file.bin";

typedef  struct {
   char  mystring[16];
   int   myint;
   char  ends[2];
} myshare;

void main(void) {
   struct stat fsize;
   int    ssize=sizeof(myshare);
   int    fd=open(sfile,MYFLAGS,S_IRWXU);

   printf("Create mmap()\n");
   fstat(fd, &fsize);
   if (fsize.st_size < ssize) {
      printf("Does %s exist? Size >= %d?\n", sfile, ssize);
      exit(1);
   }
   myshare* mymap=mmap(NULL, ssize, MYPROTECTION, MYVISIBILITY, fd, 0);
   if (mymap == MAP_FAILED) {
      printf("mmap(): FAILED\n");
      exit(1);
   }
   mymap->mystring[0]='X';
   mymap->mystring[1]='Y';
   mymap->mystring[2]='Z';
   mymap->mystring[3]=' ';
   mymap->myint=0x61626364;
   close(fd);
   printf("Please check  file \"%s\"\n", sfile);
}

