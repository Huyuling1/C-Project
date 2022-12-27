#include <iostream>
#include <cstring>
#include <iomanip>
#include "stulist.h"

Node<student>* stulist::id_find(const std::string find) //�ж�ѧ���Ƿ���ڣ��������򷵻���list���λ�� 
{
	for (auto i = list.returnFront(); i != nullptr; i = i->next) {
		if (i->val.id == find) return i;
	}
	return nullptr;
}

Node<student>* stulist::name_find(const std::string find) //�ж������Ƿ���ڣ��������򷵻���list���λ�� 
{
	for (auto i = list.returnFront(); i != nullptr; i = i->next) {
		if (i->val.name == find) return i;
	}
	return nullptr;
}

void stulist::print_list()  //��ӡlist
{
	if (list.isEmpty())
	{
		std::cout << "����ѧ����Ϣ��" << std::endl;
		return;
	}
	else
	{
		std::cout << std::left << std::setw(10) << "ѧ��" << std::setw(10)
			<< "����" << std::setw(10) << "�ɼ�" << std::endl;
		for (auto i = list.returnFront(); i != nullptr; i = i->next)
		{
			std::cout << std::left << std::setw(10) << i->val.id << std::setw(10)
				<< i->val.name << std::setw(10) << i->val.score << std::endl;
		}
		std::cout << std::endl;
		return;
	}
}

void stulist::add()//����ѧ����Ϣ
{
	std::string id;
	std::cout << "������ѧ��ѧ�� ";
	std::cin >> id;
	auto find = id_find(id);
	if (find)  //�ж�ѧ���Ƿ����
	{
		std::cout << "��ѧ���Ѵ���! " << "����Ϊ: " << find->val.name << std::endl;
		return;
	}
	std::string name;
	double score;
	std::cout << "������ѧ������ ";
	std::cin >> name;
	std::cout << "������ѧ���ɼ� ";
	std::cin >> score;
	while (score < 0 || score > 100)
	{
		std::cout << "�����ķ�ΧΪ0-100,��������,���������� ";
		std::cin >> score;
	}
	list.insert(student(id, name, score));
	std::cout << "¼��ɹ���" << std::endl;
	std::cout << std::endl;
	len++;
}

void stulist::dele() //ɾ��ѧ����Ϣ 
{
	if (list.isEmpty())
	{
		std::cout << "����ѧ����Ϣ��" << std::endl;
		return;
	}
	std::string dele_id;
	std::cout << "������Ҫɾ����ѧ��: ";
	std::cin >> dele_id;

	auto i = list.returnFront();
	if (i->val.id == dele_id) {
		list.removeFront();
		std::cout << "ɾ���ɹ�" << std::endl;
		len--;
		return;
	}

	for (; i->next != nullptr && i->next->val.id != dele_id; i = i->next);

	if (i->next) {
		auto temp = i->next;
		i->next = i->next->next;
		delete temp;
		len--;
		std::cout << "ɾ���ɹ�" << std::endl;
	}
	else
		std::cout << "û�д�ѧ�ŵ�ѧ����" << std::endl;

	return;
}

void stulist::modify() //�޸�ѧ����Ϣ
{
	if (list.isEmpty())
	{
		std::cout << "����ѧ����Ϣ��" << std::endl;
		return;
	}
	std::cout << "���������޸���Ϣ��ѧ��ѧ��: "; // Ĭ��ѧ�Ų���Ҫ�޸�
	std::string modify_id;
	std::cin >> modify_id;

	auto stu = id_find(modify_id);

	if (!stu)
		std::cout << "û�д�ѧ�ŵ�ѧ����" << std::endl;
	else {
		std::cout << std::left << std::setw(10) << "ѧ��" << std::setw(10)
			<< "����" << std::setw(10) << "�ɼ�" << std::endl;
		std::cout << std::left << std::setw(10) << stu->val.id << std::setw(10)
			<< stu->val.name << std::setw(10) << stu->val.score << std::endl;
		std::cout << std::endl;
		std::cout << "������ѧ�������� ";
		std::cin >> stu->val.name;
		std::cout << "������ѧ���³ɼ� ";
		std::cin >> stu->val.score;
		while (stu->val.score < 0 || stu->val.score > 100)
		{
			std::cout << "�����ķ�ΧΪ0-100,��������,���������룺";
			std::cin >> stu->val.score;
		}
		std::cout << "�޸ĳɹ���������£� " << std::endl;
		std::cout << std::left << std::setw(10) << "ѧ��" << std::setw(10)
			<< "����" << std::setw(10) << "�ɼ�" << std::endl;
		std::cout << std::left << std::setw(10) << stu->val.id << std::setw(10)
			<< stu->val.name << std::setw(10) << stu->val.score << std::endl;
	}
	return;
}

