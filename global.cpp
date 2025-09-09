#include "game.h"

// Global variable definitions - define each variable exactly ONCE
int ballx = MAX_WIDTH / 2;
int bally = MAX_HEIGHT / 2;
int ball_direction = 1;
int ball_velocity_y = -5;
int page = 0;
bool isGameOver = false;
bool ball_status = false;

user_info user;

Screen currentScreen = MENU;



/*
game.h - Header with all declarations
global.cpp - Global variable definitions only
game.cpp - Main game logic and rendering functions
collision.cpp - Collision detection functions
file_operations.cpp - File save/load functions
*/

/*
4. Key Rules:

Each function should be defined in exactly ONE .cpp file
Each global variable should be defined in exactly ONE .cpp file
Header files should only contain declarations (extern for variables, function prototypes)
All .cpp files should #include "game.h"
*/