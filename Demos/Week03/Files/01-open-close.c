/*
 * Copyright (C) 2015-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV08 Sun Feb 23 16:28:49 WIB 2020
 * REV07 Wed Feb 27 19:56:19 WIB 2019
 * REV05 Wed Aug 29 20:55:23 WIB 2018
 * REV02 Sun Oct 16 20:50:26 WIB 2016
 * START Xxx Xxx XX XX:XX:XX WIB 2015

 * === umask() ===
# INFO: int open(const char* pathname, int FLAGS, mode_t MODE);
# INFO:                   See also the FLAGS and MODE options.
 * === FLAGS: ===
 * O_RDONLY	Open the file so that it is read only.
 * O_WRONLY	Open the file so that it is write only.
 * O_RDWR	Open the file so that it can be read from and written to.
 * O_APPEND	Append new information to the end of the file.
 * O_TRUNC	Initially clear all data from the file.
 * O_CREAT	If the file does not exist, create it. 
                You must include the third parameter.
 * O_EXCL	With O_CREAT: exists, the call will fail.
 * === MODE ===
 * S_IRWXU  00700 user (file  owner) has read, write and execute permission
 * S_IRUSR  00400 user has read permission
 * S_IWUSR  00200 user has write permission
 * S_IXUSR  00100 user has execute permission
 * 
 * S_IRWXG  00070 group has read, write and execute permission
 * S_IRGRP  00040 group has read permission
 * S_IWGRP  00020 group has write permission
 * S_IXGRP  00010 group has execute permission
 * 
 * S_IRWXO  00007 others have read, write and execute permission
 * S_IROTH  00004 others have read permission
 * S_IWOTH  00002 others have write permission
 * S_IXOTH  00001 others have execute permission
 */

#define	FILE1 "demo-file1.txt"
#define	FILE2 "demo-file2.txt"
#define	FILE3 "demo-file3.txt"

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void main(void) {
   int fd; /* to hold a file descriptor */
   /* umask(0);    ******************** */
   fd = open (FILE1, O_CREAT | O_RDWR, S_IRWXU);
   close(fd);
   fd = open (FILE2, O_CREAT | O_RDWR, S_IRWXU|S_IRGRP|S_IWGRP|S_IROTH);
   close(fd);
   fd = open (FILE3, O_CREAT | O_RDWR, 0711);
   close(fd);
   fd = open (FILE3, O_CREAT | O_RDWR, 0700);
   close(fd);
}


