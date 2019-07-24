//很简单的动态规划
string SubStr(string a, string b)
{
	if (a.size() == 0 || b.size() == 0) return "";
	int len1 = a.size();
	int len2 = b.size();
	int ret = INT_MIN, start = 0;
	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;

			if (dp[i][j] > ret)
			{
				ret = dp[i][j];
				start = i;
			}
		}
	}
	return a.substr(start - ret, ret);
}
int main()
{
	string ret = SubStr("abcddddsd", "abcdsadasddsd");
	cout << ret << endl;
	system("pause");
	return 0;
}