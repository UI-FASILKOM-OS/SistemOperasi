/*
 * Copyright (C) 2016-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * TAKE NOTE (AII)
 * getchar() reads a single character from the standard input
 * stream and writes it to cc
 * putchar(char) writes a character (an unsigned char)
 * specified by the argument char to stdout
 *
 * REV04 Tue Nov 26 11:35:03 WIB 2019
 * REV03 Wed Aug 29 20:55:23 WIB 2018
 * REV02 Thu Oct  5 10:17:47 WIB 2017
 * START Mon Sep 26 18:23:45 WIB 2016
 */

#include <stdio.h>

void main (void) {
   int cc = getchar(); 
   putchar(cc); 
   putchar('\n');
}
