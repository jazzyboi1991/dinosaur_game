#ifndef TREE_H_
#define TREE_H_

#pragma once

class Tree {
private:
    float xPos = 50;
public:
    Tree();
    void update(float speed);
    void draw() const;
    bool isOffScreen() const;
    int getX() const;
};

#endif