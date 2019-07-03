//又是晴朗的一天，牛牛的小伙伴们都跑来找牛牛去公园玩。但是牛牛想呆在家里看E3展，不想出去逛公园，可是牛牛又不想鸽掉他的小伙伴们，于是找来了公园的地图，发现公园是由一个边长为n的正方形构成的，公园一共有m个入口，但出口只有一个。公园内有一些湖和建筑，牛牛和他的小伙伴们肯定不能从他们中间穿过，所以只能绕行。牛牛想知道他需要走的最短距离并输出这个最短距离。
//
//输入描述 :
//第一行输入一个数字n(1≤n≤1000)表示公园的边长
//接下来会给你一个n*n的公园地图，其中.表示公园里的道路，@表示公园的入口，*表示公园的出口，#表示公园内的湖和建筑。牛牛和他的小伙伴们每次只能上下左右移动一格位置。
//输入保证公园入口个数m(1≤m≤10000)且所有的入口都能和出口相连。
//
//
//输出描述 :
//输出牛牛需要行走的最短距离。
//示例1
//输入
//10
//.@....##@.
//......#...
//...@..#...
//###.......
//....##..#.
//...####...
//@...##....
//#####.....
//..##*####.
//#.........

//本题实际上可以使用逆向思维，因为出口只有一个，所以我们可以从出口开始反向搜索最近的入口，进行广度优先搜索，那么
//我们搜到的最近的一个入口就是我们所要找的最近的距离
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main()
{
	int n; cin >> n;
	vector<vector<char>> nums(n, vector<char>(n, 0));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> nums[i][j];
			if (nums[i][j] == '*')
				q.push(make_pair(i*n + j, 0));
		}
	}
	while (!q.empty())
	{
		auto& cur = q.front();
		q.pop();
		int x = cur.first / n, y = cur.first%n;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < n && nums[nx][ny] == '.')
			{
				nums[nx][ny] = 'x';
				q.push(make_pair(nx*n + ny, cur.second + 1));
			}
			else if (ny >= 0 && ny < n && nx >= 0 && nx < n && nums[nx][ny] == '@')
			{
				cout << cur.second + 1 << endl;
				return 0;
			}
		}
	}
	return 0;
}