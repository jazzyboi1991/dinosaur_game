#include <conio.h>

bool wasKeyPressed = false;

int GetKeyDown()
{
    if (_kbhit()) // 키가 눌렸는지 확인
    {
        int ch = _getch(); // 눌린 키 값을 받아옴
        if (!wasKeyPressed)
        {
            wasKeyPressed = true;
            return ch;
        }
    }
    else
    {
        wasKeyPressed = false;
    }
    return 0;
}
