/*
 * Copyright (C) 2013-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: An introduction to function scanf().
 * REV04 Sun Feb 23 16:17:15 WIB 2020
 * REV03 Fri Feb  7 01:30:37 WIB 2020
 * REV02 Tue Aug 28 13:31:19 WIB 2018
 * START 2013
 */


#include <stdio.h> 
#include <stdlib.h> 

void main(void) { 
   int ii; 
   char buf[10];
   printf("Write a string: ");
   scanf("%s",buf);
   printf("Isi buffer = %s\n",buf);
}

/*
 * TAKE NOTE(AII)
 * scanf() reads formatted data from standard input 
 * and then writes the results into the arguments given
 * 
 * the line scanf("%s",buf); will read string inputted by
 * user and write the value to variable buf
 */

