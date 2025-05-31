#ifndef DINO_H
#define DINO_H

class Dino
{
private:
    int yPos; // 현재 Y 좌표
    int jumpCount; // 점프 횟수 제한용 변수
    bool isFalling; // 낙하 여부
    bool footToggle; // 발 움직임 (애니메이션 효과)
    const int maxJumpCount = 2; // 최대 점프 횟수 = 2번
    int landingDelay; // 착지 후 딜레이
    const int landingDelayThreshold = 5; // 착지 딜레이 제한 값
    float jumpSpeed; // 점프 속도
    float fallSpeed; // 낙하 속도
    float jumpProgress; // 점프 진행도 (부드러운 점프 구현용)
    float fallProgress; // 낙하 진행도
public:
    Dino(); // 생성자
    void update(); // 상태 업데이트
    void draw(); // 화면 출력
    void jump(); // 점프 동작
    int getYPos() const; // Y 좌표 반환
    void setJumpFallSpeed(float baseSpeed); // 점프/낙하 속도 설정
};

#endif
