# (c) 2011-2017 Rahmat M. Samik-Ibrahim -- This is free software
# Feel free to copy and/or modify and/or distribute it, 
# provided this notice, and the copyright notice, are preserved. 
#
# REV06 Thu Apr 12 20:48:58 WIB 2018
# REV02 Fri Apr 28 19:11:50 WIB 2017
# REV00 Xxx Sep 30 XX:XX:XX UTC 2015
# START Xxx Mar 30 02:13:01 UTC 2011

CC=gcc
CCOPT=-std=gnu99
CCLNK=-pthread -lrt
 
P00=00-thread
P01=01-thread
P02=02-prodkon
P03=03-readwrite
P04=04-readwrite
P05=05-alu
P06=06-balap
P07=07-sudokuSV
P08=08-mainDadu
P09=09-rpsls
P10=10-kirikanan
P11=11-thread
P12=12-multi-thread
P13=13-mini-sudoku-4x4


P99=99-myutils
 

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


OBJ= \
	$(P00).o \
	$(P01).o \
	$(P02).o \
	$(P03).o \
	$(P04).o \
	$(P05).o \
	$(P06).o \
	$(P07).o \
	$(P08).o \
	$(P09).o \
	$(P10).o \
	$(P11).o \
	$(P12).o \
	$(P13).o \
	$(P99).o \


all:	$(EXECS)

$(P00): $(P00).o $(P99).o
	$(CC) $(CCOPT) $(P00).o $(P99).o $(CCLNK) -o $(P00)

$(P00).o: $(P00).c $(P99).h
	$(CC) -c $(CCOPT) $(P00).c

$(P01): $(P01).o $(P99).o
	$(CC) $(CCOPT) $(P01).o $(P99).o $(CCLNK) -o $(P01)

$(P01).o: $(P01).c $(P99).h
	$(CC) -c $(CCOPT) $(P01).c

$(P02): $(P02).o $(P99).o
	$(CC) $(CCOPT) $(P02).o $(P99).o $(CCLNK) -o $(P02)

$(P02).o: $(P02).c $(P99).h
	$(CC) -c $(CCOPT) $(P02).c

$(P03): $(P03).o $(P99).o
	$(CC) $(CCOPT) $(P03).o $(P99).o $(CCLNK) -o $(P03)

$(P03).o: $(P03).c $(P99).h
	$(CC) -c $(CCOPT) $(P03).c

$(P04): $(P04).o $(P99).o
	$(CC) $(CCOPT) $(P04).o $(P99).o $(CCLNK) -o $(P04)

$(P04).o: $(P04).c $(P99).h
	$(CC) -c $(CCOPT) $(P04).c

$(P05): $(P05).o $(P99).o
	$(CC) $(CCOPT) $(P05).o $(P99).o $(CCLNK) -o $(P05)

$(P05).o: $(P05).c $(P99).h
	$(CC) -c $(CCOPT) $(P05).c

$(P06): $(P06).o $(P99).o
	$(CC) $(CCOPT) $(P06).o $(P99).o $(CCLNK) -o $(P06)

$(P06).o: $(P06).c $(P99).h
	$(CC) -c $(CCOPT) $(P06).c

$(P07): $(P07).o $(P99).o
	$(CC) $(CCOPT) $(P07).o $(P99).o $(CCLNK) -o $(P07)

$(P07).o: $(P07).c $(P99).h
	$(CC) -c $(CCOPT) $(P07).c

$(P08): $(P08).o $(P99).o
	$(CC) $(CCOPT) $(P08).o $(P99).o $(CCLNK) -o $(P08)

$(P08).o: $(P08).c $(P99).h
	$(CC) -c $(CCOPT) $(P08).c

$(P09): $(P09).o $(P99).o
	$(CC) $(CCOPT) $(P09).o $(P99).o $(CCLNK) -o $(P09)

$(P09).o: $(P09).c $(P99).h
	$(CC) -c $(CCOPT) $(P09).c

$(P10): $(P10).o $(P99).o
	$(CC) $(CCOPT) $(P10).o $(P99).o $(CCLNK) -o $(P10)

$(P10).o: $(P10).c $(P99).h
	$(CC) -c $(CCOPT) $(P10).c

$(P11): $(P11).o $(P99).o
	$(CC) $(CCOPT) $(P11).o $(P99).o $(CCLNK) -o $(P11)

$(P11).o: $(P11).c $(P99).h
	$(CC) -c $(CCOPT) $(P11).c

$(P12): $(P12).o $(P99).o
	$(CC) $(CCOPT) $(P12).o $(P99).o $(CCLNK) -o $(P12)

$(P12).o: $(P12).c $(P99).h
	$(CC) -c $(CCOPT) $(P12).c

$(P13): $(P13).o $(P99).o
	$(CC) $(CCOPT) $(P13).o $(P99).o $(CCLNK) -o $(P13)

$(P13).o: $(P13).c $(P99).h
	$(CC) -c $(CCOPT) $(P13).c

$(P99).o: $(P99).c $(P99).h
	$(CC) -c $(CCOPT) $(P99).c

clean:
	rm -f $(EXECS)
	rm -f $(OBJ)

