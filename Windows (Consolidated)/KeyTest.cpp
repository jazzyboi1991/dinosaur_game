#include <iostream>
#include <conio.h>

int main() {
    std::cout << "아무 키나 누르면 해당 ASCII 코드를 출력합니다. ESC로 종료\n";

    while (true) {
        if (_kbhit()) {
            int ch = _getch();
            std::cout << "key = " << ch << std::endl;
            if (ch == 27) break;
        }
    }

    return 0;
}
