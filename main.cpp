#include "game.h"

int main()
{
    initwindow(MAX_WIDTH, MAX_HEIGHT, "PADDLE AND BALL");
    background_image();
    title();
    user_menu();

    while (true) {
        component_click();  // Detect click inside loop
        if (kbhit()) break; // Press any key to exit
    }

    closegraph();
    return 0;
}
