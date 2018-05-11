#include "functions.h"

int main()
{
    gotoXY(23,5);
	Color(28);
	cout << "WELCOME TO 2048!!!!";
	gotoXY(21,7);
	cout << "Press any key to start!";
	_getch();
    Color(0);
	gotoXY(20,5);
	cout << "                             ";
	gotoXY(21,7);
	cout << "                            ";

	Start_Map();
	DrawBackground();
	while (true)
	{
		ConTro(false);
		DrawGame();
		if (Check_Game()==true&&Check_Win()==true)
		{
			gotoXY(40,16);
			Color(39);
			cout << "GAME OVER! YOU WIN!";
		}
		else if (Check_Game()==true&&Check_Win()==false)
        {
            gotoXY(40,16);
			Color(39);
			cout << "GAME OVER! YOU LOSE!";
        }

		char click=_getch();

		Copy();

		if (click=='w'||click=='W') {
                Up();
                if (Check_Move()==false) continue;
                New_Map();
		}
		else if (click=='s'||click=='S') {
                Down();
                if (Check_Move()==false) continue;
                New_Map();
		}
		else if (click=='a'||click=='A') {
                Left();
                if (Check_Move()==false) continue;
                New_Map();
		}
		else if (click=='d'||click=='D') {
                Right();
                if (Check_Move()==false) continue;
                New_Map();
		}
		else if (click=='e'||click=='E') exit(true);
		else continue;


	}

	_getch();
	return 0;
}
