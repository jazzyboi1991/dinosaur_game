#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include <cmath>

using namespace std;

// ---------------- Constants ----------------
const int KEY_ESC = 27;
const int KEY_SPACE = 32;

const int MAX_JUMP = 12;
const int Y_BASE = 10;
const int Y_COLLISION = 1;

const int TREE_COLLISION = 1;
const int TREE_START = 80;
const int TREE_END = -6;

const int SLEEP_TIME = 35;

// ---------------- ScreenUtility ----------------
class ScreenUtility {
public:
    static void CursorSettings() {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hOut, &cursorInfo);
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(hOut, &cursorInfo);
    }

    static void SetCursor(int x, int y) {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coord = { (SHORT)x, (SHORT)y };
        SetConsoleCursorPosition(hOut, coord);
    }

    static void Clear() {
        system("cls");
    }
};

// ---------------- InputUtility ----------------
bool wasKeyPressed = false;
int GetKeyDown() {
    if (_kbhit())
    {
        return _getch();
    }
    return 0;
}

// ---------------- Tree ----------------
class Tree {
private:
    float xPos = 50;
public:
    Tree(int xOffset = 0) {
        xPos = TREE_START + xOffset;
    }

    void update(float speed) {
        if (xPos > TREE_END)
            xPos -= speed;
        else
            xPos = TREE_START;
    }

    void draw() const {
        int x = (int)xPos;
        if (x >= 0) {
            ScreenUtility::SetCursor(x, Y_BASE); cout << "  D  \n";
            ScreenUtility::SetCursor(x, Y_BASE + 1); cout << " DDD \n";
            ScreenUtility::SetCursor(x, Y_BASE + 2); cout << "DDDDD\n";
            ScreenUtility::SetCursor(x, Y_BASE + 3); cout << "  D  \n";
        }
    }

    bool isOffScreen() const {
        return xPos < TREE_END;
    }

    int getX() const {
        return (int)xPos;
    }
};

// ---------------- TreeManager ----------------
class TreeManager {
private:
    std::vector<Tree> trees;
    float gapCounter = 0.0f;
    float gapThreshold = 30.0f;
    float spawnChance = 0.7f;
public:
    TreeManager() {
        srand(time(nullptr));
        gapThreshold = static_cast<float>(rand() % 20 + 40);
    }

    void update(float speed) {
        for (auto& tree : trees)
            tree.update(speed);

        trees.erase(remove_if(trees.begin(), trees.end(),
            [](const Tree& t) {return t.isOffScreen();}), trees.end());
        
        gapThreshold = 30.0f;

        gapCounter += 1.0f;

        if(gapCounter >= gapThreshold && trees.size() < 4)
        {
            float chance = 0.0f;
            if (speed < 3.0f) {
                chance = (static_cast<float>(rand() % 20 + 10) / 100.0f) * (speed / 3.0f);
            } else {
                chance = static_cast<float>(rand() % 20 + 50) / 100.0f;
            }
            if ((rand() % 100) < static_cast<int>(chance * 100)) {
            trees.push_back(Tree());
        }

        gapCounter = 0.0f;
        }
    }

    void draw() const {
        for (const auto& tree : trees)
            tree.draw();
    }

    bool checkCollision(int dinoY) const {
        for (const auto& tree : trees) {
            if (tree.getX() <= TREE_COLLISION && dinoY < Y_COLLISION)
                return true;
        }
        return false;
    }
};

// ---------------- Dino ----------------
class Dino {
private:
    int yPos = 0;
    int jumpCount = 0;
    bool isFalling = true;
    bool footToggle = false;
    const int maxJumpCount = 2;
    int landingDelay = 0;
    const int landingDelayThreshold = 5;
    float jumpSpeed = 0.9f;
    float fallSpeed = 0.9f;
    float jumpProgress = 0.0f;
    float fallProgress = 0.0f;
public:
    void update() {
        if (!isFalling && yPos < MAX_JUMP) {
            jumpProgress += jumpSpeed;
            if (jumpProgress >= 1.0f) {
                yPos++;
                jumpProgress -= 1.0f;
            }
        } else {
            isFalling = true;
            if (yPos > 0) {
                fallProgress += fallSpeed;
                if (fallProgress >= 1.0f) {
                    yPos--;
                    fallProgress -= 1.0f;
                }
            } else if (yPos == 2) {
                if (landingDelay < landingDelayThreshold)
                    landingDelay++;
                else
                    jumpCount = 0;
            } else {
                jumpCount = 0;
                landingDelay = 0;
            }
        }
    }

    void draw() {
        ScreenUtility::SetCursor(0, Y_BASE - yPos);
        cout << "    D\n    DD\nDDDDD\n";
        if (footToggle)
            cout << "D\n";
        else
            cout << "    D\n";
        footToggle = !footToggle;
    }

    void jump() {
        if (jumpCount < maxJumpCount) {
            isFalling = false;
            jumpCount++;
            landingDelay = 0;
        }
    }

    int getYPos() const {
        return yPos;
    }

    void setJumpFallSpeed(float baseSpeed) {
        jumpSpeed = 1.0f + baseSpeed * 5.0f;
        fallSpeed = 1.0f + baseSpeed * 5.0f;
    }
};

// ---------------- DinoGame ----------------
class DinoGame {
private:
    Dino dino;
    TreeManager treeManager;
    bool isRunning;
    double speed;
    int frameCount;
    int score;
    bool prev_space_pressed;
public:
    DinoGame() : isRunning(true), speed(2.0), frameCount(0), score(0), prev_space_pressed(false) {}

    int getScore() const { return score; }

    void run() {
        //ScreenUtility::Clear();
        ScreenUtility::CursorSettings();
        srand((unsigned)time(nullptr));
        dino.setJumpFallSpeed(speed);

        int loopcount = 0;

        while (isRunning) {
            //ScreenUtility::Clear();
            int key = GetKeyDown();
            bool space_pressed = (key == KEY_SPACE);

            if (space_pressed && !prev_space_pressed)
                dino.jump();
            prev_space_pressed = space_pressed;

            if (key == KEY_ESC)
                isRunning = false;

            dino.update();
            treeManager.update(speed);

            int y = dino.getYPos();

            bool collided = treeManager.checkCollision(y);

            if (treeManager.checkCollision(dino.getYPos()))
                isRunning = false;

            score += speed;

            if (++frameCount % 300 == 0 && speed < 10) {
                speed += 0.2;
                dino.setJumpFallSpeed(speed);
            }

            dino.draw();
            treeManager.draw();

            ScreenUtility::SetCursor(0, 0);
            cout << "점수: " << score << "  속도: " << speed << endl;
            cout.flush();
            this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
        }
    }
};

// ---------------- main ----------------
int main() {
    char choice;
    do {
        DinoGame game;
        game.run();
        cout << "\n\n게임 오버! 최종 점수: " << game.getScore() << endl;
        cout << "\n게임이 끝났습니다. 다시 하시겠습니까? (y/n): " << endl;
        cin >> choice;
        cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
