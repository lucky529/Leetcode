//16ms 1.很简单与移动零的思路完全相同 2.设置tmp哨兵数据，可以重复两次 3.只要使用index下标挨着向前放就可以
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int index = 0, cur = 0, flag = 2;
		while (cur < nums.size())
		{
			int tmp = nums[cur];
			while (cur < nums.size() && nums[cur] == tmp && flag)
			{
				nums[index++] = nums[cur++]; flag--;
			}
			while (cur < nums.size() && nums[cur] == tmp)
			{
				cur++;
			}
			flag = 2;
		}
		return index;
	}
};