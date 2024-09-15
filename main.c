#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char titre[100][100];
char auteur[100][100];
int quantite[100];
float prix[100];
int compteur = 0;
//fonction d'ajouter des livre
void ajouter(){
    int choix;
        printf("Entrer les informations suivantes : \n");
        printf("Titre de Livre : ");
        fgets(titre[compteur], 100, stdin);
        titre[compteur][strcspn(titre[compteur], "\n")] = '\0';
        printf("Auteur : ");
        fgets(auteur[compteur], 100, stdin);
        auteur[compteur][strcspn(auteur[compteur], "\n")] = '\0';
        printf("Qantite a stoquer : ");
        scanf("%d", &quantite[compteur]);
        printf("Prix de Livre : ");
        scanf("%f", &prix[compteur]);
        //check si le livre est dejat existe 
        //strcmpi() ignore the cases
        compteur++;          
}
void afficher(){
    for (int i=0; i<compteur; i++){
        printf("\n\t********\n");
        printf("Information de Livre %d\n", i+1);
        printf("Titre de livre : %s\n", titre[i]);
        printf("auteur : %s\n", auteur[i]);
        printf("Quantite disponible : %d\n", quantite[i]);
        printf("Prix : %.2f\n", prix[i]);
        printf("\n\t********\n");
    }

}
void modifier(){
    char livreModifier[100];
    int status, existe;
    printf("Entrer le titre de livre a modifier : \n");
    fgets(livreModifier, 100, stdin);
    livreModifier[strcspn(livreModifier, "\n")] = '\0';
    for (int i=0; i<compteur; i++){
        existe = 0;
        status = strcmp(titre[i], livreModifier);
        if (!status){
            existe = 1;
            printf("Entrer la nouvelle quantite : ");
            scanf("%d", &quantite[i]);  
            break;
        }    
    } 
    if(existe == 0){
        printf("Pas de livre avec ce titre.");
    } 

    
}
void lister(){
    int somme = 0;
    for (int i=0; i<compteur; i++){
        somme = somme + quantite[i];
    }
    printf("Le nombre totale de livre est %d", somme);
}
int main(){

    int option;

    do {
        printf("\n-------------------------------------------------------------------------\n");
        printf("\t\t\tMenu d'opperation possible :\n");
        printf("1.  Ajouter un livre au stock.\n");
        printf("2.  Afficher tous les livres disponibles.\n");
        //printf("3.  Rechercher un livre par son titre.\n");
        printf("3.  Mettre a jour la quantite d'un livre.\n");
        printf("4.  Supprimer un livre du stock.\n");
        printf("5.  Afficher le nombre total de livres en stock.\n");
        printf("6.  Entrer 7 pour quiter le programme.\n");
        printf("\n---------------------------------------------------------------------\n");
        printf("Entrer votre choix : ");
        scanf("%d", &option);
        char buffer;
        scanf("%c", &buffer);

        switch(option){
            case 1: 
                ajouter();
                break;
            case 2:
                afficher();
                break;
            case 3:
                modifier();
                break;
            case 5:
                lister();
                break;
        }


    }while(option != 6);
}