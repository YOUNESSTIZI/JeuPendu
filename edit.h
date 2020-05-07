void def(char* mot , char* secret);
char lettre();
int nv_secret(char* mot ,char c , char* secret);
int countour() ;
int verif(char* secret ,int j);
void saut();
int chercher(char* mot ,char c,char* secret);
void jouer(char* mot);
int nbre_hasard(); // cette fonction choisit un nbrepar hazard
void tri_mot(int haz , char* mot); //cette fonction va trier un mot du fichier "test.txt" selon le nombre choisit ! le nbre i correspond au ligne ! chaque ligne contient un mot 
