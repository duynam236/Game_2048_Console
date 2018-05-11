#include "functions.h"

int main()
{
    gotoXY(20,5);
	Color(28);
	cout << "Chao mung ban den voi 2048!!!!";
	gotoXY(21,7);
	cout << "Nhan phim bat ky de bat dau!";
	_getch();
    Color(0);
	gotoXY(20,5);
	cout << "                             ";
	gotoXY(21,7);
	cout << "                            ";

	Start_Map();
	while (true)
	{
		ConTro(false);
		DrawGame();
		if (Check_Game()==true)
		{
			gotoXY(40,16);
			Color(39);
			cout << "Tro choi ket thuc! ";
		}

		char click=_getch();

		Copy();

		if (click=='w'||click=='W') Up();
		else if (click=='s'||click=='S') Down();
		else if (click=='a'||click=='A') Left();
		else if (click=='d'||click=='D') Right();
		else if (click=='e'||click=='E') exit(true);
		else continue;

		if (Check_Move()==false) continue;

		New_Map();
	}

	_getch();
	return 0;
}
