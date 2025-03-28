#include "game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

void cGame::SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void cGame::DrawBorder() {
    SetColor(COLOR_ROAD);
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
}

void cGame::ShowStartScreen() {
    system("cls");
    SetColor(COLOR_TEXT);
    
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
    
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    string title = "C R O S S   T H E   R O A D";
    int titlePos = (width - 2 - title.length()) / 2;
    for (int j = 0; j < titlePos; j++) cout << " ";
    SetColor(COLOR_GOAL);
    cout << title;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - title.length() - titlePos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    string ctrl1 = "Use ZQSD to move, SPACE to start";
    int ctrl1Pos = (width - 2 - ctrl1.length()) / 2;
    for (int j = 0; j < ctrl1Pos; j++) cout << " ";
    SetColor(COLOR_CAR);
    cout << ctrl1;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - ctrl1.length() - ctrl1Pos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    string ctrl2 = "P = Pause, W = Quit";
    int ctrl2Pos = (width - 2 - ctrl2.length()) / 2;
    for (int j = 0; j < ctrl2Pos; j++) cout << " ";
    SetColor(COLOR_PLAYER);
    cout << ctrl2;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - ctrl2.length() - ctrl2Pos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
}

void cGame::ShowPauseScreen() {
    system("cls");
    SetColor(COLOR_TEXT);
    
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
    
    for (int i = 0; i < 3; i++) {
        cout << BORDER_VERT;
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << BORDER_VERT << endl;
    }
    
    cout << BORDER_VERT;
    string pauseMsg = "G A M E   P A U S E D";
    int msgPos = (width - 2 - pauseMsg.length()) / 2;
    for (int j = 0; j < msgPos; j++) cout << " ";
    SetColor(COLOR_GOAL);
    cout << pauseMsg;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - pauseMsg.length() - msgPos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    string continueMsg = "Press P to continue";
    int contPos = (width - 2 - continueMsg.length()) / 2;
    for (int j = 0; j < contPos; j++) cout << " ";
    SetColor(COLOR_PLAYER);
    cout << continueMsg;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - continueMsg.length() - contPos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    for (int i = 0; i < 3; i++) {
        cout << BORDER_VERT;
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << BORDER_VERT << endl;
    }
    
    cout << BORDER_VERT;
    string scoreMsg = "Score: " + to_string(score);
    int scorePos = (width - 2 - scoreMsg.length()) / 2;
    for (int j = 0; j < scorePos; j++) cout << " ";
    SetColor(COLOR_CAR);
    cout << scoreMsg;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - scoreMsg.length() - scorePos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    for (int i = 0; i < 2; i++) {
        cout << BORDER_VERT;
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << BORDER_VERT << endl;
    }
    
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
}

