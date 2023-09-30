#include <iostream>



using namespace std;



struct information {

	int id;

	int age;

	string sex;

	information* next;

}*s, * p, * new_s, * new_p;

information* new_head = NULL;

int help_judge = 0;



void all_out(information*);

void sex_num_out(information*);

void last_inset(information*&);

void my_delete(information*&);

void classify(information*&);







int main()

{

	information* head;

	head = NULL;

	int select;

	do

	{

		cout << "************职工管理系统**********" << endl << endl;

		cout << "（0）           退出" << endl;

		cout << "（1）      显示全部信息" << endl;

		cout << "（2）         性别统计" << endl;

		cout << "（3）      新建职工信息" << endl;

		cout << "（4）      删除职工信息" << endl;

		cout << "（5）    将退休职工信息分离" << endl;

		cout << endl << "请输入相应功能的数字:" << endl;

		cin >> select;

		{

			switch (select)

			{

			case 1:

				all_out(head);

				break;

			case 2:

				sex_num_out(head);

				break;

			case 3:

				last_inset(head);

				break;

			case 4:

				my_delete(head);

				break;

			case 5:

				classify(head);

				break;

			default:

				cout << "输入错误，请重新输入：" << endl;

			}

		}

	} while (select);

}



void all_out(information* head)

{

	if (help_judge == 0)

	{

		cout << "还没有录入信息，表格为空" << endl;

		cout << endl << "返回菜单" << endl;

		return;

	}

	cout << "    职工信息表   " << endl;

	if (help_judge == 3)

		cout << endl << "职工全部信息为：" << endl;

	else

		cout << endl << "未退休职工信息为：" << endl;

	while (head)

	{

		cout << "id = " << head->id << "   age = " << head->age << "   sex = " << head->sex << endl;

		head = head->next;

	}

	if (help_judge == 5)

		cout << "退休职工信息为：" << endl;

	while (new_head)

	{

		cout << "id = " << new_head->id << "   age = " << new_head->age << "   sex = " << new_head->sex << endl;

		new_head = new_head->next;

	}

	cout << endl << "返回菜单" << endl;

}



void sex_num_out(information* head)

{

	cout << "       职工性别统计表" << endl;



	int sum_men = 0, sum_women = 0;

	while (head)

	{

		if (head->sex == "男")

			sum_men++;

		else

			sum_women++;

		head = head->next;

	}

	cout << "男职工人数为：" << sum_men << endl;

	cout << "女职工人数为：" << sum_women << endl;

	cout << endl << "返回菜单" << endl;

}





void last_inset(information*& head)

{

	help_judge = 3;

	cout << "开始录入新职工信息：" << endl;

	s = new information;

	cout << "id = ???" << "   age = ???" << "   sex = ???" << endl;

	cin >> s->id >> s->age >> s->sex;

	if (s->sex != "男" && s->sex != "女")

	{

		cout << "Sorry，性别输入错啦，程序返回菜单" << endl;

		delete s;

		return;

	}

	s->next = NULL;

	information* temp_head = head;

	while (temp_head)

	{

		if (s->id == temp_head->id)

		{

			cout << "id重复，返回菜单" << endl;

			delete s;

			return;

		}

		temp_head = temp_head->next;

	}



	if (head == NULL)

	{

		head = s;

		p = head;

		cout << endl << "返回菜单" << endl;

		return;

	}

	else

	{

		p->next = s;

		p = p->next;

		cout << endl << "返回菜单" << endl;

		return;

	}

}





void my_delete(information*& head)

{

	if (head == NULL)

	{

		cout << "删除失败，原因是你可能还没有输入信息，请输入后再尝试该功能，程序返回菜单" << endl << endl;

		return;

	}

	cout << "   删除职工信息" << endl;

	information* temp_head_1 = head->next;

	information* temp_head_2 = head;

	int delete_id;

	cin >> delete_id;

	while (temp_head_2)

	{

		if (delete_id == head->id)

		{

			head = head->next;

			delete temp_head_2;

			cout << "已删除" << endl;

			cout << endl << "返回菜单" << endl;

			return;

		}



		if (delete_id == temp_head_1->id)

		{

			s = temp_head_1;

			temp_head_1 = temp_head_1->next;

			temp_head_2->next = temp_head_1;

			delete s;

			cout << "已删除" << endl;

			cout << endl << "返回菜单" << endl;

			return;

		}

		temp_head_1 = temp_head_1->next;

		temp_head_2 = temp_head_2->next;

	}

	cout << "id没找到，返回菜单" << endl;

	return;

}



void classify(information*& head)

{

	cout << "开始分离退休职工信息" << endl;

	if (head == NULL)

	{

		cout << "分离失败，原因是你可能还没有输入信息，请输入后再尝试该功能，程序返回菜单" << endl << endl;

		return;

	}

	help_judge = 5;

	information* temp_head_1 = head->next;

	information* temp_head_2 = head;

	while (temp_head_1 || temp_head_2)

	{

		if ((head->age >= 60 && head->sex == "男") || (head->age >= 55 && head->sex == "女"))

		{

			s = head;

			if (temp_head_2)

				temp_head_2 = temp_head_2->next;

			if (temp_head_1)

				temp_head_1 = temp_head_1->next;

			head = temp_head_2;

			new_s = new information;

			new_s->id = s->id;

			new_s->age = s->age;

			new_s->sex = s->sex;

			new_s->next = NULL;

			delete s;

			if (new_head == NULL)

			{

				new_head = new_s;

				new_p = new_s;

			}

			else

			{

				new_p->next = new_s;

				new_p = new_p->next;

			}

		}

		else if ((temp_head_1) && ((temp_head_1->age >= 60 && temp_head_1->sex == "男") || (temp_head_1->age >= 55 && temp_head_1->sex == "女")))

		{

			s = temp_head_1;

			temp_head_2->next = temp_head_1->next;

			if (temp_head_1)

				temp_head_1 = temp_head_1->next;

			new_s = new information;

			new_s->id = s->id;

			new_s->age = s->age;

			new_s->sex = s->sex;

			new_s->next = NULL;

			delete s;

			if (new_head == NULL)

			{

				new_head = new_s;

				new_p = new_s;

			}

			else

			{

				new_p->next = new_s;

				new_p = new_p->next;

			}

		}

		else

		{

			if (temp_head_2)

				temp_head_2 = temp_head_2->next;

			if (temp_head_1)

				temp_head_1 = temp_head_1->next;

		}

	}

	cout << endl << "完成退休职工信息的分离，返回菜单" << endl << endl;

}