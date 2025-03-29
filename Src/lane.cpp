#include "lane.h"
#include <cstdlib>    // Pour rand()
#include <algorithm>  // Pour fill()

/**
 * @brief Constructeur de la classe cLane
 * @param width Largeur de la voie (nombre de positions)
 * Initialise une voie avec des voitures placées aléatoirement
 * et une direction aléatoire (gauche ou droite)
 */
cLane::cLane(int width) {
    // Remplit la voie avec des voitures (true) ou du vide (false)
    // Une chance sur 3 d'avoir une voiture à chaque position
    for (int i = 0; i < width; i++)
        cars.push_front(rand() % 3 == 0);
    
    // Détermine aléatoirement le sens de circulation
    right = rand() % 2;
}

/**
 * @brief Fait avancer les voitures dans la voie
 * Selon la direction de la voie, ajoute une nouvelle voiture
 * à l'entrée et supprime la voiture en sortie
 */
void cLane::Move() {
    if (right) {  // Circulation vers la droite
        // 1 chance sur 7 d'ajouter une nouvelle voiture
        if (rand() % 7 == 1)
            cars.push_front(true);
        else
            cars.push_front(false);
        // Supprime la voiture en fin de voie
        cars.pop_back();
    }
    else {  // Circulation vers la gauche
        // 1 chance sur 7 d'ajouter une nouvelle voiture
        if (rand() % 7 == 1)
            cars.push_back(true);
        else
            cars.push_back(false);
        // Supprime la voiture en début de voie
        cars.pop_front();
    }
}

/**
 * @brief Vérifie la présence d'une voiture à une position donnée
 * @param pos Position à vérifier dans la voie
 * @return true si une voiture est présente, false sinon
 */
bool cLane::CheckPos(int pos) { 
    return cars[pos]; 
}

/**
 * @brief Inverse la direction de circulation de la voie
 */
void cLane::ChangeDirection() { 
    right = !right; 
}

/**
 * @brief Supprime toutes les voitures de la voie
 * Remplace toutes les positions par false
 */
void cLane::ClearCars() { 
    fill(cars.begin(), cars.end(), false); 
}