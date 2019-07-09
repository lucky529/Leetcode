//最简单的方式就是dfs，并每次比较计数是否为最小值
class Solution {
public:
	int ret = INT_MAX;
	void dfs(vector<int>& v, int index, int sum, int target, int count)
	{
		if (sum == target)
		{
			ret = min(count, ret);
			return;
		}
		if (sum > target)
			return;
		for (int i = index; i >= 0; i--)
		{
			if (sum < target)
				dfs(v, i, sum + v[i], target, count + 1);
		}
	}
	int numSquares(int n) {
		vector<int> v;
		for (int i = 1;; i++)
		{
			if (i*i > n) break;
			v.push_back(i*i);
		}
		dfs(v, v.size() - 1, 0, n, 0);
		return ret;
	}
};

//贼经典的dp思想
class Solution {
public:	
	int numSquares(int n) {
		vector<int> dp(n + 1);
		dp[0] = 0;//表示走到这一步只需要0步
		for (int i = 1; i <= n; i++)
		{
			dp[i] = i;//暂且表示每一步都需要i步才能到达
			for (int j = 1; i - j*j >= 0; j++)
			{
				dp[i] = min(dp[i], dp[i - j*j] + 1);
			}
		}
		return dp[n];
	}
};

//4数平方定理，四平方定理： 任何一个正整数都可以表示成不超过四个整数的平方之和。 
//推论：满足四数平方和定理的数n（四个整数的情况），必定满足 n=4^a(8b+7)

//大佬简直太刁了
int numSquares(int n) {
	//先根据上面提到的公式来缩小n
	while (n % 4 == 0) {
		n /= 4;
	}
	//如果满足公式 则返回4
	if (n % 8 == 7) {
		return 4;
	}
	//在判断缩小后的数是否可以由一个数的平方或者两个数平方的和组成
	int a = 0;
	while ((a * a) <= n) {
		int b = sqrt((n - a * a));
		if (a * a + b * b == n) {
			//如果可以 在这里返回
			if (a != 0 && b != 0) {
				return 2;
			}
			else{
				return 1;
			}
		}
		a++;
	}
	//如果不行 返回3
	return 3;
}