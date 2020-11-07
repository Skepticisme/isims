#include <stdio.h>
int saisie(void);
int somme(int);
int palindrome(int);
int uniforme(int);
int dndeney(int);

int main()
{
   int input = -74183, choix, i;
   do
   {

      printf("\n\n--- MENU ---\t\t projet 2  |  Fedi krayem TD4 TP2\n");
      printf("taper:\n1-pour saisir un  entier positif de 8 chiffres au max .\n");
      (input < 0) ? printf("\t vous n'avez pas entree aucun entier .\n") : printf("Le nombre saisir est :%d\n", input);
      printf("2-Pour faire la somme de ses chiffres.\n");
      printf("3-Pour verifier s'il est un palindrome.\n");
      printf("4-Pour verifier s'il est unforme.\n");
      printf("5-Pour afficher tous ses diviseur.\n");
      printf("6-Pour verifier s'il est un deduney.\n");
      printf("7-Pour re-initialiser le nombre.\n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      do
      {
         puts("choix ?  : ");
         scanf("%d", &choix);

      } while (choix < 1 || choix > 7);

      switch (choix)
      {
      case 1:
      {
         input = saisie();
         break;
      }

      case 2:
      {
         somme(input);
         break;
      }
      case 3:
      {
         palindrome(input);
         break;
      }
      case 4:
      {
         uniforme(input);
         break;
      }
      case 5:
      {
         for (int i = 1; i <= input; i++)
         {
            if (input % i == 0)
            {
               printf("%d est un diviseur de %d\n", i, input);
            }
         }
      }
      break;
      case 6:
      {
         dndeney(input);
         break;
      }
      case 7:
      {
         input = saisie();
      }
      }

   } while (1);
}

int saisie()
{
   int x;
   do
   {
      printf("donner un entier : ");
      scanf("%d", &x);

   } while (x > 10000000 || x < 0);
   return x;
}

int somme(int x)
{
   int reste, somme = 0;
   while (x != 0)
   {
      reste = x % 10;
      somme += reste;
      x /= 10;
   }
   return printf("la somme = %d", somme);
}

int palindrome(int x)
{
   int reste, inverse = 0, copy = x;

   while (x != 0)
   {
      reste = x % 10;
      inverse = inverse * 10 + reste;
      x /= 10;
   }
   if (inverse == copy)
   {
      return printf("le nombre %d est palindrome \n", copy);
   }
   else
   {
      return printf("le nombre %d  n'est pas  palindrome \n", copy);
   }
}

int uniforme(int x)
{
   int copy = x / 10, FLAG = 1, reste = x % 10;
   while (copy != 0 && FLAG)
   {
      int reste2 = copy % 10;
      if (reste == reste2)
      {
         copy /= 10;
      }
      else
      {
         FLAG = 0;
      }
   }

   if (FLAG)
   {
      return printf("%d est uniforme.\n", x);
   }
   else
   {
      return printf("%d n'est pas uniforme.\n", x);
   }
}

int dndeney(int x)
{
   int S = somme(x);
   if (S * S * S == x)
   {
      return printf("%d est un nombre de dundeny  .\n", x);
   }
   else
   {

      return printf("%d n'est un nombre de dundeny  .\n", x);
   }
}
