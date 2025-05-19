#ifndef DINO_H_
#define DINO_H_

#pragma once
class Dino {
private:
    int yPos = 0;
    int jumpCount = 0;
    bool isFalling = false;
    bool footToggle = false;
    const int maxJumpCount = 2;
    int landingDelay = 0;
    const int landingDelayThreshold = 5;
public:
    void update();
    void draw();
    void jump();
    int getYPos() const;
};

#endif