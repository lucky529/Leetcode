//第一次400ms通过也是惊了，原来是下标控制的错了，使用回溯算法就行，和全排列的思想很像
class Solution {
public:
	vector<vector<int>> vv;
	vector<int> v;
	void _combine(int index, vector<int>& nums, int k)
	{
		if (v.size() == k)
		{
			vv.push_back(v);
			return;
		}
		for (int i = index; i < nums.size(); i++)
		{
			v.push_back(nums[i]);
			_combine(i + 1, nums, k);
			v.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<int> nums;
		for (int i = 1; i <= n; i++) nums.push_back(i);

		_combine(0, nums, k);
		return vv;
	}
};