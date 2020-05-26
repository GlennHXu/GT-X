#include<iostream>
#include<malloc.h>// ����malloc����
#include<stdlib.h> //������exit������
using namespace std;


//����һ���ṹ�壬���ڴ������
struct Arr
{
	int * pBase;//��ŵ�������ĵ�һ��Ԫ�صĵ�ַ
	int len; //���������ĳ���
	int cnt; //��ǰ��ЧԪ�صĸ���	
};
void init_arr(struct Arr * pArr, int length);//��ʼ��һ�����飬length������ĳ���
bool append_arr(struct Arr * pArr, int val ); //������׷��һ��Ԫ��
bool insert_arr(struct Arr * pArr, int pos, int val);//�������һ��Ԫ��,pos��ֵ��1��ʼ��pos ��λ�ã�val��Ҫ��ӵ�Ԫ��
bool delete_arr(struct Arr * pArr, int pos, int * pVal);//ɾ��һ��Ԫ��,������ɾ����Ԫ�أ�pVal�Ƿ���ɾ��Ԫ�ص�ֵ��ָ��

bool iis_empty( struct Arr * pArr);//�ж�������Ԫ���Ƿ�Ϊ��
bool is_full(struct Arr * pArr); //�ж�������Ԫ����Ϊ��

int get(struct Arr * pArr, int pos, int * pVal);//��ȡ�����е�Ԫ��
void sort_arr(struct Arr * pArr);//��������Ԫ������
void show_arr(struct Arr * pArr);//��ʾ������Ԫ��
void inversion_arr(struct Arr * pArr);//�ߵ�����������Ԫ��λ��

int main(void)
{

	struct Arr arr;
	int val;// ���ɾ���˵�Ԫ��
	int tal;//��Ż�ȡ����Ԫ��
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
		cout << "ɾ���ɹ�!" << endl;
		cout << "��ɾ����Ԫ����:"<< val << endl;
	}
	else
	{
		cout << "ɾ��ʧ��!" << endl;
	}

	/*
	if (append_arr(&arr, 8))
	{
		cout << "׷�ӳɹ�!" << endl;
	}
	else
	{
		cout << "׷��ʧ��!" << endl;
	};
	*/

	show_arr(&arr);
	inversion_arr(&arr);
	cout << "����֮������������ǣ�" <<endl;
	show_arr(&arr);
	sort_arr(&arr);
	cout << "����֮������������ǣ�" << endl;
	show_arr(&arr);
	get(&arr, 6, &tal);
	cout << "�����ȡ������Ԫ���ǣ�" << tal << endl;
	
		return 0;

}
//1����ʼ������
void init_arr(struct Arr * pArr, int length)
{
	pArr->pBase = (int *) malloc(sizeof(int)*length);
	if (NULL == pArr->pBase)
	{
		cout << "��̬�ڴ����ʧ��" << endl;
		exit(-1);//��ʾ��ֹ��������
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
	//(*pArr).len = 99;
}
// 2���ж������Ƿ�Ϊ��
bool iis_empty(struct Arr * pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}
//3���ж������Ƿ�Ϊ��
bool is_full(struct Arr * pArr)
{
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}
// 4����ʾ�����е�Ԫ��
void show_arr( struct Arr * pArr)
{
	if (iis_empty(pArr))  //�ж������Ƿ�Ϊ����Ϊ��
		cout << "����Ϊ��!" << endl;
	else
	{
		for (int i = 0; i < pArr->cnt; ++i)
			cout << pArr->pBase[i] << "  " ;  //int*
	}
	cout << endl;
} 
//5��׷��һ��Ԫ��
bool append_arr(struct Arr * pArr, int val)
{
	//���Ƿ���false
	if (is_full(pArr))
		return false;
	//����ʱ׷��
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true;
}
//6������һ��Ԫ��
bool insert_arr(struct Arr * pArr, int pos, int val)
{
	if (is_full(pArr))
		return false;
	if (pos<1 || pos>pArr->cnt+1)  //���޸��������һ��Ҳ�ǿ��Բ��
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
//7��ɾ��һ��Ԫ��
bool delete_arr(struct Arr * pArr, int pos, int * pVal)
{
	//���Ϸ���Ԫ��
	if (iis_empty(pArr))//�ж������Ƿ�Ϊ��
		return false;
	if (pos<1 || pos>pArr->cnt)
		return false;
	//�Ϸ���Ԫ��
	int i;
	*pVal = pArr->pBase[pos-1];
	for (i = pos; i < pArr->cnt; ++i)
	{
		
		pArr->pBase[i-1] = pArr->pBase[i];
		
	}
	(pArr->cnt)--;
	return true;

}
// 8���ߵ���������
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
// 9��������������
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
// 10����ȡԪ��
int get(struct Arr * pArr, int pos, int * pVal)
{
	if (iis_empty(pArr))//�ж������Ƿ�Ϊ��
		return false;
	if (pos<1 || pos>pArr->cnt)
		return false;
	*pVal = pArr->pBase[pos - 1];
	return 0;
}