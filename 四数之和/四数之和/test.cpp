// 60ms通过 1.思路与三数之和相同，固定两个数字，剩余两个数字使用双指针寻找
//			2.这里使用set可以帮我我们去重
//			3.返回的时候直接将set的迭代器交给二维数组就好
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		set<vector<int>> s;
		for (int i = 0; i < n; i++)
		{
			if (i > 0 && nums[i - 1] == nums[i]) continue;
			for (int j = i + 1; j < n; j++)
			{
				int start = j + 1, end = n - 1;
				while (start < end)
				{
					int tmp = nums[start] + nums[end] + nums[i] + nums[j];
					if (tmp == target && i < j)
					{
						s.insert(vector<int>{nums[start], nums[end], nums[i], nums[j]});
						while (start < end && nums[start] == nums[start + 1]) start++;
						while (start < end && nums[end] == nums[end - 1]) end--;
						start++; end--;
					}
					else if (tmp > target) end--;
					else start++;
				}
			}
		}
		return vector<vector<int>>(s.begin(), s.end());
	}
};