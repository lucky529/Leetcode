//16ms �򵥵Ķ�̬�滮����ǰ���ݼ����������ߵ���Сֵ
class Solution {
public:
	int minPathSum(vector<vector<int>>& obstacleGrid) {
		for (int i = 0; i < obstacleGrid.size(); i++)
		{
			for (int j = 0; j < obstacleGrid[i].size(); j++)
			{
				if (i == 0 && j == 0)
					continue;
				else if (i == 0 && j != 0)
					obstacleGrid[i][j] += (long long)obstacleGrid[i][j - 1];
				else if (j == 0 && i != 0)
					obstacleGrid[i][j] += (long long)obstacleGrid[i - 1][j];
				else
					obstacleGrid[i][j] += min((long long)obstacleGrid[i - 1][j], (long long)obstacleGrid[i][j - 1]);
			}
		}
		return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};