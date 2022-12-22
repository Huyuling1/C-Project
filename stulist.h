//stulist.h --�ṹ�������ඨ��
#include<iostream>
#define listlen 100
using namespace std;

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
	int len = -1;  //��ʾ�ṹ���������һ��Ԫ�ص�λ��
public:
	//������Ҫ��������׼�������ĺ���
	int is_empty(); //�ж�list�Ƿ�Ϊ��

	int is_full(); //�ж�list�Ƿ�Ϊ��

	int id_find(char []);  //�ж�ѧ���Ƿ���ڣ��������򷵻ظ�ѧ������

	void print_list();  //��ӡlist
	//����Ϊ��ʹ���ܵĺ���
	void add(); //����ѧ����Ϣ

	void dele(); //ɾ��ѧ����Ϣ

	void modify(); //�޸�ѧ����Ϣ

	void id_find(); //����ѧ�Ų���ѧ����Ϣ

	void name_find(); //������������ѧ����Ϣ

	void score_sort(); //���ɼ��Ӹߵ�������  

	void id_sort(); //��ѧ�Ŵӵ͵�������

};