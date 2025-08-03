#include "game.h"

void background_image() {
    readimagefile("C:\\Users\\user\\Downloads\\female.bmp", 1, 249, 221, 475);
}

void draw_back_button() {
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    rectangle(24, 19, 105, 44);
    outtextxy(30, 25, (char*)"BACK");
}

void title() {
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 5);
    bar(((MAX_WIDTH / 2) / 2) - 20, ((MAX_HEIGHT / 2) / 5) + 20,
        (MAX_WIDTH / 2) + ((MAX_WIDTH / 2) / 2), ((MAX_HEIGHT / 2) / 5) + 20);

    setcolor(RGB(150, 150, 150));
    int text_width = textwidth((char*)"PADDLE AND BALL");
    outtextxy((MAX_WIDTH - text_width) / 2, (MAX_HEIGHT / 2) / 5, (char*)"PADDLE AND BALL");
}

void user_menu() {
    cleardevice();
    background_image();
    title();

    setcolor(RED);
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 3);

    int btn_width = 205;
    int btn_height = 60;
    int btn_x = (MAX_WIDTH - btn_width) / 2;

    int y_start = 250;
    rectangle(btn_x, y_start, btn_x + btn_width, y_start + btn_height);
    outtextxy(btn_x + 60, y_start + 15, (char*)"START");

    int y_score = y_start + 80;
    rectangle(btn_x, y_score, btn_x + btn_width, y_score + btn_height);
    outtextxy(btn_x + 60, y_score + 15, (char*)"SCORE");

    int y_exit = y_score + 85;
    rectangle(btn_x, y_exit, btn_x + btn_width, y_exit + btn_height);
    outtextxy(btn_x + 65, y_exit + 15, (char*)"EXIT");

    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);

    const char* made_by = "This is made by Gaurab Aryal";
    const char* thank_you = "Please say : Thank You";

    int text_width1 = textwidth((char*)made_by);
    int text_width2 = textwidth((char*)thank_you);

    int text_y1 = MAX_HEIGHT - 100;
    int text_y2 = MAX_HEIGHT - 70;

    outtextxy((MAX_WIDTH - text_width1) / 2, text_y1, (char*)made_by);
    outtextxy((MAX_WIDTH - text_width2) / 2, text_y2, (char*)thank_you);

    currentScreen = MENU;
}

void history() {
    cleardevice();
    draw_back_button();

    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 3);
    setcolor(YELLOW);
    outtextxy(200, 200, (char*)"Your Score History...");

    currentScreen = HISTORY;
}

// This function handles button clicks based on current screen
void component_redirect(int x, int y) {
    // BACK button
    if (x > 24 && x < 105 && y > 19 && y < 44) {
        user_menu();
        currentScreen = MENU;
        return;
    }

    if (currentScreen == MENU) {
        if (x > 286 && x < 491 && y > 254 && y < 313) {
            game_start();
            currentScreen = GAME;
        } else if (x > 286 && x < 491 && y > 329 && y < 393) {
            history();
            currentScreen = HISTORY;
        } else if (x > 286 && x < 491 && y > 409 && y < 478) {
            exit(0);
        }
    }
}
