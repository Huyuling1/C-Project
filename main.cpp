#include<iostream>
#include "stulist.h"
#include <windows.h>

int main(void)
{
	stulist sl;
flag0:
	std::cout << "欢迎来到学生管理系统，请选择您的身份: " << std::endl;
	std::cout << "    1    教师" << std::endl;
	std::cout << "    2    学生" << std::endl;
	std::cout << std::endl;
	int l;
	std::cin >> l;
	switch (l)
	{
	case 1:
		//选择教师
	{
	flag1:
		system("cls");
		std::cout << "    1    录入学生信息" << std::endl;
		std::cout << "    2    删除学生信息" << std::endl;
		std::cout << "    3    修改学生信息" << std::endl;
		std::cout << "    4    浏览学生信息" << std::endl;
		std::cout << "    0    退出管理系统" << std::endl;
		std::cout << std::endl;
		int k;
		std::cin >> k;
		switch (k)
		{
		case 1:

		{
			sl.add();
			std::cout << "继续录入请按任意键，录入结束请输入quit：";
			char s[6];
			std::cin >> s;
			while (strcmp(s, "quit"))
			{
				sl.add();
				std::cout << "继续录入请按任意键，录入结束请输入quit：";
				std::cin >> s;
			}
			std::cout << "录入结束! " << std::endl;
			Sleep(2000);
			goto flag1;
		}

		case 2:

		{
			sl.dele();
			std::cout << "继续删除请按任意键，删除结束请输入quit：";
			char s[6];
			std::cin >> s;
			while (strcmp(s, "quit"))
			{
				sl.dele();
				std::cout << "继续删除请按任意键，删除结束请输入quit：";
				std::cin >> s;
			}
			std::cout << "删除结束!" << std::endl;
			Sleep(2000);
			goto flag1;
		}

		case 3:

		{
			sl.modify();
			std::cout << "继续修改请按任意键，修改结束请输入quit：";
			char s[6];
			std::cin >> s;
			while (strcmp(s, "quit"))
			{
				sl.modify();
				std::cout << "继续修改请按任意键，修改结束请输入quit：";
				std::cin >> s;
			}
			std::cout << "修改结束! " << std::endl;
			Sleep(2000);
			goto flag1;
		}

		case 4:
		{
		flag2:
			system("cls");
			std::cout << "请选择浏览方式：" << std::endl;
			std::cout << "    1    按学号升序浏览" << std::endl;
			std::cout << "    2    按成绩降序浏览" << std::endl;
			std::cout << "    3    查看各分数段人数及平均分" << std::endl;
			std::cout << "    0    退出浏览" << std::endl;
			std::cout << std::endl;
			int i; std::cin >> i;
			switch (i)
			{
			case 1:
			{
				sl.id_sort(); //先进行学号排序再打印
				sl.print_list();
				std::cout << "若想要继续浏览，";
				system("pause");
				goto flag2;
			}
			case 2:
			{
				sl.score_sort();
				sl.print_list();
				std::cout << "若想要继续浏览，";
				system("pause");
				goto flag2;
			}
			case 3:
			{
				sl.score_count();
				std::cout << "若想要继续浏览，";
				system("pause");
				goto flag2;
			}
			case 0:
				goto flag1;
			default:
				std::cout << "输入有误 请重新输入！" << std::endl;
				goto flag2;
			}
		}

		case 0:
		{
			std::cout << "感谢使用！正在退出..." << std::endl;
			Sleep(3000);
			system("cls");
			goto flag0;
		}

		default:
			std::cout << "输入有误 请重新输入！" << std::endl;
			goto flag1;
		}
	}

	case 2:
		//选择学生
	{
	flag3:
		system("cls");
		std::cout << "    1    按学号查找信息" << std::endl;
		std::cout << "    2    按姓名查找信息" << std::endl;
		std::cout << "    3    查看各分数段人数及平均分" << std::endl;
		std::cout << "    0    退出管理系统" << std::endl;
		std::cout << std::endl;
		std::cout << "请选择：";
		int i; std::cin >> i;
		switch (i)
		{
		case 1:
			sl.id_find_();
			system("pause");
			goto flag3;
		case 2:
			sl.name_find();
			system("pause");
			goto flag3;
		case 3:
			sl.score_count();
			system("pause");
			goto flag3;
		case 0:
			std::cout << "感谢使用！正在退出..." << std::endl;
			Sleep(3000);
			system("cls");
			goto flag0;
		default:
			std::cout << "输入有误 请重新输入！" << std::endl;
			goto flag3;
		}
	}

	default:
		std::cout << "输入有误 请重新输入！" << std::endl;
		goto flag0;
	}
	return 0;
}