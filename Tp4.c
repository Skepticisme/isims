// Code writte by skepticisme .
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define LONG 100
 
int main( )
{
	char string[LONG];

	// Reading the string :

	do {
		printf("Donner une chaine a traiter : ");
		gets(string);
	} while (strlen(string) >= LONG);

	//  Replacing non alpha - nums "etre" spaces
	unsigned int i = 0, LENGTH = strlen(string);

	for (i; i < LENGTH; ++i)
	{
		if (!(isalnum(string[i])))
		{
			string[i] = ' ';
		}
	}

	// Replacing useless spaces :
	unsigned int c = 0, d = 0;
	char *blank = malloc(50* sizeof(char));
	while (string[c] != '\0')
	{
		if (!(string[c] == ' ' && string[c + 1] == ' '))
		{
			blank[d] = string[c];
			d++;
		}
		c++;
	}

	blank[d] = '\0';


	if (isblank(blank[0]))
	{
		i = 1;
	while (blank[i] != '\0')
	{
		string[i - 1] = blank[i];
		i++;
	}
	string[strlen(blank)] = '\0';


	}
	else
    {
        strcpy(string,blank) ;
    }
	free(blank); 





// Replacing all the occurances of " est " by " etre"
  char *position_if_exists = strstr(string, "est");
        
        
	 do
    {

      

        memmove(
            position_if_exists + strlen("etre"),
            position_if_exists + strlen("est"),
            30);

        strncpy(position_if_exists, "etre", strlen("etre"));

        position_if_exists = strstr(string, "est");
    }
    while (position_if_exists);

	

 


puts(string) ;
}
