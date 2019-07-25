#include<queue>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int bfs(int row, int col, int x, int y, vector<vector<char>>& vv, vector<vector<bool>>& flag)
{
	queue<int> q;
	int count = 1;
	q.push(x*col + y);
	flag[x][y] = true;
	while (!q.empty())
	{
		int num = q.front(); q.pop();
		int nx = num / col, ny = num%col;
		for (int i = 0; i < 4; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx >= 0 && xx < row && yy >= 0 && yy < col && !flag[xx][yy] && vv[xx][yy] == '.')
			{
				flag[xx][yy] = true;
				count++;
				q.push(xx*col + yy);
			}
		}
	}
	return count;
}
int main()
{
	int row, col;
	while (cin >> row >> col && (row*col))
	{
		vector<vector<char>> vv(row, vector<char>(col));
		vector<vector<bool>> flag(row, vector<bool>(col, 0));
		int x, y, tmp = 1;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> vv[i][j];
				flag[i][j] = false;
				if (vv[i][j] == '@')
				{
					x = i; y = j;
				}
			}
		}
		flag[x][y] = true;
		cout << bfs(row, col, x, y, vv, flag) << endl;
	}
	return 0;
}