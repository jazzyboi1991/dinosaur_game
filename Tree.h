#ifndef TREE_H_
#define TREE_H_

#pragma once

class Tree {
private:
    int xPos = 50;
public:
    Tree();
    void update(int speed);
    void draw() const;
    bool isOffScreen() const;
    int getX() const;
};

#endif