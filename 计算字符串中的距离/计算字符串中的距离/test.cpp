//��������S��T�ĳ��ȷֱ�Ϊm��n, ���ߵı༭�����ʾΪdp[m][n].������н��в���ʱ�������¼������:
//
//a, ��S��T��ĩβ�ַ����ʱ, ��ĩβ�ַ�����Ҫ�����������������(�༴"�༭")���κ�һ��, Ҳ���ǲ���Ҫ���Ӽ���.���������� : dp[m][n] = dp[m - 1][n - 1].
//b, ��S��T��ĩβ�ַ������ʱ, ����Ҫ������֮һ��ĩβ���б༭, ��Ӧ�ļ���������1.
//b1, ��S��T��ĩβ�����޸�, ��ʹ֮��T��S���, ���ʱdp[m][n] = dp[m - 1][n - 1] + 1;
//b2, ɾ��Sĩβ��Ԫ��, ʹS��T���, ���ʱdp[m][n] = dp[m - 1][n] + 1;
//b3, ɾ��Tĩβ��Ԫ��, ʹT��S���, ���ʱdp[m][n] = dp[m][n - 1] + 1;
//b4, ��S��ĩβ���T��βԪ��, ʹS��T���, ���ʱS�ĳ��ȱ�Ϊm + 1, ���Ǵ�ʱS��T��ĩβԪ���Ѿ����, ֻ��Ҫ�Ƚ�S��ǰm��Ԫ����T��ǰn - 1��Ԫ��, ��������dp[m][n] = dp[m][n - 1] + 1;
//b5, ��T��ĩβ���S��βԪ��, ʹT��S���, ��ʱ�������b4��ͬ, ����dp[m][n] = dp[m - 1][n] + 1;
//c, �Ƚ�����������, ��SΪ��ʱ, dp[0][n] = n; ����TΪ��ʱ, dp[m][0] = m; ����ܺ����, �����������""��"abc", �����ߵ����ٲ���Ϊ3, ������""����3�β������, ��������"abc"����3��ɾ������.

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
		for (int i = 1; i <= str1.size(); i++)
			dp[i][0] = i;
		for (int j = 0; j <= str2.size(); j++)
			dp[0][j] = j;

		for (int i = 1; i <= str1.size(); i++)
		{
			for (int j = 1; j <= str2.size(); j++)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
				{
					int tmp = min(dp[i - 1][j], dp[i][j - 1]);
					dp[i][j] = min(dp[i - 1][j - 1], tmp) + 1;
				}
			}
		}
		cout << dp.back().back() << endl;
	}
	return 0;
}