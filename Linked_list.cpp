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
void traverse_list(PNODE pHead); // �������ֵ�����
bool iis_empty(PNODE pHead);  //�ж�����Ŷ�Ƿ�Ϊ��
int length_list(PNODE pHead);  //�������ĳ���
bool insert_list(PNODE, int, int);  //�����в���һ����
bool delete_list(PNODE, int, int *);   //ɾ�������е�һ����
void sort_list(PNODE);  //���������


// ������
int main(void)
{
	PNODE pHead = NULL;  //�ȼ���struct Node * pHead = NULL;
	pHead = create_list(); //create_list()�Ĺ��ܣ�����һ����ѭ�������������������ͷ�ڵ�ĵ�ַ����pHead;
	traverse_list(pHead); // ������������
	//
	if (iis_empty(pHead))
		cout << "����Ϊ��";
	else
		cout << "�����գ�";
	//
	 int len = length_list(pHead);
	 cout << "������Ϊ��" << len << endl;
    //
	 sort_list(pHead);
	 traverse_list(pHead);
	//
	insert_list(pHead, 4, 33);
	//
	int val;
	if (delete_list(pHead, 3, &val))
	{
		cout << "ɾ���ɹ�����ɾ����Ԫ����" << val << endl;
	}
	else
	{
		cout << "ɾ��ʧ�ܣ���ɾ����Ԫ�ز����ڣ�" << endl;
	}
	traverse_list(pHead);
     return 0;
};

// 1����������
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
	cout << endl;
	return;
}

// 3���ж�һ�������Ƿ�Ϊ��
bool iis_empty(PNODE pHead)
{
	if (pHead->pNext == NULL)
	    return true;
	else
		return false;
		
	
}

// 4����������ĳ���
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

// 5���������С��������
void sort_list(PNODE pHead)
{
	int  i, j, t;
	int len = length_list(pHead);
	PNODE p, q;
	for (i = 0, p = pHead->pNext; i < len - 1; ++i, p = p->pNext)
	{
		for (j = i + 1, q = p->pNext; j < len; ++j, q = q->pNext)
		{
			if (p->data > q->data)  // �����������еģ�a[i] > a[j]
			{
				t = p->data;  //�����������еģ�t = a[i]
				p->data = q->data; //�����������еģ�a[i] = a[j]
				q->data = t; //�����������еģ�a[j] = t;
			}
		}
	}
	return;
}

// 6������ĵ�pos���ڵ��ǰ�����һ���µĽڵ㣬�ýڵ��ֵΪval�� ����pos��ֵ�Ǵ�1��ʼ

bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL != p && i < pos - 1) // �ҵ�Ҫ����Ľڵ��ǰһ���ڵ�λ��
	{
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p) //Ҫ����λ�õ�ǰһ���ڵ�ָ�벻Ϊ��
		return false;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			cout << "�ڴ����ʧ�ܣ�" << endl;
			exit(-1);
		}
	pNew->data = val; //��ֵ
	PNODE q = p->pNext; //������ָ�룬���p�е�ָ��
	p->pNext = pNew;  //
	pNew->pNext = q;
	return true;
}

// 7��ɾ�������е�һ����
bool delete_list(PNODE pHead, int pos, int * pVal)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL != p->pNext && i < pos - 1) // �ҵ�Ҫɾ���Ľڵ��ǰһ���ڵ�λ��...�˴��Ĳ���д�� (NULL != p && i < pos-1) 
	{
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p->pNext) //Ҫɾ��λ�ô��ָ�벻Ϊ�ܿ�
		return false;
	

	PNODE q = p->pNext; //������ָ�룬���p�е�ָ��
	*pVal = q->data;
	p->pNext = p->pNext->pNext; //��ɾ���ڵ��ŵ�ָ���ǰһ���ڵ�
	free(q);  // �ͷ�q�е�ָ���ڴ�
	q = NULL;  
	return true;
}