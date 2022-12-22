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

