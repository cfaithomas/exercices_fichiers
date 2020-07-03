 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*******************************prototype************************************/
void menu();
int saisieid();
void findetudiant();
void lirealletudiant();
void ajouteretudiant();
bool openfile();
void sortir();
void erreur();
/*****************************Variables glabales et structures********************************/
 typedef struct etudiant
 {
     int id;
     char nom[255];
     float moyenne;
 }etu;
 etu etudiant; //déclaration de l'instance
 FILE *p; //pointeur de flux
int main() {

    /***************************Exercice n°2**********************************/
    /*FILE *pRead;
    char car;

    pRead = fopen("../amis.dat", "r");
    if ( pRead == NULL )
        goto ErrorHandler;
    else {


        while ( !feof(pRead) ) {
           fscanf(pRead,"%c",&car);
           if(car==';')
           {
               printf("%c",'\n');
           }
               else
           printf("%c",car);
        }


    }
    exit(EXIT_SUCCESS);
    ErrorHandler:
    perror("Une erreur est survenue");
    exit(EXIT_FAILURE);
    /******************Exercice  n°3*****************************************/
   menu();
}



void menu() {
    int choix = 0;
    printf("1-Ajouter un étudiant\n");
    printf("2-Afficher les informations de tous les étudiants\n");
    printf("3-Rechecher une étudiant\n");
    printf("4-Quitter\n");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            ajouteretudiant();
            break;
        case 2:
            lirealletudiant();
            break;

        case 3:
            findetudiant(saisieid());
            break;
        case 4:
            sortir();
            break;
    }
    menu();
}

bool openfile(char* file,char *mode)
{
    p = fopen(file,mode);
    if (p == NULL)
        return false;
    else
        return true;
}

void ajouteretudiant() {

    char choix='o';

    while(choix=='o') {
        printf("Veuillez saisir l'id");
        scanf("%d", &etudiant.id);
        printf("Veuillez saisir le nom");
        scanf("%s", etudiant.nom);
        printf("Veuillez saisir la moyenne");
        scanf("%f", &etudiant.moyenne);
        printf("Voulez-vous saisir une autre entrée");
        scanf(" %c",&choix);
    }

    if (!openfile("../etudiants.dat", "a"))
        erreur();
    else {

        fprintf(p, "%d %s %f\n",etudiant.id,etudiant.nom,etudiant.moyenne);
        fclose(p);


    }
}

    void lirealletudiant()
    {

        if (!openfile("../etudiants.dat", "r"))
           erreur();
        else {
            printf("ID\tNom\t\tmoyenne\n\n"); //Entête

            while ( fscanf(p, "%d%s%f", &etudiant.id, etudiant.nom,&etudiant.moyenne)!=-1 ) {
                printf("%d\t%s\t%f\n",etudiant.id,etudiant.nom,etudiant.moyenne);
            }


        }
        fclose(p);
    }



void findetudiant(int idrecherche)
{

    if (!openfile("../etudiants.dat", "r"))
        erreur();
    while (fscanf(p, "%d%s%f", &etudiant.id, etudiant.nom,&etudiant.moyenne)!=-1 )
    {

        if(etudiant.id==idrecherche) {
            printf("%d\t%s\t%f\n", etudiant.id,etudiant.nom,etudiant.moyenne);
            fclose(p);
            return; //sort de la fonction
        }

    }
    printf("Etudiant non trouvé\n");
    fclose(p);
}


int saisieid()
{
    int idrecherche;
    printf("Veuillez saisir l'id de l'étudiant");
    scanf("%d",&idrecherche);
    return idrecherche;

}



void sortir()
{
    exit(EXIT_SUCCESS);
}

void erreur()
{
    printf("Une erreur est survenue");
}

