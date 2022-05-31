#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 
#include "jouer.h"


void jouer()
{
    char rejouer[] = "Non";   //char rejouer[4] = {'N','o','n','\0'};
    
    do
    {
        int niveau = 0;
        const int numberOfWords = 20;
        srand((unsigned)time(NULL));    //générer un nombre aléatoire en fonction du temps pour qu'elle soit différente à chaque fois
        int ran = rand()% numberOfWords;    //Générer un nombre aléatoire entre 0 et numberOfWords - 1
        char *facile[] = {"bible", "parler", "jouer", "beure", "doyen", "canon", "effet", "buter", "jeter", "alpha", "appui", "belle", "bruit", "cadre", "crabe", "email", "faute", "gifle", "herbe", "jours"};   //le tableau avec des mots pour chaque niveau de difficulte
        char *moyen[] = {"academie", "discours", "aeroport", "agricole", "alentour", "alliance", "ancienne", "bilingue", "blessure", "caissier", "chanteur", "conduite", "demander", "ecouteur", "electeur", "fauteuil", "generale", "garantir", "habitude", "identite"};
        char *difficile[] = {"activistes", "actualites", "anglophone", "artificiel", "beneficier", "brouillage", "capricorne", "chargement", "dangereuse", "ecologiste", "entraineur", "gouverneur", "grenouille", "impossible", "individuel", "navigateur", "ordinateur", "secretaire", "tranquille", "tirailleur"};


        char motRechercher[] = "";
        char motAtrouver[20] = "";
        char missedLetter[10] = "";
        char lettreSaisi = '0';
        int missed = 0, tailleTab = 0, vie = 0, bonLettre, badLettre;

        
        printf("\t Veuillez choisir niveau : \n");
        printf("\t 1- Facile \t 2- Moyen \t 3- Difficile \n");
        scanf("%d",&niveau);

        if (niveau == 1)
        {
            strcpy(motRechercher,facile[ran]);
            tailleTab = strlen(motRechercher);
        } else if (niveau == 2)
        {
            strcpy(motRechercher,moyen[ran]);
            tailleTab = strlen(motRechercher);
        } else if (niveau == 3)
        {
            strcpy(motRechercher,difficile[ran]);
            tailleTab = strlen(motRechercher);
        }
        
        getchar();
       
        for (int k = 0; k < tailleTab; k++)
        {
            if (motRechercher[k] == ' ')
            {
                motAtrouver[k] = ' ';
            }
            else
            {    
                motAtrouver[k] = '_';
            }
        }

        printf("\n");           
        afficheMan(0,missedLetter,missed);
        printf("\n");
        afficheMotAtrouver(motAtrouver,tailleTab); 
        printf("\n");
                
        do
        {
            bonLettre = 0, badLettre = 0;  
                    
            printf("\tGuess a letter : \n");
            printf("\t");
            scanf("%c",&lettreSaisi);
                    
            for (int m = 0; m < tailleTab; m++)
            {
                if (motRechercher[m] != motAtrouver[m])
                {
                    for (int j = m; j < tailleTab; j++)
                    {
                        if (motRechercher[j] == lettreSaisi)
                        {
                            bonLettre++;
                            motAtrouver[j] = lettreSaisi;
                            continue;
                        }
                        else if(motRechercher[j] == ' ')
                        {
                            motAtrouver[j] = ' ';
                            continue;
                        }else if(motRechercher[j] != lettreSaisi)
                        {
                            badLettre = 1;
                                   
                        }
                    }
                } else
                {
                    continue;
                }    
            }

            getchar();

            if (badLettre == 1 && bonLettre == 0)
            {
                missedLetter[missed] = lettreSaisi;
                missed++;
                vie++;
            }

            afficheMan(vie,missedLetter,missed);
            afficheMotAtrouver(motAtrouver,tailleTab);
            printf("\n");
            printf("\n");
            printf("\n");

                    
            if (verifierCaractere(motRechercher,motAtrouver,tailleTab) == 0)
            {
                printf("FELECITATION vous avez trouver le mot !!! \n");
                printf("\n");
                printf("\n");
                        
                vie = 7;
            }
                    
        } while (vie < 6);

        if (vie == 6)
        {
            printf("Vous avez echouez !!!\n");
            printf("\n");
            printf("\n");
        }
                

        printf("Voulez vous refaire une nouvelle partie ? \n");
        printf("     Oui / Non ? \n");
        scanf("%s",rejouer);
    } while (strcmp(rejouer, "Oui") == 0);
}

