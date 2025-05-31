#ifndef SCREENUTILITY_H
#define SCREENUTILITY_H

class ScreenUtility {
public:
    static void CursorSettings(); // 콘솔 커서를 숨기기 위한 설정
    static void SetCursor(int x, int y); // 콘솔 커서를 (x, y) 좌표로 이동
    static void Clear(); // 콘솔 화면을 모두 지움
};

#endif