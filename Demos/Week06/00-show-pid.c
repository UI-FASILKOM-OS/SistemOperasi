/*
 * Copyright (C) 2016-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV07 Tue Mar 24 12:06:10 WIB 2020
 * REV06 Wed Aug 29 16:11:46 WIB 2018
 * REV05 Wed Nov  1 13:30:44 WIB 2017
 * START Mon Oct 24 09:42:05 WIB 2016
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(void) {
   printf("  [[[ This is 00-show-pid: PID[%d] PPID[%d] ]]]\n", getpid(), getppid());
}

/*
# INFO: Get PID dan PPID.
# INFO:                   PID  means Process ID (identification)
# INFO:                   to get PID, call system function getpid().
# INFO:                   PPID means Parent Process ID
# INFO:                   to get PPID, call system function getppid().
 */

