#include "structures.h"
#include "list_operations.h"
#include "file_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct liste* listEmployes=initListe();
    ChargementDonnees(listEmployes);
    int choix;
    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un nouveau employé\n");
        printf("2. Supprimer un employé\n");
        printf("3. Rechercher un employé par son code\n");
        printf("4. Rechercher un employé par son nom\n");
        printf("5. Rechercher un employé par son prénom\n");
        printf("6. Mettre à jour un employé\n");
        printf("7. Enregistrer tout\n");
        printf("8. Enregistrer et quitter\n");
        printf("9. afficher la liste d'employés[debug]\n");
        printf("Choix: ");
        scanf("%d", &choix);
        switch (choix){
            case 1:{
                char nom[50];
                char prenom [50];
                int day;
                int month;
                int year;
                char titrePoste[50];
                float salaire;
                printf("Nom: ");
                scanf("%s",nom);
                printf("Prenom: ");
                scanf("%s",prenom);

				printf("Date de naissance\n");
                printf("Jour: ");
                scanf("%d",&day);
                printf("Mois: ");
                scanf("%d",&month);
                printf("Année: ");
                scanf("%d",&year);

                 while(1){
                    printf("Titres de postes disponibles: 'President' 'VP-Sales' 'VP-Marketing' 'Sales-Manager' 'Sales-Rep'\n");
					printf("Titre de poste: ");
                    scanf("%s",titrePoste);
                    const char *string = titrePoste;
                    if(strcmp(string,"President")==0 || strcmp(string,"VP-Sales")==0 || strcmp(string,"VP-Marketing")==0 || strcmp(string,"Sales-Manager")==0 ||strcmp(string,"Sales-Rep")==0){
                        break;}
                }
                printf("Salaire ");
                scanf("%f",&salaire);
                ajouteEmploye(nom,prenom,day,month,year,titrePoste,salaire,listEmployes);
                break;
            }case 2:{
                int code;
                printf("Code d'employé à supprimer: ");
                scanf("%d",&code);
                supprEmploye(code,listEmployes);
                break;
            }case 3: {
                int code;
                printf("Code d'employé à rechercher: ");
                scanf("%d", &code);
                struct employe* emp = chercheParCode(listEmployes, code);
                if (emp != NULL) {
                    printf("Employé trouvé:\n");
                    afficherList(listEmployes);
                } else {
                    printf("Employé inexistant.\n");
                }
                break;
            }case 4:{
                int nom[50];
                printf("Nom d'employé à rechercher: ");
                scanf("%s",nom);
                chercheParNom(listEmployes,nom);
                break;
            }case 5:{
                int prenom[50];
                printf("Prenom d'employé à rechercher: ");
                scanf("%s",prenom);
                chercheParPrenom(listEmployes,prenom);
                break;
            }case 6:{
                int code;
                printf("Code d'employé à modifier: ");
                scanf("%d",&code);
                if(chercheParCode(listEmployes,code)!=NULL){
                    updateEmploye(listEmployes,chercheParCode(listEmployes,code));
                }else{
                    printf("Employé inexistant\n");
                }
                break;
            }case 7:{
                SauvegardeDonnees(listEmployes);
                printf("Les information ont été enregistrées\n");
                break;
            }case 8:{
                SauvegardeDonnees(listEmployes);
                printf("Les information ont été enregistrées\n");
                printf("Sortie du programme.");
                break;
            }case 9:{
                afficherList(listEmployes);
                break;
            }default:{
                printf("Choix Invalide, veuillez réessayer\n");
            }
        }
    }while(choix!=8);


    return 0;
}
