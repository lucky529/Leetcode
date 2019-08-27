#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;

int func(vector<vector<int>>& vv, int n, int m)
{
	long long ret = 0;
	for (int i = 0; i < m; i++)
	{
		int tmp = -1;
		for (int j = 0; j < n; j++)
		{
			if (tmp < vv[i][j])
				tmp = vv[i][j];
		}
		ret += tmp;
	}
	return ret;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<vector<int>> vv(n, vector<int>(m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> vv[i][j];
			}
		}
		cout << func(vv, n, m) << endl;
	}
	system("pause");
	return 0;
}