#include "game.h"  
#include <windows.h>  // Pour les fonctions spécifiques à Windows
#include <ctime>      // Pour la fonction time()

/**
 * @brief Point d'entrée principal du programme
 * 
 * Initialise et lance le jeu "Cross The Road" avec :
 * - Une configuration de console adaptée
 * - Une graine aléatoire
 * - Une instance du jeu avec des paramètres par défaut
 * 
 * @return int Code de sortie (0 pour une exécution réussie)
 */
int main() {
    // =============================================
    // CONFIGURATION DE LA CONSOLE
    // =============================================
    
    // Définit la taille de la console (60 colonnes, 30 lignes)
    system("mode con: cols=60 lines=30");
    
    // Définit le titre de la fenêtre console
    SetConsoleTitleA("Cross The Road - Jeu d'arcade");
    
    // Tentative de configuration de l'encodage en UTF-8
    // (Permet d'afficher correctement les caractères spéciaux si utilisés)
    SetConsoleOutputCP(65001);
    
    // =============================================
    // INITIALISATION DU JEU
    // =============================================
    
    // Initialise le générateur de nombres aléatoires
    // avec l'heure actuelle comme graine
    srand(static_cast<unsigned int>(time(NULL)));
    
    // Crée une instance du jeu avec :
    // - Largeur : 40 cases
    // - Hauteur : 12 voies (lanes)
    cGame game(40, 12);
    
    // Lance la boucle principale du jeu
    game.Run();
    
    // =============================================
    // FIN DU PROGRAMME
    // =============================================
    
    // Retourne 0 indiquant une exécution réussie
    return 0;
}