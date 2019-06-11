//�򵥵Ķ�̬�滮��������֮����������һ����
class Solution {
public:
	int minCost(vector<vector<int>>& costs) {
		if (costs.size() == 0) return 0;
		for (int i = 1; i < costs.size(); i++)
		{
			for (int j = 0; j < costs[i].size(); j++)
			{
				if (j == 0)
					costs[i][j] += min(costs[i - 1][1], costs[i - 1][2]);
				else if (j == 1)
					costs[i][j] += min(costs[i - 1][0], costs[i - 1][2]);
				else if (j == 2)
					costs[i][j] += min(costs[i - 1][0], costs[i - 1][1]);
			}
		}
		int ret = INT_MAX;
		for (int i = 0; i < costs[0].size(); i++)
		{
			if (costs[costs.size() - 1][i] < ret)
				ret = costs[costs.size() - 1][i];
		}
		return ret;
	}
};