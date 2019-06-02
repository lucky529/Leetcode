//与最大乘积子序列很像 16ms通过 1.从左向右遍历求出除去当前数字的左边 2.从右向左遍历求出除去当前数字的右边
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> v(nums.size(), 1);
		int k = 1;
		for (int i = 0; i < nums.size(); i++)//对除了当前数的左边数进行相乘
		{
			v[i] *= k;
			k = k*nums[i];
		}
		k = 1;
		for (int i = nums.size() - 1; i >= 0; i--)//对当前数的右边进行相乘
		{
			v[i] *= k;
			k = k*nums[i];
		}
		return v;
	}
};