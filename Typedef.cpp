//#include<iostream>
//
//using namespace std;
//
//typedef struct student
//{
//	int sid;
//	char name[200];
//	char sex;
//
//
//}* PSTU, STU;  //等价于PSTU代表了struct student * ，STU代表了struct student;
//int main(void)
//{
//	STU st;  //等价于struct stdent st;
//	PSTU ps = &st;  //等价于struct stdent * ps =*st:
//	ps->sid = 99;
//	cout << ps->sid << endl;
//	return 0;
//
//}