#!/bin/bash
# REV06: Wed Mar 25 16:45:00 WIB 2020
# REV05: Tue Mar 24 11:54:46 WIB 2020
# REV04: Sun Feb 23 14:59:35 WIB 2020
# REV03: Wed Feb 19 15:40:43 WIB 2020
# REV02: Wed Feb 19 07:13:45 WIB 2020
# START: Fri Feb  7 00:19:25 WIB 2020
# 
# Copyright (C) 2020 Rahmat M. Samik-Ibrahim
# http://RahmatM.Samik-Ibrahim.vLSM.org/
# This is a free script/software.

# INFO: This will generate file 000-READ-THIS-FIRST.txt

FILE="000-READ-THIS-FIRST.txt"
MEMOFILE=".zzz-doREADTHISFIRST"
FALLOC=15
PREFIX="^# INFO: "
ORIG="$(pwd)"

function INFO() {
   [ -e $1 ] && {
      RESULT=$(grep "$PREFIX" "$1" | cut -c9-)
      [ -z "$RESULT" ] || printf "[%${FALLOC}s] %s\n" "$1" "$RESULT"
   }
}

[ -z "$1" ]               || { INFO $1 ; exit 0; }
DATE=$(date)
for II in \
.  \
.. \
../Week00/ \
../Week01/ \
../Week02/ \
../Week02/c-language/  \
../Week02/permissions/ \
../Week03/ \
../Week03/FUSE/  \
../Week03/Files/ \
../Week04/ \
../Week05/ \
../Week06/ \
../Week07/ \
../Week08/ \
../Week09/ \
../Week09/disk-images/ \
../Week09/systemd/ \
../Week10/ \
; do
   [ -f $II/$MEMOFILE ] && {
      pushd $II
      echo "# INFO: Read This First! ==== ========= ========="       >  $FILE
      echo "# Version: $DATE"                                       >> $FILE
      echo "cat \$0; exit 0;"                                       >> $FILE
      [ -f $ORIG/zzv-download.txt ]  && cat $ORIG/zzv-download.txt  >>  $FILE
      cat $MEMOFILE                                     >> $FILE
      for JJ in $(ls) ; do [ -f $JJ ] && INFO $JJ        >> $FILE ; done
      [ -f $ORIG/zzx-thanks.txt ]    && cat $ORIG/zzx-thanks.txt    >> $FILE
      [ -f $ORIG/zzy-copyright.txt ] && cat $ORIG/zzy-copyright.txt >> $FILE
      popd
   }
done

exit 0

