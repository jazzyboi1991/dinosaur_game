#ifndef TREE_H_
#define TREE_H_

#pragma once
#include "ScreenUtility.h"

class Tree
{
private:
    float xPos;
public:
    Tree(int xOffset = 0);
    void update(float speed);
    void draw() const;
    bool isOffScreen() const;
    int getX() const;
};

#endif