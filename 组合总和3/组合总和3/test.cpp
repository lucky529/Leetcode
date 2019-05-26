//0ms通过 递归回溯的思想
class Solution {
public:
	vector<vector<int>> vv;
	vector<int> v;
	void dfs(int k, int n, int sum, int index)
	{
		if (sum == n && v.size() == k)
		{
			vv.push_back(v);
			return;
		}
		if (sum > n) return;
		for (int i = index; i <= 9; i++)
		{
			v.push_back(i);
			dfs(k, n, sum + i, i + 1);
			v.pop_back();
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		dfs(k, n, 0, 1);
		return vv;
	}
};