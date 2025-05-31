#include "DinoGame.h"
#include "ScreenUtility.h"
#include "InputUtility.h"
#include "Constants.h"
#include <iostream>
#include <thread>
#include <chrono>

DinoGame::DinoGame() : isRunning(true), speed(2.0), frameCount(0), score(0), prev_space_pressed(false) {}

int DinoGame::getScore() const {
    return score;
}

void DinoGame::run() {
    ScreenUtility::Clear();
    ScreenUtility::CursorSettings();
    dino.setJumpFallSpeed(speed);

    while (isRunning) {
        ScreenUtility::Clear();
        int key = GetKeyDown();
        bool space_pressed = (key == KEY_SPACE);

        if (space_pressed && !prev_space_pressed)
            dino.jump();
        prev_space_pressed = space_pressed;

        if (key == KEY_ESC)
            isRunning = false;

        dino.update();
        treeManager.update(speed);

        if (treeManager.checkCollision(dino.getYPos()))
            isRunning = false;

        score += speed;

        if (++frameCount % 300 == 0 && speed < 10) {
            speed += 0.2;
            dino.setJumpFallSpeed(speed);
        }

        dino.draw();
        treeManager.draw();

        ScreenUtility::SetCursor(0, 0);
        std::cout << "점수: " << score << "  속도: " << speed << std::endl;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
    }
}