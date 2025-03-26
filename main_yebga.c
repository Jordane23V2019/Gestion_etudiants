#include "fonction_yebga.h"

int main(){
    system ("clear");
    liste tYE[taille];
    char matriculeYE[10];
    char matricule2YE[10];
    char matricule3YE[10];
    for(int i=0;i<taille;i++){
        tYE[i]=NULL;
    }
    etudiant eYE;
    printf("\t\033[1;33m******************************GESTION DES ETUDIANTS*******************************\033[0m\n\n");
    int choixYE;
    do{
        printf("\t\033[1;37m####################MENU#########################\033[0m\n");
        printf("\t\033[1;37m Que souhaitez-vous faire ?                  \033[0m\n");
        printf("\033[1;37m* * * * * * * * * * * * * * * * * * * * * * * *\033[0m\n");
        printf("\033[1;37m*  1. INSERER UN NOUVEL ETUDIANT              *\033[0m\n");
        printf("\033[1;37m*  2. RECHERCHER UN ETUDIANT                  *\033[0m\n");
        printf("\033[1;37m*  3. SUPPRIMER UN ETUDIANT                   *\033[0m\n");
        printf("\033[1;37m*  4. METTRE A JOUR LES DONNEES D'UN ETUDIANT *\033[0m\n");
        printf("\033[1;37m*  5. AFFICHER LES ETUDIANTS                  *\033[0m\n");
        printf("\033[1;37m*  0. SORTIR                                  *\033[0m\n");
        printf("\033[1;37m* * * * * * * * * * * * * * * * * * * * * * * *\033[0m\n");
        printf("\033[1;37mchoisir un numero:\033[0m");
        scanf("%d",&choixYE);
        switch (choixYE){
            case 0:
                system("clear");
                printf("sortie.............................................\n");
            break;
            
            case 1:
                system("clear");
                
                do{
                    printf("MATRICULE :");
                    scanf("%s",eYE.matricule);
                    if(!verification_matriculeYE(eYE.matricule))
                    printf("ERREUR: FORMAT INVALIDE\n");
                }while (!verification_matriculeYE(eYE.matricule));        
                
                printf("NOMS:");
                scanf("%s",eYE.nom);
                printf("PRENOMS:");
                scanf("%s",eYE.prenom);
                printf("AGE:");
                scanf("%d",&eYE.age);

                ajouter_etudiantYE(tYE,eYE);

            break;

            case 2:
                system("clear");
                do{
                    printf("ENTRER LE MATRICULE A RECHERCHER :");
                    scanf("%s",matriculeYE);
                    if(!verification_matriculeYE(matriculeYE))
                    printf("ERREUR: FORMAT INVALIDE\n");
                }while (!verification_matriculeYE(matriculeYE));
                etudiant pYE=recherche_etudiantYE(tYE,matriculeYE);
                printf("MATRICULE:%s\nNOMS:%s\nPRENOM:%s\nAGE:%d\n",pYE.matricule,pYE.nom,pYE.prenom,pYE.age);

            break;

            case 3:
                system("clear");
                do{
                    printf("ENTRER LE MATRICULE A SUPPRIMER :");
                    scanf("%s",matricule2YE);
                    if(!verification_matriculeYE(matricule2YE))
                    printf("ERREUR: FORMAT INVALIDE\n");
                }while (!verification_matriculeYE(matricule2YE));
                supprimer_etudiantYE(tYE,matricule2YE);
            break;

            case 4:
                system("clear");
                do{
                    printf("ENTRER LE MATRICULE DE L'ETUDIANT A MODIFIER :");
                    scanf("%s",matricule3YE);
                    if(!verification_matriculeYE(matricule3YE))
                    printf("ERREUR: FORMAT INVALIDE\n");
                }while (!verification_matriculeYE(matricule3YE));
                mise_a_jour(tYE,matricule3YE);
            break;

            case 5:
                system("clear");
                affichageYE(tYE);
            break;

            default:
                system("clear");
                printf("CHOIX NON VALIDE\n");
            break;
        }


    }while (choixYE != 0);
    
    return 0;
}