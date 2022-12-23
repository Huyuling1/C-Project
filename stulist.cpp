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
		std::cout << std::endl;
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