#include<iostream>
#include "stulist.h"
#include <windows.h>
#include<string>

int main(void)
{
	stulist sl;
	std::string code;
flag0:
	std::cout << "��ӭ����ѧ������ϵͳ����ѡ���������: " << std::endl;
	std::cout << "    1    ��ʦ" << std::endl;
	std::cout << "    2    ѧ��" << std::endl;
	std::cout << std::endl;
	char l;
	std::cin >> l;
	switch (l)
	{
	case '1':
		//ѡ���ʦ
	{
		 if(code.empty())
		{
			std::cin.get();
			std::cout << "����������: ";
			getline(std::cin, code);
			std::cout << "�밴�س�����...";
		}
		 std::cin.get();
		 std::cout << "�������������룺";
		 std::string code1;
		 getline(std::cin, code1);
		 int i = 1;
		 while (code1 != code && i < 3)
		 {
			 std::cout << "����������������룺";
			 i++;
			 getline(std::cin, code1);
		 }
		 if (i == 3) {
			 system("cls");
			 goto flag0;
		 }
	flag1:
		system("cls");
		std::cout << "    1    ¼��ѧ����Ϣ" << std::endl;
		std::cout << "    2    ɾ��ѧ����Ϣ" << std::endl;
		std::cout << "    3    �޸�ѧ����Ϣ" << std::endl;
		std::cout << "    4    ���ѧ����Ϣ" << std::endl;
		std::cout << "    0    �˳�����ϵͳ" << std::endl;
		std::cout << std::endl;
		char k;
		std::cin >> k;
		switch (k)
		{
		case '1':

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
			Sleep(2000);
			goto flag1;
		}

		case '2':

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
			Sleep(2000);
			goto flag1;
		}

		case '3':

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
			Sleep(2000);
			goto flag1;
		}

		case '4':
		{
		flag2:
			system("cls");
			std::cout << "��ѡ�������ʽ��" << std::endl;
			std::cout << "    1    ��ѧ���������" << std::endl;
			std::cout << "    2    ���ɼ��������" << std::endl;
			std::cout << "    3    �鿴��������������ƽ����" << std::endl;
			std::cout << "    0    �˳����" << std::endl;
			std::cout << std::endl;
			char i; std::cin >> i;
			switch (i)
			{
			case '1':
			{
				sl.id_sort(); //�Ƚ���ѧ�������ٴ�ӡ
				sl.print_list();
				std::cout << "����Ҫ���������";
				system("pause");
				goto flag2;
			}
			case '2':
			{
				sl.score_sort();
				sl.print_list();
				std::cout << "����Ҫ���������";
				system("pause");
				goto flag2;
			}
			case '3':
			{
				sl.score_count();
				std::cout << "����Ҫ���������";
				system("pause");
				goto flag2;
			}
			case '0':
				goto flag1;
			default:
				std::cout << "�������� ���������룡" << std::endl;
				std::cin.get();
				Sleep(1000);
				system("cls");
				goto flag2;
			}
		}

		case '0':
		{
			std::cout << "��лʹ�ã������˳�..." << std::endl;
			Sleep(3000);
			system("cls");
			goto flag0;
		}

		default:
			std::cout << "�������� ���������룡" << std::endl;
			std::cin.get();
			Sleep(1000);
			system("cls");
			goto flag1;
		}
	}

	case '2':
		//ѡ��ѧ��
	{
	flag3:
		system("cls");
		std::cout << "    1    ��ѧ�Ų�����Ϣ" << std::endl;
		std::cout << "    2    ������������Ϣ" << std::endl;
		std::cout << "    3    �鿴��������������ƽ����" << std::endl;
		std::cout << "    0    �˳�����ϵͳ" << std::endl;
		std::cout << std::endl;
		std::cout << "��ѡ��";
		char i; std::cin >> i;
		switch (i)
		{
		case '1':
			sl.id_find_();
			system("pause");
			goto flag3;
		case '2':
			sl.name_find();
			system("pause");
			goto flag3;
		case '3':
			sl.score_count();
			system("pause");
			goto flag3;
		case '0':
			std::cout << "��лʹ�ã������˳�..." << std::endl;
			Sleep(3000);
			system("cls");
			goto flag0;
		default:
			std::cout << "�������� ���������룡" << std::endl;
			std::cin.get();
			Sleep(1000);
			system("cls");
			goto flag3;
		}
	}

	default:
		std::cout << "�������� ���������룡" << std::endl;
		std::cin.get();
		Sleep(1000);
		system("cls");
		goto flag0;
	}
	return 0;
}