#ifndef TREE_H_
#define TREE_H_

#pragma once

class Tree {
private:
    int xPos = 50;
public:
    void update();
    void draw() const;
    int getX() const;
};

#endif