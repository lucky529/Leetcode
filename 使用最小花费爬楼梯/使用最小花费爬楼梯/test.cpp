//简单的动态规划问题 1.当处于我当前所在的台阶时，只有两种方式可以跳到这个台阶上，一种是从当前的台阶的前一级，另一种是从
//当前台阶的前前一级，所以只需要求出跳到当前台阶时的最小花费，而每个问题有是一个子问题
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 0;
		for (int i = 2; i <= n; i++){
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[n];
	}
};