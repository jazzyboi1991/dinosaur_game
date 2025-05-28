#include "ScreenUtility.h"
#include <cstdio>

void ScreenUtility::CursorSettings() // 콘솔 커서를 숨김
{
    printf("\033[?25l"); // ANSI 이스케이프 시퀀스: 커서 숨김 커맨드
}

void ScreenUtility::SetCursor(int x, int y) // 커서를 특정 위치로 이동시킴
{
    printf("\033[%d;%dH", y + 1, x + 1); // ANSI 이스케이프 시퀀스로 커서 위치 이동
}

void ScreenUtility::Clear() // 콘솔 화면을 초기화시킴
{
    printf("\033[2J\033[1;1H"); // 화면을 전체 삭제 후 커서를 1행 1열로 이동시킴
}