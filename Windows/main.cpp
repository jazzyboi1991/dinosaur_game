#include "DinoGame.h"
#include <iostream>
#include <limits>

int main() {
    char choice;
    do {
        DinoGame game;
        game.run();
        std::cout << "\n\n게임 오버! 최종 점수: " << game.getScore() << std::endl;
        std::cout << "\n게임이 끝났습니다. 다시 하시겠습니까? (y/n): " << std::endl;
        std::cin >> choice;
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    } while (choice == 'y' || choice == 'Y');
    return 0;
}