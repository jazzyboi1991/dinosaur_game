#include "DinoGame.h" // DinoGame 클래스 정의 포함
#include <iostream>
#include <limits> // 입력 스트림 정리용
using namespace std;

int main() {
    char choice;
    do {
        DinoGame game; // DinoGame 객체 생성
        game.run(); // 게임 실행 (메인 루프)

        cout << "\n\n게임 오버! 최종 점수: " << game.getScore() << endl; // 게임 종료 후 점수 출력
        cout << "\n게임이 끝났습니다. 다시 하시겠습니까? (y/n): " << endl; // 사용자가 게임을 다시 시작할지 묻기

        cin >> choice; // 사용자 입력 받기
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 다음 입력에 영향을 끼치지 않도록 입력 스트림 정리
    } while (choice == 'y' || choice == 'Y'); // 'y'나 'Y' 입력 시 재실행

    return 0;
}
