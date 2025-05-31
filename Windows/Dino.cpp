#include "Dino.h"
#include "ScreenUtility.h"
#include "Constants.h"
#include <iostream>
#include <algorithm>

Dino::Dino() : yPos(0), jumpCount(0), isFalling(true), footToggle(false),
    maxJumpCount(2), landingDelay(0), landingDelayThreshold(5),
    jumpSpeed(0), fallSpeed(0), jumpProgress(0.0f), fallProgress(0.0f) {}

void Dino::update() {
    if (!isFalling && yPos < MAX_JUMP) {
        jumpProgress += jumpSpeed;
        while (jumpProgress >= 1.0f && yPos < MAX_JUMP) {
            yPos++;
            jumpProgress -= 1.0f;
        }
    } else {
        isFalling = true;
        if (yPos > 0) {
            fallProgress += fallSpeed;
            while (fallProgress >= 1.0f && yPos > 0) {
                yPos--;
                fallProgress -= 1.0f;
            }
        } else if (yPos == 2) {
            if (landingDelay < landingDelayThreshold)
                landingDelay++;
            else
                jumpCount = 0;
        } else {
            jumpCount = 0;
            landingDelay = 0;
        }
    }
}

void Dino::draw() {
    int yDraw = std::max(0, Y_BASE - yPos);
    ScreenUtility::SetCursor(0, yDraw);
    std::cout << "    D\n";
    ScreenUtility::SetCursor(0, yDraw + 1);
    std::cout << "    DD\n";
    ScreenUtility::SetCursor(0, yDraw + 2);
    std::cout << "DDDDD\n";
    ScreenUtility::SetCursor(0, yDraw + 3);
    std::cout << (footToggle ? "D\n" : "    D\n");
    footToggle = !footToggle;
}

void Dino::jump() {
    if (jumpCount < maxJumpCount) {
        isFalling = false;
        jumpCount++;
        landingDelay = 0;
    }
}

int Dino::getYPos() const {
    return yPos;
}

void Dino::setJumpFallSpeed(float baseSpeed) {
    jumpSpeed = 1.2f + baseSpeed * 0.3f;
    fallSpeed = 1.4f + baseSpeed * 0.35f;
}