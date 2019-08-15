//前后指针法 1.当前区间满足条件将pre指针++，寻找下一个符合条件的区间 2.如果没有进入while循环说明一直没有满足的区间
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int cur = 0, pre = 0, ret = INT_MAX, sum = 0, flag = 0;
		while (cur < nums.size())
		{
			if (cur < nums.size() && sum < s)
			{
				sum += nums[cur++];
			}
			while (sum >= s)
			{
				ret = min(ret, cur - pre);
				flag = 1;
				sum -= nums[pre++];
			}
		}
		return flag == 1 ? ret : 0;
	}
};