//#define _CRT_SECUTE_NO_WARNINGS  // ���strcpy()��������ȫ����
//#define WIN32_LEAN_AND_MEAN 
//#include<iostream>
//#include<string>
//using namespace std;
//
//struct student  // ����ṹ��
//{
//	int num;
//	char name[200];
//	int age;
//};
//
//// ��������
//void f(struct student * pst);
//void g(struct student * pst);
//
//int main()
//{
//	struct student st = { 100,"ldkjf",2334 };
//	f(&st);
//	g(&st);
//
//	system("pause");
//	return 0;
//}
//
//void f(struct student * pst)
//{
//	// �ṹ��ָ���ʹ����ʽ
//	(*pst).num = 23;
//	strcpy((*pst).name, "dkjfal");
//	pst->age = 33;
//}
//void g(struct student * pst)
//{
//	cout << pst->num << " " << pst->name << " " << pst->age << endl;
//}