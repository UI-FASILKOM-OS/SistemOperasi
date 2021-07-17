/*
 * Copyright (C) 2016-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * TAKE NOTE(AII)
 * getchar() reads a single character from the standard 
 * input stream and writes it to cc
 * putchar(char) writes a character (an unsigned char) 
 * specified by the argument char to stdout
 *
 * this program will continue to read character from stdin 
 * until EOF, that is, no more input from a stream
 * EOF is defined in stdio.h (and is usually -1). 
 * On linux, ctrl+d signals EOF, and on windows it's ctrl+z.
 *
 * REV05 Tue Nov 26 11:36:27 WIB 2019
 * REV04 Wed Feb 27 19:18:49 WIB 2019
 * REV03 Wed Aug 29 20:55:23 WIB 2018
 * REV01 Mon Oct  2 16:21:15 WIB 2017
 * START Mon Sep 26 18:23:45 WIB 2016
 */

#include <stdio.h>

void main(void) {
   int cc; 
   while((cc = getchar()) != EOF) { 
      putchar(cc); 
   }
}
