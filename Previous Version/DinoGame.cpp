#include <iostream>
#include <unistd.h>
#include "DinoGame.h"
#include "Dino.h"
#include "Tree.h"
#include "ScreenUtility.h"
#include "Constants.h"
using namespace std;



int GetKeyDown();

void DinoGame::run()
{
    int score = 0;
    bool collision = false;

    Dino dino;
    Tree tree;

    ScreenUtility::CursorSettings();
    ScreenUtility::Clear();

    while(true)
    {
        ScreenUtility::SetCursor(0, 0);
        cout<<"Score: "<<score<<endl;

        int key = GetKeyDown();
        if(key == KEY_ESC)
        {
            printf("\033[?25h");
            return;
        }
        else if(key == KEY_SPACE)
        {
            dino.jump();
        }
        
        dino.update();
        tree.update();

        if(tree.getX() < TREE_COLLISION && dino.getYPos() < Y_COLLISION
            && tree.getX() > TREE_END + 1)
        {
            collision = true;
        }

        tree.draw();
        dino.draw();

        usleep(SLEEP_TIME * 1000);
        ScreenUtility::Clear();

        if(collision)
        {
            cout<<"\n\n            Game Over\n           Score : "<<score<<endl;
            cout << "\nPress Enter to exit...";
            getchar();
            printf("\033[?25h");
            return;
        }
        else
        {
            score++;
        }
    }
}