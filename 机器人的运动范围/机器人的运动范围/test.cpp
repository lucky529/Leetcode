#include<iostream>
#include<windows.h>
using namespace std;

int CheckSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return number;
}
bool CheckPath(int boo[][40], int rows, int cols, int row, int col, int key)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols && !boo[row][col] && (CheckSum(row) + CheckSum(col) <= key))
	{
		return true;
	}
	return false;
}
int PathScope(int boo[][40], int rows, int cols, int row, int col, int key)
{
	int count = 0;
	if (CheckPath(boo, rows, cols, row, col, key))
	{
		boo[row][col] = 1;
		count = 1 + PathScope(boo, rows, cols, row + 1, col, key) +
			PathScope(boo, rows, cols, row, col + 1, key) +
			PathScope(boo, rows, cols, row - 1, col, key) +
			PathScope(boo, rows, cols, row, col - 1, key);
	}
	return count;
}
int main()
{
	int row = 40, col = 40, key = 19;
	int boo[40][40] = { 0 };
	int count = PathScope(boo, row, col, 0, 0, key);
	cout << count << endl;
	system("pause");
	return 0;
}