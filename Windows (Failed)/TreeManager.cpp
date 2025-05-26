#include "TreeManager.h"
#include "Constants.h"
#include <cstdlib> 
#include <ctime>
#include <algorithm>

TreeManager::TreeManager() : spawnAccumulator(0.0f), treeCount(0) {
    srand(time(nullptr));
    spawnThreshold = static_cast<float>(rand() % 15 + 25);
    gap = rand() % 20 + 20;
}

void TreeManager::update(float speed) {
    for (auto& tree : trees)
        tree.update(speed);

    trees.erase(std::remove_if(trees.begin(), trees.end(),
        [](const Tree& t) {return t.isOffScreen();}), trees.end());

    spawnAccumulator += speed * 1.0f;

    if(spawnAccumulator >= spawnThreshold)
    {
        if(trees.size() < 4)
        {
            if(trees.empty() || trees.back().getX() < TREE_START - gap)
            {
                trees.push_back(Tree());
                gap = rand() % 20 + 20;
                int raw = rand() % 100;
                if(raw < 10)
                    spawnThreshold = static_cast<float>(rand() % 10 + 5);
                else if(raw < 30)
                    spawnThreshold = static_cast<float>(rand() % 15 + 20);
                else if(raw < 60)
                    spawnThreshold = static_cast<float>(rand() % 20 + 35);
                else
                    spawnThreshold = static_cast<float>(rand() % 25 + 55);
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