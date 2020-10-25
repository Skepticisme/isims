#include <stdio.h>
#include <stdlib.h>

int main()
{
  int choix;
  int inputValue = -1, testing_Copy_of_inputValue, somme = 0, modulo10, inverser = 0, booleanTEST = 1, modulo10_2;
  ;
  do
  {
    printf("\t\t\t***********MENU***********\t --FEDI KRAYEM TD4 TP2. \n");
    printf("Tapper : \n");
    printf("1-Pour Donner Un entier de 8 chiffres au MAX.");
    (inputValue < 0) ? printf("\t vous n'avez pas entre aucun nombre \n") : printf("\t\tvotre choix actuelle est :%d\n", inputValue);
    printf("2-Pour faire la somme de ses chiffres.\n");
    printf("3-Pour verifier s'il est un palindrome.\n");
    printf("4-Pour verifier s'il est unforme.\n");
    printf("5-Pour afficher tous ses diviseur.\n");
    printf("6-Pour verifier s'il est un deduney.\n");
    printf("7-Pour re-initialiser le nombre.\n");
    printf("-------------------------------------------------\n");
    do
    {
      printf("Choix : ");
      scanf("%d", &choix);
    } while ((choix > 7) || (choix < 1));
    testing_Copy_of_inputValue = inputValue;

    switch (choix)
    {
    case 1: //getting user input which has less than 8 digits and strictly positive
    {

      do
      {
        printf("Donner votre nombre:\n");
        scanf("%i", &inputValue);
      } while (inputValue < 0);
      break;
    }
    case 2:
    {
      if (inputValue < 0)
      {
        printf("AUCUNE VALEUR N'A ETAIT ENTREE\n");
      }
      else
      {
        while (testing_Copy_of_inputValue != 0)
        {
          modulo10 = testing_Copy_of_inputValue % 10;
          somme += modulo10;
          testing_Copy_of_inputValue /= 10;
        }
        printf("la somme est =%4d\n", somme);
        break;
      }
    }

    case 3:
    {
      if (inputValue < 0)
      {
        printf("AUCUNE VALEUR N'A ETAIT ENTREE.\n");
      }
      else
      {
        while (testing_Copy_of_inputValue != 0)
        {
          modulo10 = testing_Copy_of_inputValue % 10;

          inverser = (inverser * 10) + modulo10;
          testing_Copy_of_inputValue = testing_Copy_of_inputValue / 10;
        }
        (inverser == inputValue) ? printf("Oui %d est un palindrome\n", inputValue) : printf("Non %d n'est pas un palindrome\n", inputValue);
      }
      break;
    }

    case 4:
    {
      if (inputValue < 0)
      {
        printf("AUCUNE VALEUR N'A ETAIT ENTREE.\n");
      }
      else
      {
        modulo10 = testing_Copy_of_inputValue % 10;
        testing_Copy_of_inputValue = inputValue / 10;
        if (testing_Copy_of_inputValue == 0)
        {
          printf("Le nombe %d est UNIFROME", inputValue);
        }
        else
        {
          while (booleanTEST == 1 && testing_Copy_of_inputValue != 0)
          {
            modulo10_2 = testing_Copy_of_inputValue % 10;
            if (modulo10 == modulo10_2)
            {
              testing_Copy_of_inputValue /= 10;
            }
            else
            {
              booleanTEST = 0;
            }
          }
          (booleanTEST == 1) ? printf("Le nombe %d est UNIFROME", inputValue) : printf("Le nombe %d n'est pas UNIFROME", inputValue);
        }
      }

      break;
    }

    case 5:
    {
      if (inputValue < 0)
      {
        printf("AUCUNE VALEUR N'A ETAIT ENTREE.\n");
      }
      else
      {
        for (int i = 1; i <= inputValue; i++)
        {
          if (inputValue % i == 0)
          {
            printf("%d est un diviseur de %d\n", i, inputValue);
          }
        }
      }
      break;
    }

    case 6:
    {
      if (inputValue < 0)
      {
        printf("AUCUNE VALEUR N'A ETAIT ENTREE.\n");
      }
      else
      {
        while (testing_Copy_of_inputValue != 0)
        {
          modulo10 = testing_Copy_of_inputValue % 10;
          somme += modulo10;
          testing_Copy_of_inputValue /= 10;
        }

        ((somme * somme * somme) == inputValue) ? printf("oui %d est un nombdre de dundeney.\n", inputValue) : printf("non %d n'est pas un nombdre de dundeney.\n", inputValue);
      }
      break;
    }

    case 7:
    {
      do
      {
        printf("donner une nouvelle valeur : ");
        scanf("%d", &inputValue);
      } while (inputValue < 0);
      printf("C'est bon le nombre est re-initialisee\n");
      break;
    }
    }

  } while (1);
  return 0;
}