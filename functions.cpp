#include "functions.h"

// Gia tri cua cac o
int Map[4][4];
// Diem
int Score=0;

// Ham hien con tro
void ConTro(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

// Ham tao mau
void Color(int x) {
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Ham dat mau cho tung gia tri
int SetColor(int x)
{
    int a;
	switch (x)
	{
		case 2:			 a=2;  break;
		case 4:			 a=3;  break;
		case 8:			 a=4;  break;
		case 16:		 a=5;  break;
		case 32:		 a=6;  break;
		case 64:		 a=7;  break;
		case 128:		 a=8;  break;
		case 256:		 a=9;  break;
		case 512:		 a=10; break;
		case 1024:		 a=11; break;
		case 2048:		 a=12; break;
	}
	return a;
}

// Ham di chuyen con tro den vi tri (x,y)
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Ham ve khung game
void DrawBackground() {
	Color(13);
	for (int i=1;i<=3;i++)
		{
			gotoXY(i*7,0);
			cout << (char)203;
		}
	for (int i=1;i<=3;i++)
		{
			gotoXY(i*7,16);
			cout << (char)202;
		}
	for (int i=1;i<=3;i++)
		{
			gotoXY(0,i*4);
			cout << (char)204;
		}
	for (int i=1;i<=3;i++)
		{
			gotoXY(28,i*4);
			cout << (char)185;
		}
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
		{
			gotoXY(i*7,j*4);
			cout << (char)206;
		}
	for (int i=0;i<=4;i++)
	{
		for (int j=1;j<=27;j++)
			if (j!=7&&j!=14&&j!=21)
			{
				gotoXY(j,i*4);
				cout << (char)205;
			}
	}
	for (int i=0;i<=4;i++)
	{
		for (int j=1;j<=15;j++)
			if (j!=4&&j!=8&&j!=12)
			{
				gotoXY(i*7,j);
				cout << (char)186;
			}
	}
	gotoXY(0,0);
	cout << (char)201;
	gotoXY(28,0);
	cout << (char)187;
	gotoXY(0,16);
	cout << (char)200;
	gotoXY(28,16);
	cout << (char)188;
}

// Ham lay diem so cao nhat
int HighScore()
{
	int x;
	fstream filescore;
	filescore.open("HighScore.txt", ios::in);
	filescore >> x;
	filescore.close();
	return x;
}

// Ham ghi diem so cao nhat vao file
void WriteHighScore(int a)
{
	fstream filescore;
	filescore.open("HighScore.txt", ios::out);
	filescore << a;
	filescore.close();
}

// Ham khoi tao gia tri ban dau
void Start_Map()
{

	Score = 0;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			Map[i][j] = 0;
		}
	}

	srand(time(NULL));
	int Vitri[4];

	Vitri[0]=rand()%4;
	Vitri[1]=rand()%4;

	do {
		Vitri[2]=rand()%4;
		Vitri[3]=rand()%4;
	} while (Vitri[0]==Vitri[2]||Vitri[1]==Vitri[3]);

	Map[Vitri[0]][Vitri[1]] = 2;
	Map[Vitri[2]][Vitri[3]] = 2;
}

// Cac ham di chuyen

// Di chuyen len tren
void Up()
{
	// Dua cac gia tri len phia tren

	for (int j=0;j<4;j++) {
		int k=0;
		for (int i=0;i<4;i++) {
			if (Map[i][j]!=0) {
				Map[k][j]=Map[i][j];
				k++;
			}
		}
		for (int i=k;i<4;i++) Map[i][j]=0;
	}


	// Gop 2 gia tri giong nhau

	for (int j=0;j<4;j++) {
		int k=0;
		for (int i=0;i<4;i++) {
			if (Map!=0) {
				if (Map[i][j]==Map[i+1][j]) {
					Map[k][j]=2*Map[i][j];
					Score+=Map[k][j];
					k++;
					i++;
				}
				else {
					Map[k][j]=Map[i][j];
					k++;
				}
			}
		}
		for (int i=k;i<4;i++) Map[i][j]=0;
	}

}

// Di chuyen xuong duoi
void Down()
{
	// Dua cac gia tri xuong phia duoi

	for (int j=0;j<4;j++) {
		int k=3;
		for (int i=3;i>=0;i--) {
			if (Map[i][j]!=0) {
				Map[k][j]=Map[i][j];
				k--;
			}
		}
		for (int i=k;i>=0;i--) Map[i][j]=0;
	}

	// Gop 2 gia tri giong nhau

	for (int j=0;j<4;j++) {
		int k=3;
		for (int i=3;i>=0;i--) {
			if (Map!=0) {
				if (Map[i][j]==Map[i-1][j]) {
					Map[k][j]=2*Map[i][j];
					Score+=Map[k][j];
					k--;
					i--;
				}
				else {
					Map[k][j]=Map[i][j];
					k--;
				}
			}
		}
		for (int i=k;i>=0;i--) Map[i][j]=0;
	}

}

