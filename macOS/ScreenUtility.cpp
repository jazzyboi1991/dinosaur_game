#include "ScreenUtility.h"
#include <cstdio>

void ScreenUtility::CursorSettings()
{
    printf("\033[?25l");  // Hide cursor
}

void ScreenUtility::SetCursor(int x, int y)
{
    printf("\033[%d;%dH", y + 1, x + 1);
}

void ScreenUtility::Clear()
{
    printf("\033[2J\033[1;1H");
}