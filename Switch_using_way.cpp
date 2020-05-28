// 2020-05-19  给电影打分，返回评价

#include<iostream>
using namespace std;

int main()
{
	// 1、请用户给电影打分
	cout << "请给电影打分：" << endl;

	// 2、输入电影的分数
	int score = 0;
	cin >> score;

	// 3、输出电影的评价
	switch (score)
	{
	case 10:
		cout << "此电影非常经典" << endl;
		break;
	case 9:
		cout << "此电影是经典" << endl;
	case 8:
		cout << "此电影较为经典" << endl;
		break;
	case 7:
		cout << "此电影非常好" << endl;
		break;
	case 6:
		cout << "此电影一般" << endl;
		break;
	default:
		cout << "此电影烂片" << endl;
	}
	system("pause");
	return 0;
}

//注意1：switch语句中表达式类型只能是整型或者字符型

//注意2：case里如果没有break，那么程序会一直向下执行

//总结：与if语句比，对于多条件判断时，switch的结构清晰，执行效率高，缺点是switch不可以判断区间

