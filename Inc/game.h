#ifndef GAME_H
#define GAME_H

#include <vector>
#include "player.h"
#include "lane.h"
#include "constants.h"

/**
 * @class cGame
 * @brief Classe principale gérant le jeu
 * 
 * Cette classe gère la logique du jeu, l'affichage, les entrées utilisateur
 * et le déroulement global de la partie.
 */
class cGame {
private:
    // Variables membres
    bool quit;              ///< Indique si le jeu doit quitter
    bool paused;            ///< État de pause du jeu
    bool started;           ///< Indique si le jeu a commencé
    int numberOfLanes;      ///< Nombre de voies dans le jeu
    int width;              ///< Largeur de la zone de jeu
    int score;              ///< Score du joueur
    int lives;              ///< Nombre de vies restantes
    int speed;              ///< Vitesse actuelle du jeu
    int level;              ///< Niveau actuel
    cPlayer* player;        ///< Pointeur vers le joueur
    std::vector<cLane*> map;///< Vecteur des voies du jeu
    
    // Méthodes privées
    void SetColor(int color);   ///< Change la couleur du texte en console
    void DrawBorder();          ///< Dessine les bordures du jeu
    void ShowStartScreen();     ///< Affiche l'écran de démarrage
    void ShowPauseScreen();     ///< Affiche l'écran de pause
    void ShowGameOver();        ///< Affiche l'écran de fin de jeu
    void ResetGame();           ///< Réinitialise le jeu

public:
    /**
     * @brief Constructeur de cGame
     * @param w Largeur de la zone de jeu (par défaut 30)
     * @param h Hauteur de la zone de jeu (nombre de voies, par défaut 10)
     */
    cGame(int w = 30, int h = 10);
    
    /// Destructeur
    ~cGame();
    
    /**
     * @brief Dessine l'état actuel du jeu
     */
    void Draw();
    
    /**
     * @brief Gère les entrées utilisateur
     */
    void Input();
    
    /**
     * @brief Gère la logique du jeu et les collisions
     */
    void Logic();
    
    /**
     * @brief Lance la boucle principale du jeu
     */
    void Run();
};

#endif