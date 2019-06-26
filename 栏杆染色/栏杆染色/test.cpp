//第一个栏杆有k种办法
//第二个栏杆有k*k种办法
//第三个栏杆：第三种颜色有两种情况，与3相同和与3不同 
//1.如果3和2相同，那么3不能与1相同，所以可以染的颜色就为（k*k）*(k - 1) 
//2.如果3和2不同，在不与3相同的前提下，染色方案为k*（k - 1）
class Solution {
public:
	int numWays(int n, int k) {
		if (n == 0 || k == 0) return 0;
		if (n == 1) return k;

		vector<int> dp(n + 1, 0);
		dp[1] = k;
		dp[2] = k*k;
		for (int i = 3; i <= n; i++)
		{
			dp[i] = (dp[i - 2] + dp[i - 1])*(k - 1);
		}
		return dp.back();
	}
};