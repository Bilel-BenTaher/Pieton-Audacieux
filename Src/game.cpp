#include "game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief Change la couleur du texte dans la console Windows
 * @param color Code de couleur à appliquer (voir les constantes COLOR_*)
 */
void cGame::SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/**
 * @brief Dessine la bordure horizontale du terrain de jeu
 * Utilise les caractères BORDER_CORNER et BORDER_HORIZ définis dans les constantes
 */
void cGame::DrawBorder() {
    SetColor(COLOR_ROAD);
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
}

/**
 * @brief Affiche l'écran de démarrage avec les instructions
 * Montre le titre du jeu et les contrôles disponibles
 */
void cGame::ShowStartScreen() {
    system("cls");  // Efface la console
    SetColor(COLOR_TEXT);
    
    // Cadre supérieur
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
    
    // Ligne vide
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Titre centré
    cout << BORDER_VERT;
    string title = "C R O S S   T H E   R O A D";
    int titlePos = (width - 2 - title.length()) / 2;
    for (int j = 0; j < titlePos; j++) cout << " ";
    SetColor(COLOR_GOAL);
    cout << title;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - title.length() - titlePos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Ligne vide
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Instructions de contrôle (ligne 1)
    cout << BORDER_VERT;
    string ctrl1 = "Use ZQSD to move, SPACE to start";
    int ctrl1Pos = (width - 2 - ctrl1.length()) / 2;
    for (int j = 0; j < ctrl1Pos; j++) cout << " ";
    SetColor(COLOR_CAR);
    cout << ctrl1;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - ctrl1.length() - ctrl1Pos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Instructions de contrôle (ligne 2)
    cout << BORDER_VERT;
    string ctrl2 = "P = Pause, W = Quit";
    int ctrl2Pos = (width - 2 - ctrl2.length()) / 2;
    for (int j = 0; j < ctrl2Pos; j++) cout << " ";
    SetColor(COLOR_PLAYER);
    cout << ctrl2;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - ctrl2.length() - ctrl2Pos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Ligne vide
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Cadre inférieur
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
}

/**
 * @brief Affiche l'écran de pause avec le score actuel
 */
void cGame::ShowPauseScreen() {
    system("cls");
    SetColor(COLOR_TEXT);
    
    // Cadre supérieur
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
    
    // Espace vide (3 lignes)
    for (int i = 0; i < 3; i++) {
        cout << BORDER_VERT;
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << BORDER_VERT << endl;
    }
    
    // Message "PAUSE" centré
    cout << BORDER_VERT;
    string pauseMsg = "G A M E   P A U S E D";
    int msgPos = (width - 2 - pauseMsg.length()) / 2;
    for (int j = 0; j < msgPos; j++) cout << " ";
    SetColor(COLOR_GOAL);
    cout << pauseMsg;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - pauseMsg.length() - msgPos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Instructions pour reprendre
    cout << BORDER_VERT;
    string continueMsg = "Press P to continue";
    int contPos = (width - 2 - continueMsg.length()) / 2;
    for (int j = 0; j < contPos; j++) cout << " ";
    SetColor(COLOR_PLAYER);
    cout << continueMsg;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - continueMsg.length() - contPos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Espace vide (3 lignes)
    for (int i = 0; i < 3; i++) {
        cout << BORDER_VERT;
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << BORDER_VERT << endl;
    }
    
    // Affichage du score centré
    cout << BORDER_VERT;
    string scoreMsg = "Score: " + to_string(score);
    int scorePos = (width - 2 - scoreMsg.length()) / 2;
    for (int j = 0; j < scorePos; j++) cout << " ";
    SetColor(COLOR_CAR);
    cout << scoreMsg;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - scoreMsg.length() - scorePos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Espace vide (2 lignes)
    for (int i = 0; i < 2; i++) {
        cout << BORDER_VERT;
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << BORDER_VERT << endl;
    }
    
    // Cadre inférieur
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
}

/**
 * @brief Affiche l'écran de fin de jeu avec le score final
 * Propose les options pour recommencer ou quitter
 */
