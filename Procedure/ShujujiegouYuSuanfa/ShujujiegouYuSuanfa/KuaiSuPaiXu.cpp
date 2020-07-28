// 快速排序


#include<iostream>
#include<malloc.h>
using namespace std;


void QuickSort(int * a, int low, int high);
int FindPos(int * a, int low, int high);


int main(void)
{
	int a[6] = { 7, 8, 2, 4, 5, 0 };
	int i;

	QuickSort(a, 0, 5); //  第一个参数是数组的首地址，第二个参数表示第一个元素的下标  第三个参数表示最后一个下标
	for (i = 0; i < 6; ++i)
	{
		cout << a[i] << ' ';
	}
	return 0;
}

//   

void QuickSort(int * a, int low, int high)
{


	if (low < high)
	{
		int pos;
		pos = FindPos(a, low, high);
		QuickSort(a, low, pos - 1);
		QuickSort(a, pos + 1, high);
	}
	
}

// 找出a从 low 到 high 中所在的位置

int FindPos(int * a, int low, int high)
{
	int val = a[low];

	while (low < high)
	{
		while (low < high && a[high] >= val)
			--high;
		a[low] = a[high];
		while (low < high && a[low] <= val)
			++low;
		a[high] = a[low];
	}

	a[low] = val;

	return low; // high 可以改为high, 但不能改为val 也不能改为a[low], 也不能改为a[high];
}