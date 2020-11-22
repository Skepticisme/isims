#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LONG 10

int main(void)
{
    char text_treatment_1[20] , ptr = *text_treatment_1, aux[20] ;
     

    do
    {
        printf("Donner une chaine : ");
        gets(text_treatment_1);
    } while (strlen(text_treatment_1) > LONG);
    int i = 0;

    while (i < strlen(text_treatment_1))
    {
        if ((!isalpha(text_treatment_1[i])) && (!isalnum(text_treatment_1[i])))
        {
            text_treatment_1[i] = ' ';
        }
        i++;
    }
    int c = 0, d = 0;
    char text_treatment_2[20];
    for (ptr = text_treatment_1; *ptr; ptr++)
        while (((*ptr) == ' ') && (*(ptr + 1) == ' '))

            strcpy(ptr + 1, ptr + 2);
    while (strstr(text_treatment_1, " est ") != 0)

    {
        strcpy(aux, strstr(text_treatment_1, " est ") + strlen(" est "));
        //zid espaces

        strcpy(strstr(text_treatment_1, " est "), " etre ");

        strcat(strstr(text_treatment_1, " etre ") + 4, aux);
    }

    /* while(text_treatment_1[c]!= '\0')
    { 
        if(!(text_treatment_1[c]== ' ' &&text_treatment_1[c+1]==' ' ))
        {
            text_treatment_2[d] = text_treatment_1[c] ;
            d++ ;
        }
        c++ ;
    }
    text_treatment_2[d] = '\0' ;*/

    puts(text_treatment_1);
    return 0;
}