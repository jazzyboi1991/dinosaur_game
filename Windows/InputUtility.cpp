#include <conio.h>  // Windows 콘솔 전용
#include <windows.h>

bool wasKeyPressed = false;

int GetKeyDown()
{
    if (_kbhit())
    {
        int ch = _getch();
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
