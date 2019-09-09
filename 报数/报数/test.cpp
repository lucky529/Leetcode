int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n + 1, 1);
		int index = 0, res = 0, i = 1;
		while (i)
		{
			if (v[i] != 0)
				index++;
			if (index % 5 == 0)
			{
				res += 1;
				v[i] = 0;
			}
			if (index % 5 == 0 && i == n)
			{
				cout << res << endl;
				break;
			}
			if (i == n)
			{
				i = 1; continue;
			}
			i++;
		}
	}
	system("pause");
	return 0;
}