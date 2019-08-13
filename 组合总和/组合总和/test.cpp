//1000ms通过 1.回溯的思想每当数组中的数字等于target就push到二维数组中
class Solution {
public:
	vector<vector<int>> vv;
	void _combinationSum(vector<int> v, int sum, vector<int>& candidates, int target)
	{
		if (sum == target) {
			sort(v.begin(), v.end());
			if (find(vv.begin(), vv.end(), v) == vv.end())
				vv.push_back(v);
			return;
		}
		if (sum > target) return;
		for (auto& e : candidates)
		{
			v.push_back(e);
			_combinationSum(v, sum + e, candidates, target);
			v.pop_back();//致命的pop_back(),每次回溯到上一层时需要pop的本层的上一次push的数字
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> v;
		_combinationSum(v, 0, candidates, target);
		return vv;
	}
};

//优化版本快了600倍，利用一个ind来防止使用以前的数字，不在需要进行排序
class Solution {
public:
	vector<vector<int>> res;
	vector<int> ans;
	void dfs(int ind, int sum, vector<int>& candidates, int tt) {
		if (sum == tt) {
			res.push_back(ans);
			return;
		}
		for (int i = ind; i<candidates.size(); i++) {
			if (candidates[i] + sum <= tt) {
				ans.push_back(candidates[i]);
				dfs(i, sum + candidates[i], candidates, tt);
				ans.pop_back();
			}
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.empty()) return res;
		dfs(0, 0, candidates, target);
		return res;
	}
};