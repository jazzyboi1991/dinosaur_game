#ifndef DINOGAME_H
#define DINOGAME_H

#include "Dino.h"
#include "TreeManager.h"

class DinoGame {
private:
    Dino dino;
    TreeManager treeManager;
    bool isRunning;
    int speed;
    int frameCount;
    int score;

public:
    DinoGame();
    void run();
};

#endif