void cGame::ShowGameOver() {
    system("cls");
    SetColor(COLOR_TEXT);
    
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
    
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    string gameOverMsg = "G A M E   O V E R";
    int msgPos = (width - 2 - gameOverMsg.length()) / 2;
    for (int j = 0; j < msgPos; j++) cout << " ";
    SetColor(COLOR_CAR);
    cout << gameOverMsg;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - gameOverMsg.length() - msgPos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    string scoreMsg = "Score: " + to_string(score);
    int scorePos = (width - 2 - scoreMsg.length()) / 2;
    for (int j = 0; j < scorePos; j++) cout << " ";
    SetColor(COLOR_GOAL);
    cout << scoreMsg;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - scoreMsg.length() - scorePos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    string continueMsg1 = "Press R to restart";
    int cont1Pos = (width - 2 - continueMsg1.length()) / 2;
    for (int j = 0; j < cont1Pos; j++) cout << " ";
    SetColor(COLOR_PLAYER);
    cout << continueMsg1;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - continueMsg1.length() - cont1Pos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    string continueMsg2 = "Press W to quit";
    int cont2Pos = (width - 2 - continueMsg2.length()) / 2;
    for (int j = 0; j < cont2Pos; j++) cout << " ";
    SetColor(COLOR_PLAYER);
    cout << continueMsg2;
    SetColor(COLOR_TEXT);
    for (int j = 0; j < (width - 2 - continueMsg2.length() - cont2Pos); j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_VERT;
    for (int j = 0; j < width - 2; j++) cout << " ";
    cout << BORDER_VERT << endl;
    
    cout << BORDER_CORNER;
    for (int j = 0; j < width - 2; j++) cout << BORDER_HORIZ;
    cout << BORDER_CORNER << endl;
}

void cGame::ResetGame() {
    quit = false;
    paused = false;
    started = false;
    score = 0;
    lives = 3;
    speed = 150;
    level = 1;
    
    delete player;
    player = new cPlayer(width);
    
    for (int i = 0; i < map.size(); i++) {
        delete map[i];
    }
    map.clear();
    
    for (int i = 0; i < numberOfLanes; i++) {
        map.push_back(new cLane(width));
    }
}

cGame::cGame(int w, int h) {
    numberOfLanes = h;
    width = w;
    quit = false;
    paused = false;
    started = false;
    score = 0;
    lives = 3;
    speed = 150;
    level = 1;
    
    for (int i = 0; i < numberOfLanes; i++)
        map.push_back(new cLane(width));
    
    player = new cPlayer(width);
}

cGame::~cGame() {
    delete player;
    for (int i = 0; i < map.size(); i++) {
        cLane* current = map.back();
        map.pop_back();
        delete current;
    }
}

void cGame::Draw() {
    system("cls");
    
    if (!started) {
        ShowStartScreen();
        return;
    }
    
    if (paused) {
        ShowPauseScreen();
        return;
    }
    
    SetColor(COLOR_TEXT);
    cout << "Score: " << score << "  Level: " << level << "  Lives: " << lives << "\n\n";
    
    DrawBorder();
    
    for (int i = 0; i < numberOfLanes; i++) {
        SetColor(COLOR_TEXT);
        cout << BORDER_VERT;
        
        for (int j = 0; j < width - 2; j++) {
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
            
            if (map[i]->CheckPos(j) && i != 0 && i != numberOfLanes - 1) {
                SetColor(COLOR_CAR);
                cout << CAR_CHAR;
            }
            else if (player->x == j && player->y == i) {
                SetColor(COLOR_PLAYER);
                cout << PLAYER_CHAR;
            }
            else {
                SetColor(COLOR_ROAD);
                if (i == 0 || i == numberOfLanes - 1) cout << " ";
                else cout << (rand() % 10 == 0 ? "." : " ");
            }
        }
        
        SetColor(COLOR_TEXT);
        cout << BORDER_VERT << endl;
    }
    
    DrawBorder();
    
    SetColor(COLOR_TEXT);
    cout << "\n (P)Pause (W)Quit" << endl;
}

void cGame::Input() {
    if (_kbhit()) {
        char current = tolower(_getch());
        
        if (!started) {
            if (current == ' ') started = true;
            return;
        }
        
        if (current == 'p') paused = !paused;
        if (paused) return;
        
        if (current == 'q' && player->x > 0)
            player->x--;
        if (current == 'd' && player->x < width - 3)
            player->x++;
        if (current == 'z' && player->y > 0)
            player->y--;
        if (current == 's' && player->y < numberOfLanes - 1)
            player->y++;
        if (current == 'w')
            quit = true;
    }
}

void cGame::Logic() {
    if (!started || paused) return;
    
    for (int i = 1; i < numberOfLanes - 1; i++) {
        if (rand() % (10 - level) == 1)
            map[i]->Move();
            
        if (map[i]->CheckPos(player->x) && player->y == i) {
            lives--;
            player->y = 0;
            player->x = width / 2;
            Beep(500, 300);
            if (lives <= 0) {
                for (int i = 0; i < 3; i++) {
                    Draw();
                    Beep(300, 200);
                    Sleep(200);
                }
                quit = true;
            }
        }
    }
    
    if (player->y == numberOfLanes - 1) {
        score += level * 10;
        player->y = 0;
        Beep(800, 200);
        Beep(1000, 200);
        
        if (score % (level * 30) == 0 && level < 5) {
            level++;
            speed = max(50, speed - 20);
            map[rand() % numberOfLanes]->ChangeDirection();
        }
    }
}

void cGame::Run() {
    while (true) {
        ResetGame();
        ShowStartScreen();
        
        while (!quit) {
            Input();
            if (!paused && started) {
                Logic();
                Draw();
                Sleep(speed);
            }
            else if (started) {
                Draw();
                Sleep(100);
            }
        }
        
        ShowGameOver();
        
        while (true) {
            if (_kbhit()) {
                char input = tolower(_getch());
                if (input == 'r') {
                    break;
                }
                else if (input == 'w') {
                    return;
                }
            }
            Sleep(100);
        }
    }
}