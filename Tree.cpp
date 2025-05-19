#include <iostream>
#include "ScreenUtility.h"
#include "Tree.h"
#include "Constants.h"
using namespace std;

Tree::Tree()
{
    this->xPos = TREE_START;
}

void Tree::update(float speed)
{
    if(xPos > TREE_END)
        xPos -= speed;
    else
        xPos = TREE_START;
}

void Tree::draw() const
{
    int x = xPos;
    if (x >= 0) {
        ScreenUtility::SetCursor(x, Y_BASE); cout << "  D  \n";
        ScreenUtility::SetCursor(x, Y_BASE + 1); cout << " DDD \n";
        ScreenUtility::SetCursor(x, Y_BASE + 2); cout << "DDDDD\n";
        ScreenUtility::SetCursor(x, Y_BASE + 3); cout << "  D  \n";
    }
}

bool Tree::isOffScreen() const {
    return xPos < TREE_END;
}

int Tree::getX() const
{
    return xPos;
}