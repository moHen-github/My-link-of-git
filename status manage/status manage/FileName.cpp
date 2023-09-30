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

		cout << "************ְ������ϵͳ**********" << endl << endl;

		cout << "��0��           �˳�" << endl;

		cout << "��1��      ��ʾȫ����Ϣ" << endl;

		cout << "��2��         �Ա�ͳ��" << endl;

		cout << "��3��      �½�ְ����Ϣ" << endl;

		cout << "��4��      ɾ��ְ����Ϣ" << endl;

		cout << "��5��    ������ְ����Ϣ����" << endl;

		cout << endl << "��������Ӧ���ܵ�����:" << endl;

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

				cout << "����������������룺" << endl;

			}

		}

	} while (select);

}



void all_out(information* head)

{

	if (help_judge == 0)

	{

		cout << "��û��¼����Ϣ�����Ϊ��" << endl;

		cout << endl << "���ز˵�" << endl;

		return;

	}

	cout << "    ְ����Ϣ��   " << endl;

	if (help_judge == 3)

		cout << endl << "ְ��ȫ����ϢΪ��" << endl;

	else

		cout << endl << "δ����ְ����ϢΪ��" << endl;

	while (head)

	{

		cout << "id = " << head->id << "   age = " << head->age << "   sex = " << head->sex << endl;

		head = head->next;

	}

	if (help_judge == 5)

		cout << "����ְ����ϢΪ��" << endl;

	while (new_head)

	{

		cout << "id = " << new_head->id << "   age = " << new_head->age << "   sex = " << new_head->sex << endl;

		new_head = new_head->next;

	}

	cout << endl << "���ز˵�" << endl;

}



void sex_num_out(information* head)

{

	cout << "       ְ���Ա�ͳ�Ʊ�" << endl;



	int sum_men = 0, sum_women = 0;

	while (head)

	{

		if (head->sex == "��")

			sum_men++;

		else

			sum_women++;

		head = head->next;

	}

	cout << "��ְ������Ϊ��" << sum_men << endl;

	cout << "Ůְ������Ϊ��" << sum_women << endl;

	cout << endl << "���ز˵�" << endl;

}





void last_inset(information*& head)

{

	help_judge = 3;

	cout << "��ʼ¼����ְ����Ϣ��" << endl;

	s = new information;

	cout << "id = ???" << "   age = ???" << "   sex = ???" << endl;

	cin >> s->id >> s->age >> s->sex;

	if (s->sex != "��" && s->sex != "Ů")

	{

		cout << "Sorry���Ա�������������򷵻ز˵�" << endl;

		delete s;

		return;

	}

	s->next = NULL;

	information* temp_head = head;

	while (temp_head)

	{

		if (s->id == temp_head->id)

		{

			cout << "id�ظ������ز˵�" << endl;

			delete s;

			return;

		}

		temp_head = temp_head->next;

	}



	if (head == NULL)

	{

		head = s;

		p = head;

		cout << endl << "���ز˵�" << endl;

		return;

	}

	else

	{

		p->next = s;

		p = p->next;

		cout << endl << "���ز˵�" << endl;

		return;

	}

}





void my_delete(information*& head)

{

	if (head == NULL)

	{

		cout << "ɾ��ʧ�ܣ�ԭ��������ܻ�û��������Ϣ����������ٳ��Ըù��ܣ����򷵻ز˵�" << endl << endl;

		return;

	}

	cout << "   ɾ��ְ����Ϣ" << endl;

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

			cout << "��ɾ��" << endl;

			cout << endl << "���ز˵�" << endl;

			return;

		}



		if (delete_id == temp_head_1->id)

		{

			s = temp_head_1;

			temp_head_1 = temp_head_1->next;

			temp_head_2->next = temp_head_1;

			delete s;

			cout << "��ɾ��" << endl;

			cout << endl << "���ز˵�" << endl;

			return;

		}

		temp_head_1 = temp_head_1->next;

		temp_head_2 = temp_head_2->next;

	}

	cout << "idû�ҵ������ز˵�" << endl;

	return;

}



void classify(information*& head)

{

	cout << "��ʼ��������ְ����Ϣ" << endl;

	if (head == NULL)

	{

		cout << "����ʧ�ܣ�ԭ��������ܻ�û��������Ϣ����������ٳ��Ըù��ܣ����򷵻ز˵�" << endl << endl;

		return;

	}

	help_judge = 5;

	information* temp_head_1 = head->next;

	information* temp_head_2 = head;

	while (temp_head_1 || temp_head_2)

	{

		if ((head->age >= 60 && head->sex == "��") || (head->age >= 55 && head->sex == "Ů"))

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

		else if ((temp_head_1) && ((temp_head_1->age >= 60 && temp_head_1->sex == "��") || (temp_head_1->age >= 55 && temp_head_1->sex == "Ů")))

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

	cout << endl << "�������ְ����Ϣ�ķ��룬���ز˵�" << endl << endl;

}