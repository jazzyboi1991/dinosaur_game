#include "TreeManager.h"
#include "Constants.h"
#include <cstdlib> 
#include <ctime>

TreeManager::TreeManager() : spawnTimer(0) {
    srand(time(nullptr));
}

void TreeManager::update(int speed) {
    for (auto& tree : trees)
        tree.update(speed);

    trees.erase(std::remove_if(trees.begin(), trees.end(),
        [](const Tree& t) { return t.isOffScreen(); }), trees.end());


    if (--spawnTimer <= 0) {
        trees.push_back(Tree());
        spawnTimer = 20 + rand() % 30;
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