#include<iostream>
#include "stulist.h"


int stulist::is_empty()  //�ж�list�Ƿ�Ϊ��
{
	if (len == -1)
		return 1;
	else 
		return 0;
}

int stulist::is_full()  //�ж�list�Ƿ�Ϊ��
{
	if (len + 1 == listlen)
		return 1;
	else
		return 0;
}

int stulist::id_find(const char* s) //�ж�ѧ���Ƿ���ڣ��������򷵻���list���λ�� 
{
	int i;
	for (i = 0; i <= len; i++)
	{
		if (strcmp(s, list[i].id) == 0)
			return i;
	}
	if (i == len + 1)
		return -1;
}

void stulist::print_list()  //��ӡlist
{
	if (is_empty())
	{
		std::cout << "����ѧ����Ϣ��" << std::endl;
		return;
	}
	else
	{
		std::cout << "ѧ��		" << "����		" << "�ɼ� 		" << std::endl;
		std::cout << std::endl;
		for (int i = 0; i <= len; i++)
		{
			std::cout << list[i].id << "		" << list[i].name << "	    " << list[i].score << std::endl;
		}
		std::cout << std::endl;
		return;
	}
}

void stulist::add()//����ѧ����Ϣ
{
	if (is_full())
	{
		std::cout << "�޷�������ѧ����Ϣ��" << std::endl;
		return;
	}
	std::cout << "������ѧ��ѧ�� " ;
	std::cin >> list[len + 1].id;
	int i = id_find(list[len + 1].id);
	if (i >= 0)
	{
		std::cout << "��ѧ���Ѵ���! " << "����Ϊ: "  << list[i].name << std::endl; 
		return;
	}
	std::cout << "������ѧ������ " << std::endl;
	std::cin.getline(list[len + 1].name,20);
	std::cout << "������ѧ���ɼ� ";
	std::cin >> list[len + 1].score;
	while(list[len + 1].score < 0 || list[len + 1].score > 100)
	{
		std::cout << "��������,���������� " ;
		std::cin >> list[len + 1].score;
	}
	len++;
}

void stulist::dele() //ɾ��ѧ����Ϣ 
{
	if (is_empty())
	{
		std::cout << "�޷�������ѧ����Ϣ! " << std::endl;
		return;
	}
	char dele_id[15] = { 0 };
	int i;
	std::cout << "������Ҫɾ����ѧ��: ";
	std::cin >> dele_id;
	for (i = 0; i <= len; i++)
	{
		if (strcmp(list[i].id, dele_id) == 0)
		{
			if (i == len)
			{
				len--;
				std::cout << "ɾ���ɹ�" << std::endl;
				return;
			}
			else
			{
				for (i; i <= len; i++)
				{
					list[i] = list[i + 1]; //�ṹ����ֱ�Ӹ�ֵ
				}
				len--;
				std::cout << "ɾ���ɹ�" << std::endl;
				return;
			}
		}
	}
	if (i == len + 1)
		std::cout << "û�д�ѧ�ŵ�ѧ����" << std::endl;
	return;
}