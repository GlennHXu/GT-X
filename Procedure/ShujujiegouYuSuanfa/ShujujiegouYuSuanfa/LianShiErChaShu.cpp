// 链式二叉树
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
	struct BTNode * pLchild; // p是指针  L是左  child是孩子
	struct BTNode * pRchild;
};

// 函数声明 
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

// 1.创建一个链表二叉树

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

// 2.先序遍历

void PreTraverseBTree(struct BTNode * pT)
{
	if (NULL != pT)  //必须加if ，为了防止发到pT的地址为空
	{
		cout << char(pT->data) << endl;
		if (NULL != pT->pLchild)  // 为了加快运行速度，先判断是否为空
		{
			PreTraverseBTree(pT->pLchild);          // 可以代表整个左子树；
		}
		if (NULL != pT->pRchild)   // 为了加快运行速度，先判断是否为空
		{
			PreTraverseBTree(pT->pRchild);
		}
	}
	/*
	伪算法
		先访问根节点
		再先序访问左子树
		再先序访问右子树
		*/
}

// 3. 中序遍历

void InTraverseBTree(struct BTNode * pT)
{
	if (NULL != pT)  //必须加if ，为了防止发到pT的地址为空
	{
		
		if (NULL != pT->pLchild)  // 为了加快运行速度，先判断是否为空
		{
			InTraverseBTree(pT->pLchild);          // 可以代表整个左子树；
		}
		cout << char(pT->data) << endl;
		if (NULL != pT->pRchild)   // 为了加快运行速度，先判断是否为空
		{
			InTraverseBTree(pT->pRchild);
		}
	}	
}

// 4. 后序遍历

void PostTraverseBTree(struct BTNode * pT)
{
	if (NULL != pT)  //必须加if ，为了防止发到pT的地址为空
	{

		if (NULL != pT->pLchild)  // 为了加快运行速度，先判断是否为空
		{
			PostTraverseBTree(pT->pLchild);          // 可以代表整个左子树；
		}
		
		if (NULL != pT->pRchild)   // 为了加快运行速度，先判断是否为空
		{
			PostTraverseBTree(pT->pRchild);
		}

		cout << char(pT->data) << endl;
	}
}