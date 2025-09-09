// collision.cpp
#include "game.h"

void check_collision(int &ball_x, int &ball_y, int paddle_x)
{
    static int lastMilestone = 0; // Used to track last score milestone
    static bool gameOverTriggered = false;
    
    // --- Ball hits the paddle ---
    if (ball_y + 10 >= MAX_HEIGHT - paddely)
    {
        if (ball_x >= paddle_x - 45 && ball_x <= paddle_x + 45)
        {
            // Bounce back
            ball_velocity_y = -ball_speed;
            user.score += 10;
            // Ball direction based on hit position
            ball_direction = (ball_x < paddle_x) ? -1 : 1;
            // Increase difficulty every 50 points only once
            if (user.score >= lastMilestone + 50) {
                lastMilestone = user.score;
                ball_velocity_y -= 1;  // Increase ball speed
            }
        }
        else if (ball_y >= MAX_HEIGHT - 10 && !gameOverTriggered)
        {
            // Trigger game over just once
            isGameOver = true;
            gameOverTriggered = true;
        }
    }
    
    // --- Ball hits the top wall ---
    if (ball_y <= 10) {
        ball_y = 10;
        ball_velocity_y = ball_speed;
    }
        save_info();
}
