#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>

using namespace std;

// Ham hien con tro
void ConTro(bool CursorVisibility);

// Ham tao mau
void Color(int x);

// Ham dat mau cho tung gia tri
int SetColor(int x);

// Ham di chuyen con tro den vi tri (x,y)
void gotoXY(int column, int line);

// Ham ve background
void DrawBackground();

// Ham lay diem so cao nhat
int HighScore();

// Ham lay diem so cao nhat
int HighScore();

// Ham tao gia tri ban dau
void Start_Map();

// Cac ham di chuyen

void Up();
void Down();
void Left();
void Right();

// Ham in ra giao dien game
void DrawGame();

// Ham kiem tra con o trong trong bang khong
bool Check_Nu();

// Ham tao gia tri moi neu con o trong
void New_Map();

// Ham kiem tra thao tac di chuyen co hop le khong
void Copy();
bool Check_Move();

// Ham kiem tra game ket thuc
bool Check_Game();

