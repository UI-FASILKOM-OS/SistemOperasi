/*
 * Copyright (C) 2016-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV04: Sun Feb 23 16:59:31 WIB 2020
 * REV03: Tue Aug 28 18:40:36 WIB 2018
 * REV02: Wed Oct  4 21:37:22 WIB 2017
 * START: Tue Sep 27 18:55:30 WIB 2016
 */

#include <stdio.h>

typedef struct {
   char* nama;
   int   umur;
   int   semester;
   char* NIM;
} student;

void printStruct(student* ss) {
   printf("%-10s %11s %3d %2d\n", ss->nama, ss->NIM, ss->umur, ss->semester);
}

student global;
void init(void) {
   global.nama     = "Burhan";
   global.NIM      = "1205000003";
   global.umur     = 10;
   global.semester = 2;
}

void main(void) {
   student mhs = {"Ali", 12, 1, "1205000001"};
   printStruct(&mhs);
   init();
   printStruct(&global);
}

/*
 * TAKE NOTE(BA)
 * Struct atau structur adalah tipe data yang tersedia di C yang memperbolehkan
 * gabungan dari berbagai macam data (Berbeda dengan array yang hanya boleh 1 jenis data)
 * Biasa digunakan sebagai catatan / record. Contohnya seperti catatan data mahasiswa
 * yang terdiri dari nama(char/string), npm(char), umur(int), dan lainnya
 * Line 11-16 mendefinisikan sebuah tipe data struct dengan nama student (berisi char dan int)
 * Line 18 ada method untuk mencetak data pada Struct dan Line 22 adalah global variabel
 * Line 31 membuat variabel mhs dengan tipe data struct (student) dan
 * Line 33 memanggil fungsi init untuk mengisi variabel global (Line 23-28)
 * Line 32 dan 34 akan mencetak data mahasiswa tersebut (nama,NIM,umur,semester)
 */

