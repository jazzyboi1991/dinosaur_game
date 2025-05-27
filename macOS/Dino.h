#ifndef DINO_H_
#define DINO_H_

#pragma once
#include "ScreenUtility.h"

class Dino
{
private:
    int yPos;
    int jumpCount;
    bool isFalling;
    bool footToggle;
    const int maxJumpCount = 2;
    int landingDelay;
    const int landingDelayThreshold = 5;
    float jumpSpeed;
    float fallSpeed;
    float jumpProgress;
    float fallProgress;
public:
    Dino();
    void update();
    void draw();
    void jump();
    int getYPos() const;
    void setJumpFallSpeed(float baseSpeed);
};

#endif
