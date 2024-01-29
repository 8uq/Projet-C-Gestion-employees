#include "list_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct liste* initListe() {
    struct liste* ListeEmployes = malloc(sizeof(struct liste));
    ListeEmployes->head = NULL;
    return ListeEmployes;
};

void addToListe(struct liste *listEmployes, struct employe *nouveauEmploye) {
    if (listEmployes->head == NULL) {
        listEmployes->head = nouveauEmploye;
    } else {
        struct employe* it = listEmployes->head;
        while (it->next != NULL) {
            it = it->next;
        }
        it->next = nouveauEmploye;
    }
}

struct employe *chercheParCode(struct liste *ListeEmployes, int code) {
    struct employe* it = ListeEmployes->head;
    while (it != NULL) {
        if (it->code == code) {
            return it;
        }
        it = it->next;
    }
    return NULL;
};

void supprEmploye(int code, struct liste *ListeEmployes) {
    struct employe *suppression = chercheParCode(ListeEmployes, code);
    if (suppression) {
        int choix;
        printf("1 Pour confirmer la suppression\n2 Pour annuler la suppression\nChoix: ");
        scanf("%d", &choix);
        if (choix == 1) {
            struct employe *it = ListeEmployes->head, *prev = NULL;
            while (it != NULL && it->code != code) {
                prev = it;
                it = it->next;
            }
            if (prev == NULL) {
                ListeEmployes->head = it->next;
            } else {
                prev->next = it->next;
            }
            free(it);
        } else {
            printf("suppression annulée\n");
        }
    } else {
        printf("employé inexistant\n");
    }
}


void chercheParNom(struct liste *ListeEmployes, char *nom) {
    struct employe* it = ListeEmployes->head;
    int found = 0;
    while (it != NULL) {
        if (strcmp(it->nom, nom) == 0) {
            printf("%d %s %s %d/%d/%d %s %.2f\n", it->code, it->nom, it->prenom, it->dateNaissance.day, it->dateNaissance.month, it->dateNaissance.year, it->titrePoste, it->salaire);
            found++;
        }
        it = it->next;
    }
    if (!found) {
        printf("Aucun employé trouvé avec le nom %s.\n", nom);
    }
}

void chercheParPrenom(struct liste *ListeEmployes, char *prenom) {
    struct employe* it = ListeEmployes->head;
    int found = 0;
    while (it != NULL) {
        if (strcmp(it->prenom, prenom) == 0) {
            printf("%d %s %s %d/%d/%d %s %.2f\n", it->code, it->nom, it->prenom, it->dateNaissance.day, it->dateNaissance.month, it->dateNaissance.year, it->titrePoste, it->salaire);
            found++;
        }
        it = it->next;
    }
    if (!found) {
        printf("Aucun employé trouvé avec le prénom %s.\n", prenom);
    }
}

void updateEmploye(struct liste *ListeEmployes, struct employe *emp) {
    char nouveauTitrePoste[50];
    float nouveauSalaire;

    while(1){
        printf("Titres de postes disponibles: 'President' 'VP-Sales' 'VP-Marketing' 'Sales-Manager' 'Sales-Rep'\n");
        printf("Titre de poste: ");
        scanf("%s",nouveauTitrePoste);
        const char *string = nouveauTitrePoste;
        if(strcmp(string,"President")==0 || strcmp(string,"VP-Sales")==0 || strcmp(string,"VP-Marketing")==0 || strcmp(string,"Sales-Manager")==0 ||strcmp(string,"Sales-Rep")==0){
            break;
        }
    }

    printf("\nNouveau Salaire: ");
    scanf("%f",&nouveauSalaire);
    emp->salaire=nouveauSalaire;
    strcpy(emp->titrePoste,nouveauTitrePoste);
    printf("\nEmployé %d mis à jour.\n", emp->code);
}

void afficherList(struct liste *listEmployes) {
    struct employe *it = listEmployes->head;
    while (it != NULL) {
        printf("%d %s %s %d/%d/%d %s %.2f\n", it->code, it->nom, it->prenom, it->dateNaissance.day, it->dateNaissance.month, it->dateNaissance.year, it->titrePoste, it->salaire);
        it = it->next;
    }
}