#ifndef TREE_H_
#define TREE_H_

#pragma once
#include "ScreenUtility.h"

class Tree
{
private:
    float xPos; // 현재 X좌표
public:
    Tree(int xOffset = 0); // 생성자, 시작 위치에 오프셋 적용 가능함
    void update(float speed); // 위치 갱신 (왼쪽으로 이동)
    void draw() const; // 콘솔에 나무 출력
    bool isOffScreen() const; // 화면 밖에 있는지 여부 확인
    int getX() const; // 현재 X좌표 반환
};

#endif