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
void traverse_list(PNODE pHead); // 将链表的值都输出
bool iis_empty(PNODE pHead);  //判断连败哦是否为空
int length_list(PNODE pHead);  //输出链表的长度
bool insert_list(PNODE, int, int);  //链表中插入一个数
bool delete_list(PNODE, int, int *);   //删除链表中的一个数
void sort_list(PNODE);  //链表的排序


// 主函数
int main(void)
{
	PNODE pHead = NULL;  //等价于struct Node * pHead = NULL;
	pHead = create_list(); //create_list()的功能：创建一个非循环单链表，并将该链表的头节点的地址赋给pHead;
	traverse_list(pHead); // 遍历整个链表；
	//
	if (iis_empty(pHead))
		cout << "链表为空";
	else
		cout << "链表不空！";
	//
	 int len = length_list(pHead);
	 cout << "链表长度为：" << len << endl;
    //
	 sort_list(pHead);
	 traverse_list(pHead);
	//
	insert_list(pHead, 4, 33);
	//
	int val;
	if (delete_list(pHead, 3, &val))
	{
		cout << "删除成功，您删除的元素是" << val << endl;
	}
	else
	{
		cout << "删除失败，您删除的元素不存在！" << endl;
	}
	traverse_list(pHead);
     return 0;
};

// 1、创建链表
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
	cout << endl;
	return;
}

// 3、判断一个链表是否为空
bool iis_empty(PNODE pHead)
{
	if (pHead->pNext == NULL)
	    return true;
	else
		return false;
		
	
}

// 4、计算链表的长度
int length_list(PNODE pHead)
{
	int len=0;
	PNODE p =pHead->pNext;
	while (p != NULL)
	{
		++len;
		p = p->pNext;
	}
	return len;
}

// 5、给链表从小到大排序
void sort_list(PNODE pHead)
{
	int  i, j, t;
	int len = length_list(pHead);
	PNODE p, q;
	for (i = 0, p = pHead->pNext; i < len - 1; ++i, p = p->pNext)
	{
		for (j = i + 1, q = p->pNext; j < len; ++j, q = q->pNext)
		{
			if (p->data > q->data)  // 类似于数组中的：a[i] > a[j]
			{
				t = p->data;  //类似于数组中的：t = a[i]
				p->data = q->data; //类似于数组中的：a[i] = a[j]
				q->data = t; //类似于数组中的：a[j] = t;
			}
		}
	}
	return;
}

// 6、链表的第pos个节点的前面插入一个新的节点，该节点的值为val， 并且pos的值是从1开始

bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL != p && i < pos - 1) // 找到要插入的节点的前一个节点位置
	{
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p) //要插入位置的前一个节点指针不为空
		return false;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			cout << "内存分配失败！" << endl;
			exit(-1);
		}
	pNew->data = val; //赋值
	PNODE q = p->pNext; //定义新指针，存放p中的指针
	p->pNext = pNew;  //
	pNew->pNext = q;
	return true;
}

// 7、删除链表中的一个数
bool delete_list(PNODE pHead, int pos, int * pVal)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL != p->pNext && i < pos - 1) // 找到要删除的节点的前一个节点位置...此处的不可写成 (NULL != p && i < pos-1) 
	{
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p->pNext) //要删除位置存放指针不为能空
		return false;
	

	PNODE q = p->pNext; //定义新指针，存放p中的指针
	*pVal = q->data;
	p->pNext = p->pNext->pNext; //将删除节点存放的指针给前一个节点
	free(q);  // 释放q中的指针内存
	q = NULL;  
	return true;
}