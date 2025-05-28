#ifndef TREEMANAGER_H_
#define TREEMANAGER_H_

#pragma once
#include <vector>
#include "Tree.h"

class TreeManager
{
private:
    std::vector<Tree> trees; // 현재 존재하는 나무들
    float gapCounter; // 나무 사이의 간격 프레임 수
    float gapThreshold; // 새로운 나무가 생기는 간격 프레임 수
public:
    TreeManager(); // 생성자
    void update(float speed); // 나무 위치 이동 및 생성 처리
    void draw() const; // 모든 나무를 출력함
    bool checkCollision(int dinoY) const; // 공룡과 나무의 충돌 상태 판정
};

#endif
