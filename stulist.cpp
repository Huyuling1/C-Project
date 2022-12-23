#include<iostream>
#include "stulist.h"


int stulist::is_empty()  //判断list是否为空
{
	if (len == -1)
		return 1;
	else 
		return 0;
}

int stulist::is_full()  //判断list是否为满
{
	if (len + 1 == listlen)
		return 1;
	else
		return 0;
}

int stulist::id_find(const char* s) //判断学号是否存在，若存在则返回在list里的位置 
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

void stulist::print_list()  //打印list
{
	if (is_empty())
	{
		std::cout << "暂无学生信息！" << std::endl;
		return;
	}
	else
	{
		std::cout << "学号		" << "姓名		" << "成绩 		" << std::endl;
		for (int i = 0; i <= len; i++)
		{
			std::cout << list[i].id << "		" << list[i].name << "	    " << list[i].score << std::endl;
		}
		std::cout << std::endl;
		return;
	}
}

void stulist::add()//增加学生信息
{
	if (is_full())
	{
		std::cout << "无法再增添学生信息！" << std::endl;
		return;
	}
	std::cout << "请输入学生学号 " ;
	std::cin >> list[len + 1].id;
	int i = id_find(list[len + 1].id);
	if (i >= 0)
	{
		std::cout << "该学生已存在! " << "姓名为: "  << list[i].name << std::endl; 
		return;
	}
	std::cout << "请输入学生姓名 " << std::endl;
	std::cin.getline(list[len + 1].name,20);
	std::cout << "请输入学生成绩 ";
	std::cin >> list[len + 1].score;
	while(list[len + 1].score < 0 || list[len + 1].score > 100)
	{
		std::cout << "输入有误,请重新输入 " ;
		std::cin >> list[len + 1].score;
	}
	len++;
}

void stulist::dele() //删除学生信息 
{
	if (is_empty())
	{
		std::cout << "无法再增添学生信息! " << std::endl;
		return;
	}
	char dele_id[15] = { 0 };
	int i;
	std::cout << "请输入要删除的学号: ";
	std::cin >> dele_id;
	for (i = 0; i <= len; i++)
	{
		if (strcmp(list[i].id, dele_id) == 0)
		{
			if (i == len)
			{
				len--;
				std::cout << "删除成功" << std::endl;
				return;
			}
			else
			{
				for (i; i <= len; i++)
				{
					list[i] = list[i + 1]; //结构可以直接赋值
				}
				len--;
				std::cout << "删除成功" << std::endl;
				return;
			}
		}
	}
	if (i == len + 1)
		std::cout << "没有此学号的学生！" << std::endl;
	return;
}

void stulist::modify() //修改学生信息
{
	if (is_empty())
	{
		std::cout << "暂无学生信息！" << std::endl;
		return;
	}
	std::cout << "请输入需修改信息的学生学号: "; // 默认学号不需要修改
	char modify_id[15] = { 0 };
	std::cin >> modify_id;
	int i;
	for (int i = 0; i <= len; i++)
	{
		if (strcmp(list[i].id, modify_id) == 0)
		{
			std::cout << "学号		" << "姓名		" << "成绩	 	" << std::endl;
			std::cout << list[i].id << "		" << list[i].name << "	    " << list[i].score << std::endl;
			std::cout << std::endl;
			std::cout << "请输入学生新姓名 " ;
			std::cin.getline(list[i].name,20);
	        std::cout << "请输入学生新成绩 " ;
			std::cin >> list[i].score;
			while(list[i].score < 0 || list[i].score > 100)
			{
				std::cout << "输入有误,请重新输入：";
				std::cin >> list[i].score;
			}
			std::cout << "修改成功，结果如下： " << std::endl;
			std::cout << "学号		" << "姓名		" << "成绩	 	" << std::endl;
			std::cout << list[i].id << "		" << list[i].name << "	    " << list[i].score << std::endl;
			return;
		}
	}
	if (i == len + 1)
		std::cout << "没有此学号的学生！" << std::endl;
	return;
}

void stulist::id_find_() //按照学号查找学生信息
{
	std::cout << "请输入要查询的学生学号:  ";
	char find_id[15] = { 0 };
	std::cin >> find_id;
	int i = id_find(find_id);
	if (i < 0)
		std::cout << "无该学生信息! " << std::endl;
	else
	{
		std::cout << "学号		" << "姓名		" << "成绩	 	" << std::endl;
		std::cout << list[i].id << "		" << list[i].name << "	    " << list[i].score << std::endl;
		std::cout << std::endl;
	}
	return;
}

void stulist::name_find() //按照姓名查找学生信息
{
	std::cout << "请输入要查询的学生姓名: ";
	char find_name[20] = { 0 };
	std::cin.getline(find_name,20);
	int i;
	for (i = 0; i <= len; i++)
	{
		if (strcmp(find_name, list[i].name) == 0)
		{
			std::cout << "学号		" << "姓名		" << "成绩	 	" << std::endl;
			std::cout << list[i].id << "		" << list[i].name << "	    " << list[i].score << std::endl;
			std::cout << std::endl;
			return;
		}
	}
	if (i == len + 1)
		std::cout << "无该学生信息! " << std::endl;
	return;
}

void stulist::score_sort() //将成绩从高到低排序
{
	if (is_empty())
	{
		std::cout << "暂无学生信息！" << std::endl;
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

void stulist::id_sort() //将学号从低到高排序
{
	if (is_empty())
	{
		std::cout << "暂无学生信息！" << std::endl;
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