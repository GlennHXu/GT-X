// 2020-05-19  ����Ӱ��֣���������

#include<iostream>
using namespace std;

int main()
{
	// 1�����û�����Ӱ���
	cout << "�����Ӱ��֣�" << endl;

	// 2�������Ӱ�ķ���
	int score = 0;
	cin >> score;

	// 3�������Ӱ������
	switch (score)
	{
	case 10:
		cout << "�˵�Ӱ�ǳ�����" << endl;
		break;
	case 9:
		cout << "�˵�Ӱ�Ǿ���" << endl;
	case 8:
		cout << "�˵�Ӱ��Ϊ����" << endl;
		break;
	case 7:
		cout << "�˵�Ӱ�ǳ���" << endl;
		break;
	case 6:
		cout << "�˵�Ӱһ��" << endl;
		break;
	default:
		cout << "�˵�Ӱ��Ƭ" << endl;
	}
	system("pause");
	return 0;
}

//ע��1��switch����б��ʽ����ֻ�������ͻ����ַ���

//ע��2��case�����û��break����ô�����һֱ����ִ��

//�ܽ᣺��if���ȣ����ڶ������ж�ʱ��switch�Ľṹ������ִ��Ч�ʸߣ�ȱ����switch�������ж�����

