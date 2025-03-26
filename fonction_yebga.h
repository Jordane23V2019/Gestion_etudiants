# ifndef __fonction_yebga__
# define __fonction_yebga__

    #define taille 5000
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    typedef struct Etudiant{
        char matricule[10];
        char nom[50];
        char prenom[50];
        int age;
    }etudiant;

    typedef struct Liste{
        etudiant info;  
        struct Liste* suivant;
    }Liste;
    typedef Liste *liste;

    int fonction_hachageYE(const char *valYE);
    void ajouter_etudiantYE(liste* tYE,etudiant eYE);
    etudiant recherche_etudiantYE(liste* t,char *matricule);
    int verification_matriculeYE(char *matricule);
    void affichageYE(liste* t);
    void supprimer_etudiantYE(liste* t,char *matricule);
    void mise_a_jour(liste* t,char *matricule);

#endif