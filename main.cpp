#include <graphics.h>
#include "game.h"

int main() {
    initwindow(MAX_WIDTH, MAX_HEIGHT, "Paddle and Ball");
    currentScreen = MENU;
    user_menu();

    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            if (currentScreen == MENU) {
                // START
                if (x > 286 && x < 491 && y > 254 && y < 313) {
                    currentScreen = GAME;
                    game_start();
                    user_menu();  // re-show menu after game ends
                    currentScreen = MENU;
                }
                // SCORE
                else if (x > 286 && x < 491 && y > 329 && y < 393) {
                    currentScreen = HISTORY;
                    history();
                }
                // EXIT
                else if (x > 286 && x < 491 && y > 409 && y < 478) {
                    exit(0);
                }
            }

            // BACK button from HISTORY to MENU
            if (currentScreen == HISTORY &&
                x > 24 && x < 105 && y > 19 && y < 44) {
                currentScreen = MENU;
                user_menu();
            }
        }
    }

    closegraph();
    return 0;
}
