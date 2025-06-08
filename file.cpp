#include "game.h"
// Dummy file for linking purposes
/* TO OPEN THE FILE
using the constructure
using the member function open() of the class
*/

void save_info()
{
	char str[50] = "SCORE : ";
 ofstream out("score.txt");   // write stream 
 out<<str<<user.score;
}

void view_info()
{
	int yinc = 50;
	string str2;
	ifstream in("score.txt");
	getline(in , str2);
	cout <<str2;
	
	while(!eof(int))
	{
		outtextxy(100 , 50 + yinc, str2);
	}
}