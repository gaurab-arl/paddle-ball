#include "game.h"

int ballx = MAX_WIDTH / 2;
int bally = 50;
int ball_direction = 1;
bool ball_status = false;
int ball_velocity_y = ball_speed;
int page = 0;
user_info user;
Screen currentScreen = MENU;
