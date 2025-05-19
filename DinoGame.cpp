#include "DinoGame.h"
#include "Constants.h"
#include "ScreenUtility.h"
#include "InputUtility.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

DinoGame::DinoGame() : isRunning(true), speed(1.0), frameCount(0), score(0), prev_space_pressed(false) {}

void DinoGame::run() {
    ScreenUtility::CursorSettings();
    srand(time(nullptr));

    dino.setJumpFallSpeed(speed);

    while (isRunning) {
        int key = GetKeyDown();
        bool space_pressed = (key == KEY_SPACE);

        if(space_pressed && !prev_space_pressed)
        {
            dino.jump();
        }
        prev_space_pressed = space_pressed;

        if(key == KEY_ESC)
        {
            isRunning = false;
        }

        dino.update();
        treeManager.update(speed);

        if (treeManager.checkCollision(dino.getYPos())) {
            isRunning = false;
        }

        score += speed;

        if (++frameCount % 300 == 0 && speed < 10) {
            speed += 0.2;
            dino.setJumpFallSpeed(speed);
        }

        ScreenUtility::Clear();
        dino.draw();
        treeManager.draw();
        ScreenUtility::SetCursor(0, 0);
        cout << "점수: " << score << "  속도: " << speed << endl;

        this_thread::sleep_for(chrono::milliseconds(SLEEP_TIME));
    }
}


int DinoGame::getScore() const
{
    return score;
}
