/*
 * Copyright (C) 2015-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * TAKE NOTE (MA)
 * Program ini akan mengcopy isi dari suatu file 
 * ke file lain yang sudah ada atau belum ada
 *
 * Argumen argc dan argv dari main digunakan 
 * sebagai cara untuk mengirim argumen ke program
 * argc adalah jumlah argumen,
 * argv adalah list argumennya, 
 * yang untuk list ke 0 merupakan nama filenya.
 *
 * Jadi, program ini butuh 2 argumen tambahan saat dijalankan,
 * yang pertama adalah file yang isinya mau dicopy
 * yang kedua adalah file hasil copy-annya
 * yang jika file kedua namanya sudah ada maka akan direplace isinya
 *
 * Contohnya: ./56-copy test.txt test2.txt 
 * (test.txt harus ada dibuat terlebih dahulu dahulu atau akan error)
 *
 * REV04 Tue Nov 26 11:39:10 WIB 2019
 * REV03 Wed Aug 29 20:55:23 WIB 2018
 * REV01 Mon Oct  2 16:23:50 WIB 2017
 * START Tue Apr 25 XX:XX:XX WIB 2015
 * USE "cmp file1 file2"
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define  BUF_SIZE 16

void main(int argc, char* argv[])
{
   int          fdread, fdwrite;
   unsigned int total_bytes = 0;
   ssize_t      nbytes_read, nbytes_write;
   char buf[BUF_SIZE];
   if (argc != 3) {
      printf("Usage: %s source destination\n",
      argv[0]);
      exit(1);
   }
   fdread = open(argv[1], O_RDONLY);
   if (fdread < 0) {
      perror("Failed to open source file");
      exit(1);
   }
   fdwrite = creat(argv[2], S_IRWXU);
   if (fdwrite < 0) {
      perror("Failed to open destination file");
      exit(1);
   }
   do {
      nbytes_read = read(fdread, buf, BUF_SIZE);
      if (nbytes_read < 0) {
         perror("Failed to read from file");
         exit(1);
      }
      nbytes_write = write(fdwrite, buf, nbytes_read);
      if (nbytes_write < 0) {
         perror("Failed to write to file");
         exit(1);
      }
   } while (nbytes_read > 0);
   close(fdread);
   close(fdwrite);
   exit(0);
}
