// file_operations.cpp
#include "game.h"

void save_info() {
    ofstream file("score.dat", ios::binary);
    if (file.is_open()) {
        file.write((char*)&user, sizeof(user));
        file.close();
    }
}

int view_info() {
	cleardevice();
	title();
	draw_back_button();
    ifstream file("score.dat", ios::binary);
    if (file.is_open()) {
        user_info temp;
        file.read((char*)&temp, sizeof(temp));
        if (file.gcount() == sizeof(temp)) {
            // Display the loaded score
            char scoreText[50];
            sprintf(scoreText, "Last Score: %d", temp.score);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
            setcolor(WHITE);
            outtextxy(50, 150, scoreText);
        }
        file.close();
    }
    return 0;
}