//寻找第一个比nums.size() - mid的数字且需要逼近极限
class Solution {
public:
	int hIndex(vector<int>& nums) {
		int start = 0, end = nums.size() - 1, mid = 0;
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (nums.size() - mid <= nums[mid])
				end = mid - 1;
			else
				start = mid + 1;
		}
		return nums.size() - start;
	}
};