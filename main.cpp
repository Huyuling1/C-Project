#include<iostream>
#include "stulist.h"
#include <windows.h>

int main(void)
{
	stulist sl;
	flag0:
	std::cout << "��ӭ����ѧ������ϵͳ����ѡ���������: " << std::endl;
	std::cout << "    1    ��ʦ" << std::endl;
	std::cout << "    2    ѧ��" << std::endl;
	std::cout << std::endl;
	int l;
	std::cin >> l;
	switch (l)
	{
	case 1:
		//ѡ���ʦ
	{
	flag1:
		std::cout << "    1    ¼��ѧ����Ϣ" << std::endl;
		std::cout << "    2    ɾ��ѧ����Ϣ" << std::endl;
		std::cout << "    3    �޸�ѧ����Ϣ" << std::endl;
		std::cout << "    4    ���ѧ����Ϣ" << std::endl;
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
			std::cout << "¼�����! " << std::endl;
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
			std::cout << "ɾ������!" << std::endl;
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
			std::cout << "�޸Ľ���! " << std::endl;
			system("pause");
			goto flag1;
		}

		case 4:
		{
			flag2:
			std::cout << std::endl;
			std::cout << "��ѡ�������ʽ��" << std::endl;
			std::cout << "    1    ��ѧ���������" << std::endl;
			std::cout << "    2    ���ɼ��������" << std::endl;
			std::cout << "    3    �鿴��������������ƽ����" << std::endl;
			std::cout << "    0    �˳����" << std::endl;
			std::cout << std::endl;
			int i; std::cin >> i;
			switch (i)
			{
			case 1:
			{
				sl.id_sort(); //�Ƚ���ѧ�������ٴ�ӡ
				sl.print_list();
			}
			case 2:
			{
				sl.score_sort();
				sl.print_list();
			}
			case 3:
			{
				sl.score_count();
			}
			case 0:
				goto flag1;
			default:
				std::cout << "�������� ���������룡" << std::endl;
				goto flag2;
			}
		}

		case 0:
		{
			std::cout << "��лʹ�ã������˳�..." << std::endl;
			Sleep(3000);
			system("cls");
			goto flag0;
		}
			
		default:
			std::cout << "�������� ���������룡" << std::endl;
			goto flag1;
		}
	}

	case 2:
		//ѡ��ѧ��
	{
	flag3:
		std::cout << "    1    ��ѧ�Ų�����Ϣ" << std::endl;
		std::cout << "    2    ������������Ϣ" << std::endl;
		std::cout << "    3    " << std::endl;
		std::cout << "    4    ���ѧ����Ϣ" << std::endl;
		std::cout << "    0    �˳�����ϵͳ" << std::endl;
		std::cout << std::endl;





	}

	

	return 0;
}