//int[] w = { 2, 1, 3, 2 };
//int[] v = { 12, 10, 20, 15 };
//capacity = 5


////分割等和子集同样属于背包问题
//int _canPartition(vector<int>& nums, int c)
//{
//	int size = nums.size();
//	vector<vector<int>> dp(size, vector<int>(c + 1, 0));
//	for (int i = 0; i <= c; i++)
//	{
//		dp[0][i] = i < nums[0] ? 0 : nums[0];
//	}
//	for (int i = 1; i < nums.size(); i++)
//	{
//		for (int j = 0; j <= c; j++)
//		{
//			dp[i][j] = dp[i - 1][j];
//			if (j >= nums[i])
//				dp[i][j] = max(dp[i - 1][j], nums[i] + dp[i - 1][j - nums[i]]);
//		}
//	}
//	return dp[size - 1][c];
//}
//bool canPartition(vector<int>& nums) {
//	int sum = 0;
//	for (auto& e : nums) sum += e;
//	if (sum % 2 != 0) return false;
//	return sum / 2 == _canPartition(nums, sum / 2);
//}
//

#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;
//
//int GetMaxNum(vector<int> w, vector<int> v, int c)
//{
//	int size = w.size();
//	if (size == 0) return 0;
//	vector<vector<int>> dp(size, vector<int>(c + 1, 0));
//	for (int i = 0; i <= c; i++)
//	{
//		dp[0][i] = i < w[0] ? 0 : v[0];
//	}
//
//	for (int i = 1; i < size; i++)
//	{
//		for (int j = 0; j <= c; j++)
//		{
//			dp[i][j] = dp[i - 1][j];
//			if (j >= w[i])
//				dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
//		}
//	}
//	return dp[size - 1][c];
//}
//
//
int GetMaxNum1(vector<int> w, vector<int> v, int c)
{
	int size = w.size();
	if (size == 0) return 0;
	vector<vector<int>> dp(size, vector<int>(c + 1, 0));

	for (int i = 1; i < size; i++)
	{
		for (int j = w[i]; j <= c; j++)
		{
			dp[i][j] = max(dp[i - 1][j], v[i] + dp[i][j - w[i]]);
		}
	}
	return dp[size - 1][c];
}
//

int GetMaxNum(vector<int> w, vector<int> v, int c)
{
	int size = w.size();
	if (size == 0) return 0;
	vector<int> dp(c+1, 0);

	for (int i = 0; i < size; i++)
	{
		for (int j = c; j >= w[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	return dp[c];
}
int main()
{
	vector<int> w = { 2,1,3,2 };
	vector<int> v = { 12,10,20,15 };
	int c = 5;
	cout << GetMaxNum(w, v, c) << endl;
	system("pause");
	return 0;
}
