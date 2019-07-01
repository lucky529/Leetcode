//与丑数二的解题思路完全相同，给每一个数一个指针下标，每个下标指向当前dp数组中与primes数组中乘积的最小值的下标
class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		ios::sync_with_stdio(0); cin.tie(NULL);
		vector<int> dp(n, 0);
		dp[0] = 1;
		vector<int> p(primes.size(), 0);
		for (int i = 1; i < n; i++)
		{
			int num = INT_MAX;
			for (int j = 0; j < p.size(); j++)
			{
				int tmp = dp[p[j]] * primes[j];
				if (tmp < num) num = tmp;
			}
			for (int j = 0; j < p.size(); j++)
			{
				if (num == dp[p[j]] * primes[j]) ++p[j];
			}
			dp[i] = num;
		}
		return dp[n - 1];
	}
};

//将此种方法应用到丑数2中
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> primes = { 2, 3, 5 };
		vector<int> dp(n, 0);
		vector<int> p(3, 0);
		dp[0] = 1;
		for (int i = 1; i < n; i++)
		{
			int num = INT_MAX;
			for (int j = 0; j < 3; j++)
			{
				int tmp = dp[p[j]] * primes[j];
				if (tmp < num) num = tmp;
			}
			for (int j = 0; j < 3; j++)
			{
				if (num == dp[p[j]] * primes[j]) ++p[j];
			}
			dp[i] = num;
		}
		return dp[n - 1];
	}
};