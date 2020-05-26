#include<iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;

typedef struct Node
{
	int data;  // 数据域
	struct Node * pNext;  //指针域

}NODE,*PNODE;  //NODE等价于struct Node, PNODE等价于struct Node *

// 函数声明
PNODE create_list(void);
void traverse_list(PNODE pHead);

int main(void)
{
	PNODE pHead = NULL;  //等价于struct Node * pHead = NULL;
	pHead = create_list(); //create_list()的功能：创建一个非循环单链表，并将该链表的头节点的地址赋给pHead;
	traverse_list(pHead); // 遍历整个链表；


}

//1、创建链表
PNODE create_list(void) 
{
	int len;//用来存放有效节点的个数
	int i;
	int val; //用来临时存放用户输入的节点的值

	//分配了一个不存放数据的头节点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
	{
		cout << "分配失败！程序终止" << endl;
		exit(-1);
	}
	//创建一个尾节点，并清空；第三方存放点
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	cout << "请输入想要的链表节点的个数:len =" ;
	cin >> len;

	for (i = 0; i < len; ++i)
	{
		cout << "请输入你需要的第" << i + 1 << "个节点的值:" << endl;
		cin >> val;
		PNODE pNew = (PNODE)malloc(sizeof(NODE));

		if (  NULL == pNew)
		{
			cout << "分配失败！程序终止" << endl;
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;

	}
	return pHead;
	

}

// 2、 遍历链表，即输出整个链表
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;//第三方存放指针的位置，
	while (p != NULL)
	{
		cout << p->data << "  ";
		p = p->pNext;
	}
	return;
}