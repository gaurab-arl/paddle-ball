#include "game.h"

void check_collision(int &ball_x, int &ball_y, int paddle_x)
{
    if (ball_y + 10 >= MAX_HEIGHT - paddely)
    {
        if (ball_x >= paddle_x - 45 && ball_x <= paddle_x + 45)
        {
            ball_velocity_y = -ball_speed;
            user.score += 10;

            if (ball_x < paddle_x) ball_direction = -1;
            else if (ball_x > paddle_x) ball_direction = 1;
        }
        else if (ball_y >= MAX_HEIGHT - 10)
        {
            outtextxy(MAX_WIDTH / 2 - 50, MAX_HEIGHT / 2, (char*)"Game Over");
            delay(2000);
            user.score = 0;
            ball_y = 0;
        }
    }

    if (ball_y <= 10) {
        ball_y = 10;
        ball_velocity_y = ball_speed;
    }

    if (user.score % 50 == 0 && user.score != 0) {
        ball_velocity_y += 1;
    }
}
