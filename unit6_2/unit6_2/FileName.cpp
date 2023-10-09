//用类成员结构修改第4题的程序，使其实现相同的功能。
//定义Point类和Line类，表示点和线；定义setPoint类，
//包含两个Line类成员和一个表示直线交点的Point成员，
//并定义类中求直线交点的成员函数。
//编写每个类相应的成员函数和测试用的主函数。

#include <iostream>
using namespace std;

class Point
{
public:
	double x;
	double y;
};

class Line
{
public:
	double a, b;
	Line(double a1, double a2) :a(a1), b(a2) {}
	void print();	
};

class setPoint
{
	Line line_1;
	Line line_2;
	Point cross;
public:
	setPoint(Line my_line1, Line my_line2) :line_1(my_line1),line_2(my_line2){}
	void find_point();
};


void Line::print()
{
	if (b)
	{
		if (a != 0 && a != 1 && a != -1)
			cout << "y = " << a << "x + " << b << endl;
		else if (a == 0)
			cout << "y = " << b << endl;
		else if (a == 1)
			cout << "y = " << "x + " << b << endl;
		else
			cout << "y = " << "-x + " << b << endl;
	}
	else
	{
		if (a != 0 && a != 1 && a != -1)
			cout << "y = " << a << "x " << endl;
		else if (a == 0)
			cout << "y = 0" << endl;
		else if (a == 1)
			cout << "y = " << "x  " << endl;
		else
			cout << "y = " << "-x + " << endl;
	}
}

void setPoint::find_point()
{
	Point cross;
	if (line_1.a != line_2.a)
	{
		cross.x = (line_2.b - line_1.b) / (line_1.a - line_2.a);
		cross.y = line_1.a * cross.x + line_1.b;
		cout << "交点坐标为：" << endl << "(" << cross.x << "," << cross.y << ")" << endl;
	}
	else if (line_1.a == line_2.a && line_1.b != line_2.b)
		cout << "两个直线无交点" << endl;
	else
		cout << "两个直线重合" << endl;
}

void main()
{
	double L_1a, L_1b, L_2a, L_2b;
	cout << "请依次输入第一个方程的斜率和截距" << endl;
	cin >> L_1a >> L_1b;
	cout << endl << "请依次输入第二个方程的斜率和截距" << endl;
	cin >> L_2a >> L_2b;
	Line line_01(L_1a, L_1b), line_02(L_2a, L_2b);
	cout << endl << "第一个直线方程为：" << endl;
	line_01.print();
	cout << "第二个直线方程为：" << endl;
	line_02.print();
	setPoint temp(line_01,line_02);
	temp.find_point();
}