//AUTEUR FEDI KRAYEM TD4 TP2  LE CODE A ETAIT SAISI LE  14 NOVEMBRE 2020 ||    PAS DES ERREURS MAIS IL  ME MANQUE LA PARTIE VERIF  A AJOUTER ULTE:IEUREMENT 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50
#define swap(x, y) \
    {              \
        x = x + y; \
        y = x - y; \
        x = x - y; \
    }
int main()
{
	srand(0);
	int SIZE, i;
	//int tab[50];
	int *tab = (int*) malloc(50* sizeof(int));
	int statique = 0, dynamique = 0;

	puts("--MENU REMPLISSAGE-- Fedi Krayem.");
	puts("1) Donner la taille et remplir case a case .");
	puts("2) Donner la taille et remplir par des valeurs aleatoires.");
	puts("3) remplir un tableau dynamique.");

	int user_choice;
	do {
		printf("donner votre choix : ");
		scanf("%d", &user_choice);
	} while (!(user_choice <= 3 && user_choice >= 1));
	switch (user_choice)
	{
		case 1:
			{
				do { 	printf("donner la SIZE du tableau  : ");
					scanf("%d", &SIZE);
				} while (SIZE < 0);
				for (int i = 0; i < SIZE; i++)
				{
					printf("donner l'element #%d  :", i);
					scanf("%d", &tab[i]);
				}
				statique = 1;

				break;
			}
		case 2:

			{

				do { 	printf("donner la Taille du tableau : ");
					scanf("%d", &SIZE);
				} while (SIZE < 0);
				for (i = 0; i < SIZE; i++)
					tab[i] = rand() % 100;

				statique = 1;
				break;
			}
		case 3:
			{
				do { 	printf("le nombre des case  voulu : ");
					scanf("%d", &SIZE);
				} while (!(SIZE <= N && SIZE >= 1));
				for (i = 0; i < SIZE; i++)
				{
					printf("donner la case %d", i + 1);
					scanf("%d", &tab[i]);
				}

				break;
			}
	}

	system("@cls||clear");
	puts(" -- tri -- ");
	puts("1) par selection.");
	puts("2)par insertion.");
	puts("3)a bulle");
	int choix2, index, j, nbreTRI;
	do {
		printf("Choix : ");
		scanf("%d", &choix2);
	} while (!(choix2 <= 3 && choix2 >= 1));

	do {
		printf("donner le nombres des element que vous voules trier sachant que la taille du tableau est %d.\nnombre :", SIZE);
		scanf("%d", &nbreTRI);
	} while (!(choix2 <= SIZE && choix2 >= 1));

	int choix3;
	printf("choisisers le sense de TRI : \n1)croissante\n2)decroissante.\n");

	do {
		printf("Choix : ");
		scanf("%d", &choix3);
	} while (!(choix3 <= 2 && choix3 >= 1));
	if (choix3 == 1)
	{
		switch (choix2)
		{

			case 1:
				{
					for (i = 0; i < nbreTRI - 1; i++)
					{
						index = i;
						for (j = i + 1; j < nbreTRI; j++)
						{
							if (tab[j] < tab[index])
								index = j;
						}
						if (index != i)
						{
							swap(tab[i], tab[index]);
						}
					}
					break;
				}
			case 2:
				{
					for (i = 0; i < nbreTRI; i++)
					{
						j = i;
						while (j > 0 && tab[j - 1] > tab[j])
						{
							swap(tab[j], tab[j - 1]);
							j--;
						}
					}
					break;
				}
			case 3:
				{
					for (i = 0; i < nbreTRI - 1; i++)
					{
						for (j = 0; j < nbreTRI - i - 1; j++)
						{
							if (tab[j] > tab[j + 1])
							{
								swap(tab[j], tab[j + 1]);
							}
						}
					}

					break;
				}
		}
		printf("tableau apres traige : ");

		for (i = 0; i < SIZE; i++)
			printf("%d |", tab[i]);
		printf("\n");
	}
	else if (choix3 == 2)
	{
		switch (choix2)
		{
			case 1:
				{
					for (i = 0; i < nbreTRI - 1; i++)
					{
						index = i;
						for (j = i + 1; j < nbreTRI; j++)
						{
							if (tab[j] > tab[index])
								index = j;
						}
						if (index != i)
						{
							swap(tab[i], tab[index]);
						}
						break;
					}
					case 2:
					{
						for (i = 1; i < nbreTRI - 1; i++)
						{
							j = i - 1;
							index = tab[i];
							while (j >= 0 && tab[j] < index)
							{
								swap(tab[j + 1], tab[j])
								j--;
							}
						}

						break;
					}
					case 3:
					{
						for (i = 0; i < nbreTRI - 1; i++)
						{
							for (j = 0; j < nbreTRI - i - 1; j++)
							{
								if (tab[j] > tab[j + 1])
								{
									swap(tab[j], tab[j + 1]);
								}
							}
						}
						break;
					}
				}
		}
		printf("tableau apres traige : ");

		for (i = 0; i < SIZE; i++)
			printf("%d |", tab[i]);
		printf("\n");
		return 0;
	}
}
