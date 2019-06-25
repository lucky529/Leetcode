//动态规划 判断加上当前格子以及左上角的格子最多能围成多大的矩形
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
		int mit = 0;
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				if (matrix[i - 1][j - 1] == '1') {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
					mit = max(mit, dp[i][j]);
				}
			}
		}
		int res = mit*mit;
		return res;
	}
};