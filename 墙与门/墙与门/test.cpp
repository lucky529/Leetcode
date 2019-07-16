class Solution {
public:
	void bfs(vector<vector<int>>& rooms, vector<vector<int>> nums, pair<int, int> kv)
	{
		int dx[4] = { 0, 1, 0, -1 };
		int dy[4] = { 1, 0, -1, 0 };
		queue<pair<int, int>> q; q.push(kv);
		while (!q.empty())
		{
			auto it = q.front(); q.pop();
			int x = it.first / rooms[0].size(), y = it.first % rooms[0].size();
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + x;
				int ny = dy[i] + y;
				if (ny >= 0 && ny < rooms[0].size()
					&& nx >= 0 && nx < rooms.size() && nums[nx][ny] == INT_MAX)
				{
					nums[nx][ny] = it.second + 1;
					rooms[nx][ny] = min(rooms[nx][ny], it.second + 1);
					q.push({ nx*rooms.size() + ny, it.second + 1 });
				}
			}
		}
	}
	void wallsAndGates(vector<vector<int>>& rooms) {
		if (rooms.size() == 0) return;
		vector<vector<int>> nums(rooms.size(), vector<int>(rooms[0].size()));
		queue<pair<int, int>> q;
		for (int i = 0; i < rooms.size(); i++)
		{
			for (int j = 0; j < rooms[i].size(); j++)
			{
				if (rooms[i][j] == INT_MAX) nums[i][j] = INT_MAX;
				else if (rooms[i][j] == -1) nums[i][j] = -1;
				else if (rooms[i][j] == 0)
				{
					q.push({ i* rooms[i].size() + j, 0 });
					nums[i][j] = 0;
				}
			}
		}
		while (!q.empty())
		{
			bfs(rooms, nums, q.front());
			q.pop();
		}
	}
};

//ÓÅ»¯°æ±¾
class Solution {
public:
	void bfs(vector<vector<int>>& rooms, int x, int y, int val)
	{
		if (x < 0 || x >= rooms.size())
			return;
		if (y < 0 || y >= rooms[0].size())
			return;
		if (rooms[x][y] < val)
			return;
		rooms[x][y] = val;

		bfs(rooms, x + 1, y, val + 1);
		bfs(rooms, x, y + 1, val + 1);
		bfs(rooms, x - 1, y, val + 1);
		bfs(rooms, x, y - 1, val + 1);
	}
	void wallsAndGates(vector<vector<int>>& rooms) {
		if (rooms.size() == 0) return;
		for (int i = 0; i < rooms.size(); i++)
		{
			for (int j = 0; j < rooms[0].size(); j++)
			{
				if (rooms[i][j] == 0)
				{
					bfs(rooms, i, j, 0);
				}
			}
		}
	}
};