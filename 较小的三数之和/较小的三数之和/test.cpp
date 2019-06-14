//和三数之和的思路相同 1.如果当前区间已经满足条件，说明right边界的的左边与left边界这个数同样可以组成结果
					// 如果当前的结果大于或者等于结果，那么end--
class Solution {
public:
	int threeSumSmaller(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), count = 0;
		for (int i = 0; i < n; i++)
		{
			int start = i + 1, end = n - 1;
			while (start < end)
			{
				int tmp = nums[i] + nums[start] + nums[end];
				if (tmp < target)
				{
					count += (end - start);
					start++;
				}
				if (tmp >= target)
					end--;
			}
		}
		return count;
	}
};