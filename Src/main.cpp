#include "game.h"  
#include <windows.h>
#include <ctime>

int main() {
    // Configuration de base de la console
    system("mode con: cols=60 lines=30");
    SetConsoleTitleA("Cross The Road");
    
    // Tentative de configuration UTF-8
    SetConsoleOutputCP(65001);
    
    srand(static_cast<unsigned int>(time(NULL)));
    cGame game(40, 12);
    game.Run();
    
    return 0;
}