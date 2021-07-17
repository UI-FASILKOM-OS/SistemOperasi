/*
 * Copyright (C) 2016-2021 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TOP (Table of Processes)
 * REV11 Fri  2 Apr 07:51:05 WIB 2021
 * REV10 Tue 30 Mar 18:03:18 WIB 2021
 * REV07 Fri 26 Mar 22:52:06 WIB 2021
 * REV06 Thu 25 Mar 13:52:59 WIB 2021
 * REV05 Wed 27 Feb 19:16:52 WIB 2019
 * START Mon 03 Oct 09:26:51 WIB 2016
 */

#define TOKEN  "OS211W05"
// #define MSTARTS 0x16BE5
#define MSTARTS 0x16BE4
// #define MSTARTS 0xDE5
// #define MSTARTS 0xDE4
// #define MSTARTS 0x3E4
// #define MSTARTS 0x1E5
// #define MSTARTS 0x1E4

#define MSIZE14 0x40609
#define MSIZE13 0x40609
#define MSIZE12 0x40608
#define MSIZE11 0x40608
#define MSIZE10 0x20FE8
#define MSIZE09 0x20FE8
#define MSIZE08 0x1F609
#define MSIZE07 0x1F609
#define MSIZE06 0x1F608
#define MSIZE05 0x1F608
#define MSIZE04 0x1E609
#define MSIZE03 0x1E609
#define MSIZE02 0x1E609
#define MSIZE01 0x1E608
#define MSIZE00 0x1E608
#define LINE   75
#define MAXSTR 80
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

typedef  unsigned char* uChrPtr;
void     chktoken (uChrPtr token);

void printLine(int line) {
   while(line-- > 0) putchar('x');
   putchar('\n');
   fflush(NULL);
}

uChrPtr GlobalChar[MSTARTS];

void main(void) {
   int   msize[] = {MSIZE00, MSIZE01, MSIZE02, MSIZE03, MSIZE04, 
                    MSIZE05, MSIZE06, MSIZE07, MSIZE08, MSIZE09,
                    MSIZE10, MSIZE11, MSIZE12, MSIZE13, MSIZE14};
   int   ii, jj;
   int   myPID    = (int) getpid();
   char  strSYS1[MAXSTR], strOUT[MAXSTR];
   char* chrPTR; 
   char* chrStr;

   printLine(LINE);
   chktoken(TOKEN);
   printLine(LINE);

   sprintf(strSYS1, "top -b -n 1 -p%d | tail -5", myPID);
   system (strSYS1);
   sprintf(strSYS1, "top -b -n 1 -p%d | tail -1", myPID);
   printf("PART 1\n");
   printLine(LINE);
   for (ii=0; ii < (sizeof(msize)/sizeof(int)); ii++){
      chrStr = malloc(msize[ii]);
      FILE* filePtr=popen(strSYS1, "r");
      fgets(strOUT, sizeof(strOUT)-1, filePtr);
      pclose(filePtr);
      strOUT[(int) strlen(strOUT)-1]='\0';
      printf("%s [%X]\n", strOUT, msize[ii]);
      free(chrStr);
   }
/*
   printf("\nPART 2\n");
   printLine(LINE);
   for (ii=0; ii < (sizeof(msize)/sizeof(int)); ii++){
      chrPTR = chrStr = malloc(msize[ii]);
      for (jj=0;jj<msize[ii];jj++)
         *chrPTR++='x';
      FILE* filePtr=popen(strSYS1, "r");
      fgets(strOUT, sizeof(strOUT)-1, filePtr);
      pclose(filePtr);
      strOUT[(int) strlen(strOUT)-1]='\0';
      printf("%s [%X]\n", strOUT, msize[ii]);
      free(chrStr);
   }
*/
}

