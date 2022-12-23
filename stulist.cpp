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

void stulist::modify() //�޸�ѧ����Ϣ
{
	if (is_empty())
	{
		std::cout << "����ѧ����Ϣ��" << std::endl;
		return;
	}
	std::cout << "���������޸���Ϣ��ѧ��ѧ��: "; // Ĭ��ѧ�Ų���Ҫ�޸�
	char modify_id[15] = { 0 };
	std::cin >> modify_id;
	int i;
	for (int i = 0; i <= len; i++)
	{
		if (strcmp(list[i].id, modify_id) == 0)
		{
			std::cout << "ѧ��		" << "����		" << "�ɼ�	 	" << std::endl;
			std::cout << list[i].id << "		" << list[i].name << "	    " << list[i].score << std::endl;
			std::cout << std::endl;
			std::cout << "������ѧ�������� " ;
			std::cin.getline(list[i].name,20);
	        std::cout << "������ѧ���³ɼ� " ;
			std::cin >> list[i].score;
			while(list[i].score < 0 || list[i].score > 100)
			{
				std::cout << "��������,���������룺";
				std::cin >> list[i].score;
			}
			std::cout << "�޸ĳɹ���������£� " << std::endl;
			std::cout << "ѧ��		" << "����		" << "�ɼ�	 	" << std::endl;
			std::cout << list[i].id << "		" << list[i].name << "	    " << list[i].score << std::endl;
			return;
		}
	}
	if (i == len + 1)
		std::cout << "û�д�ѧ�ŵ�ѧ����" << std::endl;
	return;
}

void stulist::id_find_() //����ѧ�Ų���ѧ����Ϣ
{
	std::cout << "������Ҫ��ѯ��ѧ��ѧ��:  ";
	char find_id[15] = { 0 };
	std::cin >> find_id;
	int i = id_find(find_id);
	if (i < 0)
		std::cout << "�޸�ѧ����Ϣ! " << std::endl;
	else
	{
		std::cout << "ѧ��		" << "����		" << "�ɼ�	 	" << std::endl;
		std::cout << list[i].id << "		" << list[i].name << "	    " << list[i].score << std::endl;
		std::cout << std::endl;
	}
	return;
}

void stulist::name_find() //������������ѧ����Ϣ
{
	std::cout << "������Ҫ��ѯ��ѧ������: ";
	char find_name[20] = { 0 };
	std::cin.getline(find_name,20);
	int i;
	for (i = 0; i <= len; i++)
	{
		if (strcmp(find_name, list[i].name) == 0)
		{
			std::cout << "ѧ��		" << "����		" << "�ɼ�	 	" << std::endl;
			std::cout << list[i].id << "		" << list[i].name << "	    " << list[i].score << std::endl;
			std::cout << std::endl;
			return;
		}
	}
	if (i == len + 1)
		std::cout << "�޸�ѧ����Ϣ! " << std::endl;
	return;
}

void stulist::score_sort() //���ɼ��Ӹߵ�������
{
	if (is_empty())
	{
		std::cout << "����ѧ����Ϣ��" << std::endl;
		return;
	}
	student	temp;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i; j++)
		{
			if (list[j].score < list[j + 1].score)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

void stulist::id_sort() //��ѧ�Ŵӵ͵�������
{
	if (is_empty())
	{
		std::cout << "����ѧ����Ϣ��" << std::endl;
		return;
	}
	student	temp;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i; j++)
		{
			if (strcmp(list[j].id, list[j + 1].id) > 0)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}