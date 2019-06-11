//注意这里出现的问题，从队列中拿数据时不要取队列数据的引用，否则将出现访问已经释放的堆空间问题
//一个简单的BFS
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& nums) {
		int dx[4] = { 0, 1, 0, -1 };
		int dy[4] = { 1, 0, -1, 0 };
		int m = nums.size(), n = nums[0].size();
		queue<pair<int, int>> q;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (nums[i][j] == 0)
				{
					q.push(make_pair(i, j));
				}
				else
				{
					nums[i][j] = INT_MAX;
				}
			}
		}
		while (!q.empty()){
			auto t = q.front();
			q.pop();
			for (int i = 0; i < 4; i++){
				int x = t.first + dx[i], y = t.second + dy[i];
				if (x<0 || y<0 || x >= m || y >= n || nums[x][y] <= nums[t.first][t.second] + 1) continue;
				nums[x][y] = nums[t.first][t.second] + 1;
				q.push(make_pair(x, y));
			}
		}
		return nums;
	}
};