// Di chuyen sang trai
void Left()
{
	// Dua cac gia tri sang ben trai
	for (int i=0;i<4;i++) {
		int k=0;
		for (int j=0;j<4;j++) {
			if (Map[i][j]!=0) {
				Map[i][k]=Map[i][j];
				k++;
			}
		}
		for (int j=k;j<4;j++) Map[i][j]=0;
	}

	// Gop 2 gia tri giong nhau

	for (int i=0;i<4;i++) {
		int k=0;
		for (int j=0;j<4;j++) {
			if (Map[i][j]!=0) {
				if (Map[i][j]==Map[i][j+1]) {
					Map[i][k]=2*Map[i][j];
					Score+=Map[i][k];
					j++;
					k++;
				}
				else {
					Map[i][k]=Map[i][j];
					k++;
				}
			}
		}
		for (int j=k;j<4;j++) Map[i][j]=0;
	}

}

// Di chuyen sang phai
void Right()
{
	// Dua cac gia tri sang ben phai

	for (int i=0;i<4;i++) {
		int k=3;
		for (int j=3;j>=0;j--) {
			if (Map[i][j]!=0) {
				Map[i][k]=Map[i][j];
				k--;
			}
		}
		for (int j=k;j>=0;j--) Map[i][j]=0;
	}

	// Gop 2 gia tri giong nhau

	for (int i=0;i<4;i++) {
		int k=3;
		for (int j=3;j>=0;j--) {
			if (Map[i][j]!=0) {
				if (Map[i][j]==Map[i][j-1]) {
					Map[i][k]=2*Map[i][j];
					Score+=Map[i][k];
					j--;
					k--;
				}
				else {
					Map[i][k]=Map[i][j];
					k--;
				}
			}
		}
		for (int j=k;j>=0;j--) Map[i][j]=0;
	}
}

// Ham in ra giao dien game
void DrawGame()
{
    DrawBackground();
	if (Score>HighScore())
		WriteHighScore(Score);
	gotoXY(40,2);
	Color(14);
	cout << "Your score: ";
	Color(11);
	cout << Score;
	gotoXY(40,3);
	Color(14);
	cout << "High score: ";
	Color(11);
	cout << HighScore();
	gotoXY(40,5);
	Color(2);
	cout << "Guide:";
	gotoXY(44,7);
	Color(4);
	cout << "Press A: To the left.";
	gotoXY(44,8);
	Color(5);
	cout << "Press D: To the right.";
	gotoXY(44,9);
	Color(6);
	cout << "Press W: Go up.";
	gotoXY(44,10);
	Color(7);
	cout << "Press S: Go down.";
	gotoXY(40,12);
	Color(10);
	cout << "Press E to exit game!";
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
				if (Map[j][i]==0)
		{
		    Color(0);
			gotoXY(1+7*i,2+4*j);
			cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;

		}
		else
		{
			if (Map[j][i]<100)
			{
			    Color(0);
                gotoXY(1+7*i,2+4*j);
                cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
                Color(SetColor(Map[j][i]));
				gotoXY(3+7*i,2+4*j);
				cout << Map[j][i];
			}
			else
			{
			    Color(SetColor(Map[j][i]));
				gotoXY(2+7*i,2+4*j);
				cout << Map[j][i];
			}
		}
}

// Ham kiem tra con o trong trong bang khong
bool Check_Nu()
{
    for (int i=0;i<4;i++) {
		for (int j=0;j<4;j++) {
			if (Map[i][j]==0) {
				return true;
			}
		}
	}
	return false;
}

// Ham tao gia tri moi neu con o trong
void New_Map()
{
	if (Check_Nu()==true) {
	// Sinh ra vi tri bat ki con trong
	int i,j;
	srand(time(NULL));
	do
	{
		i=rand()%4;
		j=rand()%4;
	}
	while (Map[i][j]!=0);
	// Co 95% ti le xuat hien so 2, 5% ti le xuat hien so 4
	int number=rand()%100;
	if (number<95) Map[i][j]=2;
	else Map[i][j]=4;
	}
	else return;
}

// Ham kiem tra thao tac di chuyen co hop le khong
int Map1[4][4];
void Copy()
{
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			Map1[i][j]=Map[i][j];
}

bool Check_Move()
{
    bool Check=false;
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			if (Map[i][j]!=Map1[i][j]) Check=true;



	return Check;
}

// Ham kiem tra game ket thuc
bool Check_Game()
{
	if (Check_Nu()==false) {
		for (int i=0;i<4;i++) {
			for (int j=0;j<4;j++) {
				if (Map[i][j]==Map[i][j+1]||Map[i][j]==Map[i+1][j]) return false;
			}
		}
	}
	else if (Check_Nu()==true) return false;
	return true;
}
