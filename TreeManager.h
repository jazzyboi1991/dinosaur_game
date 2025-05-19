#ifndef TREEMANAGER_H
#define TREEMANAGER_H

#include <vector>
#include "Tree.h"

class TreeManager {
private:
    std::vector<Tree> trees;
    int spawnTimer;

public:
    TreeManager();
    void update(int speed);
    void draw() const;
    bool checkCollision(int dinoY) const;
};

#endif