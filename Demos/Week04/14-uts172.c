/*
 * Copyright (C) 2017-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2017-2 (midterm)
 * REV03: Sun Feb 23 16:59:31 WIB 2020
 * REV02 Wed Feb 27 19:19:35 WIB 2019
 * REV01 Thu Apr 12 20:46:48 WIB 2018
 * START Mon Oct 16 21:15:03 WIB 2017
 */

#include <stdio.h>

char* stringChar="HALLO";
char* stringPTR;

void main(void) {
    stringPTR=stringChar;
    printf ("ADDR1: %p VAL: %p STR: %s\n", &stringChar, stringChar, stringChar);
    printf ("ADDR2: %p VAL: %p STR: %s\n", &stringPTR,  stringPTR, stringPTR);
    while (*(++stringPTR) != 0 ) {
         printf ("ADDR3: %p VAL: %p STR: %s\n", &stringPTR,  stringPTR, stringPTR);
    }
    printf ("End of String = %p\n", stringPTR);
}

/*
 * TAKE NOTE (RM)
 * Program ini menggambarkan suatu pointer yang sedang menunjuk string
 * "HALLO" dipindahkan oleh perintah ++stringPTR yang ada di line 20. 
 * 
 * Ketika program ini dieksekusi akan menampilkan sejumlah baris 
 * "AADR3" dimana VAL adalah kata "HALLO" namun huruf pertamanya akan
 * hilang satu persatu. Ini bukti bahwa pointer stringPTR bergerak
 * akibat perintah pada line 20. 
 */
