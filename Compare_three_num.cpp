//  2020��5��19��  �Ƚ��������ô�С�������

#include<iostream>
using namespace std;

int main()
{
	// �ж���ֻС���ĸ�����

	// 1��������ֻС������ر���
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	// 2�����û�������ֻС�������
	cout << "������С��A������" << endl;
	//cin >> num1;
	cout << "������С��B������" << endl;
	cin >> num2;
	cout << "������С��C������" << endl;
	cin >> num3;
	cout << "С��A������Ϊ��" << num1 << endl;
	cout << "С��B������Ϊ��" << num2 << endl;
	cout << "С��C������Ϊ��" << num3 << endl;
	cout << "\t" <<  endl;
	//3�� �ж���֪С������
	// ���ж�A��B����
	if (num1 > num2)   // A��B��
	{
		if (num1 > num3) //A��C��
		   cout << "С��A���������أ�" << num1 << endl;
		else
			cout << "С��C���������أ�" << num3 << endl;
		
	}
	else  //B��A��
	{
		if (num2 > num3) //B��C��
			cout << "С��B���������أ�" << num2 << endl;
		else
			cout << "С��C���������أ�" << num3 << endl;
		
	}

	system("pause");
	return 0;
}