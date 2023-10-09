//�����Ա�ṹ�޸ĵ�4��ĳ���ʹ��ʵ����ͬ�Ĺ��ܡ�
//����Point���Line�࣬��ʾ����ߣ�����setPoint�࣬
//��������Line���Ա��һ����ʾֱ�߽����Point��Ա��
//������������ֱ�߽���ĳ�Ա������
//��дÿ������Ӧ�ĳ�Ա�����Ͳ����õ���������

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
		cout << "��������Ϊ��" << endl << "(" << cross.x << "," << cross.y << ")" << endl;
	}
	else if (line_1.a == line_2.a && line_1.b != line_2.b)
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
	setPoint temp(line_01,line_02);
	temp.find_point();
}