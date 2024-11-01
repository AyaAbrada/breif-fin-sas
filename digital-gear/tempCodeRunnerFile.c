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

int validerDate(const char *date) {
    int jour, mois, annee;

    // Extraire le jour, le mois et l'année
    if (sscanf(date, "%d-%d-%d", &annee, &mois, &jour) != 3) {
        return 0; // Format invalide
    }

    // Valider le jour, le mois et l'année
    if (jour < 1 || jour > 31 || mois < 1 || mois > 12 || annee <= 0) {
        return 0; // Date invalide
    }

    // Pour plus de précision, vérifier les jours selon les mois (simplifié)
    if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30) {
        return 0; // Mois de 30 jours
    }
    if (mois == 2) {
        // Vérification des années bissextiles
        if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
            if (jour > 29) return 0; // Février d'une année bissextile
        } else {
            if (jour > 28) return 0; // Février d'une année non bissextile
        }
    }

    return 1; // Date valide
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

    // Validation de la date
    if (!validerDate(nouvelleTache.dateEcheance)) {
        printf("Erreur : Date invalide.\n");
        return;
    }

    printf("Entrez la priorite (High/Low) : ");
    scanf(" %[^\n]", nouvelleTache.priorite);

    taches[nombreTaches++] = nouvelleTache;
    printf("Tache ajoutee avec succes !\n");
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

    // Validation de la nouvelle date
    if (!validerDate(tache->dateEcheance)) {
        printf("Erreur : Date invalide.\n");
        return;
    }

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
