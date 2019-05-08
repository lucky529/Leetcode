//172ms通过 1.利用俩个数组模拟机器人改变方向之后x，y的增减 2.判断机器人在行走的每一步之后是否撞上了障碍物
class Solution {
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		int dx[4] = { 0, 1, 0, -1 };
		int dy[4] = { 1, 0, -1, 0 };
		int x = 0, y = 0, di = 0, ret = 0;
		set<pair<int, int>> mp;
		for (auto& e : obstacles)
		{
			mp.insert(make_pair(e[0], e[1]));
		}
		for (auto& e : commands)
		{
			if (e == -1)
			{
				di = (di + 1) % 4;
			}
			else if (e == -2)
			{
				di = (di + 3) % 4;
			}
			else
			{
				for (int i = 0; i < e; i++)
				{
					int nx = x + dx[di];
					int ny = y + dy[di];
					if (mp.find(make_pair(nx, ny)) == mp.end())
					{
						x = nx;
						y = ny;
						ret = max(ret, x*x + y*y);
					}
				}
			}
		}
		return ret;
	}
};