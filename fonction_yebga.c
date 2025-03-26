#include "fonction_yebga.h"

int fonction_hachageYE(const char *valYE){
    int sommeYE = 0;
    int iYE=0;
    while(valYE[iYE] != '\0'){
        sommeYE = sommeYE+ valYE[iYE];
        iYE++;
    } 
    return sommeYE % taille;
}

void ajouter_etudiantYE(liste *tYE,etudiant eYE){
    int indexYE = fonction_hachageYE(eYE.matricule);
    liste nouveauYE = malloc(sizeof(*nouveauYE));
    nouveauYE->info = eYE;
    nouveauYE->suivant = NULL;

    if (tYE[indexYE] == NULL){
        tYE[indexYE] = nouveauYE;
    }else{
        liste sYE=tYE[indexYE];
        while (sYE != NULL){
            sYE=sYE->suivant;
        }
        sYE->suivant = nouveauYE;
        tYE[indexYE]=nouveauYE;
    }
}

etudiant recherche_etudiantYE(liste *tYE,char *matriculeYE){
    
    int indexYE = fonction_hachageYE(matriculeYE);
    
    while (tYE[indexYE] != NULL){
        if(strcmp(tYE[indexYE]->info.matricule,matriculeYE) == 0){
            return tYE[indexYE]->info;
        }
        tYE[indexYE]=tYE[indexYE]->suivant;
    }
}

int verification_matriculeYE(char *matriculeYE){
    //test sur la taille 
    if(strlen(matriculeYE) != 7){
        return 0;
    }
    //test sur les 2 premiere lettre
    if(matriculeYE[0] != '2' || matriculeYE[1] != '4'){
        return 0;
    }
    //test sur le 3emme charactere
    if(matriculeYE[2] != 'a' && matriculeYE[2] != 'b' && matriculeYE[2] != 'c' && matriculeYE[2] != 'd' && matriculeYE[2] != 'e' && matriculeYE[2] != 'f' && matriculeYE[2] != 'g' && matriculeYE[2] != 'h' && matriculeYE[2] != 'i' && matriculeYE[2] != 'j' && matriculeYE[2] != 'k' && matriculeYE[2] != 'l' && matriculeYE[2] != 'm' && matriculeYE[2] != 'n' && matriculeYE[2] != 'o' && matriculeYE[2] != 'p' && matriculeYE[2] != 'q' && matriculeYE[2] != 'r' && matriculeYE[2] != 's' && matriculeYE[2] != 't' && matriculeYE[2] != 'u' && matriculeYE[2] != 'v' && matriculeYE[2] != 'w' && matriculeYE[2] != 'x' && matriculeYE[2] != 'y' && matriculeYE[2] != 'z' && matriculeYE[2] != 'A' && matriculeYE[2] != 'B' && matriculeYE[2] != 'C' && matriculeYE[2] != 'D'  && matriculeYE[2] != 'E' && matriculeYE[2] != 'F' && matriculeYE[2] != 'G' && matriculeYE[2] != 'H' && matriculeYE[2] != 'I' && matriculeYE[2] != 'J' && matriculeYE[2] != 'K' && matriculeYE[2] != 'L' && matriculeYE[2] != 'M' && matriculeYE[2] != 'N' && matriculeYE[2] != 'O' && matriculeYE[2] != 'P' && matriculeYE[2] != 'Q' && matriculeYE[2] != 'R' && matriculeYE[2] != 'S' && matriculeYE[2] != 'T' && matriculeYE[2] != 'U' && matriculeYE[2] != 'V' && matriculeYE[2] != 'W' && matriculeYE[2] != 'X' && matriculeYE[2] != 'Y' && matriculeYE[2] != 'Z'){
    return 0;
    }

    //test sur le 4emme,5emme,6emme charactere
    for(int i=3;i<7;i++){
        if(matriculeYE[i] != '0' && matriculeYE[i] != '1' && matriculeYE[i] != '2' && matriculeYE[i] != '3' && matriculeYE[i] != '4' && matriculeYE[i] != '5' && matriculeYE[i] != '6' && matriculeYE[i] != '7' && matriculeYE[i] != '8' && matriculeYE[i] != '9'){
            return 0;
        }
    }
    return 1;
}

void affichageYE(liste *t){
    for(int i=0;i<taille;i++){

        liste courant=t[i];
        while(courant != NULL){
            printf("MATRICULE: %s\nNOMS: %s\nPRENOM: %s\nAGE: %d",courant->info.matricule,courant->info.nom,courant->info.prenom,courant->info.age);
            printf("\n");
            courant=courant->suivant;
        }
    }
    printf("\n");
}

void supprimer_etudiantYE(liste *t,char *matricule){
    int index = fonction_hachageYE(matricule);
    liste s = NULL;
    liste p = t[index];

    /*if(strcmp(p->info.matricule, matricule) == 0){
        t[index]=p->suivant;
        free(p);
        printf("%s supprimé avec succès\n", matricule);
        return;
    }else{
        while (p != NULL && strcmp(p->info.matricule, matricule) != 0){
            s=p;
            p=p->suivant;
        }
        s->suivant = p->suivant;
        free(p);
        printf("%s supprimé avec succès\n", matricule);
    }
    printf("Étudiant avec matricule %s non trouvé.\n", matricule);*/

    while (p) {
        if (strcmp(p->info.matricule, matricule) == 0) {
            if (s) {
                s->suivant = p->suivant;
            } else {
                t[index] = p->suivant; // Met à jour la tête de la liste.
            }
            free(p);
            printf("%s supprimé avec succès\n", matricule);
            return;
        }
        s = p;
        p = p->suivant;
    }
    printf("Étudiant avec matricule %s non trouvé.\n", matricule);
}

void mise_a_jour(liste *t,char *matricule){
    etudiant e = recherche_etudiantYE(t,matricule);
    int choix;
    do{
        printf("que souhaitez vous modifier ?\n");
        printf("1.NOMS  2.PRENOMS  3.AGE  0.SORTIR\n");
        scanf("%d",&choix);
    
        switch(choix){
            
            case 1:
                char nom[50];
                printf("entrer le nouveau nom\n");
                scanf("%s",nom);
                strcpy(e.nom,nom);
            break;

            case 2:
                char prenom[50];
                printf("entrer le nouveau prenom\n");
                scanf("%s",prenom);
                strcpy(e.prenom,prenom);
            break;

            case 3:
                int age;
                printf("entrer le nouvel age\n");
                scanf("%d",&age);
                e.age = age;
            break;

            default:
                printf("faire un choix\n");
            break;

        }
    }while ((choix != 0));
    int index = fonction_hachageYE(matricule);
    t[index]->info = e;
}

