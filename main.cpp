#include<iostream>
#include "stulist.h"

int main(void)
{
	stulist sl;
flag1:
	system("cls");
    std::cout << "    1    ¼��ѧ����Ϣ" << std::endl;
	std::cout << "    2    ɾ��ѧ����Ϣ" << std::endl;
	std::cout << "    3    �޸�ѧ����Ϣ" << std::endl;
	std::cout << "    4    ��ѯѧ����Ϣ" << std::endl;
	std::cout << "    0    �˳�����ϵͳ" << std::endl;
	std::cout << std::endl;
	int k;
	std::cin >> k;
	switch (k)
	{
	case 1:

	{
		sl.add();
		std::cout << "����¼���밴�������¼�����������quit��";
		char s[6];
		std::cin >> s;
		while (strcmp(s, "quit"))
		{
			sl.add();
			std::cout << "����¼���밴�������¼�����������quit��";
			std::cin >> s;
		}
		std::cout << "¼�����,Ŀǰ��ѧ����Ϣ: " << std::endl;
		sl.id_sort(); //�Ƚ���ѧ�������ٴ�ӡ
		sl.print_list();
		system("pause");
		goto flag1;
	}

	case 2:

		{
			sl.dele();
			std::cout << "����ɾ���밴�������ɾ������������quit��";
			char s[6];
			std::cin >> s;
			while (strcmp(s, "quit"))
			{
				sl.dele();
				std::cout << "����ɾ���밴�������ɾ������������quit��";
				std::cin >> s;
			}
			std::cout << "ɾ������,Ŀǰ��ѧ����Ϣ: " << std::endl;
			sl.id_sort(); 
			sl.print_list();
			system("pause");
			goto flag1;
		}

	case 3:

		{
			sl.modify();
			std::cout << "�����޸��밴��������޸Ľ���������quit��";
			char s[6];
			std::cin >> s;
			while (strcmp(s, "quit"))
			{
				sl.modify();
				std::cout << "�����޸��밴��������޸Ľ���������quit��";
				std::cin >> s;
			}
			std::cout << "�޸Ľ���,Ŀǰ��ѧ����Ϣ: " << std::endl;
			sl.id_sort(); 
			sl.print_list();
			system("pause");
			goto flag1;
		}

	case 4:

		flag2:
	    std::cout << std::endl;
		std::cout << "    1    ��ѧ�Ų���ѧ����Ϣ" << std::endl;
		std::cout << "    2    ����������ѧ����Ϣ" << std::endl;
		std::cout << "    3    �鿴�ɼ�����" << std::endl;
		std::cout << "    0    �˳���ѯ" << std::endl;
		std::cout << std::endl;
		flag3:
		int m;
		std::cin >> m;
		switch (m)
		{
		case 1:
			sl.id_find_();
			goto flag2;
		case 2:
			sl.name_find();
			goto flag2;
		case 3:
			sl.score_sort();
			goto flag2;
		case 0:
			goto flag1;
		default:
			std::cout << "�������� ���������룡" << std::endl;
			goto flag3;
		}
	case 0:
		break;
	default:
		std::cout << "�������� ���������룡" << std::endl;
		goto flag1;
	}
	return 0;
}