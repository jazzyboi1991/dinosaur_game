#include "Tree.h"
#include "ScreenUtility.h"
#include "Constants.h"
#include <iostream>
using namespace std;

Tree::Tree(int xOffset) : xPos(TREE_START + xOffset) {} // 생성자, 나무를 화면 오른쪽에서 출현하도록 위치 설정

void Tree::update(float speed) // 매 프레임마다 나무를 왼쪽으로 이동시킴
{
    if (xPos > TREE_END) xPos -= speed; // 화면 왼쪽 경계를 넘지 않았으면 게임 속도에 비례하여 왼쪽으로 이동시킴
    else xPos = TREE_START; // 비정상적인 움직임이 보이면 화면 오른쪽 경계에서 재시작
}

void Tree::draw() const // 나무를 텍스트로 그리는 함수
{
    int x = (int)xPos; // 위치를 정수로 변환하여 출력 좌표로 사용
    if (x >= 0) // 화면 내에 있을 때만 그리기
    {
        ScreenUtility::SetCursor(x, Y_BASE);     cout << "  D  \n";
        ScreenUtility::SetCursor(x, Y_BASE + 1); cout << " DDD \n";
        ScreenUtility::SetCursor(x, Y_BASE + 2); cout << "DDDDD\n";
        ScreenUtility::SetCursor(x, Y_BASE + 3); cout << "  D  \n";
    }
}

bool Tree::isOffScreen() const { return xPos < TREE_END; } // 나무가 화면 왼쪽 바깥으로 벗어났는지 확인
int Tree::getX() const { return (int)xPos; } // 나무의 현재 위치를 정수로 반환 (충돌 판정 등에 사용됨)
