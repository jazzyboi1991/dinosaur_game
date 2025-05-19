#include "DinoGame.h"
#include "Constants.h"
#include "ScreenUtility.h"
#include "InputUtility.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

DinoGame::DinoGame() : isRunning(true), speed(1), frameCount(0), score(0) {}

void DinoGame::run() {
    ScreenUtility::CursorSettings();
    srand(time(nullptr));

    while (isRunning) {
        int key = GetKeyDown();
        if (key == KEY_SPACE) dino.jump();
        if (key == KEY_ESC) isRunning = false;

        dino.update();
        treeManager.update(speed);

        if (treeManager.checkCollision(dino.getYPos())) {
            isRunning = false;
        }

        // 점수는 속도에 비례하여 증가
        score += speed;

        // 난이도 점진 증가
        if (++frameCount % 300 == 0 && speed < 10) {
            speed++;
        }

        ScreenUtility::Clear();
        dino.draw();
        treeManager.draw();
        ScreenUtility::SetCursor(0, 0);
        cout << "점수: " << score << "  속도: " << speed << endl;

        this_thread::sleep_for(chrono::milliseconds(SLEEP_TIME));
    }

    cout << "\n\n게임 오버! 최종 점수: " << score << "\n";
}