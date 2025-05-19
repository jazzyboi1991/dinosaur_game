#include "TreeManager.h"
#include "Constants.h"
#include <cstdlib> 
#include <ctime>
#include <algorithm>

TreeManager::TreeManager() : spawnAccumulator(0.0f), treeCount(0) {
    srand(time(nullptr));
}

void TreeManager::update(float speed) {
    for (auto& tree : trees)
        tree.update(speed);

    trees.erase(std::remove_if(trees.begin(), trees.end(),
        [](const Tree& t) {return t.isOffScreen();}), trees.end());

    spawnAccumulator += speed * 1.0f;
    spawnThreshold = 100.0f;

    if(spawnAccumulator >= spawnThreshold)
    {
        if(trees.size() < 3)
        {
            if(trees.empty() || trees.back().getX() < TREE_START - MIN_TREE_GAP)
            {
                trees.push_back(Tree());
            }
        }
        spawnAccumulator = 0.0f;
    }
}

void TreeManager::draw() const {
    for (const auto& tree : trees)
        tree.draw();
}

bool TreeManager::checkCollision(int dinoY) const {
    for (const auto& tree : trees) {
        if (tree.getX() <= TREE_COLLISION && dinoY < Y_COLLISION)
            return true;
    }
    return false;
}