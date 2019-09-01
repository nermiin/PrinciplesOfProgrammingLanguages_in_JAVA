/**
* @author Nermin Kaya G161210560
* @author 
* @since 6/04/2019
* <p>
* Random Library to generate character,word,phrase by C language with OOP....
* </p>
*/
#include "Mean.h"

Mean MeanConstroctur()
{
    Mean this;
    this = (Mean)malloc(sizeof(struct MEAN));
    this->super = constructor();
    this->Print = &Yazdir;
    this->Print_rand_char = &Print_rand_char;
    this->Print_rand_word = &Print_rand_word;
    this->Print_rand_char_Between = &Print_rand_char_Between;
    this->Print_rand_word_Between = &Print_rand_word_Between;
    this->Print_rand_char_from_specifec = &Print_rand_char_from_specifec;
    this->Print_rand_word_from_specifec = &Print_rand_word_from_specifec;
    this->Print_rand_sentence = &Print_rand_sentence;
    this->Mean_dest = &Mean_destroctor;
    return this;
}
//============================ DISPLAY FUNCTION =================================
void Yazdir(const Mean m)
{
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    m->Print_rand_char(m);
    m->Print_rand_char(m);
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    m->Print_rand_word(m,3);
    m->Print_rand_word(m,3);    
    m->Print_rand_word(m,100);
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    m->Print_rand_char_Between(m,'a','k');
    m->Print_rand_char_Between(m,'a','k');
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    m->Print_rand_word_Between(m,'a','k',2);
    m->Print_rand_word_Between(m,'a','k',2);
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    m->Print_rand_char_from_specifec(m,"gyunec");
    m->Print_rand_char_from_specifec(m,"gyunec");
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    m->Print_rand_word_from_specifec(m,"gyunec",2);
    m->Print_rand_word_from_specifec(m,"gyunec",2);
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    Print_rand_sentence(m);
    Print_rand_sentence(m);
    printf("%s\n","-------------------------------------------------------------------------------------------------");
}
//========================================================================================

void Print_rand_char(const Mean m)
{
    printf("Rastgele Karakter : %c\n", m->super->randchar(m->super));
}
void Print_rand_word(const Mean m, int length)
{
    printf("Rastgele %d Karakter : %s\n",length, m->super->randNchar(m->super, length));
}
void Print_rand_char_Between(const Mean m, int char1, int char2)
{
    printf("Verilen iki karakter arasinda(a,k): %c\n", m->super->randBetween(char1, char2, m->super));
}
void Print_rand_word_Between(const Mean m, int char1, int char2, int length)
{
    printf("Verilen iki karakter arasindan(a,k) %d karakter alfabatik siraya gore :%s\n",length, m->super->randBetweenN(char1, char2, length, m->super));
}
void Print_rand_char_from_specifec(const Mean m, char st[])
{
    printf("Belirtilen Karakterler (g,y,u,n,e,c):  %c\n", m->super->randfromSpecific(st, m->super));
}
void Print_rand_word_from_specifec(const Mean m, char st[], int length)
{
    printf("Belirtilen karakterden (g,y,u,n,e,c) %d karakter alfabatik siraya gore :%s\n",length, m->super->randfromSpecificN(st, length, m->super));
}
void Print_rand_sentence(const Mean m)
{
    printf("Rastgele cumle:  %s\n", m->super->randSentence(m->super));
}


void Mean_destroctor(Mean m)
{
    if (m == NULL)
        return;
    if (m->super != NULL)
        m->super->Destructor(m->super);
    free(m);
    m = NULL;
}