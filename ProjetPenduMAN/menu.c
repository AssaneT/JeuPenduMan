#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 
#include "jouer.h"

int main(int argc, char const *argv[])
{
    int choixMenu = 0;

    printf("\n");
    printf("\n");
    
    printf("\t-----------------    P E N D U    M A N   -----------------\n");

    printf("\tVeuillez choisir une option svp :\n");
    do
    {
        printf("\t1- Jouer\n");
        printf("\t2- Quitter\n");
        scanf("%d",&choixMenu);

        printf("\n");
        printf("\n");
    } while ((choixMenu != 1) && (choixMenu != 2));

    getchar();

    switch (choixMenu)
    {
        case 1:
            jouer();
            break;
        case 2:
            printf("Bye Bye !! \n");
            break;
        default:
            printf("Choix non prise en compte !! \n");
            break;
    }
    
    printf("Bye Bye !!!\n");

    return 0;
}
