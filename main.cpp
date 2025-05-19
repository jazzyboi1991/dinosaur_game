#include <iostream>
#include <limits>
#include "DinoGame.h"
using namespace std;

int main()
{
    char choice;
    do
    {
        DinoGame game;
        game.run();
        cout << "\n\n게임 오버! 최종 점수: " << endl;
        cout << "\n게임이 끝났습니다. 다시 하시겠습니까? (y/n): " << game.getScore() << endl;
        cin >> choice;
        std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    } while (choice == 'y' || choice == 'Y');
    return 0;
}