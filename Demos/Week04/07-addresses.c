/*
 * Copyright (C) 2015-2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV06: Sun Feb 23 16:59:31 WIB 2020
 * REV05: Tue Aug 28 18:40:36 WIB 2018
 * REV04: Wed Oct  4 19:42:01 WIB 2017
 * REV02: Sun Oct 16 20:49:03 WIB 2016
 * START: 2015
 */

#define NOP()    __asm__("nop")  /* No Operation inline gcc ASM */
#define EXTRA   6L
#define ALLOC0  0x4BD8
#define ALLOC1  0xFF8
#define ALLOC2  0x18
#define ALLOC3  0x19
#define ALLOC4  1

#include <stdio.h>
#include <stdlib.h>

unsigned int  glInt1 = 0x41;
unsigned int  glInt2 = 0x42;
unsigned int  glInt3 = 0x43;
unsigned int  glInt4 = 0x44;
unsigned int  glInt5 = 0x45;
unsigned int* heapArray[] = 
        {&glInt1, &glInt2, &glInt3, &glInt4, &glInt5};

/* ******************************************************************** */
long printVariable(char* varName, void* varValue, unsigned long endAddr) {
   long  retVal = (long) &&end;
   if (varName == NULL) {
      printf("Variable Name     Address   Size(S)/Value(V)\n");
      printf("============================================\n");
   } else if (endAddr == 0L) {
      printf("%-16s %9p\n", varName, (int*) varValue);
   } else if (endAddr == 1L) {
      printf("%-16s %9p %#11X (V) \n", varName, 
         (int*) varValue, *((unsigned int*) varValue));
   } else if (endAddr != 2L) {
      printf("%-16s %9p %#11X (S)\n", varName, (int*) varValue, 
          (unsigned int) (EXTRA + endAddr - (long) varValue));
   }
   end: return retVal;
}

/* ******************************************************************** */
long printHeapArray(int mode) {
   long  retVal = (long) &&end;
   if (mode == 0) {
      long  retVal = (long) &&end;
      printVariable("heapArray---", &heapArray, 1L);
      printVariable("heapArray[0]", &(heapArray[0]), 1L);
      printVariable("heapArray[1]", &(heapArray[1]), 1L);
      printVariable("heapArray[2]", &(heapArray[2]), 1L);
      printVariable("heapArray[3]", &(heapArray[3]), 1L);
      printVariable("heapArray[4]", &(heapArray[4]), 1L);
   }
   end: return retVal;
}

/* ******************************************************************** */
long demoMalloc(int mode) {
   long  retVal = (long) &&end;
   if (mode == 0) {
      heapArray[0]=malloc(ALLOC0);
      heapArray[1]=malloc(ALLOC1);
      heapArray[2]=malloc(ALLOC2);
      heapArray[3]=malloc(ALLOC3);
      heapArray[4]=malloc(ALLOC4);
      printHeapArray(0);
   }
   end: return retVal;
}

/* ******************************************************************** */
long tripleLoop(int mode) {
   long  retVal = (long) &&end;
   if (mode == 0) {
   label1:
      for (glInt1=0; glInt1 < 10; glInt1++) {
         label2:
         for (glInt2=0; glInt2 < 10; glInt2++) {
         label3:
            for (glInt3=0; glInt3 < 10; glInt3++) {
               NOP();
            }
         }
      }
      label4:
      printf("single loop    size (bytes) = %8ld\n", &&label4-&&label3);
      printf("double loop    size (bytes) = %8ld\n", &&label4-&&label2);
      printf("triple loop    size (bytes) = %8ld\n", &&label4-&&label1);
   }
   end: return retVal;
}

/* ******************************************************************** */
void main(void) {
   printVariable(NULL,            NULL, 0L);
   printVariable("printf",        &printf, 0L);
   printVariable("malloc",        &malloc, 0L);
   printVariable("printVariable" ,&printVariable, 
        printVariable("printVariable" ,&printVariable, 2L));
   printVariable("printHeapArray",&printHeapArray, printHeapArray(1));
   printVariable("demoMalloc",    &demoMalloc, demoMalloc(1));
   printVariable("tripleLoop",    &tripleLoop, tripleLoop(1));
   printVariable("main",          &main, (long) &&end);
   printVariable("glInt1",        &glInt1, 1L);
   printVariable("glInt2",        &glInt2, 1L);
   printVariable("glInt3",        &glInt3, 1L);
   printVariable("glInt4",        &glInt4, 1L);
   printHeapArray(0);
   demoMalloc(0);
   tripleLoop(0);
   end: return;
}

/*
 * TAKE NOTE (RL)
 * command have address too.
 * this program wants you to see the adress of some command.
 */

