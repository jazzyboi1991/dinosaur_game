#include "TreeManager.h"
#include "Constants.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

TreeManager::TreeManager() : gapCounter(0.0f), spawnChance(0.7f) {
    srand((unsigned)time(nullptr));
    gapThreshold = static_cast<float>(rand() % 20 + 40);
}

void TreeManager::update(float speed) {
    float moveSpeed = speed * 1.2f;
    for (auto& tree : trees)
        tree.update(moveSpeed);

    trees.erase(remove_if(trees.begin(), trees.end(),
        [](const Tree& t) { return t.isOffScreen(); }), trees.end());

    gapCounter += 1.0f;
    if (gapCounter >= gapThreshold && trees.size() < 4) {
        gapThreshold = static_cast<float>(rand() % 10 + 10);
        float chance = static_cast<float>(rand() % 21 + 80) / 100.0f;
        if ((rand() % 100) < static_cast<int>(chance * 100)) {
            trees.emplace_back(Tree());
        }
        gapCounter = 0.0f;
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
