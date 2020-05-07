#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "edit.c"
 
/*ce jeu se consiste à deviner un mot lettre par lettre ! au premier temps on propose un mot à deviner , après ca sera developpé à un jeu multiple */

// tous les mots seront en majuscule .. meme les miniscule seront transformé en majuscule 









int main()
{
	char mot[100]  ;
	
	
	tri_mot(nbre_hasard() ,mot) ; //  on prend un mot du dictionnaire 
	printf("%s",mot);
	jouer(mot); // on joe avec le mot  
	return 0;
}


