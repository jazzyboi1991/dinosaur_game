#include "InputUtility.h"
#include <conio.h>

int GetKeyDown() {
    if (_kbhit()) {
        return _getch();
    }
    return 0;
}
