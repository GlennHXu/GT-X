
// ʹ�õݹ����n�Ľ׳�

#include <iostream>
using namespace std;

// �ٶ�n��ֵ�Ǵ���1��ֵ
// �ݹ���ú��� f()
long f(long n)
{
	if (n == 1)
		return 1;
	else
		return f(n - 1)*n;
	
}
// ���ǰ100�ú�
long sum(int n)
{
	if (1 == n)
		return 1;
	else
		return n + sum(n - 1);

	/* ʹ��ѭ��
	long s = 0;
	int i;

	for (i = 1; i <= 100; ++i)
		s += i;
		return s;
	*/
}

int main(void)
{
	
	cout << f(10) << endl;
	cout << sum(100) << endl;
	
		return 0;
}


