#include "file_operations.h"
#include "list_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void ChargementDonnees(struct liste *list) {
    FILE *f = fopen("employees.txt", "r");
    if (f == NULL) {
        perror("Erreur d'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    while (1) {
        struct employe *nouveauEmploye = malloc(sizeof(struct employe));
        if (fscanf(f, "%d %49s %49s %d/%d/%d %49s %f", &nouveauEmploye->code, nouveauEmploye->nom, nouveauEmploye->prenom, &nouveauEmploye->dateNaissance.day, &nouveauEmploye->dateNaissance.month, &nouveauEmploye->dateNaissance.year, nouveauEmploye->titrePoste, &nouveauEmploye->salaire) == 8) {
            nouveauEmploye->next = NULL;
            addToListe(list, nouveauEmploye);
        } else {
            free(nouveauEmploye);
            break;
        }
    }

    fclose(f);
}

void SauvegardeDonnees(struct liste *ListeEmployes) {
    FILE *f = fopen("employees.txt", "w");
    if (f == NULL) {
        perror("Erreur d'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    struct employe *it = ListeEmployes->head;
    while (it != NULL) {
        fprintf(f, "%d %s %s %d/%d/%d %s %.2f\n", it->code, it->nom, it->prenom, it->dateNaissance.day, it->dateNaissance.month, it->dateNaissance.year, it->titrePoste, it->salaire);
        it = it->next;
    }

    fclose(f);
}

void ajouteEmploye(char *nom, char *prenom, int day, int month, int year, char *titrePoste, float salaire, struct liste *ListeEmployes) {
    int RandomCode;
    srand(time(NULL));
    do {
        RandomCode = rand() % 1000 + 2000;
    } while (chercheParCode(ListeEmployes, RandomCode) != NULL);

    struct employe *nouveauEmploye = malloc(sizeof(struct employe));
    nouveauEmploye->code = RandomCode;
    strcpy(nouveauEmploye->nom, nom);
    strcpy(nouveauEmploye->prenom, prenom);
    nouveauEmploye->dateNaissance.day = day;
    nouveauEmploye->dateNaissance.month = month;
    nouveauEmploye->dateNaissance.year = year;
    strcpy(nouveauEmploye->titrePoste, titrePoste);
    nouveauEmploye->salaire = salaire;
    nouveauEmploye->next = NULL;

    addToListe(ListeEmployes, nouveauEmploye);
    printf("Employé ajouté avec succès avec le code unique: %d\n", nouveauEmploye->code);
}