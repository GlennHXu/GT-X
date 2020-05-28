//#define _CRT_SECUTE_NO_WARNINGS  // 规避strcpy()函数不安全问题
//#define WIN32_LEAN_AND_MEAN 
//#include<iostream>
//#include<string>
//using namespace std;
//
//struct student  // 定义结构体
//{
//	int num;
//	char name[200];
//	int age;
//};
//
//// 声明函数
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
//	// 结构体指针的使用形式
//	(*pst).num = 23;
//	strcpy((*pst).name, "dkjfal");
//	pst->age = 33;
//}
//void g(struct student * pst)
//{
//	cout << pst->num << " " << pst->name << " " << pst->age << endl;
//}