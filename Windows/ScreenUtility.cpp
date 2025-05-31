#include "ScreenUtility.h"
#include <windows.h>
#include <cstdlib>

void ScreenUtility::CursorSettings() // GetConsoleCursorInfo로 현재 커서 상태를 가져온 뒤, bVisible을 FALSE로 설정.
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 출력 핸들 가져오기
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo); // 현재 커서 정보 얻기
    cursorInfo.bVisible = FALSE; 
    cursorInfo.bVisible = FALSE; // 커서 숨기기 설정
    SetConsoleCursorInfo(hOut, &cursorInfo); // 커서 정보 갱신
}

// 콘솔 커서를 주어진 (x, y) 위치로 이동시킨다.
void ScreenUtility::SetCursor(int x, int y)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 출력 핸들
    COORD coord = { (SHORT)x, (SHORT)y }; // 이동할 좌표 지정
    SetConsoleCursorPosition(hOut, coord); // 콘솔 커서 위치 변경
}

// 콘솔 화면 전체를 지운다.
void ScreenUtility::Clear()
{
    system("cls"); // system 명령어를 통해 'cls' 명령 실행 (Windows 전용)
}