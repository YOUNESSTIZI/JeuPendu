#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define diff 20
#include "edit.h"
void def(char* mot , char* secret) // on definit le jeu et initialiser le mot secret en ******* 
{
	int i ;
	printf("---Bonjour , Bienvenue au pendu ! \n\t\t  ") ;
	
	printf("tous les mots seront en majuscule ..\n\t meme les miniscules seront transforme en majuscules");
	
	
	for(i=0 ;i<strlen(mot) ;i++)
	{
		secret[i] = '*' ;
						
	}
	
	printf("\n\n \tessayer de deviner notre mot secret :p \t ----%s----",secret);
	
}



char lettre() // cette fonction retourne la lettre donner par l'utilisateur !!
{
	char c = NULL;
	printf("\n\n\t quel est la lettre estime--- \t");
	scanf("%c",&c);
	getchar();
	c=toupper(c);
	return c ;
	
}



int nv_secret(char* mot ,char c , char* secret) //cette procédure sert à donner le nouveau mot secret avec les lettres dévoilés ! s'il retourne 0 ca veut dire que rien n'est changé sinon on a un lettre bien devoilé
{
	int i , b=0 ;
	for(i=0;i<strlen(mot);i++)
	{
		if(*(mot+i)== c )
			{
				secret[i]=c; // on affiche la lettre deviner et les autres seront "*" ;
				b++;
			}
    }
    return b ;
	
}


int countour() // ca consiste à compter le nombre d'essaies !! et dit combien d'essais il nous reste selon difficultie
{
	int static i = diff-1 ;
	
	if(i==0)
	{
		printf("\n\n\t\tc'est termine...."); 
		return 0;
		
	}	
	
	else if(i!=0)
	{
		printf("\n\t\t il vous reste %d essais " , i) ;
		i--;
		return(i+1);
		
		
	}
	
	
 } 



int verif(char* secret ,int j) // on verifie si tout les parametre de secret ne contient pas un * !! c'est une limite pour s'arreter !!
{
	int i=0;
	while(i<j)
	{
		if(*(secret+i)=='*') 
			{
				return 1 ;
				break;
			}
		i++;
	}
	return 0 ;
	
		
}


void saut()
{
	int i;
	for(i=0;i<22;i++)
		printf("\n\n");
}

int chercher(char* mot ,char c,char* secret) // on cherche la lettre saisit dans le mot et determine sa position !! de 0 à strlen(mot)-1
{
	int b=0 , l , k;
	
	
	b=nv_secret(mot,c,secret);
	
	
    switch(b)
    {
		case(0):
    		{
    			saut();
    			printf("\n\n\tce lettre n'existe pas , reeasser svp !! --------------%s------------",secret);
				
				break;
			}	
		
		default:
		{
			saut();
			printf("\n\n\tContinue \n\t\t\t\t ---- %s -----" , secret) ;
			
			//printf("%d",l);
			
		}
		
	}
//	printf("l= %d   k= %d",l,k);
	
	k=verif(secret,strlen(mot));
	l=countour();
	
	if(l==0 && k==0)
	{
		printf("\n\n\t\t\t -- c'est gagnant ! .. le mot est : %s \n\n\t\t\t ", mot); 
		return 1 ;// si les essais sont atteint 10 and le mot est deviné !
		
		
	}
		
	if(l==0 &&  k==1 )
	{
		printf("c dommage .. vous avez perdus la gloire :) \n\n.. a la prochaine fois \n\n\t le mot est : %s \n\n\t\t\t", mot);
		return 0 ; // si les essais sont atteint 10 and le mt n'est pas encore deviné !! 
		
	}
	
	if(l != 0 && k==0)
	{
		printf("c gagnant en %d essaies :) \n\n\t le mot : est %s \n\n\t\t\t .. a la prochaine fois \n\n\t\t\t---- HAVE A NICE DAY ----- ",l+1,mot);
		return 1 ; // si les essais sont pas encore atteint 10 mais le mot est deviné !! 
		
	}
	
	return 2;
		
		
}


int nbre_hasard() // cette fonction choisit un nbrepar hazard
{
	int haz ; // c'est la case ou on stockera le nombre choisit par hazard !
	srand(time(NULL)); // on a initialisé le temps pour qu'on utilise le rand !! c'est pour l'interet de choisir un nombre par hazard !
	
	haz = (rand()) % (5) ; // pour que les nombre seront contenu dans [0,4]
	
	return(haz) ;
}


void tri_mot(int haz , char* mot) //cette fonction va trier un mot du fichier "test.txt" selon le nombre choisit ! le nbre i correspond au ligne ! chaque ligne contient un mot 
{
	int i=0 ;
	FILE* fichier ;
	fichier=fopen("test.txt","r");
	
	while(i!=haz+1)
	{
		
		fgets(mot,10,fichier) ;
		
		i++;
		
	
	}
	*(mot+strlen(mot)-1)='\0' ;
		
	
}

void jouer(char* mot)
{
	int i=2;
	char secret[strlen(mot)] ,c=NULL;
	
	def(mot,secret) ;

	while(i==2)
	{
		c=lettre();
		i=chercher(mot ,c,secret);
	
	}
	
	
}
