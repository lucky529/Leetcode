// 与螺旋矩阵1的道理相同，只不过是开一个二维数组逐个放进去就好
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> vv(n, vector<int>(n, int()));
		int cur = 0, row = n, col = n, count = (min(row, col) + 1) / 2, num = 1, target = pow(n, 2);
		while (cur < count && num <= target)
		{
			for (int i = cur; i < row - cur && num <= target; i++)
				vv[cur][i] = num++;
			for (int i = cur + 1; i < col - cur && num <= target; i++)
				vv[i][row - cur - 1] = num++;
			for (int i = row - cur - 2; i >= cur && col - cur - 1 != cur && num <= target; i--)
				vv[col - cur - 1][i] = num++;
			for (int i = col - cur - 2; i >= cur + 1 && row - cur - 1 != cur && num <= target; i--)
				vv[i][cur] = num++;
			cur++;
		}
		return vv;
	}
};