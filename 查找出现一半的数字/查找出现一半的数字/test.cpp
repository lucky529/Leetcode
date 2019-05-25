class Solution {
public:
	int checknum(vector<int> nums, int ret)
	{
		int count = 0;
		for (auto& e : nums)
		{
			if (e == ret)
				count++;
		}
		return count > (int)(nums.size() / 2) ? ret : 0;
	}
	int MoreThanHalfNum_Solution(vector<int> nums) {
		if (nums.size() == 0) return 0;
		srand(time(NULL));
		int ret = MoreThanHalfNum_Solution(nums, 0, nums.size() - 1, nums.size() / 2);
		return checknum(nums, ret);
	}
	int MoreThanHalfNum_Solution(vector<int> nums, int l, int r, int k)
	{
		int index = partition(nums, l, r);
		if (index == nums.size() - k) return nums[index];
		if (index < nums.size() - k) return MoreThanHalfNum_Solution(nums, index + 1, r, k);
		if (index > nums.size() - k) return MoreThanHalfNum_Solution(nums, l, index - 1, k);
		return -1;
	}
	int partition(vector<int> v, int l, int r)
	{
		int key = rand() % (r - l + 1) + l;
		swap(v[l], v[key]);
		int cur = l + 1, pre = l;
		while (cur <= r){
			if (v[cur] <= v[l] && ++pre != cur)
				swap(v[cur], v[pre]);
			cur++;
		}
		swap(v[l], v[pre]);
		return pre;
	}
};