// game.h
#ifndef GAME_H
#define GAME_H

#include <graphics.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <cstdio>

using namespace std;

#define MAX_WIDTH 700
#define MAX_HEIGHT 650
#define paddel_speed 50
#define paddel_x (MAX_WIDTH / 2)
#define paddely (MAX_HEIGHT / 26)
#define ball_speed 10


// Global variable declarations (extern)
extern int ballx;
extern int bally;
extern int ball_direction;
extern int ball_velocity_y;
extern int page;
extern bool isGameOver;
extern bool ball_status;


struct user_info {
    int score;
    user_info() : score(0) {} // Constructor to initialize
};
extern user_info user;

enum Screen { MENU, GAME, HISTORY };
extern Screen currentScreen;

// Function declarations
void component_redirect(int x, int y);
void game_start();
void history();
void user_menu();
void background_image();
void title();
void draw_back_button();
void draw_circle(int x, int y);
void draw_paddel(int x);
void check_collision(int &ball_x, int &ball_y, int paddle_x);
void save_info();
int view_info();
void show_message(const char* msg, int delay_ms);

#endif