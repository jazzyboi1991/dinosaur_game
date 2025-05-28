#ifndef DINOGAME_H_
#define DINOGAME_H_

#pragma once
#include "Dino.h" // 공룡 캐릭터 클래스
#include "TreeManager.h" // 나무 관리 클래스

class DinoGame
{
private:
    Dino dino; // 공룡 객체
    TreeManager treeManager; // 나무 매니저 객체
    bool isRunning; // 게임 실행 여부
    double speed; // 게임 속도
    int frameCount; // 프레임 카운터 (게임 진행 시 속도 증가에 사용)
    int score; // 현재 점수
    bool prev_space_pressed; // 점프 중복 방지용 스페이스 바 입력 점검용 변수
public:
    DinoGame(); // 생성자
    int getScore() const; // 현재 점수 반환
    void run(); // 게임 실행 함수
};

#endif