#include <graphics.h>
#include <conio.h>
#include<iostream>

using namespace std;

#define WINDOW_LENGTH 1024    //棋盘长
#define WINDOW_WIDTH 768      //棋盘宽
#define BEGIN_X 85            //棋盘最左上角点的x坐标
#define BEGIN_Y 85            //棋盘最左上角点的y坐标
#define GRID_N 15             //格子数
#define GRID_LENGTH 30        //每个格子的边长（像素数）


//定义图型变量
IMAGE pic_moon;
IMAGE pic_ren;

//定义二维棋盘数组 
int chessboard[15][15] = { 0 };


//****************核心数据*****************//


//定义判断玩家或电脑
int last = 1;

//人物初始位置
int renX = 0;
int renY = 14;

int moonX = 7;
int moonY = 7;

int step = 0;

//判断赢 
int num = 0;


void start();
void loadsource();
void playgame();
void wingame();
void drawpicture();


void main()
{
	start();
}


void start()
{
	//设置初始面板
	//mciSendString("play  music\\qingtian.mp3",0,0,0);
	initgraph(WINDOW_LENGTH, WINDOW_WIDTH);
	loadsource();
	playgame();
}


void loadsource()
{

	//加载
	loadimage(&pic_moon, L"tupian\\moon.png", GRID_LENGTH, GRID_LENGTH);
	loadimage(&pic_ren, L"tupian\\ren.png", GRID_LENGTH, GRID_LENGTH);
}


void playgame()
{


	//移动人物
	unsigned char ch;
	while (1)
	{
		drawpicture();
		if (last == 1 && renX >= 0 && renX <= 14 && renY >= 0 && renY <= 14)
		{
			ch = _getch();
			step++;
			switch (ch)
			{
			case 'a':
			case 'A':
			{
				renX--;
				last = 2;
				break;
			}
			case 'w':
			case 'W':
			{
				renY--;
				last = 2;
				break;
			}
			case 's':
			case 'S':
			{
				renY++;
				last = 2;
				break;
			}
			case 'd':
			case 'D':
			{
				renX++;
				last = 2;
				break;
			}
			}
		}

		if (renX > 14)
			renX--;
		if (renX < 0)
			renX++;
		if (renY > 14)
			renY--;
		if (renY < 0)
			renY++;

		//移动月亮
		if (last == 2)
		{
			last = 1;
			int moon_temp_X = rand() % 3;
			int moon_temp_Y = rand() % 3;
			switch (moon_temp_X)
			{
			case 0:
				break;
			case 1:
				moonX++;
				break;
			case 2:
				moonX--;
				break;
			}
			switch (moon_temp_Y)
			{
			case 0:
				break;
			case 1:
				moonY++;
				break;
			case 2:
				moonY--;
				break;
			}
		}
		if (moonX > 14)
			moonX--;
		if (moonX < 0)
			moonX++;
		if (moonY > 14)
			moonY--;
		if (moonY < 0)
			moonY++;
		wingame();
	}
}

void drawpicture()
{

	for (int i = 0; i < GRID_N; i++)
	{
		setlinecolor(WHITE);
		line(100, 100 + i * GRID_LENGTH, 100 + GRID_LENGTH * 14, 100 + i * GRID_LENGTH);
		line(100 + i * GRID_LENGTH, 100, 100 + i * GRID_LENGTH, 100 + GRID_LENGTH * 14);
	}

	cleardevice();
	putimage(BEGIN_X + renX * GRID_LENGTH, BEGIN_Y + renY * GRID_LENGTH, &pic_ren);
	putimage(BEGIN_X + moonX * GRID_LENGTH, BEGIN_Y + moonY * GRID_LENGTH, &pic_moon);

	if (num == 1)
	{
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		settextstyle(50, 30, L"宋体");
		outtextxy(650, 340, L"胜利,终端查看移动步数!");
		cout << "玩家胜利，共移动" << step << "步" << endl;
		Sleep(1000);
		closegraph();
	}
}

void wingame()
{
	if (renX == moonX && renY == moonY)
		num = 1;
}