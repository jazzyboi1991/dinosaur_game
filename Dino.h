#ifndef DINO_H_
#define DINO_H_

#pragma once
class Dino {
private:
    int yPos = 0;
    bool isJumping = false;
    bool isJumped = false;
    bool footToggle = false;
public:
    void update();
    void draw();
    void jump();
    int getYPos() const;
};

#endif