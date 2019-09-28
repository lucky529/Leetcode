//44ms通过 可以使用dfs加上记忆化矩阵的思想进行
class Solution {
public:
	int m, n;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int longestIncreasingPath(vector<vector<int>>& nums) {
		if (nums.size() == 0) return 0;
		m = nums.size();
		n = nums[0].size();
		int ret = 0;
		vector<vector<int>> flag(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				ret = max(ret, dfs(nums, i, j, flag));
			}
		}
		return ret;
	}
	int dfs(vector<vector<int>>& nums, int x, int y, vector<vector<int>>& flag)
	{
		if (flag[x][y] != 0) return flag[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && nums[nx][ny] > nums[x][y])
				flag[x][y] = max(flag[x][y], dfs(nums, nx, ny, flag));
		}
		return ++flag[x][y];
	}
};