
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


int main(void)
{
	
	cout << f(10) << endl;
		return 0;
}