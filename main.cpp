#include "Game.h"
Game GameSunny;
int main(int argc, char *args[])
{
    if (GameSunny.init())
    {
        if (GameSunny.loadMedia())
        {
            GameSunny.PlayMusic();
            while (!GameSunny.Quit_Menu)
                GameSunny.RenderMenu();
            while (GameSunny.Play_Again)
                GameSunny.PlayAgain();
        }
    }
    GameSunny.close();
    return 0;
}