//stulist.h --结构声明与类定义
#include<iostream>
#define listlen 100

struct student
{
	char id[15];
	char name[20];
	double score;
};

class stulist
{
private:
	student list[listlen] = { 0 };
	int len = -1;  //表示结构数组中最后一个元素的位置
	int ranking[listlen] = { 0 }; //纪录排名（解决学生有相同分数出现排名不同的情况）
public:
	//首先需要几个进行准备工作的函数
	int is_empty(); //判断list是否为空

	int is_full(); //判断list是否为满

	int id_find(const char*);  //判断学号是否存在，若存在则返回在list里的位置

	void print_list();  //打印list
	//以下为行使功能的函数
	void add(); //增加学生信息

	void dele(); //删除学生信息

	void modify(); //修改学生信息

	void id_find_(); //按照学号查找信息(若成绩不及格则不显示成绩，并提醒重修）

	void name_find(); //按照姓名查找信息(若成绩不及格则不显示成绩，并提醒重修）

	void score_sort(); //将成绩从高到低排序  

	void id_sort(); //将学号从低到高排序

	void score_count(); //统计各分数段人数，计算平均分

	void rank(); //解决学生有相同分数出现排名不同的情况
};