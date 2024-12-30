#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TEXT 1000
#define MIN_SHIFT -25
#define MAX_SHIFT 25

// Fonction pour nettoyer le buffer d'entrée
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fonction pour valider le décalage
bool validate_shift(int shift) {
    return (shift >= MIN_SHIFT && shift <= MAX_SHIFT);
}

// Fonction pour chiffrer un texte en utilisant le chiffrement de César
void chiffrer_cesar(char texte[], int decalage) {
    // Normaliser le décalage pour qu'il soit toujours positif
    decalage = ((decalage % 26) + 26) % 26;
    
    for (int i = 0; texte[i] != '\0'; i++) {
        if (isalpha(texte[i])) {
            char base = islower(texte[i]) ? 'a' : 'A';
            texte[i] = (texte[i] - base + decalage) % 26 + base;
        }
    }
}

// Fonction pour déchiffrer un texte en utilisant le chiffrement de César
void dechiffrer_cesar(char texte[], int decalage) {
    chiffrer_cesar(texte, 26 - (decalage % 26));
}

// Fonction pour afficher l'analyse de fréquence
void analyser_frequence(const char texte[]) {
    int freq[26] = {0};
    int total = 0;

    for (int i = 0; texte[i] != '\0'; i++) {
        if (isalpha(texte[i])) {
            freq[tolower(texte[i]) - 'a']++;
            total++;
        }
    }

    printf("\nAnalyse de fréquence des lettres :\n");
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d (%.1f%%)\n", 
                   'A' + i, 
                   freq[i], 
                   (float)freq[i] * 100 / total);
        }
    }
}

// Fonction pour tester tous les décalages possibles
void bruteforce_cesar(const char texte[]) {
    char test[MAX_TEXT];
    printf("\nTest de tous les décalages possibles :\n");
    
    for (int i = 1; i < 26; i++) {
        strcpy(test, texte);
        dechiffrer_cesar(test, i);
        printf("Décalage %2d: %s\n", i, test);
    }
}

int main() {
    char texte[MAX_TEXT];
    int decalage;
    int choix;
    bool continuer = true;

    while (continuer) {
        printf("\n=== Menu SafeMessage ===\n");
        printf("1. Chiffrer un texte\n");
        printf("2. Déchiffrer un texte\n");
        printf("3. Analyser la fréquence des lettres\n");
        printf("4. Tester tous les décalages\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("Erreur : entrée invalide\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        if (choix == 5) {
            continuer = false;
            continue;
        }

        if (choix < 1 || choix > 5) {
            printf("Erreur : option invalide\n");
            continue;
        }

        if (choix <= 2) {
            printf("Entrez le texte : ");
            if (!fgets(texte, sizeof(texte), stdin)) {
                printf("Erreur de lecture\n");
                continue;
            }
            texte[strcspn(texte, "\n")] = '\0';

            if (strlen(texte) == 0) {
                printf("Erreur : texte vide\n");
                continue;
            }

            printf("Entrez le décalage (%d à %d) : ", MIN_SHIFT, MAX_SHIFT);
            if (scanf("%d", &decalage) != 1 || !validate_shift(decalage)) {
                printf("Erreur : décalage invalide\n");
                clear_input_buffer();
                continue;
            }
            clear_input_buffer();
        } else {
            printf("Entrez le texte à analyser : ");
            if (!fgets(texte, sizeof(texte), stdin)) {
                printf("Erreur de lecture\n");
                continue;
            }
            texte[strcspn(texte, "\n")] = '\0';
        }

        switch (choix) {
            case 1:
                chiffrer_cesar(texte, decalage);
                printf("Texte chiffré : %s\n", texte);
                break;
            case 2:
                dechiffrer_cesar(texte, decalage);
                printf("Texte déchiffré : %s\n", texte);
                break;
            case 3:
                analyser_frequence(texte);
                break;
            case 4:
                bruteforce_cesar(texte);
                break;
        }
    }

    printf("Au revoir !\n");
    return 0;
}
