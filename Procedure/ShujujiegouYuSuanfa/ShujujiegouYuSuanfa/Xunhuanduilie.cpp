// ʵ��ѭ������

#include<iostream>
#include<malloc.h>

using namespace std;
// ����һ���ṹ�壬�����ŷ���������׵�ַ�����
typedef struct Qqueue
{
	int * pBase;
	int front;
	int rear;
}QUEUE;

void init(QUEUE *);  // ��ʼ������
bool en_queue(QUEUE *, int val); // �����и�ֵ
void traverse_queue(QUEUE *); // ����ѭ������
bool full_queue(QUEUE *);   // �ж϶����Ƿ�Ϊ��
bool out_queue(QUEUE*, int *); // ����
bool emput_queue(QUEUE *);  // �ж϶����Ƿ�Ϊ��

// ������
int main(void)
{
	QUEUE Q; // ����ṹ�� Q
	int val;

	init(&Q);
	/*en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);
	en_queue(&Q, 7);*/

	traverse_queue(&Q);
	if (out_queue(&Q, &val))
	{
		cout << "���Գɹ������г���Ԫ��Ϊ��" << val << endl;
	}
	else 
	{
		cout << "����ʧ�ܣ�";
	}

	traverse_queue(&Q);
	return 0;

}

// 1�� ��ʼ�����У����������ڴ�
void init(QUEUE * pQ)
{
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;

}

// 2���ж϶����Ƿ�Ϊ��
bool full_queue(QUEUE *pQ)
{
	if ((pQ->rear + 1) % 6 == pQ->front)
		return true;
	else
		return false;
}

// 3�����
bool en_queue(QUEUE * pQ, int val)
{
	if (full_queue(pQ))
	{
		return true;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return false;
	}
}

// 4������
void traverse_queue(QUEUE *pQ)
{
	int i = pQ->front;
	while (i != pQ->rear)
	{
		cout << pQ->pBase[i] << endl;
		i = (i + 1) % 6;
	}
	cout << endl;
	return;
}

// 5���ж϶����Ƿ�Ϊ��
bool emput_queue(QUEUE * pQ)
{
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}
 
// 6������
bool out_queue(QUEUE *pQ, int * pVal)
{
	if (emput_queue(pQ))
	{
		return false;
 }
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6; 
		return true;
	}
}