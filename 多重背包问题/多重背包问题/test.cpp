class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @return: The maximum size
	*/
	int backPack(int m, vector<int> &A) {
		// write your code here
		if (A.empty() || m < 1) {
			return 0;
		}
		// write your code here
		vector<int> dp(m + 1, 0);


		for (int i = 0; i < A.size(); i++)
		{
			for (int j = A[i]; j <= m; j++)//核心代码需要理解这一行的含义
			{
				dp[j] = max(dp[j], A[i] + dp[j - A[i]]);
			}
		}
		return dp[m];
	}
};