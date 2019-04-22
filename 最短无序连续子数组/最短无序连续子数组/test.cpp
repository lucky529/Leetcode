//704ms通过（思路正确，但是代码写的有些问题）
//1.左边的当前数字是否存在比他小的数 2.右边的当前数字是否存在比他大的数字 3.右减去左加一
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int start = 0, end = nums.size() - 1, gap1 = 0, gap2 = 0, flag1 = 0, flag2 = 0;
		while (start <= end)
		{
			for (int i = start; i <= end; i++)
			{
				if (nums[i] < nums[start])
				{
					gap1 = start;
					flag1 = 1;
					break;
				}
			}
			if (flag1) break;
			start++;
		}
		start = gap1;
		while (start <= end)
		{
			for (int i = end - 1; i >= start; i--)
			{
				if (nums[i] > nums[end])
				{
					gap2 = end; flag2 = 1;
					break;
				}
			}
			if (flag2) break;
			end--;
		}
		if (gap2 > gap1)
			return gap2 - gap1 + 1;
		else
			return 0;
	}
};
//优化版本
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int n = nums.size(), a = nums[0], b = nums[n - 1], l = -1, r = -2;
		for (int i = 1; i<n; i++){
			a = max(a, nums[i]);
			b = min(b, nums[n - 1 - i]);
			if (a != nums[i])r = i;
			if (b != nums[n - 1 - i])l = n - 1 - i;
		}
		return r - l + 1;
	}
};