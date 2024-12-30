# SafeMessage - Chiffrement César

Une application en C qui implémente le chiffrement de César avec des fonctionnalités avancées d'analyse et de cryptanalyse.

## Fonctionnalités

- Chiffrement et déchiffrement de texte avec le chiffrement de César
- Support des décalages positifs et négatifs (-25 à +25)
- Analyse de fréquence des lettres
- Mode bruteforce pour tester tous les décalages possibles
- Préservation de la casse (majuscules/minuscules)
- Conservation des caractères non-alphabétiques

## Prérequis

- Compilateur C (GCC recommandé)
- Make (optionnel, pour utiliser le Makefile)

## Installation

1. Clonez le dépôt :
```bash
git clone [votre-url-de-repo]
cd SafeMessage
```

2. Compilez le programme :
```bash
# Avec Make
make

# Sans Make
gcc SafeMessage.c -o safemessage
```

## Utilisation

Lancez le programme :
```bash
./safemessage
```

Le menu principal propose les options suivantes :
1. Chiffrer un texte
2. Déchiffrer un texte
3. Analyser la fréquence des lettres
4. Tester tous les décalages possibles
5. Quitter

### Exemples

1. **Chiffrement** :
   ```
   Texte : "Hello World"
   Décalage : 3
   Résultat : "Khoor Zruog"
   ```

2. **Analyse de fréquence** :
   ```
   Texte : "Hello World"
   Résultat :
   L: 3 (30%)
   O: 2 (20%)
   ...
   ```

## Structure du Code

- `SafeMessage.c` : Code source principal
- `Makefile` : Script de compilation
- `README.md` : Documentation

## Sécurité

- Validation des entrées utilisateur
- Protection contre les buffer overflow
- Gestion sécurisée des décalages
