#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "structures.h"

void ChargementDonnees(struct liste *list);
void SauvegardeDonnees(struct liste *ListeEmployes);
void ajouteEmploye(char *nom, char *prenom, int day, int month, int year, char *titrePoste, float salaire, struct liste *ListeEmployes);

#endif