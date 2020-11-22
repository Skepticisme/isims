#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define BLUE(string) "\x1b[34m" string "\x1b[0m"
#define ROUGE(string) "\x1b[31m" string "\x1b[0m"

int main()
{
	char choix;
	int choix2, taille, i, j, index, tmp, dynamique = 0, tri_bulle = 0, compteur, statique = 0;
	// remplissage3 = 0;
	int tab[taille];
	int *tab_d = (int*)(malloc(taille* sizeof(int)));

	while (1)
	{
		printf("\033[1;32m");

		printf("\n**********MENU**********\t\tFEDI KRAYEM TD4 TP2\n");

		printf("\033[0m");

		if (statique == 0)
			printf("vous n'avez pas entrer aucun tableau .\n");
		else if (statique != 0)
		{
			printf("le tableau  que vous avez inserer :\n ");
			for (compteur = 0; compteur < taille; compteur++)
				printf("%d - ", tab[compteur]);
		}
		else if (dynamique == 0)
			printf("vous n'avez pas entrer aucun tableau .\n");
		else if (dynamique == 1)
		{
			printf("le tableau  que vous avez inserer : ");
			for (compteur = 0; compteur < taille; compteur++)
				printf("%d - ", tab_d[compteur]);
		}

		printf("\033[1;34m	");
		printf("\nI) REMPLISSAGE : \n");
		printf("\033[0m");
		printf("a)donner la taille puis entrer les elements .\n");
		printf("b)donner la taille et remplir le tableau avec des valeurs aleatoires.\n");
		printf("c)remplir un tableau selon le nombre es element *tableau dynamique*\n");
		printf("\033[1;34m	");

		printf("II) TRI : \n ");
		printf("\033[0m");

		printf("\n1) Selection  \n2)Insertion \n3)Bulle\n");
		printf("\033[1;34m	");

		printf("III) Verifier si un tableau est tries.\n");
		printf("\033[0m");

		printf("x)pour re-initialiser.\n");
		printf("y)pour utiliser le tableau actuel\n");

		do { 	printf(BLUE("CHOIX :"));
			scanf("%c", &choix);
		} while (choix != 'a' && choix != 'A' && choix != 'b' && choix != 'B' && choix != 'C' && choix != 'c' && choix != '1' && choix != '2' && choix != '3' && choix != 'x' && choix != 'y');
		switch (choix)
		{
			// REMPLISSAGE :
			case 'A':
			case 'a':
				{
					do {

						printf("donner la taille : ");
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

			case 'b':
			case 'B':
				{
					srand(time(NULL));

					do { 	printf("donner la taille : ");
						scanf("%d", &taille);
					} while (taille < 0);

					int tab[taille];
					for (i = 0; i < taille; i++)
					{

						tab[i] = rand() % 100;
					}

					statique = 1;

					break;
				}
			case 'C':
			case 'c':
				{
					do { 	printf("donner le nombres des element que vous voulez  : ");
						scanf("%d", &taille);
					} while (taille < 0);

					int i;

					if (tab_d == NULL)
					{
						printf("memory not available \n");
						exit(1);
					}
					for (i = 0; i < taille; i++)
					{
						printf("integer : ");
						scanf("%d", tab_d + i);
					}
					dynamique = 1;
					break;
				}
				// TRIAGE :
			case '1':
				{

					if (statique == 1)
					{
						for (i = 0; i < (taille - 1); i++)
						{
							index = i;

							for (j = i + 1; j < taille; j++)
							{
								if (tab[index] > tab[j])
									index = j;
							}
							if (index != i)
							{
								tmp = tab[i];
								tab[i] = tab[index];
								tab[index] = tmp;
							}
						}
						break;
					}
					else if (dynamique == 1)
					{
						for (i = 0; i < (taille - 1); i++)
						{
							index = i;

							for (j = i + 1; j < taille; j++)
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
						break;
					}
					break;
				}
			case '2':
				{

					{

						if (statique == 1)
						{
							for (i = 1; i <= taille - 1; i++)
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
							break ;
						}
						else if (dynamique == 1)
						{
							for (i = 1; i <= taille - 1; i++)
							{
								j = i;

								while (j > 0 && tab_d[j - 1] > tab_d[j])
								{
									tmp = tab_d[j];
									tab_d[j] = tab_d[j-1];
									tab_d[j - 1] = tmp;

									j--;
								}
							}
							break;
						}

						
					}

					break;
				}
			case '3':
				{ 		{ 			if (statique == 1)
						{
							for (int i = 0; i < taille - 1; i++)
							{
								for (j = 0; j < taille - i - 1; j++)
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
						else if (dynamique == 1)
						{
							for (i = 0; i < taille - 1; i++)
							{
								for (j = 0; j < taille - i - 1; j++)
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
					break;
				}
				/*	// III VERIFICATION :
        case 'x':
        {
            break;
        }
        case 'y':
        {
            break;
        }*/
		}
		system("@cls||clear");
	}

	return 0;
}

// before return 0 ; bracket !!!!!!!!!!!!!!!!!!!!!!!1
/*system("@cls||clear"); */
/*statique = 1 ; */