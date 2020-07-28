// ��ʽ������
/*
       A
	B      C
	     D   
		   E
*/

#include <iostream>
#include <malloc.h>
using namespace std;

struct BTNode
{
	int data;
	struct BTNode * pLchild; // p��ָ��  L����  child�Ǻ���
	struct BTNode * pRchild;
};

// �������� 
struct BTNode * CreateBTree(void);
void PreTraverseBTree(struct BTNode * pT);
void InTraverseBTree(struct BTNode * pT);
void PostTraverseBTree(struct BTNode * pT);

int  main(void)
{
	struct BTNode * pT = CreateBTree();

	PreTraverseBTree(pT);
	cout << endl;

    InTraverseBTree(pT);
	cout << endl;

 	PostTraverseBTree(pT);

	return 0;
}

// 1.����һ�����������

struct BTNode * CreateBTree(void)
{
	struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));
	// struct BTNode * pF = (struct BTNode *)malloc(sizeof(struct BTNode));

	pA ->data = 'A';
	pB ->data = 'B';
	pC ->data = 'C';
	pD ->data = 'D';
	pE ->data = 'E';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;

	return pA;
}

// 2.�������

void PreTraverseBTree(struct BTNode * pT)
{
	if (NULL != pT)  //�����if ��Ϊ�˷�ֹ����pT�ĵ�ַΪ��
	{
		cout << char(pT->data) << endl;
		if (NULL != pT->pLchild)  // Ϊ�˼ӿ������ٶȣ����ж��Ƿ�Ϊ��
		{
			PreTraverseBTree(pT->pLchild);          // ���Դ���������������
		}
		if (NULL != pT->pRchild)   // Ϊ�˼ӿ������ٶȣ����ж��Ƿ�Ϊ��
		{
			PreTraverseBTree(pT->pRchild);
		}
	}
	/*
	α�㷨
		�ȷ��ʸ��ڵ�
		���������������
		���������������
		*/
}

// 3. �������

void InTraverseBTree(struct BTNode * pT)
{
	if (NULL != pT)  //�����if ��Ϊ�˷�ֹ����pT�ĵ�ַΪ��
	{
		
		if (NULL != pT->pLchild)  // Ϊ�˼ӿ������ٶȣ����ж��Ƿ�Ϊ��
		{
			InTraverseBTree(pT->pLchild);          // ���Դ���������������
		}
		cout << char(pT->data) << endl;
		if (NULL != pT->pRchild)   // Ϊ�˼ӿ������ٶȣ����ж��Ƿ�Ϊ��
		{
			InTraverseBTree(pT->pRchild);
		}
	}	
}

// 4. �������

void PostTraverseBTree(struct BTNode * pT)
{
	if (NULL != pT)  //�����if ��Ϊ�˷�ֹ����pT�ĵ�ַΪ��
	{

		if (NULL != pT->pLchild)  // Ϊ�˼ӿ������ٶȣ����ж��Ƿ�Ϊ��
		{
			PostTraverseBTree(pT->pLchild);          // ���Դ���������������
		}
		
		if (NULL != pT->pRchild)   // Ϊ�˼ӿ������ٶȣ����ж��Ƿ�Ϊ��
		{
			PostTraverseBTree(pT->pRchild);
		}

		cout << char(pT->data) << endl;
	}
}