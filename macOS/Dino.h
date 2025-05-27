#ifndef DINO_H_
#define DINO_H_

#pragma once
class Dino {
private:
    int yPos = 0;
    int jumpCount = 0;
    bool isFalling = true;
    bool footToggle = false;
    const int maxJumpCount = 2;
    int landingDelay = 0;
    const int landingDelayThreshold = 5;
    float jumpSpeed = 0.9f;
    float fallSpeed = 0.9f;
public:
    void update();
    void draw();
    void jump();
    int getYPos() const;
    void setJumpFallSpeed(float baseSpeed);
};

#endif