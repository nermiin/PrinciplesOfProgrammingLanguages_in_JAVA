/**
* @author Nermin Kaya G161210560
* @author 
* @since 6/04/2019
* <p>
* Random Library to generate character,word,phrase by C language with OOP....
* </p>
*/

#include "Random.h"
/* attribut pointers to their functions and give a value started to variables  */
Rand RandCons()
{
    Rand this;
    this = (Rand)malloc(sizeof(struct Random));
    this->max = 122;
    this->min = 65;
    this->last = rand_builder(this);
    this->nextInt = &nanorand;
    this->rand = &randm;
    this->randFromTo = &rand1;

    return this;
}
/* return time in micro second  */
char *currentTimeMillis()
{
    char *buff = malloc(sizeof(char) * 100);
    time_t simdi = time(0);
    strftime(buff, 100, "%S", localtime(&simdi));
    return buff;
}
// Take the time and make some displacement bit to get int number 
int rand_builder(const Rand r)
{
    char *X = currentTimeMillis();
    r->number = (*X << 8) + (*(X + 1) << 16) + (*(X + 2) << 24) + (*(X + 3));
    return r->number;
}
/* generate randon number by lineer generator and it change evrey time program runs 
cause it takes time in micro second from OS */
int nanorand(const Rand this)
{
    this->last = (this->last * 32719 + 3) % 32749;
    return this->last;
}
/* generates a random number between 65-122 and deletes numbers between 90-97  */
int randm(const Rand r)
{
    while (1)
    {
        r->number = nanorand(r) % ( r->max + 1 - r->min) + r->min;
        // if statement written to remove character between 90 - 97 ..
        if ((r->number > 90) && (r->number < 97))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return r->number;
}

//  Generate random number between two numbers ..
int rand1(int min, int max, const Rand r)
{
    r->number = nanorand(r) % (max + 1 - min) + min;
    return r->number;
}

void destructor(Rand this)
{
    if (this == NULL)
        return;
    free(this);
    this = NULL;
}