//Fonction qui permet de verifier si le mot a été trouvée
int verifierCaractere(char motRechercher[], char motAtrouver[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        if (motRechercher[i] == motAtrouver[i])
        {
            continue;
        } else
        {
            return 1;
        }  
    }
        
    return 0;  
}

//Fonction qui affiche l'homme pendu 
void afficheMan(int vie, char *tab, int tailleMiss)
{
    switch(vie)
    {
        case 0:
        {
            printf("\t+---+\n");
            printf("\t    |\n");
            printf("\t    |\n");
            printf("\t    |\n");
            printf("\t    |\n");
            printf("\t   ===\n");

            printf("\tMissed Letters : \t");
            for (int i = 0; i < tailleMiss; i++)
            {
                printf("  %c",tab[i]);
            }  
            printf("\n");
        }break;
        case 1:
        {
            printf("\t+---+\n");
            printf("\tO   |\n");
            printf("\t    |\n");
            printf("\t    |\n");
            printf("\t    |\n");
            printf("\t   ===\n");

            printf("\tMissed Letters : \t");
            for (int i = 0; i < tailleMiss; i++)
            {
                printf("  %c",tab[i]);
            }  
            printf("\n");
        }break;
        case 2:
        {
            printf("\t +---+\n");
            printf("\t O   |\n");
            printf("\t/    |\n");
            printf("\t     |\n");
            printf("\t     |\n");
            printf("\t    ===\n");

            printf("\tMissed Letters : \t");
            for (int i = 0; i < tailleMiss; i++)
            {
                printf("  %c",tab[i]);
            }  
            printf("\n");
        }break;
        case 3:
        {
            printf("\t +---+\n");
            printf("\t O   |\n");
            printf("\t/ \\  |\n");
            printf("\t     |\n");
            printf("\t     |\n");
            printf("\t    ===\n");

            printf("\tMissed Letters : \t");
            for (int i = 0; i < tailleMiss; i++)
            {
                printf("  %c",tab[i]);
            }  
            printf("\n");
        }break;
        case 4:
        {
            printf("\t +---+\n");
            printf("\t O   |\n");
            printf("\t/ \\  |\n");
            printf("\t |   |\n");
            printf("\t     |\n");
            printf("\t    ===\n");

            printf("\tMissed Letters : \t");
            for (int i = 0; i < tailleMiss; i++)
            {
                printf("  %c",tab[i]);
            }  
            printf("\n");
        }break;
        case 5:
        {
            printf("\t +---+\n");
            printf("\t O   |\n");
            printf("\t/ \\  |\n");
            printf("\t |   |\n");
            printf("\t/    |\n");
            printf("\t    ===\n");

            printf("\tMissed Letters : \t");
            for (int i = 0; i < tailleMiss; i++)
            {
                printf("  %c",tab[i]);
            }  
            printf("\n");
        }break;
        case 6:
        {
            printf("\t +---+\n");
            printf("\t O   |\n");
            printf("\t/ \\  |\n");
            printf("\t |   |\n");
            printf("\t/ \\  |\n");
            printf("\t    ===\n");

            printf("\tMissed Letters : \t");
            for (int i = 0; i < tailleMiss; i++)
            {
                printf("  %c",tab[i]);
            }  
            printf("\n");
        }break;
    }
}

//Fonction qui affiche à chaque étape les lettres trouvées par le joueur
void afficheMotAtrouver(char motAtrouver[], int tailleTab)
{
    printf("\t");
    for (int i = 0; i < tailleTab; i++)
    {   
        printf("%c",motAtrouver[i]);
    }
}



