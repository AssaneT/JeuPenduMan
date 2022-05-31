#define TAILLE_MAX 15
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int verifierChaine(char chaine1[], char chaine2[], int tailleChaine)
{
    int ok = 0;

    for (int i = 0; i < tailleChaine; i++)
    {
        if (chaine1[i] == chaine2[i])
        {
            ok = 1;
        } else if (chaine2[i] == '_')
        {
            ok = 2;
            break;
        }
        else
        {
            ok = 3;
            break;
        }       
    }  

    return ok;
}

int main(int argc, char const *argv[])
{
    char rejouer[] = "Non";   //char rejouer[4] = {'N','o','n','\0'};
    FILE* fichier = NULL;
    fichier = fopen("listemot.txt", "r");
    //char mot[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
    char motRechercher[] = "";
    char lettreSaisi = 0;
    int tailleMot = 0, vie = 0, bonLettre = 0, nombreTentative = 0;
    int i = 0, bon = 0;
    long curseur = 0;


    do
    {
        fseek(fichier, curseur, SEEK_CUR);

        if (fichier != NULL)
        {
            // On peut lire dans le fichier
            printf("Fichier Ouvert avec success \n");

            do
            {
                bonLettre = fgetc(fichier);
                printf("%c", bonLettre); 
                motRechercher[i] = bonLettre;
                tailleMot++;
                i++;
            } while (bonLettre != '\n');

            char motAtrouver[tailleMot];

            for (int j = 0; j < tailleMot-1; j++)
            {
                if (motRechercher[j] == ' ')
                {
                    motAtrouver[j] = ' ';
                } else
                {
                    motAtrouver[j] = '_';
                }     
            }
            
             for (int o = 0; o < tailleMot-1; o++)
             {
                 printf("%c",motRechercher[o]);        //  A Changer par motAretrouver
             }
            
            printf("\n");
            
            /* printf("%s \n", motRechercher); // On affiche la chaîne  
            printf("%d \n", tailleMot); // On affiche la chaîne   */  

            vie = 0;

            while (vie < 6)
            {
                bon = 0;
                printf("\tMissed Letters :\n");
                printf("\t");
                for (int k = 0; k < tailleMot-1; k++)
                {
                    printf("%c",motAtrouver[k]);        //  A Changer par motAretrouver
                }

                printf("\n");
                
                //  PROCHAINE ETAPE LA SAISIT
                printf("\tGuess a letter :");
                printf("\n");
                scanf("%c",&lettreSaisi);
                nombreTentative++;

                getchar();

                for (int l = 0; l < tailleMot-1; l++)
                {
                    if ((motRechercher[l] != motAtrouver[l]))
                    {
                        if ((motRechercher[l] == lettreSaisi))
                        {
                            bon = 1;
                            motAtrouver[l] = lettreSaisi;
                        } else if (motRechercher[l] == ' ')
                        {
                            motAtrouver[l] = ' ';
                        }
                    }  
                }
        
                if (bon == 0)
                {
                    vie = vie + 1;
                    printf("vie = %d \n", vie);
                }   

                /*int n = verifierChaine(motRechercher,motAtrouver,tailleMot);
                if (n == 1)
                {
                    printf("Mot trouvé avec success !!");
                    vie = 6;
                } else if ((n == 2) && (vie == 6))
                {
                    printf("Echec vous avez echouee 1 !!");
                } else if ((n == 3) && (vie == 6))
                {
                    printf("Echec vous avez echouee 2 !!");
                }   */
                
                
                printf("\n");
                printf("\n");
                printf("\n");     
            }  
            
            
            printf("Bye Bye !!!\n");
            fclose(fichier); // On ferme le fichier qui a été ouvert
        }
        else
        {
            // On affiche un message d'erreur si on veut
            printf("Impossible d'ouvrir le fichier test.txt \n");
        }

        curseur = curseur + 20;

        printf("Voulez vous refaire une nouvelle partie ? \n");
        printf("     Oui / Non ? \n");
        scanf("%s",rejouer);
    } while (strcmp(rejouer, "Oui") == 0);
    
    return 0;
}

