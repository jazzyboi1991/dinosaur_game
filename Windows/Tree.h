#ifndef TREE_H
#define TREE_H

class Tree {
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