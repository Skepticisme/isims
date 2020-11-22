//  MADE WITH <3 BY FEDI KRAYEM TD4 TP2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BLUE(string) "\x1b[34m" string "\x1b[0m"
#define ROUGE(string) "\x1b[31m" string "\x1b[0m"

//PROTOCOLE :
void insertion(int T[], int n);
void selection(int T[], int n);
void bulle(int T[], int n);

//MAIN FUNCTION
void main()

{
	/*DECLARATION : */

	int n, user_choice;
	//declaring a dynamically allocated array
	int *T = (int *)malloc(n * sizeof(int));

	//  randomizing  : could also be srand(time(NULL))
	srand(0);

	//MAIN WORK

	printf(BLUE("OPTIONS :[1 or 2] \n 1. Donner des entiers \n 2. Des entiers au hasard \n"));
	//INPUT VALIDATION :
	do
	{
		printf(ROUGE("Choix  : "));
		scanf("%d", &user_choice);
	}

	while ((user_choice != 1) && (user_choice != 2));

	//  FILLING UP THE ARRAY
	switch (user_choice)

	{
	case 1:

		do
		{
			printf("Donnez la taille du tableau : ");

			scanf("%d", &n);
		}

		while ((n < 0) || (n > 100));

		for (int i = 0; i < n; i++)

		{

			printf("La case %d : ", i + 1);

			scanf("%d", &T[i]);
		}

		break;

	case 2:

		do
		{
			printf("Donnez la taille du tableau : ");

			scanf("%d", &n);
		} while ((n < 0) || (n > 100));

		for (int i = 0; i < n; i++)

			T[i] = rand() % (100 + 1);

		break;
	}

	//ACTUALLY SORTING THE ARRAY
	printf(BLUE("Type de tri : \n"));

	printf(BLUE(" 1.bulle \n 2.insertion \n 3.selection \n"));

	do
	{
		printf("Choix  : ");

		scanf("%d", &user_choice);
	}

	while ((user_choice < 1) || (user_choice > 3));

	switch (user_choice)

	{
	case 1:

		bulle(T, n);

		break;

	case 2:
		insertion(T, n);

		break;

	case 3:

		selection(T, n);

		break;
	}

	//DISPLAY

	for (int i = 0; i < n; i++)

	{
		if (i == 0)

			printf("\n<");

		printf(" %d ", T[i]);

		if (i < n - 1)

			printf("|");

		if (i == n - 1)

			printf(">  \n");
	}
}

void insertion(int T[], int n)

{
	int i, pivot, j;

	for (i = 1; i < n; i++)

	{
		pivot = T[i];
		j = i - 1;

		while (j >= 0 && T[j] > pivot)

		{

			T[j + 1] = T[j];
			j = j - 1;
		}

		T[j + 1] = pivot;
	}
}

void bulle(int T[], int n)

{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)

			if (T[j] > T[j + 1])

				temp = T[j];

	T[j] = T[j + 1];

	T[j + 1] = temp;
}

void selection(int T[], int n)

{
	int i, j, minimal_index, temp;

	for (i = 0; i < n - 1; i++)

	{
		minimal_index = i;

		for (j = i + 1; j < n; j++)

			if (T[j] < T[minimal_index])

				minimal_index = j;

		temp = T[minimal_index];
		T[minimal_index] = T[i];
		T[i] = temp;
	}
}
