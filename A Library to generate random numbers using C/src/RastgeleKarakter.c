/**
* @author Nermin Kaya G161210560
* @author 
* @since 6/04/2019
* <p>
* Random Library to generate character,word,phrase by C language with OOP....
* </p>
*/

#include "RastgeleKarakter.h"
#include "string.h"

rastgelekarakter constructor()
{
    rastgelekarakter this;
    this = (rastgelekarakter)malloc(sizeof(struct RastgeleKarakter));
    this->random = RandCons();     // point to SortAscending func
    this->sirala = &SortAscending; //point to SortAscending
    this->randchar = &generatechar;
    this->randNchar = &generatecharNtimes;
    this->randBetween = &randBetween;
    this->randBetweenN = &randBetweenNtimes;
    this->randfromSpecific = &RandomFromArray;
    this->randfromSpecificN = &RandomFromArrayNtimes;
    this->randword = &RandomPhrase;
    this->randSentence = &RandomPhraseM;
    this->Destructor = &Rastdestructor;
    return this;
}
// Taking struct like a parameter and SortAscending its random numbers
char *SortAscending(const rastgelekarakter rk)
{
    char a;
    for (int i = 0; i < strlen(rk->array); ++i)
    {
        for (int j = i + 1; j < strlen(rk->array); ++j)
        {
            if (rk->array[i] > rk->array[j])
            {
                a = rk->array[i];
                rk->array[i] = rk->array[j];
                rk->array[j] = a;
            }
        }
    }
    return rk->array;
}
/* calling randm function which is return integer and return the character corresponding 
to him from Ascii table */
char generatechar(const rastgelekarakter rk)
{
    rk->karak = randm(rk->random);
    return rk->karak;
}
/* number given in parameter (count) is how many times to return generatechar function 
(word length) -The task of the function is to generate random word  */
char *generatecharNtimes(const rastgelekarakter rk, int count)
{
    int i = 0;
    rk->array = (char *)malloc(sizeof(int) * count);
    for (i; i < count; i++)
    {
        rk->array[i] = generatechar(rk);
    }
    rk->array[i] = '\0';
    return rk->array;
}
/* numbers given in parameter min,max are corresponding numbers in ASCII table and 
it can be written like this 'a' , 'k'.
The task of the function is to generate random character between two given characters */
char randBetween(int min, int max, const rastgelekarakter rk)
{
    //      while statement always true and when it start a random character will generated
    //      next if statement will check if the character between a-z or A-Z then if it's correct it will be exite while statement
    //      and return it.
    while (1)
    {
        rk->karak = nanorand(rk->random);
        if ((rk->karak >= min && rk->karak <= max) && (rk->karak < 91 || rk->karak > 96))
        {
            break;
        }
    }
    return rk->karak;
}

/* The task of the function is to generate random word that is her letters are between 
min and max   */
char *randBetweenNtimes(int min, int max, int count, const rastgelekarakter rk)
{
    rk->array = (char *)malloc(sizeof(int) * count);
    //      while statement always true and when it start a random character will generated
    //      next if statement will check if the character between a-z or A-Z then if it's correct it will be exite while statement
    //      and return it.
    int i = 0;
    for (i; i < count; i++)
    {
        while (1)
        {
            rk->array[i] = nanorand(rk->random);
            if ((rk->array[i] >= min && rk->array[i] <= max) && (rk->array[i] < 91 || rk->array[i] > 96))
            {
                break;
            }
        }
    }
    rk->array[i] = '\0';
    return rk->sirala(rk);
}

/*  Generate random letter from specific range by calling rand1 function that is generate a random 
number between given two numbers */
char RandomFromArray(char RL[], const rastgelekarakter rk)
{
    rk->array = RL;
    int x = rand1(0, strlen(RL) - 1, rk->random);
    // generate a random number the return random arrays elemant ..
    return rk->array[x];
}
/* Generate word from specifec letters  */
char *RandomFromArrayNtimes(char RL[], int count, const rastgelekarakter rk)
{
    rk->array = (char *)malloc(sizeof(int) * count);
    int x;
    int i = 0;
    for (i; i < count; i++)
    {
        x = randBetween(0, strlen(RL) - 1, rk);
        rk->array[i] = RL[x];
    }
    rk->array[i] = '\0';
    // return a random arrays elemant after sort ascending ..
    return rk->sirala(rk);
}

/*  Generate a random word by calling the function that generate word and make its parameter
taken from random numbers  */
char *RandomPhrase(const rastgelekarakter rk)
{
    rk->array = (char *)malloc(sizeof(char) * 100);
    char *ss = (char *)malloc(sizeof(char) * 100);
    // generate word , word length is a random number.

    //  collect it together ..
    rk->array = generatecharNtimes(rk, rand1(2, 10, rk->random));
    ss = " ";
    strcat(rk->array, ss);
    return rk->array;
}
/*  Generate a random sentence by calling the function that generate a word in for loop 
from 3 to random number and make its parameter taken from random numbers  */
char *RandomPhraseM(const rastgelekarakter rk)
{
    char *s = (char *)malloc(sizeof(char) * 100);
    char *p = (char *)malloc(sizeof(char) * 100);
    *p = 0;
    int num = rand1(3, 9, rk->random);
    for (int i = 0; i < rand1(3, 15, rk->random); i++)
    {
        s = RandomPhrase(rk);
        p = strcat(p, s); // strcat collect words and evrey word ends with " "
    }
    rk->array = p;
    return rk->array;
}

void Rastdestructor(rastgelekarakter rk)
{
    if (rk == NULL)
        return;
    free(rk->random);
    destructor(rk->random);
    free(rk);
    rk = NULL;
}