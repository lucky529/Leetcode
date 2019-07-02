//16ms通过 1.非常有趣的一道题，看似简单但是事实上涵盖了很多细节的地方，通过dr dc数组来访问当前元素的上下左右是否挡住了某些部分
class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		int dr[4] = { 0, 1, 0, -1 };
		int dc[4] = { 1, 0, -1, 0 };

		int sum = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid.size(); j++)
			{
				if (grid[i][j] > 0)
				{
					sum += 2;
					for (int flag = 0; flag < 4; flag++)
					{
						int nx = i + dr[flag];
						int ny = j + dc[flag];
						int nv = 0;
						if (0 <= nx && nx < grid.size() && 0 <= ny && ny < grid.size())
							nv = grid[nx][ny];

						sum += max(grid[i][j] - nv, 0);
					}
				}
			}
		}
		return sum;
	}
};