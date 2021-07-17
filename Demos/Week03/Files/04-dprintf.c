/*
 * Copyright (C) 2019 - 2021 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: dprintf() prints to a file descriptor (int fd).
 * REV02 Sun 21 Mar 2021 00:11:29 WIB
 * REV01 Sun 23 Feb 2020 16:38:33 WIB
 * START Mon 28 Jan 2019 10:03:57 WIB
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define DEMO "demo-file4.txt"

void main(void) {
   int filed = open (DEMO, O_APPEND | O_RDWR , 0664);
   if (filed < 0) {
      printf("fopen error...\n");
      exit(1);
   }
   dprintf(filed, "[dprintf] file: %s; descriptor: %d\n", DEMO, filed);
   printf("See also file %s\n", DEMO);
   close(filed); 
}
