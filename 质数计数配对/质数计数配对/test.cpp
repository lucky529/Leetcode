//先使用厄拉筛筛选出前1000个质数，然后匹配即可
int main()
{
	int boo[1000] = { 1 };//厄拉筛
	boo[1] = 1;
	for (int i = 2; i <= sqrt(1000) + 1; i++){
		if (boo[i] == 0){
			for (int j = i * 2; j < 1000; j += i)
				boo[j] = 1;
		}
	}
	vector<int> v;
	for (int i = 0; i < 1000; i++)	{
		if (boo[i] == 0)
			v.push_back(i);
	}

	int n;
	while (cin >> n){//匹配每一对质数
		vector<vector<int>> vv;
		for (int i = 0; i < v.size(); i++){
			int tmp = n - v[i];
			vector<int> tm{ v[i], tmp };
			sort(tm.begin(), tm.end());
			if (find(v.begin(), v.end(), tmp) != v.end() &&
				find(vv.begin(), vv.end(), tm) == vv.end())
				vv.push_back(tm);
		}
		cout << vv.size() << endl;
	}
	system("pause");
	return 0;
}