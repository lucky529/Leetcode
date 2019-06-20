//二分查找的思想，每次都将查找的范围缩小一半
class Solution {
public:
	int CountNum(vector<int>& nums, int start, int end)
	{
		int count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] >= start && nums[i] <= end)
				++count;
		}
		return count;
	}
	int findDuplicate(vector<int>& nums) {
		int start = 1, end = nums.size() - 1;
		while (start <= end)
		{
			int mid = start + ((end - start) >> 1);
			int count = CountNum(nums, start, mid);
			if (start == end)
			{
				if (count > 1)
					return start;
			}
			if (count > (mid - start + 1))
				end = mid;
			else
				start = mid + 1;
		}
		return -1;
	}
};