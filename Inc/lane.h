#ifndef LANE_H
#define LANE_H

#include <deque>

/**
 * @class cLane
 * @brief Représente une voie de circulation dans le jeu
 * 
 * Cette classe gère une voie individuelle contenant des véhicules
 * en mouvement, leur déplacement et la détection de collisions.
 */
class cLane {
private:
    std::deque<bool> cars;  ///< Conteneur représentant les véhicules (true = présence d'un véhicule)
    bool right;             ///< Sens de déplacement (true = droite, false = gauche)

public:
    /**
     * @brief Constructeur de cLane
     * @param width Largeur de la voie (détermine le nombre de positions)
     */
    cLane(int width);
    
    /**
     * @brief Déplace tous les véhicules de la voie selon leur direction
     */
    void Move();
    
    /**
     * @brief Vérifie si un véhicule est présent à la position donnée
     * @param pos Position à vérifier
     * @return true si un véhicule est présent, false sinon
     */
    bool CheckPos(int pos);
    
    /**
     * @brief Inverse la direction des véhicules de la voie
     */
    void ChangeDirection();
    
    /**
     * @brief Supprime tous les véhicules de la voie
     */
    void ClearCars();
};

#endif