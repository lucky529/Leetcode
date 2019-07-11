//很简单，正数不可以作为最下子序列的前缀，所以每当num和大于0时那么就重新开始计算序列
int main()
{
	vector<int> v = { 2, 2, 3, 3, 1 };
	int num = v[0], Min = INT_MAX;
	for (int i = 1; i < v.size(); i++)
	{
		if (num > 0)
			num = v[i];
		else
			num += v[i];
		Min = min(Min, num);
	}
	cout << Min << endl;
	system("pause");
	return 0;
}