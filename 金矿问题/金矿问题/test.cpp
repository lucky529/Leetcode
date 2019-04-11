//���⣺����һ����ά����ÿ������Ԫ�ش�����һ����Ǯ���󹤴ӵ�һ�п�ʼ�ߣ��������ң����ϣ��������ַ�ʽǰ���������󹤵õ�
//      ���Ļƽ���
//˼·��1.�����Ǵӵ�һ�г���һ�������һ�н���
//		2.����һ���������ͬ��ı����洢��ǰ����õĽ��
//		3.�����ƶ������󹤴������һ��ʱ�޷��������ҽ����ƶ�
//		4.�������ƶ����������һ��ʱ�޷����� �Ҵ��ڵ�һ���޷������ƶ�
//		5.�������ƶ���ͬ���������һ�л������һ���޷��������ƶ�

#include<windows.h>
#include<iostream>
using namespace std;

int GetGold(int arr[][4], int row, int col)
{
	int goldtable[4][4];
	memset(goldtable, 0, sizeof(goldtable));
	for (int j = col - 1; j >= 0; j--)//һ��Ҫ��������һ�е�����
	{		
		for (int i = 0; i < row; i++)
		{
			int right = (j == col - 1) ? 0 : goldtable[i][j + 1];
			int right_up = (i == 0 || j == col - 1) ? 0 : goldtable[i - 1][j + 1];
			int right_down = (i == row - 1 || j == col - 1) ? 0 : goldtable[i + 1][j + 1];

			goldtable[i][j] = max(right, max(right_down, right_up)) + arr[i][j];
		}
	}
	int ret = goldtable[0][0];
	for (int i = 0; i < row; i++)
	{
		if (goldtable[i][0] > ret)
			ret = goldtable[i][0];
	}
	return ret;
}
int main()
{
	int arr[4][4] = { 
	{ 1, 2, 3, 4 }, 
	{ 2, 3, 4, 5 }, 
	{ 3, 4, 5, 6 }, 
	{ 4, 5, 3, 7 } };

	printf("%d", GetGold(arr,4,4));
	system("pause");
	return 0;
}