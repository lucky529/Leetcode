#include<iostream>
#include<windows.h>
#include<algorithm>
using namespace std;

//��̬�滮��ʱ�临�Ӷ�Ϊn2�ռ临�Ӷ�Ϊn ��ת��Ϊ̰���㷨����o1��ʱ��ռ��㷨
int main()
{
	int length = 10;
	if (length < 2)
	{
		cout << 0 << endl;
		system("pause");
		return 0;
	}
	if (length == 2)
	{
		cout << 1 << endl;
		system("pause");
		return 0;
	}
	if (length == 3)
	{
		cout << 2 << endl;
		system("pause");
		return 0;
	}
	int* p = new int[length + 1];
	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	p[3] = 3;
	int max = 0;
	for (int i = 4; i <= length; i++)
	{
		for (int j = 1; j <= i / 2; j++)
		{
			int tmp = p[j] * p[i - j];
			if (tmp > max)
				max = tmp;
			p[i] = max;
		}
	}
	cout << p[length] << endl;	
	system("pause");
	return 0;
}