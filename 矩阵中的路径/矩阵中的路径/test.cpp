#include<iostream>
#include<windows.h>
using namespace std;

bool CheckPath(char arr[][4],int rows, int cols, int row, int col, char* str, int boo[][4], int& index)
{
	if (str[index] == '\0')
		return true;
	bool HasPath = false;
	if (row < rows && col < cols && str[index] == arr[row][col] && !boo[row][col])
	{
		++index;
		boo[row][col] = 1;
		HasPath = CheckPath(arr, 3, 4, row + 1, col, str, boo, index) ||
			CheckPath(arr, 3, 4, row, col + 1, str, boo, index) ||
			CheckPath(arr, 3, 4, row - 1, col, str, boo, index) ||
			CheckPath(arr, 3, 4, row, col - 1, str, boo, index);
		if (!HasPath)
		{
			--index;
			boo[row][col] = 0;
		}
	}
	return HasPath;
}
int main()
{
	int index = 0;
	char arr[3][4] = { 
		{ 'a', 'b', 't', 'g' },
		{ 'c', 'f', 'c', 's' },
		{ 'j', 'd', 'e', 'h' } };
	char* str = "bfce";
	int boo[3][4] = { 0 };
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (CheckPath(arr,3,4,row,col,str,boo,index))
			{
				cout << "存在路径" << endl;
				system("pause");
				return 0;
			}
		}
	}
	cout << "不存在路径" << endl;
	system("pause");
	return 0;
}

