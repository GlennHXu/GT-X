//  2020年5月19号  比较三个数得大小，并输出

#include<iostream>
using namespace std;

int main()
{
	// 判断三只小猪哪个最重

	// 1、创建三只小猪的体重变量
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	// 2、让用户输入三只小猪的重量
	cout << "请输入小猪A的体重" << endl;
	//cin >> num1;
	cout << "请输入小猪B的体重" << endl;
	cin >> num2;
	cout << "请输入小猪C的体重" << endl;
	cin >> num3;
	cout << "小猪A的体重为：" << num1 << endl;
	cout << "小猪B的体重为：" << num2 << endl;
	cout << "小猪C的体重为：" << num3 << endl;
	cout << "\t" <<  endl;
	//3、 判断哪知小猪最重
	// 先判断A和B重量
	if (num1 > num2)   // A比B重
	{
		if (num1 > num3) //A比C重
		   cout << "小猪A的质量最重：" << num1 << endl;
		else
			cout << "小猪C的质量最重：" << num3 << endl;
		
	}
	else  //B比A重
	{
		if (num2 > num3) //B比C重
			cout << "小猪B的质量最重：" << num2 << endl;
		else
			cout << "小猪C的质量最重：" << num3 << endl;
		
	}

	system("pause");
	return 0;
}