#include "game.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Dummy file for linking purposes
// TO OPEN THE FILE:
// - Using the constructor
// - Using the member function open() of the class

void save_info()
{
   ofstream out("C:\\Users\\user\\Videos\\paddel-ball\\score.txt");

    if (!out) {
        cout << "Unable to open file for writing.\n";
        return;
    }
    out << "SCORE : " << user.score;
    out.close();
}

void view_info()
{
    ifstream in("C:\\Users\\user\\Videos\\paddel-ball\\score.txt");
    if (!in) {
        cout << "Unable to open file for reading.\n";
        return;
    }

    string line;
    int y = 100;

    while (getline(in, line)) {
        cout << line << endl; // Console
        outtextxy(100, y, const_cast<char*>(line.c_str())); // Graphics
        y += 20;
    }

    in.close();
}
