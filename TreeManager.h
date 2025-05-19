#ifndef TREEMANAGER_H
#define TREEMANAGER_H

#include <vector>
#include "Tree.h"

class TreeManager {
private:
    std::vector<Tree> trees;
    int spawnTimer;
    int treeCount;
public:
    TreeManager();
    void update(float speed);
    void draw() const;
    bool checkCollision(int dinoY) const;
};

#endif