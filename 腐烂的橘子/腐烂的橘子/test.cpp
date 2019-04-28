//在给定的网格中，每个单元格可以有以下三个值之一：
//值 0 代表空单元格；
//值 1 代表新鲜橘子；
//值 2 代表腐烂的橘子。
//每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
//返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 - 1。
//示例 1：
//
//输入：[[2, 1, 1], [1, 1, 0], [0, 1, 1]]
//输出：4
//示例 2：
//
//输入：[[2, 1, 1], [0, 1, 1], [1, 0, 1]]
//输出： - 1
//解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
//示例 3：
//
//输入：[[0, 2]]
//输出：0
//解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。

//思路 1.首先记录二维矩阵中有多少已经腐烂的橘子，并将这些橘子腐烂的时间设置为0
//     2.判断已经记录的橘子周围是否有新鲜的橘子，如果有就把腐烂橘子的时间加上1并且记录
//     3.最后判断二维矩阵中是否存在新鲜的橘子，如果有则返回-1
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int dr[4] = { 0, 1, 0, -1 };
		int dc[4] = { 1, 0, -1, 0 };
		int row = grid.size(), col = grid[0].size(), ret = 0;
		queue<int> q; map<int, int> mp;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == 2) {
					q.push(i*col + j);
					mp[i*col + j] = 0;
				}
			}
		}
		while (!q.empty()) {
			int tmp = q.front(); q.pop();
			int x = tmp / col, y = tmp%col;
			for (int i = 0; i < 4; i++) {
				int nx = x + dr[i];
				int ny = y + dc[i];
				if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
					grid[nx][ny] = 2;
					q.push(nx*col + ny);
					mp[nx*col + ny] = mp[x*col + y] + 1;
					ret = mp[nx*col + ny];
				}
			}
		}
		for (auto& e : grid)
		for (int v : e)
		if (v == 1)
			return -1;
		return ret;
	}
};