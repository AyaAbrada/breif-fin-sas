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
    printf("\n---{ Menu }---\n");
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
    printf("Tache ajoutae avec succes !\n");
}

void afficherTaches() {
    if (nombreTaches == 0) {
        printf("Aucune tache a afficher.\n");
        return;
    }

    for (int i = 0; i < nombreTaches; i++) {
        printf("Tache %d :\n", i + 1);
        printf("Titre : %s\n", taches[i].titre);
        printf("Description : %s\n", taches[i].description);
        printf("Date d'echeance : %s\n", taches[i].dateEcheance);
        printf("Priorite : %s\n", taches[i].priorite);
        printf("----------------------\n");
    }
}

void modifierTache() {
    int index;
    printf("Entrez le numero de la tache a modifier (1 a %d) : ", nombreTaches);
    scanf("%d", &index);

    if (index < 1 || index > nombreTaches) {
        printf("Erreur : Numero de tache invalide.\n");
        return;
    }

    Tache *tache = &taches[index - 1];
    printf("Modifier la description (actuelle : %s) : ", tache->description);
    scanf(" %[^\n]", tache->description);
    printf("Modifier la date d'echeance (actuelle : %s) : ", tache->dateEcheance);
    scanf(" %[^\n]", tache->dateEcheance);
    printf("Modifier la priorite (actuelle : %s) : ", tache->priorite);
    scanf(" %[^\n]", tache->priorite);

    printf("Tache modifiee avec succes !\n");
}

void supprimerTache() {
    int index;
    printf("Entrez le numero de la tache a supprimer (1 a %d) : ", nombreTaches);
    scanf("%d", &index);

    if (index < 1 || index > nombreTaches) {
        printf("Erreur : Numero de tache invalide.\n");
        return;
    }

    for (int i = index - 1; i < nombreTaches - 1; i++) {
        taches[i] = taches[i + 1];
    }
    nombreTaches--;
    printf("Tache supprimee avec succes !\n");
}

void filtrerTaches() {
    char priorite[10];
    printf("Entrez la priorite a filtrer (High/Low) : ");
    scanf(" %[^\n]", priorite);

    int trouve = 0;
    for (int i = 0; i < nombreTaches; i++) {
        if (strcmp(taches[i].priorite, priorite) == 0) {
            printf("Tache %d :\n", i + 1);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Date d'echeance : %s\n", taches[i].dateEcheance);
            printf("Priorite : %s\n", taches[i].priorite);
            printf("----------------------\n");
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucune tache trouvee avec la priorite '%s'.\n", priorite);
    }
}

int main() {
    int choix;

    do {
        afficherMenu();
        printf("\nEntrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterTache();
                break;
            case 2:
                afficherTaches();
                break;
            case 3:
                modifierTache();
                break;
            case 4:
                supprimerTache();
                break;
            case 5:
                filtrerTaches();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 0);

    return 0;
}
