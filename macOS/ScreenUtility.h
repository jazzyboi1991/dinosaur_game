#ifndef SCREENUTILITY_H_
#define SCREENUTILITY_H_

#pragma once

class ScreenUtility // 콘솔 화면 출력과 커서 제어
{
public:
    static void CursorSettings(); // 커서 설정 (숨김 등)
    static void SetCursor(int x, int y); // 커서를 특정 위치로 이동시킴
    static void Clear(); // 화면 지우기
};

#endif