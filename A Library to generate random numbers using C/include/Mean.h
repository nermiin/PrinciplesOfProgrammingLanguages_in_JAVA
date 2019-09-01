/**
* @author Nermin Kaya G161210560
* @since 6/04/2019
* <p>
* Random Library to generate character,word,phrase by C language with OOP....
* </p>
*/
#ifndef MEAN_H 
#define MEAN_H 
#include "RastgeleKarakter.h"

struct MEAN
{
    rastgelekarakter super;
    void (*Print)(struct MEAN *);// point to Yazdir function
    void (*Print_rand_char)(struct MEAN *);// point to the same name function
    void (*Print_rand_word)(struct MEAN *,int);// point to the same name function
    void (*Print_rand_char_Between)(struct MEAN *,int,int);// point to the same name function
    void (*Print_rand_word_Between)(struct MEAN *,int,int,int);// point to the same name function
    void (*Print_rand_char_from_specifec)(struct MEAN *,char[]);// point to the same name function
    void (*Print_rand_word_from_specifec)(struct MEAN *,char[],int);// point to the same name function
    void (*Print_rand_sentence)(struct MEAN *);// point to the same name function
    void (*Mean_dest)(struct MEAN *);// point to the Mean_destroctor
};
typedef struct MEAN *Mean;

Mean MeanConstroctur();
void Yazdir(const Mean);
void Mean_destroctor(Mean);
void Print_rand_char(const Mean);
void Print_rand_word(const Mean,int);
void Print_rand_char_Between(const Mean,int,int);
void Print_rand_word_Between(const Mean,int,int,int);
void Print_rand_char_from_specifec(const Mean,char[]);
void Print_rand_word_from_specifec(const Mean,char[],int);
void Print_rand_sentence(const Mean);

#endif