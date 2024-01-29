#ifndef STRUCTURES_H
#define STRUCTURES_H

struct date{
    int day;
    int month;
    int year;
};

struct employe{
    int code;
    char nom[50];
    char prenom[50];
    struct date dateNaissance;
    char titrePoste[50];
    float salaire;
    struct employe *next;
};

struct liste{
    struct employe *head;
};

#endif