void cGame::ShowGameOver() {
    system("cls");
    SetColor(COLOR_TEXT);
    
    // Cadre supérieur
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
    
    // Ligne vide
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Message "GAME OVER" centré
    cout << BORDER_VERT;
    string gameOverMsg = "G A M E   O V E R";
    int msgPos = (width - 2 - gameOverMsg.length()) / 2;
    for (int j = 0; j < msgPos; j++) cout << " ";
    SetColor(COLOR_CAR);
    cout << gameOverMsg;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - gameOverMsg.length() - msgPos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Ligne vide
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Affichage du score final centré
    cout << BORDER_VERT;
    string scoreMsg = "Score: " + to_string(score);
    int scorePos = (width - 2 - scoreMsg.length()) / 2;
    for (int j = 0; j < scorePos; j++) cout << " ";
    SetColor(COLOR_GOAL);
    cout << scoreMsg;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - scoreMsg.length() - scorePos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Ligne vide
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Option "Recommencer" centrée
    cout << BORDER_VERT;
    string continueMsg1 = "Press R to restart";
    int cont1Pos = (width - 2 - continueMsg1.length()) / 2;
    for (int j = 0; j < cont1Pos; j++) cout << " ";
    SetColor(COLOR_PLAYER);
    cout << continueMsg1;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - continueMsg1.length() - cont1Pos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Option "Quitter" centrée
    cout << BORDER_VERT;
    string continueMsg2 = "Press W to quit";
    int cont2Pos = (width - 2 - continueMsg2.length()) / 2;
    for (int j = 0; j < cont2Pos; j++) cout << " ";
    SetColor(COLOR_PLAYER);
    cout << continueMsg2;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - continueMsg2.length() - cont2Pos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Ligne vide
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    // Cadre inférieur
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
}

/**
 * @brief Réinitialise toutes les variables du jeu pour une nouvelle partie
 * Remet le score à 0, les vies à 3 et recrée les voies et le joueur
 */
void cGame::ResetGame() {
    // Réinitialisation des états
    quit = false;
    paused = false;
    started = false;
    
    // Réinitialisation des scores et paramètres
    score = 0;
    lives = 3;
    speed = 150;
    level = 1;
    
    // Recréation du joueur
    delete player;
    player = new cPlayer(width);
    
    // Nettoyage et recréation des voies
    for (int i = 0; i < map.size(); i++) {
        delete map[i];
    }
    map.clear();
    
    for (int i = 0; i < numberOfLanes; i++) {
        map.push_back(new cLane(width));
    }
}

/**
 * @brief Constructeur de la classe cGame
 * @param w Largeur du terrain de jeu
 * @param h Hauteur (nombre de voies) du terrain de jeu
 */
cGame::cGame(int w, int h) {
    // Initialisation des dimensions
    numberOfLanes = h;
    width = w;
    
    // Initialisation des états
    quit = false;
    paused = false;
    started = false;
    
    // Initialisation des paramètres de jeu
    score = 0;
    lives = 3;
    speed = 150;
    level = 1;
    
    // Création des voies
    for (int i = 0; i < numberOfLanes; i++)
        map.push_back(new cLane(width));
    
    // Création du joueur
    player = new cPlayer(width);
}

/**
 * @brief Destructeur de la classe cGame
 * Libère la mémoire allouée pour le joueur et les voies
 */
cGame::~cGame() {
    delete player;
    for (int i = 0; i < map.size(); i++) {
        cLane* current = map.back();
        map.pop_back();
        delete current;
    }
}

/**
 * @brief Dessine l'état actuel du jeu dans la console
 * Gère l'affichage des différents écrans (démarrage, pause, jeu principal)
 */
void cGame::Draw() {
    system("cls");  // Efface la console
    
    // Affiche l'écran de démarrage si le jeu n'a pas commencé
    if (!started) {
        ShowStartScreen();
        return;
    }
    
    // Affiche l'écran de pause si le jeu est en pause
    if (paused) {
        ShowPauseScreen();
        return;
    }
    
    // Affiche les informations de jeu (score, niveau, vies)
    SetColor(COLOR_TEXT);
    cout << "Score: " << score << "  Level: " << level << "  Lives: " << lives << "\n\n";
    
    // Dessine la bordure supérieure
    DrawBorder();
    
    // Dessine chaque ligne du terrain de jeu
    for (int i = 0; i < numberOfLanes; i++) {
        SetColor(COLOR_TEXT);
        cout << BORDER_VERT;
        
        // Dessine chaque colonne de la ligne courante
        for (int j = 0; j < width - 2; j++) {
            // Dessine les étoiles de départ/arrivée aux coins
            if (i == 0 && (j == 0 || j == width - 3)) {
                SetColor(COLOR_GOAL);
                cout << STAR_CHAR;
                SetColor(COLOR_TEXT);
                continue;
            }
            
            if (i == numberOfLanes - 1 && (j == 0 || j == width - 3)) {
                SetColor(COLOR_GOAL);
                cout << STAR_CHAR;
                SetColor(COLOR_TEXT);
                continue;
            }
            
            // Dessine une voiture si présente à cette position
            if (map[i]->CheckPos(j) && i != 0 && i != numberOfLanes - 1) {
                SetColor(COLOR_CAR);
                cout << CAR_CHAR;
            }
            // Dessine le joueur s'il est à cette position
            else if (player->x == j && player->y == i) {
                SetColor(COLOR_PLAYER);
                cout << PLAYER_CHAR;
            }
            // Dessine la route (vide ou avec des points aléatoires)
            else {
                SetColor(COLOR_ROAD);
                if (i == 0 || i == numberOfLanes - 1) cout << " ";
                else cout << (rand() % 10 == 0 ? "." : " ");
            }
        }
        
        SetColor(COLOR_TEXT);
        cout << BORDER_VERT << endl;
    }
    
    // Dessine la bordure inférieure
    DrawBorder();
    
    // Affiche les commandes disponibles
    SetColor(COLOR_TEXT);
    cout << "\n (P)Pause (W)Quit" << endl;
}

