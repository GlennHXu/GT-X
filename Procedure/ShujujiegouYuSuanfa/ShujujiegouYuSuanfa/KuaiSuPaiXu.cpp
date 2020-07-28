// ��������


#include<iostream>
#include<malloc.h>
using namespace std;


void QuickSort(int * a, int low, int high);
int FindPos(int * a, int low, int high);


int main(void)
{
	int a[6] = { 7, 8, 2, 4, 5, 0 };
	int i;

	QuickSort(a, 0, 5); //  ��һ��������������׵�ַ���ڶ���������ʾ��һ��Ԫ�ص��±�  ������������ʾ���һ���±�
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

// �ҳ�a�� low �� high �����ڵ�λ��

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

	return low; // high ���Ը�Ϊhigh, �����ܸ�Ϊval Ҳ���ܸ�Ϊa[low], Ҳ���ܸ�Ϊa[high];
}