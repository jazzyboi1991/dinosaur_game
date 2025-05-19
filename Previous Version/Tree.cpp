#include <iostream>
#include "ScreenUtility.h"
#include "Tree.h"
#include "Constants.h"
using namespace std;

void Tree::update()
{
    if(xPos > TREE_END)
        xPos -= 2;
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

int Tree::getX() const
{
    return xPos;
}