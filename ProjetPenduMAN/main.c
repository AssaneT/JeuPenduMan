#define TAILLE_MAX 15
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int verifierChaine(char chaine1[], char chaine2[], int tailleChaine)
{
    for (int i = 0; i < tailleChaine; i++)
    {
        if (chaine1[i] == chaine2[i])
        {
            continue;
        } else
        {
            return 1;
        }       
    }  

    return 0;  
}

int main(int argc, char const *argv[])
{
    char rejouer[] = "Non";   //char rejouer[4] = {'N','o','n','\0'};
    FILE* fichier = NULL;

    do
    {
        fichier = fopen("listemot.txt", "r");
        char mot[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
        char motRechercher[] = "";
        char lettreSaisi = 0;
        int tailleMot = 0, vie = 0, bonLettre = 0, nombreTentative = 0;

        if (fichier != NULL)
        {
            // On peut lire dans le fichier
            printf("Fichier Ouvert avec success \n");

            fgets(mot, TAILLE_MAX, fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans mot
            
            strcpy(motRechercher, mot);
            tailleMot = strlen(motRechercher);
            

            char motAtrouver[tailleMot];

            for (int i = 0; i < tailleMot; i++)
            {
                if (motRechercher[i] != ' ')
                {
                    motAtrouver[i] = '_';
                }
            }
            
            
            /* printf("%s \n", motRechercher); // On affiche la chaîne  
            printf("%d \n", tailleMot); // On affiche la chaîne     */

            vie = 0;

            printf("\t+---+\n");
            printf("\t    |\n");
            printf("\t    |\n");
            printf("\t    |\n");
            printf("\t   ===\n");
            printf("\tMissed Letters :\n");
            printf("\t");
    
            for (int i = 0; i < tailleMot; i++)
            {
                printf("%c",motAtrouver[i]);        //  A Changer par motAretrouver
            }

            printf("\n");
                
            //  PROCHAINE ETAPE LA SAISIT
            printf("\tGuess a letter :");
            printf("\n");
            scanf("%c",&lettreSaisi);

            do
            {
                switch (vie)
                {
                case 1 :
                    printf("\t+---+\n");
                    printf("\tO    |\n");
                    printf("\t     |\n");
                    printf("\t     |\n");
                    printf("\t    ===\n");
                    printf("\tMissed Letters :\n");
                    printf("\t");
            
                    for (int i = 0; i < tailleMot; i++)
                    {
                        printf("%c",motAtrouver[i]);        //  A Changer par motAretrouver
                    }

                    printf("\n");
                        
                    //  PROCHAINE ETAPE LA SAISIT
                    printf("\tGuess a letter :");
                    printf("\n");
                    scanf("%c",&lettreSaisi);
                    break;
                case 2 :
                    printf("\t +---+\n");
                    printf("\t O   |\n");
                    printf("\t/    |\n");
                    printf("\t     |\n");
                    printf("\t    ===\n");
                    printf("\tMissed Letters :\n");
                    printf("\t");
            
                    for (int i = 0; i < tailleMot; i++)
                    {
                        printf("%c",motAtrouver[i]);        //  A Changer par motAretrouver
                    }

                    printf("\n");
                        
                    //  PROCHAINE ETAPE LA SAISIT
                    printf("\tGuess a letter :");
                    printf("\n");
                    scanf("%c",&lettreSaisi);
                    break;
                case 3 :
                    printf("\t +---+\n");
                    printf("\t O   |\n");
                    printf("\t/ \\ |\n");
                    printf("\t     |\n");
                    printf("\t    ===\n");
                    printf("\tMissed Letters :\n");
                    printf("\t");
            
                    for (int i = 0; i < tailleMot; i++)
                    {
                        printf("%c",motAtrouver[i]);        //  A Changer par motAretrouver
                    }

                    printf("\n");
                        
                    //  PROCHAINE ETAPE LA SAISIT
                    printf("\tGuess a letter :");
                    printf("\n");
                    scanf("%c",&lettreSaisi);
                    break;
                case 4 :
                    printf("\t +---+\n");
                    printf("\t O   |\n");
                    printf("\t/|\\ |\n");
                    printf("\t     |\n");
                    printf("\t    ===\n");
                    printf("\tMissed Letters :\n");
                    printf("\t");
            
                    for (int i = 0; i < tailleMot; i++)
                    {
                        printf("%c",motAtrouver[i]);        //  A Changer par motAretrouver
                    }

                    printf("\n");
                        
                    //  PROCHAINE ETAPE LA SAISIT
                    printf("\tGuess a letter :");
                    printf("\n");
                    scanf("%c",&lettreSaisi);
                    break;
                case 5 :
                    printf("\t +---+\n");
                    printf("\t O   |\n");
                    printf("\t/|\\ |\n");
                    printf("\t/    |\n");
                    printf("\t    ===\n");
                    printf("\tMissed Letters :\n");
                    printf("\t");
            
                    for (int i = 0; i < tailleMot; i++)
                    {
                        printf("%c",motAtrouver[i]);        //  A Changer par motAretrouver
                    }

                    printf("\n");
                        
                    //  PROCHAINE ETAPE LA SAISIT
                    printf("\tGuess a letter :");
                    printf("\n");
                    scanf("%c",&lettreSaisi);
                    break;
                case 6 :
                    printf("\t +---+\n");
                    printf("\t O   |\n");
                    printf("\t/|\\ |\n");
                    printf("\t/ \\ |\n");
                    printf("\t    ===\n");
                    printf("\tMissed Letters :\n");
                    printf("\t");
            
                    for (int i = 0; i < tailleMot; i++)
                    {
                        printf("%c",motAtrouver[i]);        //  A Changer par motAretrouver
                    }

                    printf("\n");
                        
                    //  PROCHAINE ETAPE LA SAISIT
                    printf("\tGuess a letter :");
                    printf("\n");
                    scanf("%c",&lettreSaisi);
                    break;
                default :
                    break;
                }

                for (int i = 0; i < tailleMot; i++)
                {
                    if ((motRechercher[i] != motAtrouver[i]) && (motRechercher[i] == lettreSaisi))
                    {
                        bonLettre = 1;
                        motAtrouver[i] = lettreSaisi;
                        //break;
                    }  
                }
        
                if (bonLettre == 0)
                {
                    vie++;
                }

                if (vie == 6)
                {
                    if (verifierChaine(motRechercher,motAtrouver,tailleMot) == 0)
                    {
                        printf("Mot trouver avec succes !! \n");
                    } else
                    {
                        printf("Echec vous avez échoué !! \n");
                    }
                } 
                
                
                printf("\n");
                printf("\n");
                printf("\n");
                bonLettre = 0;
                
            } while (vie < 6);
            
            
            printf("Bye Bye !!!\n");
            fclose(fichier); // On ferme le fichier qui a été ouvert
        }
        else
        {
            // On affiche un message d'erreur si on veut
            printf("Impossible d'ouvrir le fichier test.txt \n");
        }


        printf("Voulez vous refaire une nouvelle partie ? \n");
        printf("     Oui / Non ? \n");
        scanf("%s",rejouer);
    } while (strcmp(rejouer, "Oui") == 0);
    
    return 0;
}

