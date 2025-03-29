#ifndef PLAYER_H
#define PLAYER_H

/**
 * @class cPlayer
 * @brief Représente le joueur dans le jeu
 * 
 * Cette classe gère la position et les caractéristiques
 * du personnage contrôlé par le joueur.
 */
class cPlayer {
public:
    int x;  ///< Position horizontale du joueur (en colonnes)
    int y;  ///< Position verticale du joueur (en lignes)

    /**
     * @brief Constructeur de cPlayer
     * @param width Largeur de la zone de jeu (pour positionner le joueur au centre)
     */
    cPlayer(int width);
};

#endif