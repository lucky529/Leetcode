//纪念一下自己第一次重手动写过的动态规划
class Solution {
public:
	int integerBreak(int n) {
		if (n == 2) return 1;
		if (n == 3) return 2;
		vector<int> dp(n + 2);
		dp[0] = 0; dp[1] = 1;
		for (int i = 3; i <= n + 1; i++)
		{
			dp[i] = 1;
			for (int j = 1; i - j >= 0; j++)
			{
				dp[i] = max(dp[i], dp[i - j] * j);
			}
		}
		return dp[n + 1];
	}
};
//略微优化
class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		for (int i = 2; i<n + 1; i++) {
			for (int j = i - 1; j >= 1; j--) {
				dp[i] = max(dp[i], dp[j] * (i - j));
				dp[i] = max(dp[i], j*(i - j));//判断如果仅仅被拆成俩个数字
			}
		}
		return dp[n];
	}
};