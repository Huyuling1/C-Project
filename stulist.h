//stulist.h --�ṹ�������ඨ��
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
		id = ""; name = ""; score = 0.0;
	} //���캯��
	student(std::string id, std::string name, double score)
	{
		id = id; name = name; score = score;
	} //���캯������
};

class stulist
{
private:
	List<student> list;
	int len = 0;  //��ʾ�б�ĳ���
public:

	void print_list();  //��ӡlist

	void add(); //����ѧ����Ϣ

	void dele(); //ɾ��ѧ����Ϣ

	void modify(); //�޸�ѧ����Ϣ

	Node<student>* id_find(const std::string);  //�ж�ѧ���Ƿ���ڣ��������򷵻���list���λ��

	Node<student>* name_find(const std::string);  //�ж������Ƿ���ڣ��������򷵻���list���λ��

	void id_find_(); //����ѧ�Ų�����Ϣ(���ɼ�����������ʾ�ɼ������������ޣ�

	void name_find(); //��������������Ϣ(���ɼ�����������ʾ�ɼ������������ޣ�

	void score_sort(); //���ɼ��Ӹߵ�������  

	void id_sort(); //��ѧ�Ŵӵ͵�������

	void score_count(); //ͳ�Ƹ�����������������ƽ����

	void rank(); //���ѧ������ͬ��������������ͬ�����
};