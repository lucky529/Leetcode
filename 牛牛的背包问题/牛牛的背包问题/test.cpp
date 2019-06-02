//dfs �жϵ�ǰ��Ʒ�Ƿ���Ҫ���뱦��
#include<iostream>
#include<vector>
using namespace std;
int ans = 0;
int num;
int dfs(vector<int> v, int capacity, int index)
{
	if (capacity < 0)
		return 0;
	if (index == num)
	{
		return 1;
	}

	return dfs(v, capacity, index + 1) + dfs(v, capacity - v[index], index + 1);
}
int main()
{
	cin >> num;
	int capacity; cin >> capacity;
	vector<int> v(num);
	long long sum = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	if (sum < capacity)
	{
		cout << (1 << num) << endl;
	}
	else
	{
		cout << dfs(v, capacity, 0) << endl;
	}
	return 0;
}