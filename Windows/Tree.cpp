#include "Tree.h"
#include "ScreenUtility.h"
#include "Constants.h"
#include <iostream>

Tree::Tree(int xOffset) : xPos(TREE_START + xOffset) {}

void Tree::update(float speed) {
    if (xPos > TREE_END) xPos -= speed;
    else xPos = TREE_START;
}

void Tree::draw() const {
    int x = (int)xPos;
    if (x >= 0) {
        ScreenUtility::SetCursor(x, Y_BASE);     std::cout << "  D  \n";
        ScreenUtility::SetCursor(x, Y_BASE + 1); std::cout << " DDD \n";
        ScreenUtility::SetCursor(x, Y_BASE + 2); std::cout << "DDDDD\n";
        ScreenUtility::SetCursor(x, Y_BASE + 3); std::cout << "  D  \n";
    }
}

bool Tree::isOffScreen() const { return xPos < TREE_END; }
int Tree::getX() const { return (int)xPos; }
