// 实现循环队列

#include<iostream>
#include<malloc.h>

using namespace std;
// 定义一个结构体，里面存放分配数组的首地址，序号
typedef struct Qqueue
{
	int * pBase;
	int front;
	int rear;
}QUEUE;

void init(QUEUE *);  // 初始化队列
bool en_queue(QUEUE *, int val); // 给队列赋值
void traverse_queue(QUEUE *); // 遍历循环队列
bool full_queue(QUEUE *);   // 判断队列是否为满
bool out_queue(QUEUE*, int *); // 出队
bool emput_queue(QUEUE *);  // 判断队列是否为空

// 主函数
int main(void)
{
	QUEUE Q; // 定义结构体 Q
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
		cout << "出对成功，队列出队元素为：" << val << endl;
	}
	else 
	{
		cout << "出队失败！";
	}

	traverse_queue(&Q);
	return 0;

}

// 1、 初始化队列，分配数组内存
void init(QUEUE * pQ)
{
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;

}

// 2、判断队列是否为满
bool full_queue(QUEUE *pQ)
{
	if ((pQ->rear + 1) % 6 == pQ->front)
		return true;
	else
		return false;
}

// 3、入队
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

// 4、遍历
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

// 5、判断队列是否为空
bool emput_queue(QUEUE * pQ)
{
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}
 
// 6、出队
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