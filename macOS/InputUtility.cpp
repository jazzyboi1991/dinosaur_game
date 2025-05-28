// 이 부분은 생성형 AI를 사용하여 만들어졌음.

#include "InputUtility.h"
#include <termios.h> // 터미널 Input/Output 설정
#include <unistd.h> // POSIX API
#include <fcntl.h> // 파일 디스크립터 설정
#include <cstdio> // getchar()

bool wasKeyPressed = false; // 키가 눌린 상태인지 여부 확인

int getKeyDown()
{
    struct termios oldt, newt; // 터미널 상태 저장용 구조체
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt); // 현재 터미널 속성 저장

    // 새로운 속성 설정: 캐논 모드와 에코 비활성화 (한 글자씩 입력 처리)
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // 변경 적용

    // 표준 입력을 논블로킹 모드로 설정 (입력이 없어도 프로그램이 종료되지 않음)
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    // 입력된 문자 가져오기 (없으면 EOF 반환)
    ch = getchar();

    // 원래의 터미널 설정 복구
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    // 키가 눌린 경우
    if (ch != EOF)
    {
        if (!wasKeyPressed)
        {
            wasKeyPressed = true; // 키가 새롭게 눌렸다고 표시
            return ch; // 해당 문자 반환
        }
    }
    else
    {
        wasKeyPressed = false; // 눌린 키가 없으면 상태 초기화
    }

    return 0; // 입력이 없을 경우 0 반환
}