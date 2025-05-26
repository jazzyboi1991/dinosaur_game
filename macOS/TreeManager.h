#ifndef TREEMANAGER_H
#define TREEMANAGER_H

#include <vector>
#include "Tree.h"

class TreeManager {
private:
    std::vector<Tree> trees;
    int treeCount;
    float spawnAccumulator = 0.0f;
    float spawnThreshold;
    int gap;
public:
    TreeManager();
    void update(float speed);
    void draw() const;
    bool checkCollision(int dinoY) const;
};

#endif