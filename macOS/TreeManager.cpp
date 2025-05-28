#include "TreeManager.h"
#include "Constants.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

TreeManager::TreeManager() // 생성자: 초기 상태 설정
{
    srand(time(nullptr)); // 난수 초기화
    gapCounter = 0.0f; // 간격 프레임 카운터 초기화
    gapThreshold = 30.0f; // 초기 간격 설정
}

void TreeManager::update(float speed) // 나무 이동, 생성, 제거 처리 (매 프레임마다 실행됨)
{
    float moveSpeed = speed * 1.2f; // 나무가 공룡보다 약간 빠르게 이동함

    for (auto& tree : trees) // 모든 나무를 이동시킴
        tree.update(moveSpeed);

    // 화면 밖의 나무는 제거함
    trees.erase(remove_if(trees.begin(), trees.end(),
        [](const Tree& t) { return t.isOffScreen(); }), trees.end());

    gapCounter += 1.0f; // 새로운 나무 생성 조건 확인

    // 일정 간격이 지나고 나무가 너무 많지 않으면
    if (gapCounter >= gapThreshold && trees.size() < 4)
    {
        gapThreshold = static_cast<float>(rand() % 30 + 20);  // 새 간격 랜덤 재설정 (20~49 프레임)

        float chance = static_cast<float>(rand() % 21 + 80) / 100.0f;  // 출현 확률 80% ~ 100%

        // 계산된 확률보다 작으면 나무 생성
        if ((rand() % 100) < static_cast<int>(chance * 100))
        {
            trees.push_back(Tree()); // 새로운 나무 추가
        }
        gapCounter = 0.0f; // 간격 카운터 초기화
    }
}

void TreeManager::draw() const // 모든 나무 출력
{
    for (const auto& tree : trees)
        tree.draw(); // 각 Tree 객체의 draw 함수 호출
}

bool TreeManager::checkCollision(int dinoY) const // 공룡과 나무의 충돌 여부 판정
{
    for (const auto& tree : trees)
    {
        // X좌표가 충돌 범위 이내이고, 공룡의 Y좌표가 낮으면 충돌로 간주함
        if (tree.getX() <= TREE_COLLISION && dinoY < Y_COLLISION)
            return true;
    }
    return false;
}
