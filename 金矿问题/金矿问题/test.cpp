//问题：给定一个二维矩阵，每个矩阵元素代表了一个金钱，矿工从第一列开始走，可以向右，右上，右下三种方式前进，求最后矿工得到
//      最多的黄金数
//思路：1.矿工总是从第一列出发一定在最后一列结束
//		2.建立一个与矩阵相同大的表来存储当前所获得的金矿
//		3.向右移动：当矿工处于最后一列时无法接着向右进行移动
//		4.向右上移动：处于最后一列时无法向右 且处于第一行无法向上移动
//		5.向右下移动：同理，处于最后一行或者最后一列无法向右下移动

#include<windows.h>
#include<iostream>
using namespace std;

int GetGold(int arr[][4], int row, int col)
{
	int goldtable[4][4];
	memset(goldtable, 0, sizeof(goldtable));
	for (int j = col - 1; j >= 0; j--)//一定要先填充最后一列的数据
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