//广度优先搜索，查找板块中的连通域
class Solution {
public:
	void GetNum(vector<vector<char>>& grid, int x, int y)
	{
		grid[x][y] = '0';
		if (x - 1 >= 0 && grid[x - 1][y] == '1') GetNum(grid, x - 1, y);
		if (x + 1<grid.size() && grid[x + 1][y] == '1') GetNum(grid, x + 1, y);
		if (y - 1 >= 0 && grid[x][y - 1] == '1') GetNum(grid, x, y - 1);
		if (y + 1<grid[0].size() && grid[x][y + 1] == '1') GetNum(grid, x, y + 1);
	}
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					GetNum(grid, i, j);
					count++;
				}
			}
		}
		return count;
	}
};