#ifndef GAME_H
#define GAME_H

#include <vector>
#include "player.h"
#include "lane.h"
#include "constants.h"

class cGame {
private:
    bool quit;
    bool paused;
    bool started;
    int numberOfLanes;
    int width;
    int score;
    int lives;
    int speed;
    int level;
    cPlayer* player;
    std::vector<cLane*> map;
    
    void SetColor(int color);
    void DrawBorder();
    void ShowStartScreen();
    void ShowPauseScreen();
    void ShowGameOver();
    void ResetGame();

public:
    cGame(int w = 30, int h = 10);
    ~cGame();
    void Draw();
    void Input();
    void Logic();
    void Run();
};

#endif