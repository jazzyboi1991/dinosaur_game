#include "Dino.h"
#include "ScreenUtility.h"
#include "Constants.h"
#include <iostream>
#include <algorithm>
using namespace std;

Dino::Dino() // 생성자: 공룡의 초기 상태 변수 설정
    : yPos(0), jumpCount(0), isFalling(true), footToggle(false),
    maxJumpCount(2), landingDelay(0), landingDelayThreshold(5),
    jumpSpeed(0), fallSpeed(0), jumpProgress(0.0f), fallProgress(0.0f) {}

void Dino::update() // 상태 업데이트: 점프/낙하 알고리즘
{
    if (!isFalling && yPos < MAX_JUMP) { // 떨어지는 상태가 아니고 Y좌표가 최대가 아닌 경우
        jumpProgress += jumpSpeed; // 점프 속도 누적
        while (jumpProgress >= 1.0f && yPos < MAX_JUMP) { // 점프 진행도가 1 이상일 때 실제 위치 증가
            yPos++; // Y 위치 증가
            jumpProgress -= 1.0f; // 이동 후 남은 진행도 유지
        }
    } else { // 점프 상태가 아니거나 최고점에 도달했을 때
        isFalling = true; // 떨어지는 상태로 설정
        if (yPos > 0) { // 공룡이 땅에 있지 않은 경우
            fallProgress += fallSpeed; // 낙하 시작
            while (fallProgress >= 1.0f && yPos > 0) { // 누적 낙하 진행도가 1 이상일 때 실제 위치 감소
                yPos--; // Y 위치 감소
                fallProgress -= 1.0f;
            }
        } else if (yPos == 2) { // 착지 위치가 2일 경우 (예외적 상황에 대응)
            // 지면에 닿은 직후 잠시 대기 (애니메이션 보정용)
            if (landingDelay < landingDelayThreshold)
                landingDelay++; // 딜레이 카운터 증가
            else
                jumpCount = 0; // 딜레이 경과 후 점프 가능 횟수 초기화
        } else {  // 공룡이 완전히 착지했을 경우
            jumpCount = 0; // 점프 가능 횟수 초기화
            landingDelay = 0; // 딜레이 카운터 초기화
        }
    }
}

void Dino::draw()  // 공룡 출력, 콘솔 커서 위치 설정
{
    int yDraw = std::max(0, Y_BASE - yPos); // 공룡의 높이에 따라 출력 위치 조정
    
    // "D"자를 사용해서 공룡의 모양 출력
    ScreenUtility::SetCursor(0, yDraw);
    cout << "    D\n";
    ScreenUtility::SetCursor(0, yDraw + 1);
    cout << "    DD\n";
    ScreenUtility::SetCursor(0, yDraw + 2);
    cout << "DDDDD\n";
    ScreenUtility::SetCursor(0, yDraw + 3);
    cout << (footToggle ? "D\n" : "    D\n"); // 발 움직임 표현
    footToggle = !footToggle; // 다음 프레임에 발 모양 전환
}

void Dino::jump() // 공룡의 점프를 다루는 함수
{
    if (jumpCount < maxJumpCount) { // 이중 점프 제한 확인
        isFalling = false; // 점프 상태로 전환함
        jumpCount++; // 점프 횟수 증가
        landingDelay = 0; // 착지 후 지연 제거 (빠른 연속 점프 가능)
    }
}

int Dino::getYPos() const // 현재 Y좌표 반환
{
    return yPos;
}

void Dino::setJumpFallSpeed(float baseSpeed) // 점프/낙하 속도 설정
{
    jumpSpeed = 1.2f + baseSpeed * 0.3f; // 게임 속도의 15%만큼 점프 속도 설정
    fallSpeed = 1.4f + baseSpeed * 0.35f; // 게임 속도의 10%만큼 낙하 속도 설정
}