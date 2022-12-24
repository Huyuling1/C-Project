#include<iostream>
#include<cstring>
#include<iomanip>
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
		std::cout << std::left << std::setw(10) << "ѧ��" << std::setw(10) 
			<< "����" << std::setw(10) << "�ɼ�" << std::endl;
		for (int i = 0; i <= len; i++)
		{
			std::cout << std::left << std::setw(10) << list[i].id << std::setw(10) 
				<< list[i].name << std::setw(10) << list[i].score << std::endl;
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
	std::cin.get();
	int i = id_find(list[len + 1].id);
	if (i >= 0)
	{
		std::cout << "��ѧ���Ѵ���! " << "����Ϊ: "  << list[i].name << std::endl; 
		return;
	}
	std::cout << "������ѧ������ ";
	std::cin.getline(list[len + 1].name,20);
	std::cout << "������ѧ���ɼ� ";
	std::cin >> list[len + 1].score;
	while(list[len + 1].score < 0 || list[len + 1].score > 100)
	{
		std::cout << "��������,���������� " ;
		std::cin >> list[len + 1].score;
	}
	std::cout << "¼��ɹ���" << std::endl;
	std::cout << std::endl;
	len++;
}

void stulist::dele() //ɾ��ѧ����Ϣ 
{
	if (is_empty())
	{
		std::cout << "����ѧ����Ϣ��" << std::endl;
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
	std::cin.get();
	int i;
	for (i = 0; i <= len; i++)
	{
		if (strcmp(list[i].id, modify_id) == 0)
		{
			std::cout << std::left << std::setw(10) << "ѧ��" << std::setw(10)
				<< "����" << std::setw(10) << "�ɼ�" << std::endl;
			std::cout << std::left << std::setw(10) << list[i].id << std::setw(10)
				<< list[i].name << std::setw(10) << list[i].score << std::endl;
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
			std::cout << std::left << std::setw(10) << "ѧ��" << std::setw(10)
				<< "����" << std::setw(10) << "�ɼ�" << std::endl;
			std::cout << std::left << std::setw(10) << list[i].id << std::setw(10)
				<< list[i].name << std::setw(10) << list[i].score << std::endl;
			return;
		}
	}
	if (i == len + 1)
		std::cout << "û�д�ѧ�ŵ�ѧ����" << std::endl;
	return;
}

void stulist::id_find_() //����ѧ�Ų�����Ϣ(���ɼ�����������ʾ�ɼ������������ޣ�
{
	score_sort();
	std::cout << "����������ѧ��:  ";
	char find_id[15] = { 0 };
	std::cin >> find_id;
	int i = id_find(find_id);
	while (i < 0)
	{
		std::cout << "�޸�ѧ����Ϣ!����������: " << std::endl;
		std::cin >> find_id;
		int i = id_find(find_id);
	}
	if (list[i].score < 60)
	{
		std::cout << "���ĳɼ������������ޣ�" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		rank();
		std::cout << "���ĳɼ�Ϊ: " << list[i].score <<  "    "  << "����Ϊ: " << ranking[i] << std::endl;
		std::cout << std::endl;
	}
	return;
}

void stulist::name_find() //��������������Ϣ(���ɼ�����������ʾ�ɼ������������ޣ�
{
	score_sort();
	flag:
	std::cout << "������Ҫ��ѯ��ѧ������: ";
	char find_name[20] = { 0 };
	std::cin.getline(find_name,20);
	int i;
	for (i = 0; i <= len; i++)
	{
		if (strcmp(find_name, list[i].name) == 0)
		{
			if (list[i].score < 60)
			{
				std::cout << "���ĳɼ������������ޣ�" << std::endl;
				std::cout << std::endl;
			}
			else
			{
				rank();
				std::cout << "���ĳɼ�Ϊ: " << list[i].score << "    " << "����Ϊ: " << ranking[i] << std::endl;
				std::cout << std::endl;
			}
			return;
		}
	}
	if (i == len + 1)
		std::cout << "�޸�������Ϣ!����������: " << std::endl;
	goto flag;
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

void stulist::score_count() //ͳ�Ƹ�����������������ƽ����
{
	int count[4] = {0};
	for (int i = 0; i <= len; i++)
	{
		if (list[i].score >= 90)
			count[0]++;
		else if (list[i].score >= 70 && list[i].score < 90)
			count[1]++;
		else if (list[i].score >= 60 && list[i].score < 70)
			count[2]++;
		else
			count[3]++;
	}
	std::cout << std::endl;
	std::cout << std::left << std::setw(10) << "> 90" << std::setw(10) << "70-90"
		<< std::setw(10) << "60-70" << std::setw(10) << "< 60" << std::endl;
	std::cout << std::left << std::setw(10) << count[0] << std::setw(10) << count[1]
		<< std::setw(10) << count[2] << std::setw(10) << count[3] << std::setw(10) << "��" << std::endl;
	if(len == 0)
		std::cout << "ƽ����Ϊ�� " << list[0].score << std::endl;
	else
	{
		double s = 0;
		for (int i = 0; i <= len; i++)
			s = s + list[i].score;
		std::cout << "ƽ����Ϊ�� " << s / (len + 1) << std::endl;
	}
	std::cout << std::endl;
	return;
}

void stulist::rank() //���ѧ������ͬ��������������ͬ�����
{
	for (int i = 0; i <= len; i++)
		ranking[i] = i + 1;
	for (int i = 1; i <= len; i++)
	{
		if (list[i].score == list[i - 1].score)
			ranking[i] = ranking[i - 1];
	}
}