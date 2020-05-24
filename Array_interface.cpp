#include<iostream>
#include<malloc.h>// 包含malloc函数
#include<stdlib.h> //包含了exit函数；
using namespace std;


//定义一个结构体，用于存放数组
struct Arr
{
	int * pBase;//存放的是数组的第一个元素的地址
	int len; //存的是数组的长度
	int cnt; //当前有效元素的个数	
};
void init_arr(struct Arr * pArr, int length);//初始化一个数组，length是数组的长度
bool append_arr(struct Arr * pArr, int val ); //数组中追加一个元素
bool insert_arr(struct Arr * pArr, int pos, int val);//数组插入一个元素,pos的值从1开始，pos 是位置，val是要添加的元素
bool delete_arr(struct Arr * pArr, int pos, int * pVal);//删除一个元素,并返回删除的元素，pVal是返回删除元素的值的指针

bool iis_empty( struct Arr * pArr);//判断数组里元素是否为空
bool is_full(struct Arr * pArr); //判断数组里元素是为满

int get();//获取数组中的元素
void sort_arr(struct Arr * pArr);//将数组中元素排序
void show_arr(struct Arr * pArr);//显示出数组元素
void inversion_arr(struct Arr * pArr);//颠倒数组中两个元素位置

int main(void)
{

	struct Arr arr;
	int val;
	init_arr(&arr,6);
	show_arr(&arr);
	append_arr(&arr, 1);
	append_arr(&arr, 10);
	append_arr(&arr, -3);
	append_arr(&arr, 6);
	append_arr(&arr, 88);
	//append_arr(&arr, 77);
	insert_arr(&arr,3, 23);
	// delete_arr(&arr, 1, &val);
	if (delete_arr(&arr, 3, &val))
	{
		cout << "删除成功!" << endl;
		cout << "您删除的元素是:"<< val << endl;
	}
	else
	{
		cout << "删除失败!" << endl;
	}

	/*
	if (append_arr(&arr, 8))
	{
		cout << "追加成功!" << endl;
	}
	else
	{
		cout << "追加失败!" << endl;
	};
	*/

	show_arr(&arr);
	inversion_arr(&arr);
	cout << "倒置之后的数组内容是：" <<endl;
	show_arr(&arr);
	sort_arr(&arr);
	cout << "排序之后的数组内容是：" << endl;
	show_arr(&arr);
		return 0;

}
//1、初始化数组
void init_arr(struct Arr * pArr, int length)
{
	pArr->pBase = (int *) malloc(sizeof(int)*length);
	if (NULL == pArr->pBase)
	{
		cout << "动态内存分配失败" << endl;
		exit(-1);//表示终止整个程序
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
	//(*pArr).len = 99;
}
// 2、判断数组是否为空
bool iis_empty(struct Arr * pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}
//3、判断数组是否为满
bool is_full(struct Arr * pArr)
{
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}
// 4、显示数组中的元素
void show_arr( struct Arr * pArr)
{
	if (iis_empty(pArr))  //判断数组是否为数组为空
		cout << "数组为空!" << endl;
	else
	{
		for (int i = 0; i < pArr->cnt; ++i)
			cout << pArr->pBase[i] << "  " ;  //int*
	}
	cout << endl;
} 
//5、追加一个元素
bool append_arr(struct Arr * pArr, int val)
{
	//满是返回false
	if (is_full(pArr))
		return false;
	//不满时追加
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true;
}
//6、插入一个元素
bool insert_arr(struct Arr * pArr, int pos, int val)
{
	if (is_full(pArr))
		return false;
	if (pos<1 || pos>pArr->cnt+1)  //有限个数的最后一个也是可以插的
		return false;
	int i;
	
	for (i = pArr->cnt - 1; i >= pos-1; --i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];

	}
	pArr->pBase[pos - 1] = val;
	(pArr->cnt)++;
	return true;
}
//7、删除一个元素
bool delete_arr(struct Arr * pArr, int pos, int * pVal)
{
	//不合法的元素
	if (iis_empty(pArr))//判断数组是否为空
		return false;
	if (pos<1 || pos>pArr->cnt)
		return false;
	//合法的元素
	int i;
	*pVal = pArr->pBase[pos-1];
	for (i = pos; i < pArr->cnt; ++i)
	{
		
		pArr->pBase[i-1] = pArr->pBase[i];
		
	}
	(pArr->cnt)--;
	return true;

}
// 8、颠倒整个数组
void inversion_arr(struct Arr * pArr)
{
	int i= 0;
	int j = pArr->cnt - 1;
	int t = 0;
	while (i<j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;

	}
	return;
}
// 9、排序整个数组
void sort_arr(struct Arr * pArr)
{
	int i, j;
	int t = 0;
	
	for (i = 0; i < pArr->cnt; ++i)
	{
		for (j = i + 1; j < pArr->cnt; ++j)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
	return;
}