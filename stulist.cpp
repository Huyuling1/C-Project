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

