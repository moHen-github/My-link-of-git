#include <graphics.h>
#include <conio.h>
#include<iostream>

using namespace std;

#define WINDOW_LENGTH 1024    //���̳�
#define WINDOW_WIDTH 768      //���̿�
#define BEGIN_X 85            //���������Ͻǵ��x����
#define BEGIN_Y 85            //���������Ͻǵ��y����
#define GRID_N 15             //������
#define GRID_LENGTH 30        //ÿ�����ӵı߳�����������


//����ͼ�ͱ���
IMAGE pic_moon;
IMAGE pic_ren;

//�����ά�������� 
int chessboard[15][15] = { 0 };


//****************��������*****************//


//�����ж���һ����
int last = 1;

//�����ʼλ��
int renX = 0;
int renY = 14;

int moonX = 7;
int moonY = 7;

int step = 0;

//�ж�Ӯ 
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
	//���ó�ʼ���
	//mciSendString("play  music\\qingtian.mp3",0,0,0);
	initgraph(WINDOW_LENGTH, WINDOW_WIDTH);
	loadsource();
	playgame();
}


void loadsource()
{

	//����
	loadimage(&pic_moon, L"tupian\\moon.png", GRID_LENGTH, GRID_LENGTH);
	loadimage(&pic_ren, L"tupian\\ren.png", GRID_LENGTH, GRID_LENGTH);
}


void playgame()
{


	//�ƶ�����
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

		//�ƶ�����
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
		settextstyle(50, 30, L"����");
		outtextxy(650, 340, L"ʤ��,�ն˲鿴�ƶ�����!");
		cout << "���ʤ�������ƶ�" << step << "��" << endl;
		Sleep(1000);
		closegraph();
	}
}

void wingame()
{
	if (renX == moonX && renY == moonY)
		num = 1;
}