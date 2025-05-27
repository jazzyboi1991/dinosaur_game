#ifndef DINOGAME_H_
#define DINOGAME_H_

#pragma once
#include "Dino.h"
#include "TreeManager.h"

class DinoGame
{
private:
    Dino dino;
    TreeManager treeManager;
    bool isRunning;
    double speed;
    int frameCount;
    int score;
    bool prev_space_pressed;
public:
    DinoGame();
    int getScore() const;
    void run();
};

#endif