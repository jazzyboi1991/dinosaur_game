#include <iostream>
#include "ScreenUtility.h"
#include "Dino.h"
#include "Constants.h"
using namespace std;

void Dino::jump()
{
    if(jumpCount < maxJumpCount)
    {
        isFalling = false;
        jumpCount++;
        landingDelay = 0;
    }
}

void Dino::update()
{
    if(!isFalling && yPos < MAX_JUMP)
    {
        if (!isFalling && yPos < MAX_JUMP) {
            jumpProgress += jumpSpeed;
            if (jumpProgress >= 1.0f) {
                yPos++;
                jumpProgress -= 1.0f;
            }
        } else {
            isFalling = true;
            if (yPos > 0) {
                fallProgress += fallSpeed;
                if (fallProgress >= 1.0f && yPos > 0) {
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
}

void Dino::draw()
{
    ScreenUtility::SetCursor(0, Y_BASE - yPos);
    cout<<"    D\n    DD\nDDDDD\n";
    if(footToggle)
    {
        cout<<"D\n";
    }
    else
    {
        cout<<"    D\n";
    }
    footToggle = !footToggle;
}

int Dino::getYPos() const
{
    return yPos;
}

void Dino::setJumpFallSpeed(float baseSpeed = 2)
{
    jumpSpeed = 5.0f + baseSpeed * 5.0f;
    fallSpeed = 5.0f + baseSpeed * 5.0f;
}