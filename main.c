#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char titre[100][100];
char auteur[100][100];
int quantite[100];
float prix[100];
char livreRechercher[100];
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
        compteur++;
       /* if (compteur=100) {
          printf("Pas de place pour stocker ce livre.");
       } */        
}
//Fonction d'afficher les detailles de livre.
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
void details(){
    int status, existe;
    printf("Entrer le titre de livre a modifier : \n");
    fgets(livreRechercher, 100, stdin);
    livreRechercher[strcspn(livreRechercher, "\n")] = '\0';
    for (int i=0; i<compteur; i++){
        existe = 0;
        status = strcmp(titre[i], livreRechercher);
        if (!status){
            existe = 1;
            printf("Information de Livre rechercher :\n");
            printf("Titre de livre : %s\n", titre[i]);
            printf("auteur : %s\n", auteur[i]);
            printf("Quantite disponible : %d\n", quantite[i]);
            printf("Prix : %.2f\n", prix[i]);  
            break;
        }    
    } 
    if (existe == 0){
        printf("Livre n'existe pas dans le stcks.\n");
    }
    
}
//Fonction pour modifier la quantite d'un Livre
void modifier(){
    
    int status, existe;
    printf("Entrer le titre de livre a modifier : \n");
    fgets(livreRechercher, 100, stdin);
    livreRechercher[strcspn(livreRechercher, "\n")] = '\0';
    for (int i=0; i<compteur; i++){
        existe = 0;
        status = strcmp(titre[i], livreRechercher);
        if (!status){
            existe = 1;
            printf("Entrer la nouvelle quantite : ");
            scanf("%d", &quantite[i]);  
            printf("La Quantite est Bien modifier.");
            break;
        }    
    } 
    if(existe == 0){
        printf("Pas de livre avec ce titre, Essayer de le ajouter.");
    }     
}
//Fonction pour supprimer Un livre
void supprimer(){
    char search_livre[100];
    int position;
    printf("Entrer le titre de Livre a suprimer : ");
    fgets(search_livre, 100, stdin);
    search_livre[strcspn(search_livre, "\n")] = '\0';
    //int status = strcmp(search_livre, titre[100])
    for(int i=0; i<compteur; i++){
        if (strcmp(search_livre, titre[i]) == 0){
            position = i;
            break;
        }
    }
    for (int i = position; i<compteur-1; i++){
        strcpy(titre[i], titre[i+1]);
    }
    printf("Le livre est bien supprimer.");
    compteur--;
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
        printf("3.  Rechercher un livre par son titre.\n");
        printf("4.  Mettre a jour la quantite d'un livre.\n");
        printf("5.  Supprimer un livre du stock.\n");
        printf("6.  Afficher le nombre total de livres en stock.\n");
        printf("7.  Entrer 7 pour quiter le programme.\n");
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
                details();
                break;
            case 4:
                modifier();
                break;
            case 5:
                supprimer();
                break;
            case 6:
                lister();
                break;
            case 7:
                break;
            default :
                printf("L'operation souhaiter n'existe pas.");
        }


    }while(option != 7);
    system("pause");
    return 0;
}