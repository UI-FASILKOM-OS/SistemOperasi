/*
 * (c) 2011-2018 Rahmat M. Samik-Ibrahim -- This is free software
 * Feel free to copy and/or modify and/or distribute it, 
 * provided this notice, and the copyright notice, are preserved. 
 * REV04 Wed Aug 29 18:47:14 WIB 2018
 * REV03 Tue Nov  7 19:51:39 WIB 2017
 * REV02 Mon Nov  7 14:33:08 WIB 2016
 * START Xxx Mar 30 02:13:01 UTC 2011
 */

#include <semaphore.h>

#define MAX_THREAD 256
#define MAX_globalID 5
#define BUFFER_SIZE  5
#define TRUE         1
#define FALSE        0

extern sem_t    mutex, db, empty, full, globalIDmutex;

typedef struct {
   int   buffer[BUFFER_SIZE];
   int   in;
   int   out;
   int   count;
} bbuf_t;

void daftar_trit   (void* trit);      // mempersiapkan "trit"
void jalankan_trit (void);            // menjalankan dan menunggu hasil dari
                                      // "daftar_trit"
void beberes_trit  (char* pesan);     // beberes menutup "jalankan_trit"

void rehat_acak    (long max_mdetik); // istirohat acak "0-max_mdetik" (ms)

void init_globalID (void);            // globalID
int getADDglobalID (int id);          // globalID[id]++

void init_buffer   (void);            // init buffer
void enter_buffer  (int entry);       // enter  an integer item 
int remove_buffer  (void);            // remove the item

void init_rw       (void);            // init readers writers
int  startRead     (void);            // start reading
int  endRead       (void);            // end reading
void startWrite    (void);            // start writing
void endWrite      (void);            // end writing

/*
 * TAKE NOTE ()
 */

