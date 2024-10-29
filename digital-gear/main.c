#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TACHES 100

typedef struct {
    char titre[100];
    char description[255];
    char dateEcheance[11]; // format YYYY-MM-DD
    char priorite[10];     // "High" ou "Low"
} Tache;

Tache taches[MAX_TACHES];
int nombreTaches = 0;

void afficherMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Ajouter une Tache\n");
    printf("2. Afficher les Taches\n");
    printf("3. Modifier une Tache\n");
    printf("4. Supprimer une Tache\n");
    printf("5. Filtrer les Taches par Priorite\n");
    printf("0. Quitter\n");
}

void ajouterTache() {
    if (nombreTaches >= MAX_TACHES) {
        printf("Erreur : Limite de taches atteinte.\n");
        return;
    }

    Tache nouvelleTache;
    printf("Entrez le titre : ");
    scanf(" %[^\n]", nouvelleTache.titre);
    printf("Entrez la description : ");
    scanf(" %[^\n]", nouvelleTache.description);
    printf("Entrez la date d'echeance (YYYY-MM-DD) : ");
    scanf(" %[^\n]", nouvelleTache.dateEcheance);
    printf("Entrez la priorite (High/Low) : ");
    scanf(" %[^\n]", nouvelleTache.priorite);

    taches[nombreTaches++] = nouvelleTache;
    printf("Tache ajoutee avec succes !\n");
}
