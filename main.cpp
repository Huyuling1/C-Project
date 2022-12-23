#include<iostream>
#include "stulist.h"

int main(void)
{
	stulist sl;
flag1:
	system("cls");
    std::cout << "    1    录入学生信息" << std::endl;
	std::cout << "    2    删除学生信息" << std::endl;
	std::cout << "    3    修改学生信息" << std::endl;
	std::cout << "    4    查询学生信息" << std::endl;
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
		std::cout << "录入结束,目前的学生信息: " << std::endl;
		sl.id_sort(); //先进行学号排序再打印
		sl.print_list();
		system("pause");
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
			std::cout << "删除结束,目前的学生信息: " << std::endl;
			sl.id_sort(); 
			sl.print_list();
			system("pause");
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
			std::cout << "修改结束,目前的学生信息: " << std::endl;
			sl.id_sort(); 
			sl.print_list();
			system("pause");
			goto flag1;
		}

	case 4:

		flag2:
	    std::cout << std::endl;
		std::cout << "    1    按学号查找学生信息" << std::endl;
		std::cout << "    2    按姓名查找学生信息" << std::endl;
		std::cout << "    3    查看成绩排名" << std::endl;
		std::cout << "    0    退出查询" << std::endl;
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
			std::cout << "输入有误 请重新输入！" << std::endl;
			goto flag3;
		}
	case 0:
		break;
	default:
		std::cout << "输入有误 请重新输入！" << std::endl;
		goto flag1;
	}
	return 0;
}