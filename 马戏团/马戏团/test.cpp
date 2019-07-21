//先使用体重对各位同学进行排序，然后从身高中找出最长的递增序列即可
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n; cin >> n;
	vector<vector<int>> vv(n, vector<int>(2, 0));
	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		cin >> vv[i][0];
		cin >> vv[i][1];
	}
	sort(vv.begin(), vv.end(), [](vector<int> v1, vector<int> v2)
	{
		return v1[0] < v2[0];
	});
	vector<int> dp(n, 1);
	int ret = INT_MIN;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((vv[j][1] < vv[i][1] && vv[j][0] < vv[i][0]) || (vv[j][1] == vv[i][1]
				&& vv[i][0] == vv[j][0]) || (vv[j][0] <  vv[i][0] && vv[j][1] == vv[i][1]))
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
			if (dp[i] > ret)
				ret = dp[i];
		}
	}
	cout << ret << endl;
	system("pause");
	return 0;
}