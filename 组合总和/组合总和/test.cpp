//1000msͨ�� 1.���ݵ�˼��ÿ�������е����ֵ���target��push����ά������
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
			v.pop_back();//������pop_back(),ÿ�λ��ݵ���һ��ʱ��Ҫpop�ı������һ��push������
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> v;
		_combinationSum(v, 0, candidates, target);
		return vv;
	}
};

//�Ż��汾����600��������һ��ind����ֹʹ����ǰ�����֣�������Ҫ��������
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