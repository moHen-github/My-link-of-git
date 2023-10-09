//����һ����ʾ��Ľṹ����Point��һ����ֱ�߷���y = ax + bȷ����ֱ����Line��
//�ṹ����Point��������Աx��y���ֱ��ʾ��ĺ�����������ꡣLine�����������ݳ�Աa��b��
//�ֱ��ʾֱ�߷����е�ϵ����Line����һ����Ա����print������ʾֱ�߷��̡�
//��Ԫ����setPoint(Line & l1, Line & l2)����������ֱ�ߵĽ��㡣
//��main�����У���������ֱ�߶��󣬷ֱ����print������ʾ����ֱ�ߵķ��̣�
//�����ú���setPoint��������ֱ�ߵĽ��㡣

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
		cout << "��������Ϊ��" << endl << "(" << cross.x << "," << cross.y << ")" << endl;
	}
	else if(line_1.a == line_2.a && line_1.b != line_2.b)
		cout << "����ֱ���޽���" << endl;
	else
		cout << "����ֱ���غ�" << endl;
}

void main()
{
	double L_1a, L_1b, L_2a, L_2b;
	cout << "�����������һ�����̵�б�ʺͽؾ�" << endl;
	cin >> L_1a >> L_1b;
	cout << endl << "����������ڶ������̵�б�ʺͽؾ�" << endl;
	cin >> L_2a >> L_2b;
	Line line_01(L_1a, L_1b), line_02(L_2a, L_2b);
	cout << endl << "��һ��ֱ�߷���Ϊ��" << endl;
	line_01.print();
	cout << "�ڶ���ֱ�߷���Ϊ��" << endl;
	line_02.print();
	setPoint(line_01, line_02);
}