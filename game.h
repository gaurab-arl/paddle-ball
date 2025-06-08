#ifndef GAME_H
#define GAME_H

#include "graphics.h"
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

#define MAX_WIDTH 700
#define MAX_HEIGHT 650

#define paddel_speed 50
#define paddel_x (MAX_WIDTH / 2)
#define paddely (MAX_HEIGHT / 26)
#define ball_speed 10

extern int ballx;
extern int bally;
extern int ball_direction;
extern bool ball_status;
extern int ball_velocity_y;
extern int page;

struct user_info {
    int score = 0;
};

extern user_info user;

enum Screen { MENU, GAME, HISTORY };
extern Screen currentScreen;

// User UI
void component_redirect(int x, int y);
void game_start();
void history();
void user_menu();
void background_image();
void title();
void component_click();
void draw_back_button();

// Game UI
void draw_circle(int x, int y);
void draw_paddel(int x);

// Collision
void check_collision(int &ball_x, int &ball_y, int paddle_x);

// File 
void save_info();
void view_info();

#endif
