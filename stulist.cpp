#include <iostream>
#include <cstring>
#include <iomanip>
#include "stulist.h"

Node<student>* stulist::id_find(const std::string find) //判断学号是否存在，若存在则返回在list里的位置
                                                                         //实则是返回指向该id所在的Node的指针
{
	for (auto i = list.returnFirst(); i != nullptr; i = i->next) 
	{
		if (i->val.id == find) 
			return i;
	}
	return nullptr;
}

Node<student>* stulist::name_find(const std::string find) //判断姓名是否存在，若存在则返回在list里的位置 
{
	for (auto i = list.returnFirst(); i != nullptr; i = i->next) 
	{
		if (i->val.name == find)
			return i;
	}
	return nullptr;
}

void stulist::print_list()  //打印list
{
	if (list.isEmpty())
	{
		std::cout << "暂无学生信息！" << std::endl;
		return;
	}
	else
	{
		std::cout << std::left << std::setw(10) << "学号" << std::setw(10)
			<< "姓名" << std::setw(10) << "成绩" << std::endl;
		for (auto i = list.returnFirst(); i != nullptr; i = i->next)
		{
			std::cout << std::left << std::setw(10) << i->val.id << std::setw(10)
				<< i->val.name << std::setw(10) << i->val.score << std::endl;
		}
		std::cout << std::endl;
		return;
	}
}

void stulist::add()//增加学生信息
{
	std::string id;
	std::cout << "请输入学生学号 ";
	std::cin >> id;
	auto find = id_find(id);
	if (find)  //判断学生是否存在
	{
		std::cout << "该学生已存在! " << "姓名为: " << find->val.name << std::endl;
		return;
	}
	std::string name;
	double score;
	std::cout << "请输入学生姓名 ";
	std::cin >> name;
	std::cout << "请输入学生成绩 ";
	std::cin >> score;
	while (score < 0 || score > 100)
	{
		std::cout << "分数的范围为0-100,输入有误,请重新输入 ";
		std::cin >> score;
	}
	list.insert(student(id, name, score));
	std::cout << "录入成功！" << std::endl;
	std::cout << std::endl;
	len++;
}

void stulist::dele() //删除学生信息 
{
	if (list.isEmpty())
	{
		std::cout << "暂无学生信息！" << std::endl;
		return;
	}
	std::string dele_id;
	std::cout << "请输入要删除的学号: ";
	std::cin >> dele_id;

	auto i = list.returnFirst(); //i = first
	if (i->val.id == dele_id) {
		list.removeFirst();
		std::cout << "删除成功" << std::endl;
		len--;
		return;
	}

	for (; i->next != nullptr && i->next->val.id != dele_id; i = i->next);

	if (i->next) {
		auto temp = i->next;
		i->next = i->next->next;
		delete temp;
		len--;
		std::cout << "删除成功" << std::endl;
	}
	else
		std::cout << "没有此学号的学生！" << std::endl;

	return;
}

void stulist::modify() //修改学生信息
{
	if (list.isEmpty())
	{
		std::cout << "暂无学生信息！" << std::endl;
		return;
	}
	std::cout << "请输入需修改信息的学生学号: "; // 默认学号不需要修改
	std::string modify_id;
	std::cin >> modify_id;

	auto stu = id_find(modify_id);

	if (!stu)
		std::cout << "没有此学号的学生！" << std::endl;
	else {
		std::cout << std::left << std::setw(10) << "学号" << std::setw(10)
			<< "姓名" << std::setw(10) << "成绩" << std::endl;
		std::cout << std::left << std::setw(10) << stu->val.id << std::setw(10)
			<< stu->val.name << std::setw(10) << stu->val.score << std::endl;
		std::cout << std::endl;
		std::cout << "请输入学生新姓名 ";
		std::cin >> stu->val.name;
		std::cout << "请输入学生新成绩 ";
		std::cin >> stu->val.score;
		while (stu->val.score < 0 || stu->val.score > 100)
		{
			std::cout << "分数的范围为0-100,输入有误,请重新输入：";
			std::cin >> stu->val.score;
		}
		std::cout << "修改成功，结果如下： " << std::endl;
		std::cout << std::left << std::setw(10) << "学号" << std::setw(10)
			<< "姓名" << std::setw(10) << "成绩" << std::endl;
		std::cout << std::left << std::setw(10) << stu->val.id << std::setw(10)
			<< stu->val.name << std::setw(10) << stu->val.score << std::endl;
	}
	return;
}

void stulist::id_find_() //按照学号查找信息(若成绩不及格则不显示成绩，并提醒重修）
{
	std::cin.get();
	std::cout << "请输入您的学号:  ";
	std::string find_id;

	std::cin >> find_id;
	Node<student>* i = id_find(find_id);
	while (!i)
	{
		std::cout << "无该学号信息!请重新输入: " << std::endl;
		std::cin >> find_id;
		i = id_find(find_id);
	}

	if (i->val.score < 60)
	{
		std::cout << "您的成绩不及格，请重修！" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		rank();
		std::cout << "您的成绩为: " << i->val.score << "    " << "排名为: " << i->val.rank << std::endl;
		std::cout << std::endl;
	}
	return;
}

void stulist::name_find() //按照姓名查找信息(若成绩不及格则不显示成绩，并提醒重修）
{
	std::cin.get();
	std::cout << "请输入您的姓名: ";
	std::string find_name;

	std::cin >> find_name;
	Node<student>* i = name_find(find_name);
	while (!i)
	{
		std::cout << "无该姓名信息!请重新输入: " << std::endl;
		std::cin >> find_name;
		i = name_find(find_name);
	}

	if (i->val.score < 60)
	{
		std::cout << "您的成绩不及格，请重修！" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		rank();
		std::cout << "您的成绩为: " << i->val.score << "    " << "排名为: " << i->val.rank << std::endl;
		std::cout << std::endl;
	}
}

void stulist::score_sort() //将成绩从高到低排序
{
	if (list.isEmpty())
	{
		std::cout << "暂无学生信息！" << std::endl;
		return;
	}
	student	temp;
	for (auto i = list.returnFirst(); i != nullptr; i = i->next)
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

void stulist::id_sort() //将学号从低到高排序
{
	if (list.isEmpty())
	{
		std::cout << "暂无学生信息！" << std::endl;
		return;
	}
	student	temp;
	for (auto i = list.returnFirst(); i != nullptr; i = i->next)
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

void stulist::score_count() //统计各分数段人数，计算平均分
{
	if (list.isEmpty())
	{
		std::cout << "暂无学生信息！" << std::endl;
		return;
	}

	int count[4] = { 0 };
	double s = 0.0;
	for (auto i = list.returnFirst(); i != nullptr; i = i->next)
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
		<< std::setw(10) << count[2] << std::setw(10) << count[3] << std::setw(10) << "人" << std::endl;

	std::cout << "平均分为： " << s / len << std::endl;

	std::cout << std::endl;
	return;
}

void stulist::rank() //解决学生有相同分数出现排名不同的情况
{
	score_sort();
	int rank = 1;
	auto i = list.returnFirst();
	i->val.rank = rank;
	for (auto j = i->next; i != nullptr && j != nullptr; i = i->next, j = j->next) {
		rank++;
		if (j->val.score == i->val.score) j->val.rank = i->val.rank;
		else j->val.rank = rank;
	}
}