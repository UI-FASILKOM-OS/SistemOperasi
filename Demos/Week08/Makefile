# REV07 Wed Mar 25 10:53:41 WIB 2020
# REV06 Tue May  7 20:44:12 WIB 2019
# REV05 Wed Apr 24 21:09:27 WIB 2019
# REV04 Wed Nov 14 20:38:35 WIB 2018
# REV03 Tue May  1 20:35:45 DST 2018
# START Wed Apr 18 20:55:24 WIB 2018

CC=gcc
CFLAGS=-std=gnu11 -pthread

P10=10-create-file
P11=11-create-mmap
P20=20-parent
P21=21-child
P22=22-hello-goodbye
P23=23-kirim-ambil
P50=50-181
P51=51-182
P52=52-182a
P53=53-182b
P54=54-191
P55=55-192a
P56=56-192b


EXECS= \
        $(P10) \
        $(P11) \
        $(P20) \
        $(P21) \
        $(P22) \
        $(P23) \
        $(P50) \
        $(P51) \
        $(P52) \
        $(P53) \
        $(P54) \
        $(P55) \
        $(P56) \


DEMOFILES=\
	demo-file.txt \
	demo-file.bin \
        

all:  $(EXECS)

$(EXECS): %: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
demo:
	bash .shsh

