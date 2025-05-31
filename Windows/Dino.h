#ifndef DINO_H
#define DINO_H

class Dino {
private:
    int yPos;
    int jumpCount;
    bool isFalling;
    bool footToggle;
    const int maxJumpCount;
    int landingDelay;
    const int landingDelayThreshold;
    float jumpSpeed;
    float fallSpeed;
    float jumpProgress;
    float fallProgress;

public:
    Dino();
    void update();
    void draw();
    void jump();
    int getYPos() const;
    void setJumpFallSpeed(float baseSpeed);
};

#endif