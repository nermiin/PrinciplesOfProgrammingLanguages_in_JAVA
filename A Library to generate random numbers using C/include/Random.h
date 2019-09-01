/**
* @author Nermin Kaya G161210560
* @author 
* @since 6/04/2019
* <p>
* Random Library to generate character,word,Sentences by C language with OOP....
* </p>
*/

#ifndef RANDOM_H
#define RANDOM_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
//The struct Random is designed to contain variables and functions like a class in c++ language .
struct Random
{
    int max; // what is the largest random number to be generated ! 
    int min; // what is the smallest random number to be generated ! 
    unsigned last; // When run a program it takes random number 
    int number;
    int (*rand)(struct Random *); // pointer to randm function
    int (*nextInt)(struct Random *); // pointer to nanorand function
    int (*randFromTo)(int, int, struct Random *); // pointer to rand1 func
    void (*Rand_destructor)(struct Random *); // pointer to destructor func
};
typedef struct Random *Rand;

Rand RandCons();
char *currentTimeMillis();
int randm(const Rand);
int rand_builder(const Rand);
int nanorand(const Rand);
int rand1(int, int, const Rand);
void destructor(const Rand);

#endif