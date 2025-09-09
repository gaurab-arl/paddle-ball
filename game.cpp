#include "game.h"

// No global variable definitions here - they're in global.cpp

void draw_paddel(int x) {
    setfillstyle(SOLID_FILL, WHITE);
    bar(x - 50, MAX_HEIGHT - paddely, x + 50, MAX_HEIGHT);
}

void draw_circle(int x, int y) {
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x, y, 10, 10);
}

void show_message(const char* msg, int delay_ms) {
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    setcolor(YELLOW);
    outtextxy(MAX_WIDTH / 2 - 150, MAX_HEIGHT / 2, (char*)msg);
    delay(delay_ms);
}

// Functions check_collision and save_info are defined in separate files

void game_start() {
    // Reset state
    isGameOver = false;
    page = 0;
    ball_status = false;

    // Initialize variables
    char scoreText[20];
    int paddleX = paddel_x;
    char ch;
    int lastScoreCheckpoint = 0;

    ballx = MAX_WIDTH / 2;
    bally = MAX_HEIGHT / 2;
    ball_velocity_y = -5;
    ball_direction = 1;

    cleardevice();

    while (!isGameOver) {
        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();

        draw_circle(ballx, bally);
        sprintf(scoreText, "Score: %d", user.score);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        setcolor(WHITE);
        outtextxy(550, 50, scoreText);

        bally += ball_velocity_y;
        ballx += ball_direction * ball_speed;

        if (ballx <= 10) {
            ballx = 10;
            ball_direction = 1;
        }
        if (ballx >= MAX_WIDTH - 10) {
            ballx = MAX_WIDTH - 10;
            ball_direction = -1;
        }

        if (GetAsyncKeyState(VK_LEFT) & 0x8000 && paddleX > 50)
            paddleX -= paddel_speed;
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && paddleX < MAX_WIDTH - 50)
            paddleX += paddel_speed;

        if (kbhit()) {
            ch = getch();
            if (ch == 27) {
                show_message("Game Paused", 1000);
                // Optionally save or exit here
                return;  // Exit to menu on ESC
            }
        }

        draw_paddel(paddleX);
        check_collision(ballx, bally, paddleX);
        
        sprintf(scoreText, "Score: %d", user.score);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(WHITE);
outtextxy(550, 50, scoreText);

        if (user.score >= lastScoreCheckpoint + 100) {
            show_message("LEVEL UP! SPEED INCREASED!", 1200);
            lastScoreCheckpoint = user.score;
        }

        if (bally > MAX_HEIGHT) {
            isGameOver = true;
        }

        delay(30);
        page = 1 - page;
        ball_status = false;
    }

    // Outside the loop: always show Game Over screen
    setvisualpage(0);
    setactivepage(0);
    cleardevice();
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    setcolor(RED);
    outtextxy(MAX_WIDTH / 2 - 100, MAX_HEIGHT / 2 - 20, (char*)"GAME OVER");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);
    outtextxy(MAX_WIDTH / 2 - 150, MAX_HEIGHT / 2 + 30, (char*)"Press any key to return to menu...");
    getch();

    save_info();
    user.score = 0;

    user_menu();
}

