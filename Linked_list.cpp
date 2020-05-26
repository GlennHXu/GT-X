#include<iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;

typedef struct Node
{
	int data;  // ������
	struct Node * pNext;  //ָ����

}NODE,*PNODE;  //NODE�ȼ���struct Node, PNODE�ȼ���struct Node *

// ��������
PNODE create_list(void);
void traverse_list(PNODE pHead);

int main(void)
{
	PNODE pHead = NULL;  //�ȼ���struct Node * pHead = NULL;
	pHead = create_list(); //create_list()�Ĺ��ܣ�����һ����ѭ�������������������ͷ�ڵ�ĵ�ַ����pHead;
	traverse_list(pHead); // ������������


}

//1����������
PNODE create_list(void) 
{
	int len;//���������Ч�ڵ�ĸ���
	int i;
	int val; //������ʱ����û�����Ľڵ��ֵ

	//������һ����������ݵ�ͷ�ڵ�
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
	{
		cout << "����ʧ�ܣ�������ֹ" << endl;
		exit(-1);
	}
	//����һ��β�ڵ㣬����գ���������ŵ�
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	cout << "��������Ҫ������ڵ�ĸ���:len =" ;
	cin >> len;

	for (i = 0; i < len; ++i)
	{
		cout << "����������Ҫ�ĵ�" << i + 1 << "���ڵ��ֵ:" << endl;
		cin >> val;
		PNODE pNew = (PNODE)malloc(sizeof(NODE));

		if (  NULL == pNew)
		{
			cout << "����ʧ�ܣ�������ֹ" << endl;
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;

	}
	return pHead;
	

}

// 2�� ���������������������
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;//���������ָ���λ�ã�
	while (p != NULL)
	{
		cout << p->data << "  ";
		p = p->pNext;
	}
	return;
}