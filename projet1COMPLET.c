#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char choice;
    int TVT, user_input, my_number, max, min, answer = 1, compteur;
    printf("*******MENU*******\t\t FEDI KRAIEM TD4 TP 2  \n");
    printf("Taper 1 pour Commencer.\nTaper 2 Pour quitter.\n");
    scanf("%c", &choice);
    if (choice == '2')
    {
        printf("Au revoir .\n");
        return EXIT_SUCCESS;
    }
    
    else if (choice == '1')
    {
        do
        {
            do
            {
                printf("donner le nombre des tentatives : ");
                scanf("%d", &TVT);
            } while (TVT < 0);

            printf("donner un intervele MIN-MAX\nmin:");
            scanf("%d", &min);
            printf("max: ");
            scanf("%d", &max);
            srand(time(NULL));
            my_number = rand() % (max - min + 1) + min;
            for (compteur = 1; compteur <= TVT; compteur++)
            {
                printf("donner un entier : ");
                scanf("%d", &user_input);
                if (user_input < my_number)
                {
                    printf("tentatives %d / %d est fausse .\n le nombre mysterieux est plus grand.\n", compteur, TVT);
                }
                else if (user_input > my_number)
                {
                    printf("tentatives %d / %d est fausse .\n le nombre mysterieux est plus petit.\n", compteur, TVT);
                }
                else
                {
                    printf("BRAVO ! vous aves gangne  apres %d tentatives !\n", compteur);
                    break;
                }
            }

            printf("si vous voulez quitter tapper 0 si vous voulez continuer taper 1");
            scanf("%d", &answer);
        } while (answer != 0);
    }
    system("PAUSE");
}