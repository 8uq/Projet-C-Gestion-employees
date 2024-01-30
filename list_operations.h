#ifndef LIST_OPERATIONS_H
#define LIST_OPERATIONS_H

#include "structures.h"

struct liste* initListe();
void addToListe(struct liste *listEmployes, struct employe *nouveauEmploye);
struct employe *chercheParCode(struct liste *ListeEmployes, int code);
void supprEmploye(int code, struct liste *ListeEmployes);
void chercheParNom(struct liste *ListeEmployes, char *nom);
void chercheParPrenom(struct liste *ListeEmployes, char *prenom);
void updateEmploye(struct liste *ListeEmployes, struct employe *emp);
void afficherList(struct liste *listEmployes);

int isEmpty(struct liste *list);
#endif