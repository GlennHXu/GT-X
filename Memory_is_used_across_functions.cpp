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
	//分配结构体类型的内存空间
	//malloc返回分配内存的第一个字节的地址，需要强制转换成某一类型的地址长度的第一个字节。
	// 如 int * p = (int *) malloc*(20),强制转换成int类型中四个字节的第一个字节的地址赋值给p,
	struct student * p = (struct student *)  malloc(sizeof(struct student));
	p->sid = 333;
	p->age = 11;
	return p;
}
void ShowStudent(struct student * pst)
{
	cout << pst->sid <<"   "<< pst->age << endl;
}