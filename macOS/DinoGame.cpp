#include "DinoGame.h"
#include "ScreenUtility.h"
#include "InputUtility.h"
#include "Constants.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

DinoGame::DinoGame() // 생성자, 각종 변수의 초기 상태 설정
    : isRunning(true), speed(1.0), frameCount(0), score(0), prev_space_pressed(false) {}

int DinoGame::getScore() const // 점수 반환
{
    return score;
}

void DinoGame::run() // 게임 루프 실행
{
    ScreenUtility::Clear(); // 화면 초기화
    ScreenUtility::CursorSettings(); // 커서 설정
    srand(time(nullptr)); // 랜덤 초기화
    dino.setJumpFallSpeed(speed); // 공룡 점프 시 상승/낙하 속도 설정

    while (isRunning) // 게임이 실행 중일 때
    {
        int key = getKeyDown(); // 키보드 입력 감지
        bool space_pressed = (key == KEY_SPACE); // 스페이스 바 입력 여부 확인

        if (space_pressed && !prev_space_pressed)
            dino.jump(); // 직전에 스페이스 키가 입력되지 않은 상태로 지금 입력되면 점프 트리거 발동
        prev_space_pressed = space_pressed; // 스페이스 입력 저장

        if (key == KEY_ESC)
            isRunning = false; // ESC 키를 누르면 게임 종료

        dino.update(); // 공룡 상태 업데이트
        treeManager.update(speed); // 나무 상태 업데이트

        if (treeManager.checkCollision(dino.getYPos())) // 나무와 공룡 충돌 여부 체크
            isRunning = false; // 충돌하면 게임 종료

        score += speed; // 점수 증가 (게임 속도에 비례하여 증가)

        if (++frameCount % 300 == 0 && speed < 10) // 일정 프레임마다 속도 증가 (속도 최대값은 10)
        {
            speed += 0.2;
            dino.setJumpFallSpeed(speed); // 속도가 증가할수록 공룡의 점프 상승/하강 속도 증가
        }

        ScreenUtility::Clear(); // 화면 다시 그리기
        dino.draw(); // 공룡 그리기
        treeManager.draw(); // 나무 그리기

        ScreenUtility::SetCursor(0, 0); // 커서 위치 설정
        cout << "점수: " << score << "  속도: " << speed << endl;
        this_thread::sleep_for(chrono::milliseconds(SLEEP_TIME)); // 다음 프레임까지 대기
    }
}
