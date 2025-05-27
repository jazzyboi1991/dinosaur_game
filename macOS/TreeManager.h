#ifndef TREEMANAGER_H_
#define TREEMANAGER_H_

#pragma once
#include <vector>
#include "Tree.h"

class TreeManager
{
private:
    std::vector<Tree> trees;
    float gapCounter;
    float gapThreshold;
    float spawnChance;
public:
    TreeManager();
    void update(float speed);
    void draw() const;
    bool checkCollision(int dinoY) const;
};

#endif
