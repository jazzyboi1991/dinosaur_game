#include <iostream>
#include "ScreenUtility.h"
#include "Dino.h"
#include "Constants.h"
using namespace std;

void Dino::jump()
{
    isJumping = true;
}

void Dino::update()
{
    if(isJumping)
    {
        if(yPos < MAX_JUMP && !isJumped)
        {
            yPos++;
        }
        else if(isJumped && yPos == 0)
        {
            isJumped = false;
            isJumping = false;
        }
        else if(isJumped)
        {
            yPos--;
        }
        else if(yPos == MAX_JUMP)
        {
            isJumped = true;
        }
    }
    else
    {
        if(yPos > 0)
        {
            yPos--;
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