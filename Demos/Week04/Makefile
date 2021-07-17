# REV15 Fri  2 Apr 07:17:37 WIB 2021
# REV14 Mon 12 Oct 11:32:36 WIB 2020
# REV11 Thu 17 Jan 15:58:20 WIB 2019
# REV10 Thu  4 Oct 10:41:39 WIB 2018
# START Tue 13 Sep 11:44:18 WIB 2016

# INFO: With this "Makefile", just run:
# INFO:                     make

CC=gcc

P00=00-global-variables
P01=01-local-variables
P02=02-pointers
P03=03-pointers-of-pointers
P04=04-pointers-of-pointers-of-pointers
P05=05-chrptr-vs-intptr
P06=06-pointer-address
P07=07-addresses
P08=08-passing-parameters
P09=09-struct
P10=10-pppchar
P11=11-pppint
P12=12-uts162
P13=13-uts171
P14=14-uts172
P15=15-uts181
P16=16-uts182
P17=17-uts191
P18=18-uts192
P19=19-uts201


EXECS= \
        $(P00) \
        $(P01) \
        $(P02) \
        $(P03) \
        $(P04) \
        $(P05) \
        $(P06) \
        $(P07) \
        $(P08) \
        $(P09) \
        $(P10) \
        $(P11) \
        $(P12) \
        $(P13) \
        $(P14) \
        $(P15) \
        $(P16) \
        $(P17) \
        $(P18) \
        $(P19) \


DEMOFILES=\
	demo-file1.txt \
	demo-file2.txt \
	demo-file3.txt \
	demo-file4.txt \
	demo-file5.txt \
	demo-file6.txt \
	demo-file7.txt \
	demo-file8.txt \
	demo-file9.txt \
	demo-fileA.txt \
	demo-copy.txt  \


all:  $(EXECS)

$(P00): $(P00).c
	$(CC) -std=gnu18 $(P00).c -o $(P00) -Xlinker -Map=$(P00).map

$(P01): $(P01).c
	$(CC) -std=gnu18 $(P01).c -o $(P01) -Xlinker -Map=$(P01).map

$(P02): $(P02).c
	$(CC) -std=gnu18 $(P02).c -o $(P02)

$(P03): $(P03).c
	$(CC) -std=gnu18 $(P03).c -o $(P03)

$(P04): $(P04).c
	$(CC) -std=gnu18 $(P04).c -o $(P04)

$(P05): $(P05).c
	$(CC) -std=gnu18 $(P05).c -o $(P05)

$(P06): $(P06).c
	$(CC) -std=gnu18 $(P06).c -o $(P06)

$(P07): $(P07).c
	$(CC) -std=gnu18 $(P07).c -o $(P07) -Xlinker -Map=$(P07).map

$(P08): $(P08).c
	$(CC) -std=gnu18 $(P08).c -o $(P08)

$(P09): $(P09).c
	$(CC) -std=gnu18 $(P09).c -o $(P09)

$(P10): $(P10).c
	$(CC) -std=gnu18 $(P10).c -o $(P10)

$(P11): $(P11).c
	$(CC) -std=gnu18 $(P11).c -o $(P11)

$(P12): $(P12).c
	$(CC) -std=gnu18 $(P12).c -o $(P12)

$(P13): $(P13).c
	$(CC) -std=gnu18 $(P13).c -o $(P13)

$(P14): $(P14).c
	$(CC) -std=gnu18 $(P14).c -o $(P14)

$(P15): $(P15).c
	$(CC) -std=gnu18 $(P15).c -o $(P15)

$(P16): $(P16).c
	$(CC) -std=gnu18 $(P16).c -o $(P16)

$(P17): $(P17).c
	$(CC) -std=gnu18 $(P17).c -o $(P17)

$(P18): $(P18).c
	$(CC) -std=gnu18 $(P18).c -o $(P18)

$(P19): $(P19).c
	$(CC) -std=gnu18 $(P19).c -o $(P19)

clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
demo:
	bash .shsh

