//定义一个表示点的结构类型Point和一个由直线方程y = ax + b确定的直线类Line。
//结构类型Point有两个成员x和y，分别表示点的横坐标和纵坐标。Line类有两个数据成员a和b，
//分别表示直线方程中的系数。Line类有一个成员函数print用于显示直线方程。
//友元函数setPoint(Line & l1, Line & l2)用于求两条直线的交点。
//在main函数中，建立两个直线对象，分别调用print函数显示两条直线的方程，
//并调用函数setPoint求这两条直线的交点。

#include <iostream>
using namespace std;

struct Point
{
	double x;
	double y;
};
class Line
{
	double a, b;
public:
	Line(double a1, double a2) :a(a1), b(a2) {}
	void print();
	friend void setPoint(Line& line_1, Line& line_2);
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

void setPoint(Line& line_1, Line& line_2)
{
	Point cross;
	if (line_1.a != line_2.a)
	{
		cross.x = (line_2.b - line_1.b) / (line_1.a - line_2.a);
		cross.y = line_1.a * cross.x + line_1.b;
		cout << "交点坐标为：" << endl << "(" << cross.x << "," << cross.y << ")" << endl;
	}
	else if(line_1.a == line_2.a && line_1.b != line_2.b)
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
	setPoint(line_01, line_02);
}