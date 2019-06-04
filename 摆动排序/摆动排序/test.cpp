//对数组相邻的俩个数字进行俩次大小的比较进行排序
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 0) return;
		int cur = 1, pre = 0;
		while (cur < nums.size()) {
			if (nums[cur] < nums[pre]) {
				int tmp = nums[cur];
				nums[cur] = nums[pre];
				nums[pre] = tmp;
			}
			cur += 2;
			pre += 2;
		}
		if (nums.size() == 2) return;
		cur = 2, pre = 1;
		while (cur < nums.size()) {
			if (nums[cur] > nums[pre]) {
				int tmp = nums[cur];
				nums[cur] = nums[pre];
				nums[pre] = tmp;
			}
			cur += 2;
			pre += 2;
		}
	}
};
//判断奇数偶数位置进行排序
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int size = nums.size();
		for (int i = 1; i < size; ++i)
		{
			if (i & 1)
			{
				if (nums[i - 1] > nums[i])
				{
					swap(nums[i - 1], nums[i]);
				}
			}
			else
			{
				if (nums[i - 1] < nums[i])
				{
					swap(nums[i - 1], nums[i]);
				}
			}
		}
	}
};