//��ʹ�ö���ɸɸѡ��ǰ1000��������Ȼ��ƥ�伴��
int main()
{
	int boo[1000] = { 1 };//����ɸ
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
	while (cin >> n){//ƥ��ÿһ������
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