/**
 * @brief Gère les entrées clavier du joueur
 * Traite les commandes de mouvement, pause et quitter
 */
void cGame::Input() {
    if (_kbhit()) {  // Si une touche est pressée
        char current = tolower(_getch());  // Lit la touche en minuscule
        
        // Gestion de l'écran de démarrage
        if (!started) {
            if (current == ' ') started = true;  // Espace pour commencer
            return;
        }
        
        // Gestion de la pause
        if (current == 'p') paused = !paused;  // P pour pause/reprendre
        if (paused) return;
        
        // Déplacements du joueur (ZQSD)
        if (current == 'q' && player->x > 0)
            player->x--;  // Gauche
        if (current == 'd' && player->x < width - 3)
            player->x++;  // Droite
        if (current == 'z' && player->y > 0)
            player->y--;  // Haut
        if (current == 's' && player->y < numberOfLanes - 1)
            player->y++;  // Bas
        if (current == 'w')
            quit = true;  // W pour quitter
    }
}

/**
 * @brief Gère la logique du jeu (mouvements, collisions, score)
 * Appelée à chaque frame du jeu
 */
void cGame::Logic() {
    if (!started || paused) return;  // Ne rien faire si jeu non démarré ou en pause
    
    // Parcours toutes les voies (sauf la première et dernière)
    for (int i = 1; i < numberOfLanes - 1; i++) {
        // Déplace aléatoirement les voitures
        if (rand() % (10 - level) == 1)
            map[i]->Move();
            
        // Vérifie les collisions avec le joueur
        if (map[i]->CheckPos(player->x) && player->y == i) {
            lives--;  // Perd une vie
            player->y = 0;  // Réinitialise la position
            player->x = width / 2;
            Beep(500, 300);  // Son d'avertissement
            
            // Vérifie si le jeu est terminé (plus de vies)
            if (lives <= 0) {
                // Animation de fin de jeu
                for (int i = 0; i < 3; i++) {
                    Draw();
                    Beep(300, 200);
                    Sleep(200);
                }
                quit = true;
            }
        }
    }
    
    // Vérifie si le joueur a atteint le bas (objectif)
    if (player->y == numberOfLanes - 1) {
        score += level * 10;  // Augmente le score
        player->y = 0;  // Réinitialise la position
        Beep(800, 200);  // Sons de réussite
        Beep(1000, 200);
        
        // Augmente le niveau si le score atteint un seuil
        if (score % (level * 30) == 0 && level < 5) {
            level++;
            speed = max(50, speed - 20);  // Augmente la vitesse
            map[rand() % numberOfLanes]->ChangeDirection();  // Change une voie aléatoire
        }
    }
}

/**
 * @brief Boucle principale du jeu
 * Gère le cycle du jeu (initialisation, boucle de jeu, fin de partie)
 */
void cGame::Run() {
    while (true) {  // Boucle principale (redémarrage du jeu)
        ResetGame();  // Réinitialise le jeu
        ShowStartScreen();  // Affiche l'écran de démarrage
        
        // Boucle de jeu
        while (!quit) {
            Input();  // Gère les entrées
            if (!paused && started) {
                Logic();  // Met à jour la logique
                Draw();   // Dessine l'état
                Sleep(speed);  // Contrôle la vitesse
            }
            else if (started) {
                Draw();  // Dessine même en pause
                Sleep(100);
            }
        }
        
        // Affiche l'écran de fin de jeu
        ShowGameOver();
        
        // Boucle d'attente des actions après Game Over
        while (true) {
            if (_kbhit()) {
                char input = tolower(_getch());
                if (input == 'r') {
                    break;  // R pour recommencer
                }
                else if (input == 'w') {
                    return;  // W pour quitter
                }
            }
            Sleep(100);
        }
    }
}