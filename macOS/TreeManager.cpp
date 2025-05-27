#include "TreeManager.h"
#include "Constants.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

TreeManager::TreeManager()
{
    srand(time(nullptr));
    gapCounter = 0.0f;
    gapThreshold = 30.0f;
    spawnChance = 0.7f;
}

void TreeManager::update(float speed)
{
    float moveSpeed = speed * 1.2f;

    for (auto& tree : trees)
        tree.update(moveSpeed);

    trees.erase(remove_if(trees.begin(), trees.end(),
        [](const Tree& t) { return t.isOffScreen(); }), trees.end());

    gapCounter += 1.0f;

    if (gapCounter >= gapThreshold && trees.size() < 4)
    {
        gapThreshold = static_cast<float>(rand() % 30 + 20);  // 새 간격 랜덤 재설정

        float chance = static_cast<float>(rand() % 21 + 80) / 100.0f;  // 출현 확률 80% ~ 100%
        if ((rand() % 100) < static_cast<int>(chance * 100))
        {
            trees.push_back(Tree());
        }
        gapCounter = 0.0f;
    }
}

void TreeManager::draw() const
{
    for (const auto& tree : trees)
        tree.draw();
}

bool TreeManager::checkCollision(int dinoY) const
{
    for (const auto& tree : trees)
    {
        if (tree.getX() <= TREE_COLLISION && dinoY < Y_COLLISION)
            return true;
    }
    return false;
}
