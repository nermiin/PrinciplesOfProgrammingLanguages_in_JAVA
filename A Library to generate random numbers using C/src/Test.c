/**
* @author Nermin Kaya G161210560
* @author 
* @since 6/04/2019
* <p>
* Random Library to generate character,word,phrase by C language with OOP....
* </p>
*/
#include "Mean.h"

int main()
{
    Mean m = MeanConstroctur();/*
    char st[] = "gyunec";
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    printf("Rastgele Karakter : %c\n", m->super->randchar(m->super));
    printf("Rastgele Karakter : %c\n", m->super->randchar(m->super));
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    printf("Rastgele 100 Karakter : %c");
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    for (int i = 0; i < 100; i++)
    {
        printf("%c", m->super->randchar(m->super));
    }
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    printf("\nRastgele 30 Karakter : %s\n", m->super->randNchar(m->super, 30));
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    printf("Verilen iki karakter arasinda(a,k): %c\n", m->super->randBetween('a', 'k', m->super));
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    printf("Verilen iki karakter  arasindan(a,k) 2 karakter alfabatik siraya gore :%s\n", m->super->randBetweenN('a', 'k', 2, m->super));
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    printf("Belirtilen Karakterler (g,y,u,n,e,c):  %c\n", m->super->randfromSpecific(st, m->super));
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    printf("Belirtilen karakterden (g,y,u,n,e,c) 2 karakter alfabatik siraya gore :%s\n", m->super->randfromSpecificN(st, 2, m->super));
    printf("%s\n","-------------------------------------------------------------------------------------------------");
    printf("Rastgele cumle:  %s\n", m->super->randSentence(m->super));
    printf("Rastgele cumle:  %s\n", m->super->randSentence(m->super));
    printf("%s\n","-------------------------------------------------------------------------------------------------");

    // */   m->Print(m);
    m->Mean_dest(m);
    return 0;
}