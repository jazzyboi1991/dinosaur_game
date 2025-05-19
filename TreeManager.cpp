#include "TreeManager.h"
#include "Constants.h"
#include <cstdlib> 
#include <ctime>
#include <algorithm>

TreeManager::TreeManager() : spawnTimer(0), treeCount(0) {
    srand(time(nullptr));
}

void TreeManager::update(float speed) {
    for (auto& tree : trees)
        tree.update(speed);

    trees.erase(std::remove_if(trees.begin(), trees.end(),
        [](const Tree& t) { return t.isOffScreen(); }), trees.end());


    if (--spawnTimer <= 0) {
        if(trees.size() < 3) {
            trees.push_back(Tree());
            treeCount++;
        }
        else {
            treeCount = 0;
        }
        int base = 80 + rand() % 60;
        spawnTimer = std::max(15, static_cast<int>(base / speed));
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