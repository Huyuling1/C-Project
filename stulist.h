//stulist.h --结构声明与类定义
#include <iostream>
#include <string>
#include "list.h"

struct student
{
	std::string id;
	std::string name;
	int rank = 0;
	double score;

	student()
	{
		id = "";name = "";score = 0.0; 
	}
	student(std::string id1, std::string name1, double score1)
	{
		id = id1;name = name1;score = score1;
	}
};

class stulist
{
private:
	List<student> list;
	int len = 0;  //表示列表的长度
public:

	void print_list();  //打印list

	void add(); //增加学生信息

	void dele(); //删除学生信息

	void modify(); //修改学生信息

	Node<student>* id_find(const std::string);  //判断学号是否存在，若存在则返回在list里的位置

	Node<student>* name_find(const std::string);  //判断姓名是否存在，若存在则返回在list里的位置

	void id_find_(); //按照学号查找信息(若成绩不及格则不显示成绩，并提醒重修）

	void name_find(); //按照姓名查找信息(若成绩不及格则不显示成绩，并提醒重修）

	void score_sort(); //将成绩从高到低排序  

	void id_sort(); //将学号从低到高排序

	void score_count(); //统计各分数段人数，计算平均分

	void rank(); //解决学生有相同分数出现排名不同的情况
};