
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


int main(void)
{
	
	cout << f(10) << endl;
		return 0;
}