#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int taille, taille2;
    do
    {

        // BOOLEANS OPERATORS
        int statique = 0;
        int dynamique = 0;
        int affichage = (statique ^ dynamique); // EN  SYNTAXE C : XOR DEVIEN  ' ^ '
        // Ce module sera utliser pour afficher le tableau s'il exist !!!!!!!!!!!.

        // THIS MENU NEEDS A LOT OF EDITING AND REFINING  ::
        printf("\nI) REMPLISSAGE : \n");
        printf("1)donner la taille puis entrer les elements .\n");
        printf("2)saisir un tableau trie .\n");
        printf("3)donner la taille et remplir le tableau avec des valeurs aleatoires.\n");
        printf("4)remplir un tableau selon le nombre es element *tableau dynamique*\n");

        printf("\nII) TRI : \n ");
        printf("\n5) Selection  \n6)Insertion \n7)Bulle\n");
        printf("III) Verifier si un tableau est tries.\n");
        printf("8)pour re-initialiser.\n");
        printf("9)pour utiliser le tableau actuel\n");
        printf("boolean AFFICHAGE : %d", affichage);
        printf("\n 0 pour quitter ...\n");

        //CHOIX DE L UTILISIATEUR :
        int choix;
        do
        {
            printf("donner votre choix : ");
            scanf("%d", &choix);
        } while (!(choix >= 0 && choix <= 9));

        int tab[taille] ;
	    int *tab_d = (int*)(malloc(taille2* sizeof(int)));

        int i;
        switch (choix)
        {
        case 1:
        {
            do
            {
                printf("donner la taille ");
                scanf("%d", &taille);
            } while (taille < 0);
            for (i = 0; i < taille; i++)
            {
                printf("donner la case numero #%d ", i + 1);
                scanf("%d", &tab[i]);
            }
            statique = 1;
            break;
        }
            /*
        case 2:

        {

            break;
        }*/

        case 3:
        {
            srand(0);
            do
            {
                printf("donner la taille ");
                scanf("%d", &taille);
            } while (taille < 0);
            for (i = 0; i < taille; i++)
            {
                tab[i] = rand() % 100;
            }

            statique = 1;
            break;
        }
        case 4:
        {
            do
            {
                printf("donner le nombre des case que vous voulez remplir :  ");
                scanf("%d", &taille2);
            } while (taille2 < 0);
            if (tab_d == NULL)
            {
                printf("Momoire invalable.  \n");
                exit(1) ;
            }
            for (i = 0; i < taille2; i++)
            {
                printf("integer : ");
                scanf("%d", tab_d + i);
            }
            dynamique = 1 ; 
            break ;
        }
        case 5 : 
        { 
            
            break ; 
        }
        }while(1)  ;


    return 0;
    } 