void stulist::id_find_() //����ѧ�Ų�����Ϣ(���ɼ�����������ʾ�ɼ������������ޣ�
{
	std::cin.get();
	std::cout << "����������ѧ��:  ";
	std::string find_id;

	std::cin >> find_id;
	Node<student>* i = id_find(find_id);
	while (!i)
	{
		std::cout << "�޸�ѧ����Ϣ!����������: " << std::endl;
		std::cin >> find_id;
		i = id_find(find_id);
	}

	if (i->val.score < 60)
	{
		std::cout << "���ĳɼ������������ޣ�" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		rank();
		std::cout << "���ĳɼ�Ϊ: " << i->val.score << "    " << "����Ϊ: " << i->val.rank << std::endl;
		std::cout << std::endl;
	}
	return;
}

void stulist::name_find() //��������������Ϣ(���ɼ�����������ʾ�ɼ������������ޣ�
{
	std::cin.get();
	std::cout << "��������������: ";
	std::string find_name;

	std::cin >> find_name;
	Node<student>* i = name_find(find_name);
	while (!i)
	{
		std::cout << "�޸�������Ϣ!����������: " << std::endl;
		std::cin >> find_name;
		i = name_find(find_name);
	}

	if (i->val.score < 60)
	{
		std::cout << "���ĳɼ������������ޣ�" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		rank();
		std::cout << "���ĳɼ�Ϊ: " << i->val.score << "    " << "����Ϊ: " << i->val.rank << std::endl;
		std::cout << std::endl;
	}
}

void stulist::score_sort() //���ɼ��Ӹߵ�������
{
	if (list.isEmpty())
	{
		std::cout << "����ѧ����Ϣ��" << std::endl;
		return;
	}
	student	temp;
	for (auto i = list.returnFront(); i != nullptr; i = i->next)
	{
		for (auto j = i->next; j != nullptr; j = j->next)
		{
			if (i->val.score < j->val.score)
			{
				temp = i->val;
				i->val = j->val;
				j->val = temp;
			}
		}
	}
}

void stulist::id_sort() //��ѧ�Ŵӵ͵�������
{
	if (list.isEmpty())
	{
		std::cout << "����ѧ����Ϣ��" << std::endl;
		return;
	}
	student	temp;
	for (auto i = list.returnFront(); i != nullptr; i = i->next)
	{
		for (auto j = i->next; j != nullptr; j = j->next)
		{
			if (i->val.id > j->val.id)
			{
				temp = i->val;
				i->val = j->val;
				j->val = temp;
			}
		}
	}
}

void stulist::score_count() //ͳ�Ƹ�����������������ƽ����
{
	if (list.isEmpty())
	{
		std::cout << "����ѧ����Ϣ��" << std::endl;
		return;
	}

	int count[4] = { 0 };
	double s = 0.0;
	for (auto i = list.returnFront(); i != nullptr; i = i->next)
	{
		s += i->val.score;
		if (i->val.score >= 90)
			count[0]++;
		else if (i->val.score >= 70 && i->val.score < 90)
			count[1]++;
		else if (i->val.score >= 60 && i->val.score < 70)
			count[2]++;
		else
			count[3]++;
	}
	std::cout << std::endl;
	std::cout << std::left << std::setw(10) << "> 90" << std::setw(10) << "70-90"
		<< std::setw(10) << "60-70" << std::setw(10) << "< 60" << std::endl;
	std::cout << std::left << std::setw(10) << count[0] << std::setw(10) << count[1]
		<< std::setw(10) << count[2] << std::setw(10) << count[3] << std::setw(10) << "��" << std::endl;

	std::cout << "ƽ����Ϊ�� " << s / len << std::endl;

	std::cout << std::endl;
	return;
}

void stulist::rank() //���ѧ������ͬ��������������ͬ�����
{
	score_sort();
	int rank = 1;
	auto i = list.returnFront();
	i->val.rank = rank;
	for (auto j = i->next; i != nullptr && j != nullptr; i = i->next, j = j->next) {
		rank++;
		if (j->val.score == i->val.score) j->val.rank = i->val.rank;
		else j->val.rank = rank;
	}
}