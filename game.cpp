#include "game.h"

void game_start()
{
    char scoreText[20];
    int paddleX = paddel_x;
    char ch;

    cleardevice();

    while (true) 
    {
        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();

        draw_circle(ballx,bally);

        sprintf(scoreText, "Score: %d", user.score);
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
            if (ch == 27) break;
        }

        draw_paddel(paddleX);
        check_collision(ballx, bally, paddleX);

        delay(30);
        page = 1 - page;
        ball_status = false;
    }
    save_info();
}

void draw_paddel(int x)
{
    setfillstyle(SOLID_FILL, WHITE);
    bar(x - 50, MAX_HEIGHT - paddely, x + 50, MAX_HEIGHT);
}

void draw_circle(int x, int y)
{
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x, y, 10, 10);
}
