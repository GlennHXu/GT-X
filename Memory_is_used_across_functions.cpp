#include<iostream>
#include<malloc.h>
#include<string.h>
using namespace std;

struct student
{
	int sid;
	int age;
};
struct student * CreateStudent(void);
void ShowStudent(struct student *);
int main()
{
	struct student * ps ;
	ps = CreateStudent();
	ShowStudent(ps);

	//system("pasue");
		return 0;
}
struct student * CreateStudent(void)
{
	//����ṹ�����͵��ڴ�ռ�
	//malloc���ط����ڴ�ĵ�һ���ֽڵĵ�ַ����Ҫǿ��ת����ĳһ���͵ĵ�ַ���ȵĵ�һ���ֽڡ�
	// �� int * p = (int *) malloc*(20),ǿ��ת����int�������ĸ��ֽڵĵ�һ���ֽڵĵ�ַ��ֵ��p,
	struct student * p = (struct student *)  malloc(sizeof(struct student));
	p->sid = 333;
	p->age = 11;
	return p;
}
void ShowStudent(struct student * pst)
{
	cout << pst->sid <<"   "<< pst->age << endl;
}