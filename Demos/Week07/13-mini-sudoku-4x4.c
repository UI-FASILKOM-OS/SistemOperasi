/*
 * Copyright (C) 2017-2020 Rahmat M. Samik-Ibrahim (2017-2)
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV10 Sat Apr 11 13:34:55 WIB 2020
 * REV09 Wed Mar 25 10:41:35 WIB 2020
 * REV08 Wed Aug 29 18:45:09 WIB 2018
 * START Mon Dec  4 18:52:57 WIB 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"
#define  WaitSudoku 3
#define  SSIZE      4
#define  TOTALSIZE  SSIZE * SSIZE

int    globalExit=FALSE;
sem_t  mutexing;
sem_t  syncing1;
sem_t  syncing2;

// cellSudoku[row][column][0]   = value
// cellSudoku[row][column][1-4] = guesses
// if (value != 0) all guesses  = 0 
//                      (no more guesses)
int cellSudoku[][SSIZE+1][SSIZE+1]={
   {},{{}, {0,1,2,3,4}, {0,1,2,3,4}, 
           {0,1,2,3,4}, {0,1,2,3,4}},
      {{}, {0,1,2,3,4}, {0,1,2,3,4}, 
           {0,1,2,3,4}, {0,1,2,3,4}},
      {{}, {0,1,2,3,4}, {0,1,2,3,4},
           {0,1,2,3,4}, {0,1,2,3,4}},
      {{}, {0,1,2,3,4}, {0,1,2,3,4}, 
           {0,1,2,3,4}, {0,1,2,3,4}}
};

// Print Cells
void printCells(char* state) {
   printf ("\nSudoku Cells: %s\n", state);
   for (   int jj=1; jj<SSIZE+1; jj++) {
      for (int kk=1; kk<SSIZE+1; kk++) {
         int cell=cellSudoku[jj][kk][0];
         if (cell == 0 || cell == 5) 
                         printf ("[ ]");
         else     printf ("[%d]", cell);
         if (kk == SSIZE) printf ("\n");
      }
   }
   fflush(NULL);
}

// Filling the CELLs
void
fillCell(int rowCell,int colCell,int valCell)
{
   sem_wait (&mutexing);
   // Filling  "valCell" into 
   // cellSudoku[rowCell, colCell];
   cellSudoku[rowCell][colCell][0] = valCell;
   // This is Cell is "taken". 
   // Eliminate all guesses!
   for (int ii=1; ii<SSIZE+1; ii++) {
      cellSudoku[rowCell][colCell][ii] = 0;
   }
   // Deleting "valCell" 
   // from all "columns guess"
   for (int ii=1; ii<SSIZE+1; ii++) {
      cellSudoku[rowCell][ii][valCell] = 0;
   }
   // Delete "valCell" from all "rows guess".
   for (int ii=1; ii<SSIZE+1; ii++) {
      cellSudoku[ii][colCell][valCell] = 0;
   }
   // Delete "valCell" from all "boxes guess".
   rowCell = 1 + 2*((rowCell - 1)/2);
   colCell = 1 + 2*((colCell - 1)/2);
   for (int ii=rowCell; ii<rowCell+2; ii++) {
      for (int jj=colCell;jj<colCell+2;jj++){
         cellSudoku[ii][jj][valCell] = 0;
      }
   }
   sem_post (&mutexing);
}

// From Standard Input into Cell using 
// fillCell  -- SCAN INPUT: scanf() 
// is the oposite of printf()
void inputCell(void) {
   for (int ii=0; ii < TOTALSIZE; ii++) {
      int tmpCell=0;
      scanf("%d", &tmpCell);
      int rowCell = ii/4 + 1;
      int colCell = ii%4 + 1;
      if (tmpCell != 0) {
            fillCell(rowCell,colCell,tmpCell);
      }
   }
}

// CellWatcher
int cwID = 0;
void* cellWatcher (void* a) {
  sem_wait (&syncing1);
  sem_wait (&mutexing);
  int rowCell = cwID/4 + 1;
  int colCell = cwID%4 + 1;
  cwID++;
  sem_post (&mutexing);
  int localExit=FALSE;
  while (!localExit && !globalExit) {
    int tmpCell=0, nZero=0;
    for (int ii=1; ii<SSIZE+1; ii++) {
      if(cellSudoku[rowCell][colCell][ii]==0) 
        nZero++;
      else 
        tmpCell=ii;
    }
    if (nZero==3) 
      fillCell(rowCell, colCell, tmpCell);
    localExit = 
      cellSudoku[rowCell][colCell][0]!=0;
  }
  fflush(NULL);
  sem_post (&syncing2);
}

// Timeout after "WaitSudoku"
void* managerSudoku (void* a) {
  sleep(WaitSudoku);
  for (int ii=0; ii<TOTALSIZE; ii++) {
    int rowCell = ii/4 + 1;
    int colCell = ii%4 + 1;
    if(cellSudoku[rowCell][colCell][0]==0){
       cellSudoku[rowCell][colCell][0]= 5;
    }
    sem_post (&syncing2);
  }
  globalExit = TRUE;
}

// Display Sudoku
void* displaySudoku (void* a) {
   printCells("INITIAL");
   for(int jj=0;jj<TOTALSIZE;jj++) 
      sem_post(&syncing1);
   for(int jj=0;jj<TOTALSIZE;jj++) 
      sem_wait(&syncing2);
   printCells("RESULT");
}

// This is MAIN
void main(void) {
   printf   ("MAIN:\nRUN: ./13-mini-sudoku-4x4 < 13-1-data-sudoku.txt");
   printf   (     "\n OR: Enter the value of the 16 cells (4x4)\n");
   sem_init (&mutexing, 0, 1);
   sem_init (&syncing1, 0, 0);
   sem_init (&syncing2, 0, 0);
   inputCell();
   for (int ii=0; ii<TOTALSIZE; ii++) {
      daftar_trit(cellWatcher);
   }
   daftar_trit   (displaySudoku);
   daftar_trit   (managerSudoku);
   jalankan_trit ();
   beberes_trit  ("\nTRIT: EXIT");
}

// END
/* ***
PROMPT> ./13-mini-sudoku-4x4 < 13-1-data-sudoku.txt

MAIN: START

Sudoku Cells: INITIAL
[ ][ ][ ][3]
[ ][1][4][ ]
[ ][2][3][ ]
[1][ ][ ][ ]

Sudoku Cells: RESULT
[2][4][1][3]
[3][1][4][2]
[4][2][3][1]
[1][3][2][4]

TRIT: EXIT

PROMPT>
0 0  0 3
0 1  4 0
0 2  3 0
1 0  0 0

# INFO: SUDOKU 4x4
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished.
# INFO:                   sem_init():      init a semaphore.
# INFO:                   sem_wait():      wait a semaphore.
# INFO:                   sem_post():      signal a semaphore.
 */

