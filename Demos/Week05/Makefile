# REV03 Fri 02 Apr 2021 07:47:15 WIB
# REV02 Thu 25 Mar 18:25:15 WIB 2021
# REV01 Sun 23 Feb 18:32:26 WIB 2020
# START Mon 03 Oct 09:21:51 WIB 2016

# INFO: With this "Makefile", just run:
# INFO:                     make

CC=gcc

EXECS= \
	12-memory


all:  $(EXECS)


12-memory: 12-memory.c 13-chktoken.c
	$(CC) -std=gnu18 12-memory.c 13-chktoken.c -o 12-memory -Xlinker  \
		-Map=12-memory.map

clean:
	rm -f ${EXECS} 
	rm -f *.map
 
.phony: all clean

