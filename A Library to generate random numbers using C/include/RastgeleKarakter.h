/**
* @author Nermin Kaya G161210560
* @author 
* @since 6/04/2019
* <p>
* Random Library to generate character,word,phrase by C language with OOP....
* </p>
*/
#ifndef RASTGELEKARAKTER_H
#define RASTGELEKARAKTER_H

#include "stdio.h"
#include "stdlib.h"
#include "Random.h"
#include "string.h"

struct RastgeleKarakter
{
    Rand random;
    char karak;
    char *array;
    char *(*sirala)(struct RastgeleKarakter *); // pointer to SortAscending func
    char (*randchar)(struct RastgeleKarakter *); // pointer to generatechar func
    char *(*randNchar)(struct RastgeleKarakter *,int);// pointer to generatecharNtimes
    char (*randBetween)(int,int,struct RastgeleKarakter *);// pointer to randBetween
    char *(*randBetweenN)(int,int,int,struct RastgeleKarakter *);// pointer to randBetweenNtimes
    char (*randfromSpecific)(char[],struct RastgeleKarakter *);// pointer to RandomFromArray
    char *(*randfromSpecificN)(char[],int,struct RastgeleKarakter *);// pointer to RandomFromArrayNtimes
    char *(*randword)(struct RastgeleKarakter *);// pointer to RandomPhrase
    char *(*randSentence)(struct RastgeleKarakter *);// pointer to RandomPhraseM
    void (*Destructor)(struct RastgeleKarakter *);// pointer to Rastdestructor
};

typedef struct RastgeleKarakter *rastgelekarakter;
rastgelekarakter constructor();
char *SortAscending( const rastgelekarakter);
char generatechar(const rastgelekarakter);
char *generatecharNtimes(const rastgelekarakter, int);
char randBetween(int, int, const rastgelekarakter);
char *randBetweenNtimes(int, int, int,const rastgelekarakter);
char RandomFromArray(char[],const rastgelekarakter);
char *RandomFromArrayNtimes(char[], int,const rastgelekarakter);
char *RandomPhrase(const rastgelekarakter);
char *RandomPhraseM(const rastgelekarakter);
void Rastdestructor(rastgelekarakter);

#endif