#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  SIZE 50
#define swap(x,y) { x = x + y; y = x - y; x = x - y; }

int main(void)
{

    int statique = 0, dynamique = 0, user_choice;
    ;
    int size;
    int tab[size];
    int *tab_d = (int *)(malloc(SIZE * sizeof(int)));

    // int *tab = (int *)(size * sizeof(int));
    puts("*********** | MENU | ***********");
    printf("1)donner la size puis entrer les elements .\n");
    printf("2)saisir un tableau trie .\n");
    printf("3)donner la size et remplir le tableau avec des valeurs aleatoires.\n");
    printf("4)remplir un tableau selon le nombre es element *tableau dynamique*\n");
    printf("\n");
        srand(0);

    do
    {
        printf("donner votre choix : ");
        scanf("%d", &user_choice);
    } while (!(user_choice <= 5 && user_choice >= 1));

    switch (user_choice)
    {
    case 1:
    {
        do
        {
            printf("donner la size du tableau  : ");
            scanf("%d", &size);
        } while (size < 0);
        for (int i = 0; i < size; i++)
        {
            printf("donner l'element #%d", i);
            scanf("%d", &tab[i]);
        }
        statique = 1;

        break;
    }
    case 2:
    {
        do
        {
            printf("donner la size du tableau  : ");
            scanf("%d", &size);
        } while (size < 0);
        int i = 0;
        while (i < size)
        {
            do
            {
                printf("donner la case #%d : ", i);
                scanf("%d", &tab[i]);
            } while (tab[i] < tab[i + 1]);
            i++;
        }
        statique = 1;
        break;
    }
    case 3:
    {
        do
        {
            printf("donner la size du tableau  : ");
            scanf("%d", &size);
        } while (size < 0);
        for (int i = 0; i < size; i++)
        {               tab[i] = rand() % 100;
 }

        statique = 1;
        break;
    }
    case 4:
    {
        do
        {
            printf("donner la size du tableau  : ");
            scanf("%d", &size);
        } while (size < 0);
        for (int i = 0; i < size; i++)
        {
            printf("donner la case #%d : ", i);
            scanf("%d", (tab_d + i));
        }
        dynamique = 1;
        break;
    }
    }
    system("@cls||clear");
    int affichage = dynamique ^ statique;
    printf("le tableau saisi : \n: ");
    if (affichage && dynamique)
    {
        for (int i = 0; i < size; i++)
            printf("%d | ", tab_d[i]);

    }
    else if (affichage && statique)
    {
        for (int i = 0; i < size; i++)
            printf("%d | ", tab[i]);
    }

    printf("\npartie II ) TRI : \n");
    printf("choisir un sense  de tri : \n");
    printf("1) Croissante.\n2)Decroissante.\n");
    int user_choice_2, user_choice_3;
    do
    {
        printf("choix ?  : ");
        scanf("%d", &user_choice_2);
    } while ((user_choice_2 != 1) && (user_choice_2 != 2));
    if (user_choice_2 == 1)
    {
        printf("choisir une methode de tri . \n");
        printf("1- tri par selection .\n");
        printf("2- tri par insertion . \n");
        printf("3- Tri a bulle.\n");
        do
        {
            printf("Choix  : ");
            scanf("%d", &user_choice_3);
        } while ((user_choice_3 < 1) || (user_choice_3 > 3));

        int index;
        int i, j, tmp;

        switch (user_choice_3)
        {
        case 1:
        {
            if (affichage && statique)

            {
                for (i = 0; i < (size - 1); i++)
                {
                    index = i;

                    for (j = i + 1; j < size; j++)
                    {
                        if (tab[index] > tab[j])
                            index = j;
                    }
                    if (index != i)
                    {
                      swap(tab[i],tab[index]);
                       /* tmp = tab[i];
                        tab[i] = tab[index];
                        tab[index] = tmp ; */
                    }
                }
            }
            else if (affichage && dynamique)
            {
                for (i = 0; i < (size - 1); i++)
                {
                    index = i;

                    for (j = i + 1; j < size; j++)
                    {
                        if (tab_d[index] > tab_d[j])
                            index = j;
                    }
                    if (index != i)
                    {
                        swap(tab[i],tab[index]);
                        /* tmp = tab_d[i];
                        tab_d[i] = tab_d[index];
                        tab_d[index] = tmp;*/
                    }
                }
            }

            break;
        }
        case 2:
        {
            if (affichage && statique)
            {
                for (i = 1; i <= size - 1; i++)
                {
                    j = i;

                    while (j > 0 && tab[j - 1] > tab[j])
                    {
                       /* tmp = tab[j];
                        tab[j] = tab[j - 1];
                        tab[j - 1] = tmp;*/
                        swap(tab[j],tab[j-1]) ;

                        j--;
                    }
                }
            }
            else if (affichage && dynamique)
            {
                for (i = 1; i <= size - 1; i++)
                {
                    j = i;

                    while (j > 0 && tab_d[j - 1] > tab_d[j])
                    {
                       /* tmp = tab_d[j];
                        tab_d[j] = tab_d[j - 1];
                        tab_d[j - 1] = tmp;*/
                        swap(tab_d[j] , tab_d[j-1]);

                        j--;
                    }
                }
            }
            break;
        }
        case 3:

        {
            if (affichage && statique)
            {
                for (int i = 0; i < size - 1; i++)
                {
                    for (j = 0; j < size - i - 1; j++)
                    { /*Pour un ordre décroissant utiliser<*/
                        if (tab[j] > tab[j + 1])
                        {
                            /*tmp = tab[j];
                            tab[j] = tab[j + 1];
                            tab[j + 1] = tmp;*/
                            swap(tab[j],tab[j+1]); 
                        }
                    }
                }
            }
            else if (affichage && dynamique)
            {
                for (i = 0; i < size - 1; i++)
                {
                    for (j = 0; j < size - i - 1; j++)
                    { /*Pour un ordre décroissant utiliser<*/
                        if (tab_d[j] > tab_d[j + 1])
                        {
                           /* int tmp = tab_d[j];
                            tab_d[j] = tab_d[j + 1];
                            tab_d[j + 1] = tmp;*/
                            swap(tab[j+1],tab[j]) ;
                        }
                    }
                }
            }
            break;
        }
        }
        if (user_choice_2 == 2)
        {
            printf("choisir une methode de tri . \n");
            printf("1- tri par selection .\n");
            printf("2- tri par insertion . \n");
            printf("3- Tri a bulle.\n");
            do
            {
                printf("Choix  : ");
                scanf("%d", &user_choice_3);
            } while ((user_choice_3 < 1) || (user_choice_3 > 3));

            int index;
            int i, j, tmp;

            switch (user_choice_3)
            {
            case 1:
            {
                if (affichage && statique)

                {
                    for (i = 0; i < (size - 1); i++)
                    {
                        index = i;

                        for (j = i + 1; j < size; j++)
                        {
                            if (tab[index] < tab[j])
                                index = j;
                        }
                        if (index != i)
                        {
                            tmp = tab[i];
                            tab[i] = tab[index];
                            tab[index] = tmp;
                        }
                    }
                }
                else if (affichage && dynamique)
                {
                    for (i = 0; i < (size - 1); i++)
                    {
                        index = i;

                        for (j = i + 1; j < size; j++)
                        {
                            if (tab_d[index] > tab_d[j])
                                index = j;
                        }
                        if (index != i)
                        {
                            tmp = tab_d[i];
                            tab_d[i] = tab_d[index];
                            tab_d[index] = tmp;
                        }
                    }
                }

                break;
            }
            case 2:
            {
                if (affichage && statique)
                {
                    for (i = 1; i <= size - 1; i++)
                    {
                        j = i;

                        while (j > 0 && tab[j - 1] > tab[j])
                        {
                            tmp = tab[j];
                            tab[j] = tab[j - 1];
                            tab[j - 1] = tmp;

                            j--;
                        }
                    }
                }
                else if (affichage && dynamique)
                {
                    for (i = 1; i <= size - 1; i++)
                    {
                        j = i;

                        while (j > 0 && tab_d[j - 1] > tab_d[j])
                        {
                            tmp = tab_d[j];
                            tab_d[j] = tab_d[j - 1];
                            tab_d[j - 1] = tmp;

                            j--;
                        }
                    }
                }
                break;
            }
            case 3:

            {
                if (affichage && statique)
                {
                    for (int i = 0; i < size - 1; i++)
                    {
                        for (j = 0; j < size - i - 1; j++)
                        { /*Pour un ordre décroissant utiliser<*/
                            if (tab[j] > tab[j + 1])
                            {
                                tmp = tab[j];
                                tab[j] = tab[j + 1];
                                tab[j + 1] = tmp;
                            }
                        }
                    }
                }
                else if (affichage && dynamique)
                {
                    for (i = 0; i < size - 1; i++)
                    {
                        for (j = 0; j < size - i - 1; j++)
                        { /*Pour un ordre décroissant utiliser<*/
                            if (tab_d[j] > tab_d[j + 1])
                            {
                                int tmp = tab_d[j];
                                tab_d[j] = tab_d[j + 1];
                                tab_d[j + 1] = tmp;
                            }
                        }
                    }
                }
                break;
            }
            }

            printf("le tableau saisi : \n: ");
            if (affichage && dynamique)
            {
                for (int i = 0; i < size; i++)
                    printf("%d | ", tab_d[i]);
            }
            else if (affichage && statique)
            {
                for (int i = 0; i < size; i++)
                    printf("%d | ", tab[i]);
            }
        }
    }
}
