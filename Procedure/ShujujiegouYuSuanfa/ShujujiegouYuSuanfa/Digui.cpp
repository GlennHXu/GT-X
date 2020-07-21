
// 使用递归求解n的阶乘

#include <iostream>
using namespace std;

// 假定n的值是大于1的值
// 递归调用函数 f()
long f(long n)
{
	if (n == 1)
		return 1;
	else
		return f(n - 1)*n;
	
}
// 求解前100得和
long sum(int n)
{
	if (1 == n)
		return 1;
	else
		return n + sum(n - 1);

	/* 使用循环
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


