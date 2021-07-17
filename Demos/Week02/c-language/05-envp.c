/*
 * Copyright (C) 2016-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
# INFO: About variable "envp" in main().
 * REV05 Fri Feb  7 01:29:46 WIB 2020
 * REV04 Tue Sep 25 11:55:22 WIB 2018
 * START Tue Sep 13 12:11:09 WIB 2016
 */

#include <stdio.h>
#include <string.h>
#define MAXLOOP 15
#define MAXLENG 45

void main(int argc, char *argv[], char **envp) {
   int ii;
   printf("=====================================================================\n");
   for (ii=0; (ii < MAXLOOP ) && (envp[ii] != NULL) ; ii++) {
      if (strlen(envp[ii]) > MAXLENG) {
         envp[ii][MAXLENG-4] = 'X';
         envp[ii][MAXLENG-3] = 'X';
         envp[ii][MAXLENG-2] = 'X';
         envp[ii][MAXLENG-1] = '\0';
      }
      printf("The value of envp[%2.2d] is %s\n", ii, envp[ii]);
   }
   printf("=====================================================================\n");
}


/*
 * TAKE NOTE (BA)
 * In the beginning this program defined a main method with argc,argv, and envp as parameters
 * and constant variable named MAXLOOP and MAXLENG
 * ARGC (argument counter) is represents the number of things that you entered into the 
 * command line when running this program on a terminal
 * ARGV (argument vector) is an array that holds the string values of the things that 
 * were entered on the command line when running this program
 * ENVP (program environment) is an array of strings that consists a list of the environment 
 * variables of your shell
 * When you run this program, this program will print your program environtment on your console
 * This program will only print as many as 15 environtment (envp[0] - envp[14]) according to 
 * the limit (MAXLOOP) and the environtment length is only 60 (MAXLENG)
 * Char 57 to 59 will be replaced with X (line 20-22) and the rest will not be printed
 */



