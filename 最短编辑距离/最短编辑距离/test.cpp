#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));
		for (int i = 0; i <= str1.size(); i++)
		{
			dp[i][0] = i;
		}
		for (int j = 0; j <= str2.size(); j++)
		{
			dp[0][j] = j;
		}
		for (int i = 1; i <= str1.size(); i++)
		{
			for (int j = 1; j <= str2.size(); j++)
			{
				if (str1[i - 1] == str2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				}
			}
		}
		cout << dp.back().back() << endl;
	}
	return 0;
}